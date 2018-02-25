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
/* $XConsortium: dtdext.h /main/3 1995/11/08 09:49:13 rswiston $ */
/* Copyright (c) 1988, 1989 Hewlett-Packard Co. */
/* Dtdext.h contains the dtd-independent external forms of
   declarations relevant to document-type definitions.  The
   definition form of these declarations is contained in files
   dtd.h and arc.h generated by BUILD. */

#include "dtddef.h"

extern M_PTRIE m_entree[];

extern M_WCHAR m_ename[];

extern int m_elcount;
extern M_ELTSTRUCT m_element[];

extern M_WCHAR m_keyword[];

extern M_WCHAR m_defval[];

extern struct { int keyword, next; } m_ptype[];

extern M_PARAMETER m_parameter[];

extern M_WCHAR m_pname[];

extern M_PTRIE m_maptree[];

extern M_PTRIE m_sreftree[];

extern int m_map[];

extern M_SREF m_sref[];

extern M_STATESTRUCT m_state[];

extern M_ANDSTRUCT m_andgroup[];

extern M_EXCEPTION m_exception[];

extern M_ARCSTRUCT m_arc[];
