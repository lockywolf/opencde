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
/* $XConsortium: Startup.h /main/4 1995/10/30 13:12:58 rswiston $ */
/************************************<+>*************************************
 ****************************************************************************
 **
 **   File:        Startup.h
 **
 **   Project:     DT 3.0
 **
 **  This file contains function definitions for the corresponding .c
 **  file
 **
 **
 **  (c) Copyright Hewlett-Packard Company, 1990.
 **
 **
 **
 ****************************************************************************
 ************************************<+>*************************************/
#ifndef _startup_h
#define _startup_h

/* External Interface */

extern void popup_startupBB(Widget shell);
extern void restoreStartup(Widget shell, XrmDatabase db);
extern void saveStartup(int fd);

#endif /* _startup_h */
/* DON'T ADD ANYTHING AFTER THIS #endif */
