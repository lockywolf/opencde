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
/*******************************************************************************
**
**  cmfns.c
**
**  $XConsortium: cmfns.c /main/3 1995/11/03 10:37:19 rswiston $
**
**  RESTRICTED CONFIDENTIAL INFORMATION:
**
**  The information in this document is subject to special
**  restrictions in a confidential disclosure agreement between
**  HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
**  document outside HP, IBM, Sun, USL, SCO, or Univel without
**  Sun's specific written approval.  This document and all copies
**  and derivative works thereof must be returned or destroyed at
**  Sun's request.
**
**  Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
**
*******************************************************************************/

/*									*
 * (c) Copyright 1993, 1994 Hewlett-Packard Company			*
 * (c) Copyright 1993, 1994 International Business Machines Corp.	*
 * (c) Copyright 1993, 1994 Sun Microsystems, Inc.			*
 * (c) Copyright 1993, 1994 Novell, Inc. 				*
 */


#ifndef lint
static 	char sccsid[] = "@(#)cmfns.c 1.3 94/11/07 Copyr 1993 Sun Microsystems, Inc.";
#endif

/*
 * Copyright 1993 Sun Microsystems, Inc.  All rights reserved
 */

#ifdef FNS

#include <EUSCompat.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#include "cm_tty.h"
#include "debug.h"
#include "props.h"
#include "dtfns.h"
#include "cmfns.h"

extern char *strdup(const char *);
extern FILE	*fdopen(int, const char *);

/*
 * Returns 1 if we can use FNS, else 0
 *
 * The first call to this routine can be a little costly.  Subsequent calls
 * are very cheap.  So avoid calling this routine at startup.
 */
int
cmfns_use_fns(Props *p)

{
	static int	init = 1;
	static int	fns_available;
	static boolean_t	use_fns;

	if (init) {
		use_fns = convert_boolean_str(get_char_prop(p, CP_USEFNS));
		if ((fns_available = dtfns_available()) == -1) {
			fns_available = 0;
		}
		init = 0;
	}

	if (use_fns && fns_available) {
		return 1;
	} else {
		return 0;
	}
}

/*
 *
 *	Get a calendar address from FNS
 *
 *      'name' may  be an absolute Helix name:
 *              user:smith
 *              org:ssi.eng:user:smith
 *              user:smith:service
 *
 *	'name' may be an FNS shorthand name:
 *		dipol
 *		dipol@ssi.eng
 *
 *	'name' may be a calendar address:
 *		dipol@sidewinder
 *	In which case it is copied unmodified into addr_buf.
 *
 *      'buf' is a buffer provided by the caller in which the calendar address
 *      is placed.
 *
 *      'size' is the size of 'buf'
 *
 *
 * Returns
 *
 *	-1	Name not found / Error
 *	0	FNS not available
 *	1	Success
 *
 */
int
cmfns_lookup_calendar(
	const char	*name,
	char		*addr_buf,
	int		addr_size
)

{
	int	rcode;
	char	fns_name[256];
	char	*types[4];
	char	*name_buf;
	char	*org, *tmp, *p;

	DP(("cmfns_lookup_calendar: Looking up %s\n", name));

	name_buf = strdup(name);

	strncpy(addr_buf, name, addr_size);

	addr_buf[addr_size - 1] = '\0';
	if ((org = strchr(name_buf, '@')) != NULL) {
		/* Either a calendar address or FNS shorthand */
		*org = '\0';
		org++;
		if (gethostbyname(org) != NULL) {
			/* Old style address.  Just return it */
			free(name_buf);
			return 1;
		}
	}

	/* Expand name to point at a calendar service */
	rcode = dtfns_service_name(name_buf, "user", CMFNS_CALENDAR_SERVICE,
		CMFNS_CALENDAR_TYPE, org, fns_name, sizeof(fns_name));

	if (rcode <= 0) {
		return rcode;
	}

	/* Specify the address types we support */
	types[0] = CMFNS_CALENDAR_ADDR_TYPE;
	types[1] = "SUNW_calendar";
	types[2] = "SUNW_cal_deskset";
	types[3] = NULL;

	/* Get string bound to calendar service name */
	rcode = dtfns_lookup_str(fns_name, types,  addr_buf, addr_size,
			NULL, 0);

	if (rcode <= 0) {
		return rcode;
	}

	if (strchr(addr_buf, '@') == NULL) {
		/*
		 * Just the location (host) is bound in FNS.  Pull
		 * the name of the object (user) out of the FNS
		 * name
		 */
		tmp = strdup(addr_buf);
		if ((p = strstr(fns_name, ":service:")) == NULL) {
			return -1;
		}

		*p = '\0';
		while (*p != ':')
			p--;
		snprintf(addr_buf, addr_size, "%s@%s", p + 1, tmp);
	}

	if (org != NULL) {
		/*
		 * Crossing organizations. Is host qualified
		 * by domain?
		 */
		p = strchr(addr_buf, '@');
		p++;
		if (strchr(p, '.') == NULL) {
			/*
			 * Host does not appear to have domain
			 * name.  Add it
			 */
			strlcat(addr_buf, ".", addr_size);
			strlcat(addr_buf, org, addr_size);
		}
	}

	DP(("cmfns_lookup_calendar: FNS Lookup complete. address=%s",
		addr_buf));
	return rcode;
}

/*
 * Register a calendar location in FNS.
 */
int
cmfns_register_calendar(const char *username, const char *location)

{
	char	buf[256];
	int	rcode;
	char	*types[4];
	char	*user;
	char	*p;

	user = strdup(username);

	if ((p = strchr(user, '@')) != NULL) {
		*p = '\0';
	}

	DP(("register_calendar: Generating service name for %s\n", user));
	/* Expand name to point at a calendar service */
	rcode = dtfns_service_name(user, DTFNS_USER_NAME,
		CMFNS_CALENDAR_SERVICE, CMFNS_CALENDAR_TYPE, NULL,
		buf, sizeof(buf));

	free(user);

	if (rcode < 1)
		return rcode;

	types[0] = CMFNS_CALENDAR_ADDR_TYPE;
	types[1] = "SUNW_calendar";
	types[2] = "SUNW_cal_deskset";
	types[3] = NULL;

	DP(("register_calendar: Binding %s to %s\n", location, buf));
	return dtfns_bind_str(buf, CMFNS_CALENDAR_TYPE, types, location);
}
#endif /* FNS */
