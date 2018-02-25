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
/* $XConsortium: default.c /main/3 1995/11/08 09:29:42 rswiston $ */
/*
Copyright 1988, 1989, 1992 Hewlett-Packard Co.
*/

/* HP Tag to TeX default processing */

#include "userinc.h"
#include "globdec.h"

#if defined(M_PROTO)
int vextextsize(const M_WCHAR *keyword)
#else
int vextextsize(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return NORMAL;

        if (!m_wcmbupstrcmp(keyword, QNORMAL))
                return NORMAL;
        else if (!m_wcmbupstrcmp(keyword, QSMALLER))
                return SMALLER;
        else if (!m_wcmbupstrcmp(keyword, QSMALLEST))
                return SMALLEST;

        m_err1("Unexpected value for ex/vex textsize parameter: %s", keyword);
        return NORMAL;
}

#if defined(M_PROTO)
int vgloss(const M_WCHAR *keyword)
#else
int vgloss(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return GLOSS;

        if (!m_wcmbupstrcmp(keyword, QGLOSS))
                return GLOSS;
        else if (!m_wcmbupstrcmp(keyword, QNOGLOSS))
                return NOGLOSS;

        m_err1("Unexpected value for gloss parameter: %s", keyword);
        return GLOSS;
}

#if defined(M_PROTO)
int vcenter(const M_WCHAR *keyword)
#else
int vcenter(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return CENTER;

        if (!m_wcmbupstrcmp(keyword, QLEFT))
                return LEFT;
        else if (!m_wcmbupstrcmp(keyword, QCENTER))
                return CENTER;
        else if (!m_wcmbupstrcmp(keyword, QRIGHT))
                return RIGHT;

        m_err1("Unexpected value for center parameter: %s", keyword);
        return CENTER;
}

#if defined(M_PROTO)
int vnumber(const M_WCHAR *keyword)
#else
int vnumber(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return NONUMBER;

        if (!m_wcmbupstrcmp(keyword, QNUMBER))
                return NUMBER;
        else if (!m_wcmbupstrcmp(keyword, QNONUMBER))
                return NONUMBER;

        m_err1("Unexpected value for number parameter: %s", keyword);
        return NONUMBER;
}

#if defined(M_PROTO)
LOGICAL vstack(const M_WCHAR *keyword)
#else
LOGICAL vnumber(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return FALSE;

        if (!m_wcmbupstrcmp(keyword, QSIDE))
                return FALSE;
        else if (!m_wcmbupstrcmp(keyword, QSTACK))
                return TRUE;

        m_err1("Unexpected value for number parameter: %s", keyword);
        return FALSE;
}

#if defined(M_PROTO)
int vordertype(const M_WCHAR *keyword)
#else
int vordertype(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return ARABIC;

        if (!m_wcmbupstrcmp(keyword, QUALPHA))
                return UALPHA;
        else if (!m_wcmbupstrcmp(keyword, QLALPHA))
                return LALPHA;
        else if (!m_wcmbupstrcmp(keyword, QARABIC))
                return ARABIC;
        else if (!m_wcmbupstrcmp(keyword, QUROMAN))
                return UROMAN;
        else if (!m_wcmbupstrcmp(keyword, QLROMAN))
                return LROMAN;

        m_err1("Unexpected list order type: %s", keyword);
        return ARABIC;
}

#if defined(M_PROTO)
int vspacing(const M_WCHAR *keyword)
#else
int vspacing(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return LOOSE;

        if (!m_wcmbupstrcmp(keyword, QTIGHT))
                return TIGHT;
        else if (!m_wcmbupstrcmp(keyword, QLOOSE))
                return LOOSE;

        m_err1("Unexpected value for spacing parameter: %s", keyword);
        return LOOSE;
}

#if defined(M_PROTO)
int vlonglabel(const M_WCHAR *keyword)
#else
int vlonglabel(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return WRAP;

        if (!m_wcmbupstrcmp(keyword, QWRAP))
                return WRAP;
        else if (!m_wcmbupstrcmp(keyword, QNOWRAP))
                return NOWRAP;

        m_err1("Unexpected value for longlabel parameter: %s", keyword);
        return WRAP;
}

#if defined(M_PROTO)
int vtype(const M_WCHAR *keyword)
#else
int vtype(keyword) M_WCHAR *keyword;
#endif /* M_PROTO */
{
        if (!keyword)
                return BULLET;

        if (!m_wcmbupstrcmp(keyword, QORDER))
                return ORDER;
        else if (!m_wcmbupstrcmp(keyword, QBULLET))
                return BULLET;
        else if (!m_wcmbupstrcmp(keyword, QPLAIN))
                return PLAIN;
        else if (!m_wcmbupstrcmp(keyword, QMILSPEC))
                return ORDER;
        else if (!m_wcmbupstrcmp(keyword, QCHECK))
                return CHECK;

        m_err1("Unexpected list type: %s", keyword);
        return BULLET;
}
