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
/* $XConsortium: sparse.c /main/3 1995/11/08 11:42:35 rswiston $ */
/* Copyright (c) 1986, 1987, 1988, 1989 Hewlett-Packard Co. */
/* Sparse.c has a procedure used with the tables generated by program
   CONTEXT when the sparse option is used */

int m_sprscon(i, j) int i, j;
{
        int k;

        for (k = m_trnsptr[i]; k; k++) {
                if ((int)m_trnsit[k - 1].context > j)
                        return (0);
                if (!m_trnsit[k - 1].context)
                        return (0);
                if ((int)m_trnsit[k - 1].context == j)
                        return (m_trnsit[k - 1].nextcon);
        }
        return (0);
}
