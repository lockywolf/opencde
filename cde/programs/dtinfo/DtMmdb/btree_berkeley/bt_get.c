/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these librararies and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: bt_get.c /main/3 1996/06/11 17:12:34 cde-hal $ */
/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Mike Olson.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)bt_get.c	8.2 (Berkeley) 9/7/93";
#endif /* LIBC_SCCS and not lint */

#include <sys/types.h>

#include <errno.h>
#include <stddef.h>
#include <stdio.h>

#include <db.h>
#include "btree.h"

/*
 * __BT_GET -- Get a record from the btree.
 *
 * Parameters:
 *	dbp:	pointer to access method
 *	key:	key to find
 *	data:	data to return
 *	flag:	currently unused
 *
 * Returns:
 *	RET_ERROR, RET_SUCCESS and RET_SPECIAL if the key not found.
 */
int __bt_get(dbp, key, data, flags) const DB *dbp;
const DBT *key;
DBT *data;
u_int flags;
{
        BTREE *t;
        EPG *e;
        int exact, status;

        t = dbp->internal;

        /* Toss any page pinned across calls. */
        if (t->bt_pinned != NULL) {
                mpool_put(t->bt_mp, t->bt_pinned, 0);
                t->bt_pinned = NULL;
        }

        /* Get currently doesn't take any flags. */
        if (flags) {
                errno = EINVAL;
                return (RET_ERROR);
        }

        if ((e = __bt_search(t, key, &exact)) == NULL)
                return (RET_ERROR);
        if (!exact) {
                mpool_put(t->bt_mp, e->page, 0);
                return (RET_SPECIAL);
        }

        /*
         * A special case is if we found the record but it's flagged for
         * deletion.  In this case, we want to find another record with the
         * same key, if it exists.  Rather than look around the tree we call
         * __bt_first and have it redo the search, as __bt_first will not
         * return keys marked for deletion.  Slow, but should never happen.
         */
        if (ISSET(t, B_DELCRSR) && e->page->pgno == t->bt_bcursor.pgno &&
            e->index == t->bt_bcursor.index) {
                mpool_put(t->bt_mp, e->page, 0);
                if ((e = __bt_first(t, key, &exact)) == NULL)
                        return (RET_ERROR);
                if (!exact)
                        return (RET_SPECIAL);
        }

        status = __bt_ret(t, e, NULL, data);
        /*
         * If the user is doing concurrent access, we copied the
         * key/data, toss the page.
         */
        if (ISSET(t, B_DB_LOCK))
                mpool_put(t->bt_mp, e->page, 0);
        else
                t->bt_pinned = e->page;
        return (status);
}

/*
 * __BT_FIRST -- Find the first entry.
 *
 * Parameters:
 *	t:	the tree
 *	key:	the key
 *
 * Returns:
 *	The first entry in the tree greater than or equal to key.
 */
EPG *__bt_first(t, key, exactp) BTREE *t;
const DBT *key;
int *exactp;
{
        register PAGE *h;
        register EPG *e;
        EPG save;
        pgno_t cpgno, pg;
        indx_t cindex;
        int found;

        /*
         * Find any matching record; __bt_search pins the page.  Only exact
         * matches are tricky, otherwise just return the location of the key
         * if it were to be inserted into the tree.
         */
        if ((e = __bt_search(t, key, exactp)) == NULL)
                return (NULL);
        if (!*exactp)
                return (e);

        if (ISSET(t, B_DELCRSR)) {
                cpgno = t->bt_bcursor.pgno;
                cindex = t->bt_bcursor.index;
        } else {
                cpgno = P_INVALID;
                cindex = 0; /* GCC thinks it's uninitialized. */
        }

        /*
         * Walk backwards, skipping empty pages, as long as the entry matches
         * and there are keys left in the tree.  Save a copy of each match in
         * case we go too far.  A special case is that we don't return a match
         * on records that the cursor references that have already been flagged
         * for deletion.
         */
        save = *e;
        h = e->page;
        found = 0;
        do {
                if (cpgno != h->pgno || cindex != e->index) {
                        if (save.page->pgno != e->page->pgno) {
                                mpool_put(t->bt_mp, save.page, 0);
                                save = *e;
                        } else
                                save.index = e->index;
                        found = 1;
                }
                /*
                 * Make a special effort not to unpin the page the last (or
                 * original) match was on, but also make sure it's unpinned
                 * if an error occurs.
                 */
                while (e->index == 0) {
                        if (h->prevpg == P_INVALID)
                                goto done1;
                        if (h->pgno != save.page->pgno)
                                mpool_put(t->bt_mp, h, 0);
                        if ((h = mpool_get(t->bt_mp, h->prevpg, 0)) == NULL) {
                                if (h->pgno == save.page->pgno)
                                        mpool_put(t->bt_mp, save.page, 0);
                                return (NULL);
                        }
                        e->page = h;
                        e->index = NEXTINDEX(h);
                }
                --e->index;
        } while (__bt_cmp(t, key, e) == 0);

        /*
         * Reach here with the last page that was looked at pinned, which may
         * or may not be the same as the last (or original) match page.  If
         * it's not useful, release it.
         */
done1:
        if (h->pgno != save.page->pgno)
                mpool_put(t->bt_mp, h, 0);

        /*
         * If still haven't found a record, the only possibility left is the
         * next one.  Move forward one slot, skipping empty pages and check.
         */
        if (!found) {
                h = save.page;
                if (++save.index == NEXTINDEX(h)) {
                        do {
                                pg = h->nextpg;
                                mpool_put(t->bt_mp, h, 0);
                                if (pg == P_INVALID) {
                                        *exactp = 0;
                                        return (e);
                                }
                                if ((h = mpool_get(t->bt_mp, pg, 0)) == NULL)
                                        return (NULL);
                        } while ((save.index = NEXTINDEX(h)) == 0);
                        save.page = h;
                }
                if (__bt_cmp(t, key, &save) != 0) {
                        *exactp = 0;
                        return (e);
                }
        }
        *e = save;
        *exactp = 1;
        return (e);
}
