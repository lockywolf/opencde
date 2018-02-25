/*** DTB_USER_CODE_START vvv Add file header below vvv ***/
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
/*** DTB_USER_CODE_END   ^^^ Add file header above ^^^ ***/

/*
 * File: dtbuilder.h
 * Contains: object data structures and callback declarations
 *
 * This file was generated by dtcodegen, from project dtbuilder
 *
 * Any text may be added between the DTB_USER_CODE_START and
 * DTB_USER_CODE_END comments (even non-C code). Descriptive comments
 * are provided only as an aid.
 *
 *  ** EDIT ONLY WITHIN SECTIONS MARKED WITH DTB_USER_CODE COMMENTS.  **
 *  ** ALL OTHER MODIFICATIONS WILL BE OVERWRITTEN. DO NOT MODIFY OR  **
 *  ** DELETE THE GENERATED COMMENTS!                                 **
 */
#ifndef _DTBUILDER_H_
#define _DTBUILDER_H_

#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <nl_types.h>
#define DTB_PROJECT_CATALOG	"dtbuilder"
/* Handle for standard message catalog for the project */
extern nl_catd	Dtb_project_catd;

/*
 * Structure to store values for Application Resources
 */
typedef struct {
    char	*session_file;
    
    /*** DTB_USER_CODE_START vvv Add structure fields below vvv ***/

        Boolean use_small_drag_cursor; /* Workaround for HP cursor bug */
        Boolean implied_apply;

    /*** DTB_USER_CODE_END   ^^^ Add structure fields above ^^^ ***/
} DtbAppResourceRec;

void palette_help_pulldown_About_Application_Builder_item_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void brws_help_pulldown_About_Application_Builder_item_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void proj_proj_help_menu_About_Application_Builder_item_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void cgen_win_help_pulldown_About_Application_Builder_item_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

Boolean Session_saveCB(
    Widget	widget,
    String	session_file,
    char ***	argv,
    int *	argc
);

Boolean Session_restoreCB(
    Widget	widget,
    String	session_file
);

void proj_show_new_proj_dlgCB(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void proj_show_open_chooserCB(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void proj_save_projCB(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void proj_show_save_proj_as_chooserCB(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void proj_show_new_module_dlgCB(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void proj_close_projCB(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

void proj_show_import_chooserCB(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);


extern DtbAppResourceRec	dtb_app_resource_rec;


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** Add types, macros, and externs here
 ***/
/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/


#endif /* _DTBUILDER_H_ */
