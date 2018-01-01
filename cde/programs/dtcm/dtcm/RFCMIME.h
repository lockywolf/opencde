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
/* $XConsortium: RFCMIME.h /main/1 1995/11/03 10:17:13 rswiston $ */
/*
 *   COMPONENT_NAME: desktop
 *
 *   FUNCTIONS: none
 *
 *   ORIGINS: 119
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */

#include <EUSCompat.h>

typedef enum {
	MIME_7BIT,
	MIME_8BIT,
	MIME_QPRINT,
	MIME_BASE64
	} Encoding;

typedef enum {
	CURRENT_TO_INTERNET,
	INTERNET_TO_CURRENT
	} Direction;


void rfc1522cpy(char *, const char *, int);
int CvtStr( char *, void *, unsigned long,
            void **, unsigned long *, Direction );
void DtXlateOpToStdLocale (char *, char *, char **, char **, char **);
void getCharSet(char *);
Encoding getEncodingType(const char *, const unsigned int, boolean_t);
void md5PlainText(const char *, const unsigned long, unsigned char *);
void writeContentHeaders(char *, const char *, const Encoding, const char *, int);
