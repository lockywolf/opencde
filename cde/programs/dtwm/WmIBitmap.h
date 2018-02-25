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
 * (c) Copyright 1989, 1990, 1991, 1992, 1993 OPEN SOFTWARE FOUNDATION, INC.
 * ALL RIGHTS RESERVED
 */
/*
 * Motif Release 1.2.3
 */
/*   $XConsortium: WmIBitmap.h /main/3 1995/11/01 11:39:56 rswiston $ */
/*
 * (c) Copyright 1987, 1988, 1989, 1990 HEWLETT-PACKARD COMPANY */

/*
 * Global Variables And Definitions:
 */

#ifdef MWM_NEED_IIMAGE
#ifdef MOTIF_DEFAULT_ICON
/*
 * Default icon image with four buttons:
 */

#define iImage_width 50
#define iImage_height 50
static unsigned char iImage_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0xe0,
    0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca,
    0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0,
    0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff,
    0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00,
    0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55,
    0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf,
    0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0,
    0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca,
    0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0,
    0xaa, 0xca, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0xe0, 0xff,
    0x3f, 0xe0, 0xff, 0x3f, 0x00, 0xf0, 0xff, 0x7f, 0xf0, 0xff, 0x7f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0x40,
    0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf,
    0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0,
    0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa,
    0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00,
    0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff,
    0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5,
    0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40,
    0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf,
    0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0,
    0xff, 0xdf, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0xe0, 0xff,
    0x3f, 0xe0, 0xff, 0x3f, 0x00, 0xf0, 0xff, 0x7f, 0xf0, 0xff, 0x7f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00};
#else
/*
 * Default icon image with X logo:
 */

#define iImage_width 50
#define iImage_height 50
static unsigned char iImage_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0xe0,
    0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca,
    0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0,
    0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff,
    0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00,
    0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55,
    0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0, 0xff, 0xdf,
    0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca, 0x00, 0xe0,
    0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0, 0xaa, 0xca,
    0x00, 0xe0, 0xff, 0xdf, 0x40, 0x55, 0xd5, 0x00, 0xe0, 0xff, 0xdf, 0xa0,
    0xaa, 0xca, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0xe0, 0xff,
    0x3f, 0xe0, 0xff, 0x3f, 0x00, 0xf0, 0xff, 0x7f, 0xf0, 0xff, 0x7f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0x40,
    0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf,
    0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0,
    0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa,
    0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00,
    0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff,
    0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40, 0x55, 0xd5,
    0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf, 0x00, 0x40,
    0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0, 0xff, 0xdf,
    0x00, 0x40, 0x55, 0xd5, 0xe0, 0xff, 0xdf, 0x00, 0xa0, 0xaa, 0xca, 0xe0,
    0xff, 0xdf, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0xe0, 0xff,
    0x3f, 0xe0, 0xff, 0x3f, 0x00, 0xf0, 0xff, 0x7f, 0xf0, 0xff, 0x7f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00};

#endif /* MOTIF_DEFAULT_ICON */
#endif /* MWM_NEED_IIMAGE */

#ifdef MWM_NEED_ICONBOX
#define iconBox_width 50
#define iconBox_height 50
static unsigned char iconBox_bits[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
    0xd0, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x02, 0x01, 0x00, 0x00,
    0x00, 0x00, 0xf0, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0xf9,
    0xe3, 0x8f, 0x3f, 0xfe, 0x10, 0x02, 0x09, 0x24, 0x90, 0x40, 0x02, 0xd1,
    0x02, 0x09, 0x24, 0x90, 0x40, 0x02, 0xd1, 0x02, 0x09, 0x24, 0x90, 0x40,
    0x02, 0xd1, 0x02, 0x09, 0x24, 0x90, 0x40, 0x02, 0xd1, 0x02, 0x09, 0x24,
    0x90, 0x40, 0x02, 0xd1, 0x02, 0x09, 0x24, 0x90, 0x40, 0x02, 0xd1, 0x02,
    0x09, 0x24, 0x90, 0x40, 0x02, 0xd1, 0x02, 0xf1, 0xc7, 0x1f, 0x7f, 0xfc,
    0xd0, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0xf9, 0xe3, 0x8f, 0x3f, 0xfe, 0x10,
    0x02, 0x09, 0x24, 0x90, 0x40, 0x02, 0x11, 0x02, 0x09, 0x24, 0x90, 0x40,
    0x02, 0x11, 0x02, 0x09, 0x24, 0x90, 0x40, 0x02, 0x11, 0x02, 0x09, 0x24,
    0x90, 0x40, 0x02, 0x11, 0x02, 0x09, 0x24, 0x90, 0x40, 0x02, 0x11, 0x02,
    0x09, 0x24, 0x90, 0x40, 0x02, 0x11, 0x02, 0x09, 0x24, 0x90, 0x40, 0x02,
    0x11, 0x02, 0xf1, 0xc7, 0x1f, 0x7f, 0xfc, 0x10, 0x02, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10,
    0x02, 0xf9, 0xe3, 0x8f, 0x3f, 0x00, 0x10, 0x02, 0x09, 0x24, 0x90, 0x40,
    0x00, 0x10, 0x02, 0x09, 0x24, 0x90, 0x40, 0x00, 0x10, 0x02, 0x09, 0x24,
    0x90, 0x40, 0x00, 0x10, 0x02, 0x09, 0x24, 0x90, 0x40, 0x00, 0x10, 0x02,
    0x09, 0x24, 0x90, 0x40, 0x00, 0x10, 0x02, 0x09, 0x24, 0x90, 0x40, 0x00,
    0x10, 0x02, 0x09, 0x24, 0x90, 0x40, 0x00, 0x10, 0x02, 0xf1, 0xc7, 0x1f,
    0x7f, 0x00, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x01,
    0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0xd0,
    0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x02, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x03, 0x09, 0x00, 0x00, 0x00, 0x00, 0x12, 0x02, 0xcf, 0xff,
    0xff, 0x01, 0x00, 0x1e, 0x02, 0xcf, 0xff, 0xff, 0x01, 0x00, 0x1e, 0x02,
    0x09, 0x00, 0x00, 0x00, 0x00, 0x12, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x03};
#endif /* MWM_NEED_ICONBOX */

/*
 * Used to create the stipple for greyed icons
 */

#ifdef MWM_NEED_GREYED75
#define greyed75_width 16
#define greyed75_height 16
static unsigned char greyed75_bits[] = {
    0xee, 0xee, 0xbb, 0xbb, 0xee, 0xee, 0xbb, 0xbb, 0xee, 0xee, 0xbb,
    0xbb, 0xee, 0xee, 0xbb, 0xbb, 0xee, 0xee, 0xbb, 0xbb, 0xee, 0xee,
    0xbb, 0xbb, 0xee, 0xee, 0xbb, 0xbb, 0xee, 0xee, 0xbb, 0xbb};
#endif /* MWM_NEED_GREYED75 */

/*
 * Used to create the stipple for greyed icons
 */

#ifdef MWM_NEED_GREYED50
#define greyed50_width 16
#define greyed50_height 16
static unsigned char greyed50_bits[] = {
    0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa,
    0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55,
    0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa};
#endif /* MWM_NEED_GREYED50 */

/*
 * Used to create the stipple for greyed icons
 */

#ifdef MWM_NEED_GREYED25
#define greyed25_width 16
#define greyed25_height 16
static unsigned char greyed25_bits[] = {
    0x11, 0x11, 0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11, 0x44,
    0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11,
    0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11, 0x44, 0x44};
#endif /* MWM_NEED_GREYED25 */

/*
 * Used to create the stipple for greyed icons
 */

#ifdef MWM_NEED_SLANT2
#define slant2_width 16
#define slant2_height 16
static unsigned char slant2_bits[] = {
    0x99, 0x99, 0xcc, 0xcc, 0x66, 0x66, 0x33, 0x33, 0x99, 0x99, 0xcc,
    0xcc, 0x66, 0x66, 0x33, 0x33, 0x99, 0x99, 0xcc, 0xcc, 0x66, 0x66,
    0x33, 0x33, 0x99, 0x99, 0xcc, 0xcc, 0x66, 0x66, 0x33, 0x33};
#endif /* MWM_NEED_SLANT2 */

#ifdef PANELIST
#ifdef DTWM_NEED_FNTPL
#define fntpl_i_bm_width 50
#define fntpl_i_bm_height 50
#define fntpl_i_bm_x_hot 0
#define fntpl_i_bm_y_hot 0
static unsigned char fntpl_i_bm_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x00, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00,
    0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x00, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0xfa, 0xff, 0xff,
    0xff, 0xff, 0xbf, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 0xda,
    0xff, 0xff, 0xff, 0xff, 0x9f, 0x00, 0xd4, 0xff, 0xff, 0xff, 0xff, 0x5f,
    0x01, 0xda, 0xf1, 0xe4, 0x75, 0x00, 0x83, 0x00, 0xd4, 0xe4, 0xe6, 0x64,
    0x00, 0x43, 0x01, 0xda, 0xe4, 0xee, 0xfd, 0xff, 0xa7, 0x00, 0xd4, 0xe6,
    0xff, 0xf7, 0xff, 0x57, 0x01, 0xda, 0xe0, 0xff, 0x64, 0x00, 0xa3, 0x00,
    0xd4, 0xf1, 0xe0, 0x75, 0x00, 0x53, 0x01, 0xda, 0xff, 0xff, 0xff, 0xff,
    0xa9, 0x00, 0xd4, 0xff, 0xff, 0xff, 0xff, 0x55, 0x01, 0x1a, 0x00, 0x00,
    0x00, 0x80, 0xa8, 0x00, 0xd4, 0xfb, 0xe1, 0xe1, 0x4f, 0x54, 0x01, 0x5a,
    0x02, 0xa0, 0x20, 0x49, 0xaa, 0x00, 0xd4, 0xfb, 0xe1, 0xe1, 0x2f, 0x55,
    0x01, 0x1a, 0x00, 0x00, 0x00, 0xa0, 0xaa, 0x00, 0xf4, 0xff, 0xff, 0xff,
    0x3f, 0x55, 0x01, 0x0a, 0x00, 0x00, 0x00, 0x80, 0xaa, 0x00, 0x54, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00,
    0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0x00, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x54, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00,
    0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00};
#endif /* DTWM_NEED_FNTPL */

#endif /* PANELIST */
#ifdef WSM
/*
 * Backdrop bitmap patterns
 */

#ifdef DTWM_NEED_BACKBITS
#define bits0_width 8
#define bits0_height 8
static unsigned char bits0_bits[] = {0x00, 0x00, 0x00, 0x00,
                                     0x00, 0x00, 0x00, 0x00};

#define bits1_width 8
#define bits1_height 8
static unsigned char bits1_bits[] = {0x11, 0x00, 0x44, 0x00,
                                     0x11, 0x00, 0x44, 0x00};

#define bits2_width 8
#define bits2_height 8
static unsigned char bits2_bits[] = {0x55, 0x00, 0x55, 0x00,
                                     0x55, 0x00, 0x55, 0x00};

#define bits3_width 8
#define bits3_height 8
static unsigned char bits3_bits[] = {0x55, 0xaa, 0x55, 0xaa,
                                     0x55, 0xaa, 0x55, 0xaa};

#define bits4_width 8
#define bits4_height 8
static unsigned char bits4_bits[] = {0xff, 0xaa, 0xff, 0xaa,
                                     0xff, 0xaa, 0xff, 0xaa};

#define bits5_width 8
#define bits5_height 8
static unsigned char bits5_bits[] = {0xff, 0xbb, 0xff, 0xee,
                                     0xff, 0xbb, 0xff, 0xee};

#define bits6_width 8
#define bits6_height 8
static unsigned char bits6_bits[] = {0xff, 0xff, 0xff, 0xff,
                                     0xff, 0xff, 0xff, 0xff};
#endif /* DTWM_NEED_BACKBITS */

#endif /* WSM */
#ifdef PANELIST
/*
 *
 *  Used to define the small hourglass and mask used to indicate
 *  a front panel wait state.
 *
 */
#ifdef DTWM_NEED_TIME16
#define time16_x_hot 7
#define time16_y_hot 7
#define time16_width 14
#define time16_height 15

static unsigned char time16_bits[] = {
    0x00, 0x00, 0xfe, 0x1f, 0xfe, 0x1f, 0x04, 0x0c, 0x54, 0x0d,
    0xac, 0x0e, 0x58, 0x07, 0xb0, 0x03, 0x50, 0x03, 0x08, 0x06,
    0x44, 0x0c, 0xa4, 0x0c, 0x54, 0x0d, 0xfe, 0x1f, 0xfe, 0x1f};

#define time16m_width 14
#define time16m_height 15
static unsigned char time16m_bits[] = {
    0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x06, 0x1c, 0xfe, 0x1f,
    0xfe, 0x1f, 0xfc, 0x0f, 0xf8, 0x07, 0x5c, 0x07, 0x0e, 0x0e,
    0x66, 0x0c, 0xf6, 0x1c, 0xfe, 0x1f, 0xff, 0x3f, 0xff, 0x3f};
#endif /* DTWM_NEED_TIME16 */

#endif /* PANELIST */
#ifdef WSM
/****************************   eof    ***************************/
#endif /* WSM */
