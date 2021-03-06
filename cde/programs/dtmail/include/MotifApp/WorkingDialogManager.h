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
/* $XConsortium: WorkingDialogManager.h /main/4 1996/04/21 19:46:54 drk $
 *
 * (c) Copyright 1996 Digital Equipment Corporation.
 * (c) Copyright 1996 Hewlett-Packard Company.
 * (c) Copyright 1996 International Business Machines Corp.
 * (c) Copyright 1996 Sun Microsystems, Inc.
 * (c) Copyright 1996 Novell, Inc.
 * (c) Copyright 1996 FUJITSU LIMITED.
 * (c) Copyright 1996 Hitachi.
 */
/*
 *+SNOTICE
 *
 *	RESTRICTED CONFIDENTIAL INFORMATION:
 *
 *	The information in this document is subject to special
 *	restrictions in a confidential disclosure agreement between
 *	HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *	document outside HP, IBM, Sun, USL, SCO, or Univel without
 *	Sun's specific written approval.  This document and all copies
 *	and derivative works thereof must be returned or destroyed at
 *	Sun's request.
 *
 *	Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 *+ENOTICE
 */

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//         This example code is from the book:
//
//           Object-Oriented Programming with C++ and OSF/Motif
//         by
//           Douglas Young
//           Prentice Hall, 1992
//           ISBN 0-13-630252-1
//
//         Copyright 1991 by Prentice Hall
//         All Rights Reserved
//
//  Permission to use, copy, modify, and distribute this software for
//  any purpose except publication and without fee is hereby granted, provided
//  that the above copyright notice appear in all copies of the software.
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
// WorkingDialogManager.h
//////////////////////////////////////////////////////////
#ifndef WORKINGDIALOGMANAGER_H
#define WORKINGDIALOGMANAGER_H

#include "DialogManager.h"

class PixmapCycler;

class WorkingDialogManager : public DialogManager {

      protected:
        Widget createDialog(Widget);
        PixmapCycler *_busyPixmaps; // Source of animated pixmap sequence

        XtIntervalId _intervalId; // ID of the last timeout

        static void unpostCallback(Widget, XtPointer, XtPointer);
        static void timerCallback(XtPointer, XtIntervalId *);

        void timer();

      public:
        WorkingDialogManager(char *);

        virtual Widget post(char *, char *, void *clientData = NULL,
                            DialogCallback ok = NULL,
                            DialogCallback cancel = NULL,
                            DialogCallback help = NULL);

        virtual Widget post(char *, char *, Widget, void *clientData = NULL,
                            DialogCallback ok = NULL,
                            DialogCallback cancel = NULL,
                            DialogCallback help = NULL);

        void unpost(); // Remove the dialog from the screen

        void updateMessage(char *); // Change the text in the dialog
};

extern WorkingDialogManager *theWorkingDialogManager;

#endif
