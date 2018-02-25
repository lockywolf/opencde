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
/*
 *+SNOTICE
 *
 *	$XConsortium: PasswordDialogManager.h /main/4 1996/04/21 19:42:56 drk $
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

///////////////////////////////////////////////////////////
// PasswordDialogManager.h
//////////////////////////////////////////////////////////

#ifndef PASSWORDDIALOGMANAGER_H
#define PASSWORDDIALOGMANAGER_H
#include "PromptDialogManager.h"

class PasswordDialogManager : public PromptDialogManager {
      private:
        Widget _user;
        Widget _password;
        static void modifyVerifyCallback(Widget, XtPointer,
                                         XmTextVerifyCallbackStruct *);
        char _pwd[100]; // Big enough for most reasonable passwords.
      protected:
        Widget createDialog(Widget);

      public:
        PasswordDialogManager(char *);
        void modifyVerify(Widget, XmTextVerifyCallbackStruct *);
#ifdef DEAD_WOOD
        char *userName();
        char *password();
        void resetPassword();
#endif /* DEAD_WOOD */
};

extern PasswordDialogManager *thePasswordDialogManager;

#endif
