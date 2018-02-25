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
/* $XConsortium: fileio.h /main/5 1995/11/01 16:14:03 rswiston $ */
/***************************************************************************/
/*                                                                         */
/*  fileio.h                                                               */
/*                                                                         */
/***************************************************************************/

#ifndef _FILEIO_H_INCLUDED
#define _FILEIO_H_INCLUDED

#ifndef STORAGECLASS
#ifdef NOEXTERN
#define STORAGECLASS
#else
#define STORAGECLASS extern
#endif
#endif

/***************************************************************************/
/*                                                                         */
/*  Prototypes for functions                                               */
/*                                                                         */
/***************************************************************************/

extern ushort WriteDefinitionFile(char *, ActionData *);
extern ushort WriteActionFile(ActionData *);
extern Boolean check_file_exists(char *);
extern int OpenDefinitionFile(char *, ActionData *);
extern ushort CopyIconFiles(ActionData *);
extern char *CreateIconName(char *, char *, enum icon_size_range, char *,
                            Boolean);
extern Boolean ActionHasIcon(void);
extern Boolean FiletypeHasIcon(FiletypeData *);

#endif /* _FILEIO_H_INCLUDED */
