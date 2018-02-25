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
/*%%  (c) Copyright 1993, 1994 Hewlett-Packard Company			 */
/*%%  (c) Copyright 1993, 1994 International Business Machines Corp.	 */
/*%%  (c) Copyright 1993, 1994 Sun Microsystems, Inc.			 */
/*%%  (c) Copyright 1993, 1994 Novell, Inc. 				 */
/*%%  $XConsortium: tt_entry_pt.h /main/5 1995/11/28 19:34:19 cde-sun $
 */
/* @(#)tt_entry_pt.h	1.1 93/11/03
 * Files tt_entry_pt.h, tt_entry_pt.C, and tt_entry_pt_names.h must
 * be updated each time a new API call is added.  You can do this
 * by hand, or by running the "mktrcfiles" shell script which
 * will regenerate them from tt_c.h.
 */
#ifndef _TT_ENTRY_PT_H
#define _TT_ENTRY_PT_H

enum _Tt_entry_pt {
        TT_X_SESSION,
        TT_BCONTEXT_JOIN,
        TT_BCONTEXT_QUIT,
        TT_CLOSE,
        TT_CONTEXT_JOIN,
        TT_CONTEXT_QUIT,
        TT_DEFAULT_FILE,
        TT_DEFAULT_FILE_SET,
        TT_DEFAULT_PROCID,
        TT_DEFAULT_PROCID_SET,
        TT_THREAD_PROCID,
        TT_THREAD_PROCID_SET,
        TT_DEFAULT_PTYPE,
        TT_DEFAULT_PTYPE_SET,
        TT_DEFAULT_SESSION,
        TT_DEFAULT_SESSION_SET,
        TT_THREAD_SESSION,
        TT_THREAD_SESSION_SET,
        TT_ERROR_INT,
        TT_ERROR_POINTER,
        TT_FD,
        TT_FILE_COPY,
        TT_FILE_DESTROY,
        TT_FILE_JOIN,
        TT_FILE_MOVE,
        TT_FILE_OBJECTS_QUERY,
        TT_FILE_QUIT,
        TT_FREE,
        TT_ICONTEXT_JOIN,
        TT_ICONTEXT_QUIT,
        TT_INITIAL_SESSION,
        TT_INT_ERROR,
        TT_MALLOC,
        TT_MARK,
        TT_MESSAGE_ABSTAINER,
        TT_MESSAGE_ABSTAINERS_COUNT,
        TT_MESSAGE_ACCEPT,
        TT_MESSAGE_ACCEPTER,
        TT_MESSAGE_ACCEPTERS_COUNT,
        TT_MESSAGE_ADDRESS,
        TT_MESSAGE_ADDRESS_SET,
        TT_MESSAGE_ARG_ADD,
        TT_MESSAGE_ARG_BVAL,
        TT_MESSAGE_ARG_BVAL_SET,
        TT_MESSAGE_ARG_IVAL,
        TT_MESSAGE_ARG_IVAL_SET,
        TT_MESSAGE_ARG_MODE,
        TT_MESSAGE_ARG_TYPE,
        TT_MESSAGE_ARG_VAL,
        TT_MESSAGE_ARG_VAL_SET,
        TT_MESSAGE_ARG_XVAL,
        TT_MESSAGE_ARG_XVAL_SET,
        TT_MESSAGE_ARGS_COUNT,
        TT_MESSAGE_BARG_ADD,
        TT_MESSAGE_BCONTEXT_SET,
        TT_MESSAGE_CALLBACK_ADD,
        TT_MESSAGE_CLASS,
        TT_MESSAGE_CLASS_SET,
        TT_MESSAGE_CONTEXT_BVAL,
        TT_MESSAGE_CONTEXT_IVAL,
        TT_MESSAGE_CONTEXT_SET,
        TT_MESSAGE_CONTEXT_SLOTNAME,
        TT_MESSAGE_CONTEXT_VAL,
        TT_MESSAGE_CONTEXT_XVAL,
        TT_MESSAGE_CONTEXTS_COUNT,
        TT_MESSAGE_CREATE,
        TT_MESSAGE_CREATE_SUPER,
        TT_MESSAGE_DESTROY,
        TT_MESSAGE_DISPOSITION,
        TT_MESSAGE_DISPOSITION_SET,
        TT_MESSAGE_FAIL,
        TT_MESSAGE_FILE,
        TT_MESSAGE_FILE_SET,
        TT_MESSAGE_GID,
        TT_MESSAGE_HANDLER,
        TT_MESSAGE_HANDLER_PTYPE,
        TT_MESSAGE_HANDLER_PTYPE_SET,
        TT_MESSAGE_HANDLER_SET,
        TT_MESSAGE_IARG_ADD,
        TT_MESSAGE_ICONTEXT_SET,
        TT_MESSAGE_ID,
        TT_MESSAGE_OBJECT,
        TT_MESSAGE_OBJECT_SET,
        TT_MESSAGE_OP,
        TT_MESSAGE_OP_SET,
        TT_MESSAGE_OPNUM,
        TT_MESSAGE_OTYPE,
        TT_MESSAGE_OTYPE_SET,
        TT_MESSAGE_PATTERN,
        TT_MESSAGE_PRINT,
        TT_MESSAGE_RECEIVE,
        TT_MESSAGE_REJECT,
        TT_MESSAGE_REJECTER,
        TT_MESSAGE_REJECTERS_COUNT,
        TT_MESSAGE_REPLY,
        TT_MESSAGE_SCOPE,
        TT_MESSAGE_SCOPE_SET,
        TT_MESSAGE_SEND,
        TT_MESSAGE_SEND_ON_EXIT,
        TT_MESSAGE_SENDER,
        TT_MESSAGE_SENDER_PTYPE,
        TT_MESSAGE_SENDER_PTYPE_SET,
        TT_MESSAGE_SESSION,
        TT_MESSAGE_SESSION_SET,
        TT_MESSAGE_STATE,
        TT_MESSAGE_STATUS,
        TT_MESSAGE_STATUS_SET,
        TT_MESSAGE_STATUS_STRING,
        TT_MESSAGE_STATUS_STRING_SET,
        TT_MESSAGE_UID,
        TT_MESSAGE_USER,
        TT_MESSAGE_USER_SET,
        TT_MESSAGE_XARG_ADD,
        TT_MESSAGE_XCONTEXT_SET,
        TT_OBJID_EQUAL,
        TT_OBJID_OBJKEY,
        TT_ONOTICE_CREATE,
        TT_OPEN,
        TT_OREQUEST_CREATE,
        TT_OTYPE_BASE,
        TT_OTYPE_DERIVED,
        TT_OTYPE_DERIVEDS_COUNT,
        TT_OTYPE_HSIG_ARG_MODE,
        TT_OTYPE_HSIG_ARG_TYPE,
        TT_OTYPE_HSIG_ARGS_COUNT,
        TT_OTYPE_HSIG_COUNT,
        TT_OTYPE_HSIG_OP,
        TT_OTYPE_IS_DERIVED,
        TT_OTYPE_OPNUM_CALLBACK_ADD,
        TT_OTYPE_OSIG_ARG_MODE,
        TT_OTYPE_OSIG_ARG_TYPE,
        TT_OTYPE_OSIG_ARGS_COUNT,
        TT_OTYPE_OSIG_COUNT,
        TT_OTYPE_OSIG_OP,
        TT_PATTERN_ADDRESS_ADD,
        TT_PATTERN_ARG_ADD,
        TT_PATTERN_BARG_ADD,
        TT_PATTERN_BCONTEXT_ADD,
        TT_PATTERN_CALLBACK_ADD,
        TT_PATTERN_CATEGORY,
        TT_PATTERN_CATEGORY_SET,
        TT_PATTERN_CLASS_ADD,
        TT_PATTERN_CONTEXT_ADD,
        TT_PATTERN_CREATE,
        TT_PATTERN_DESTROY,
        TT_PATTERN_DISPOSITION_ADD,
        TT_PATTERN_FILE_ADD,
        TT_PATTERN_IARG_ADD,
        TT_PATTERN_ICONTEXT_ADD,
        TT_PATTERN_OBJECT_ADD,
        TT_PATTERN_OP_ADD,
        TT_PATTERN_OPNUM_ADD,
        TT_PATTERN_OTYPE_ADD,
        TT_PATTERN_PRINT,
        TT_PATTERN_REGISTER,
        TT_PATTERN_SCOPE_ADD,
        TT_PATTERN_SENDER_ADD,
        TT_PATTERN_SENDER_PTYPE_ADD,
        TT_PATTERN_SESSION_ADD,
        TT_PATTERN_STATE_ADD,
        TT_PATTERN_UNREGISTER,
        TT_PATTERN_USER,
        TT_PATTERN_USER_SET,
        TT_PATTERN_XARG_ADD,
        TT_PATTERN_XCONTEXT_ADD,
        TT_PNOTICE_CREATE,
        TT_POINTER_ERROR,
        TT_PREQUEST_CREATE,
        TT_PROCID_SESSION,
        TT_PTYPE_DECLARE,
        TT_PTYPE_EXISTS,
        TT_PTYPE_OPNUM_CALLBACK_ADD,
        TT_PTYPE_UNDECLARE,
        TT_RELEASE,
        TT_SESSION_BPROP,
        TT_SESSION_BPROP_ADD,
        TT_SESSION_BPROP_SET,
        TT_SESSION_EQUAL,
        TT_SESSION_JOIN,
        TT_SESSION_PROP,
        TT_SESSION_PROP_ADD,
        TT_SESSION_PROP_COUNT,
        TT_SESSION_PROP_SET,
        TT_SESSION_PROPNAME,
        TT_SESSION_PROPNAMES_COUNT,
        TT_SESSION_QUIT,
        TT_SESSION_TYPES_LOAD,
        TT_SPEC_BPROP,
        TT_SPEC_BPROP_ADD,
        TT_SPEC_BPROP_SET,
        TT_SPEC_CREATE,
        TT_SPEC_DESTROY,
        TT_SPEC_FILE,
        TT_SPEC_MOVE,
        TT_SPEC_PROP,
        TT_SPEC_PROP_ADD,
        TT_SPEC_PROP_COUNT,
        TT_SPEC_PROP_SET,
        TT_SPEC_PROPNAME,
        TT_SPEC_PROPNAMES_COUNT,
        TT_SPEC_TYPE,
        TT_SPEC_TYPE_SET,
        TT_SPEC_WRITE,
        TT_STATUS_MESSAGE,
        TT_TRACE_CONTROL,
        TT_XCONTEXT_JOIN,
        TT_XCONTEXT_QUIT,
        TT_FILE_NETFILE,
        TT_NETFILE_FILE,
        TT_HOST_FILE_NETFILE,
        TT_HOST_NETFILE_FILE,
        TT_FEATURE_ENABLED,
        TT_FEATURE_REQUIRED,
        TT_API_CALL_LAST
};
#endif
