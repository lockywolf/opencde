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
/* $XConsortium: ctscm.c /main/2 1996/05/09 04:01:14 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: d_ctscm
 *
 *   ORIGINS: 157
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */
/*-----------------------------------------------------------------------
   ctscm.c -- db_VISTA current member creation timestamp get module.

   (C) Copyright 1987 by Raima Corporation.
-----------------------------------------------------------------------*/

/* ********************** EDIT HISTORY *******************************

 SCR    DATE    INI                   DESCRIPTION
----- --------- --- -----------------------------------------------------
      04-Aug-88 RTK MULTI_TASK changes
*/

#include <stdio.h>
#include "vista.h"
#include "dbtype.h"

#ifndef NO_TIMESTAMP
/* Get creation timestamp of current member
 */
d_ctscm(set, timestamp TASK_PARM DBN_PARM) int set;
ULONG FAR *timestamp;
TASK_DECL
DBN_DECL {
        INT rec;
        char FAR *rptr;
        SET_ENTRY FAR *set_ptr;

        DB_ENTER(DB_ID TASK_ID LOCK_SET(SET_IO));

        if (nset_check(set, &set, (SET_ENTRY FAR * FAR *)&set_ptr) != S_OKAY)
                RETURN(db_status);

        /* make sure we have a current member */
        if (!curr_mem[set])
                RETURN(dberr(S_NOCM));

        /* read current member */
        if (dio_read(curr_mem[set], (char FAR *FAR *)&rptr, NOPGHOLD) != S_OKAY)
                RETURN(db_status);

        /* get record id */
        bytecpy(&rec, rptr, sizeof(INT));
        if (rec >= 0) {
                rec &= ~RLBMASK; /* mask off rlb */
                if (record_table[NUM2INT(rec, rt_offset)].rt_flags &
                    TIMESTAMPED)
                        bytecpy(timestamp, rptr + RECCRTIME, sizeof(ULONG));
                else
                        *timestamp = 0L;
        } else
                db_status = S_DELETED;

        RETURN(db_status);
}
#endif
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC
 * -f/usr/users/master/config/nonwin ctscm.c */
