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
/* $XConsortium: ebcdic.c /main/3 1996/06/19 17:14:38 drk $ */
/* ASCII to EBCDIC (ISO 8859-1 to IBM CP 37v2) table. */
/* Contributed by C. M. Sperberg-McQueen <u35395@uicvm.uic.edu>. */

/* The mapping must be 1 to 1.  The positions of *CHAR and *CH in the table
must not be changed, although the values in ebcdic.h can be. */

#include "ebcdic.h"

unsigned char charset[] = {
    0,         1,       2,       3,   55,      45,       46,       47,
    GENRECHAR, TABCHAR, RSCHAR,  11,  12,      RECHAR,   14,       15,
    16,        17,      18,      19,  60,      61,       50,       38,
    24,        25,      EOFCHAR, 39,  EOBCHAR, DELCDATA, DELSDATA, DELNONCH,
    SPCCHAR,   90,      127,     123, 91,      108,      80,       125,
    77,        93,      92,      78,  107,     96,       75,       97,
    240,       241,     242,     243, 244,     245,      246,      247,
    248,       249,     122,     94,  76,      126,      110,      111,
    124,       193,     194,     195, 196,     197,      198,      199,
    200,       201,     209,     210, 211,     212,      213,      214,
    215,       216,     217,     226, 227,     228,      229,      230,
    231,       232,     233,     173, 224,     189,      176,      109,
    121,       129,     130,     131, 132,     133,      134,      135,
    136,       137,     145,     146, 147,     148,      149,      150,
    151,       152,     153,     162, 163,     164,      165,      166,
    167,       168,     169,     192, 79,      208,      161,      7,
    4,         6,       8,       9,   10,      20,       21,       23,
    26,        27,      32,      33,  34,      35,       36,       40,
    41,        42,      43,      44,  48,      49,       51,       52,
    53,        54,      56,      57,  58,      59,       62,       255,
    65,        170,     74,      177, 159,     178,      106,      181,
    187,       180,     154,     138, 95,      202,      175,      188,
    144,       143,     234,     250, 190,     160,      182,      179,
    157,       218,     155,     139, 183,     184,      185,      171,
    100,       101,     98,      102, 99,      103,      158,      104,
    116,       113,     114,     115, 120,     117,      118,      119,
    172,       105,     237,     238, 235,     239,      236,      191,
    128,       253,     254,     251, 252,     186,      174,      89,
    68,        69,      66,      70,  67,      71,       156,      72,
    84,        81,      82,      83,  88,      85,       86,       87,
    140,       73,      205,     206, 203,     207,      204,      225,
    112,       221,     222,     219, 220,     141,      142,      223,
};
