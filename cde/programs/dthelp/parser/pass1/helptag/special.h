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
/* $XConsortium: special.h /main/3 1995/11/08 10:12:54 rswiston $ */
0, "^@  NUL", SPECIAL, 0, 0, 1, "^A  SOH", SPECIAL, 0, 0, 2, "^B  STX", SPECIAL,
    0, 0, 3, "^C  ETX", SPECIAL, 0, 0, 4, "^D  EOT", SPECIAL, 0, 0, 5,
    "^E  ENQ", SPECIAL, 0, 0, 6, "^F  ACK", SPECIAL, 0, 0, 7, "^G  BEL",
    SPECIAL, 0, 0, 8, "^H  BS", SPECIAL, 0, 0, 9, "^I  HT", SPECIAL, 0, 0, 10,
    "^J  LF", SPECIAL, 0, 0, 11, "^K  VT", SPECIAL, 0, 0, 12, "^L  FF", SPECIAL,
    0, 0, 13, "^M  CR", SPECIAL, 0, 0, 14, "^N  SO", SPECIAL, 0, 0, 15,
    "^O  SI", SPECIAL, 0, 0, 16, "^P  DLE", SPECIAL, 0, 0, 17, "^Q  DC1",
    SPECIAL, 0, 0, 18, "^R  DC2", SPECIAL, 0, 0, 19, "^S  DC3", SPECIAL, 0, 0,
    20, "^T  DC4", SPECIAL, 0, 0, 21, "^U  NAK", SPECIAL, 0, 0, 22, "^V  SYN",
    SPECIAL, 0, 0, 23, "^W  ETB", SPECIAL, 0, 0, 24, "^X  CAN", SPECIAL, 0, 0,
    25, "^Y  EM", SPECIAL, 0, 0, 26, "^Z  SUB", SPECIAL, 0, 0, 27, "^[  ESC",
    SPECIAL, 0, 0, 28, "^\\  FS", SPECIAL, 0, 0, 29, "^]  GS", SPECIAL, 0, 0,
    30, "^^  RS", SPECIAL, 0, 0, 31, "^_  US", SPECIAL, 0, 0, 32, "SP", SPECIAL,
    0, 0, 33, "!", SPECIAL, 0, 0, 34, "\"", SPECIAL, 0, 0, 35, "#", SPECIAL,
    "\\\\#", 0, 36, "$", SPECIAL, "\\\\dollar{}", 0, 37, "%", SPECIAL, "\\\\%",
    0, 38, "&", SPECIAL, "\\\\&", 0, 39, "'", SPECIAL, 0, 0, 40, "(", SPECIAL,
    0, 0, 41, ")", SPECIAL, 0, 0, 42, "*", SPECIAL, 0, 0, 43, "+", SPECIAL, 0,
    0, 44, ",", SPECIAL, 0, 0, 45, "-", SPECIAL, "{-}", 0, 46, ".", SPECIAL, 0,
    0, 47, "/", SPECIAL, 0, 0, 58, ":", SPECIAL, 0, 0, 59, ";", SPECIAL, 0, 0,
    60, "<", SPECIAL, "{\\\\lthan}", 0, 61, "=", SPECIAL, 0, 0, 62, ">",
    SPECIAL, "{\\\\gthan}", 0, 63, "?", SPECIAL, 0, 0, 64, "@", SPECIAL, 0, 0,
    91, "[", SPECIAL, 0, 0, 92, "\\\\", SPECIAL, "{\\\\bslash}", 0, 93, "]",
    SPECIAL, 0, 0, 94, "^", SPECIAL, "\\\\string^", 0, 95, "_", SPECIAL,
    "{\\\\under}", 0, 96, "`", SPECIAL, 0, 0, 123, "{", SPECIAL, "{\\\\lbrac}",
    0, 124, "|", SPECIAL, "{\\\\vbar}", 0, 125, "}", SPECIAL, "{\\\\rbrac}", 0,
    126, "~", SPECIAL, "\\\\string~", 0, 184, "inverted exclamation mark",
    SPECIAL, "{!`}", 0, 185, "inverted question mark", SPECIAL, "{?`}", 0, 168,
    "acute accent", SPECIAL, "\\\\'{ }", 0, 169, "grave accent", SPECIAL,
    "\\\\`{ }", 0, 170, "circumflex", SPECIAL, "\\\\^{ }", 0, 171, "dieresis",
    SPECIAL, "\\\\\\\"{ }", 0, 172, "tilde", SPECIAL, "\\\\~{ }", 0, 127, "DEL",
    SPECIAL, 0, 0, 48, "0", NORMAL, 0, 0, 49, "1", NORMAL, 0, 0, 50, "2",
    NORMAL, 0, 0, 51, "3", NORMAL, 0, 0, 52, "4", NORMAL, 0, 0, 53, "5", NORMAL,
    0, 0, 54, "6", NORMAL, 0, 0, 55, "7", NORMAL, 0, 0, 56, "8", NORMAL, 0, 0,
    57, "9", NORMAL, 0, 0, 97, "a", NORMAL, 0, 0, 192, "a   circumflex", NORMAL,
    "\\\\^a", 0, 200, "a   grave", NORMAL, "\\\\`a", 0, 196, "a   acute",
    NORMAL, "\\\\'a", 0, 204, "a   dieresis", NORMAL, "\\\\\\\"a", 0, 226,
    "a   tilde", NORMAL, "\\\\~a", 0, 212, "a   angstrom", NORMAL, "{\\\\aa}",
    0, 215, "ae  ligature", NORMAL, "{\\\\ae}", 0, 65, "A", NORMAL, NULL, 97,
    162, "A   circumflex", NORMAL, "\\\\^A", 192, 161, "A   grave", NORMAL,
    "\\\\`A", 200, 224, "A   acute", NORMAL, "\\\\'A", 196, 216, "A   dieresis",
    NORMAL, "\\\\\\\"A", 204, 225, "A   tilde", NORMAL, "\\\\~A", 226, 208,
    "A   angstrom", NORMAL, "{\\\\AA}", 212, 211, "AE  ligature", NORMAL,
    "{\\\\AE}", 215, 98, "b", NORMAL, 0, 0, 66, "B", NORMAL, 0, 98, 99, "c",
    NORMAL, 0, 0, 67, "C", NORMAL, 0, 99, 181, "c   cedilla", NORMAL,
    "\\\\c{c}", 0, 180, "C   cedilla", NORMAL, "\\\\c{C}", 181, 68, "D", NORMAL,
    0, 100, 100, "d", NORMAL, 0, 0, 101, "e", NORMAL, 0, 0, 193,
    "e   circumflex", NORMAL, "\\\\^e", 0, 201, "e   grave", NORMAL, "\\\\`e",
    0, 197, "e   acute", NORMAL, "\\\\'e", 0, 205, "e   dieresis", NORMAL,
    "\\\\\\\"e", 0, 69, "E", NORMAL, 0, 101, 164, "E   circumflex", NORMAL,
    "\\\\^E", 193, 163, "E   grave", NORMAL, "\\\\`E", 201, 220, "E   acute",
    NORMAL, "\\\\'E", 197, 165, "E   dieresis", NORMAL, "\\\\\\\"E", 205, 102,
    "f", NORMAL, 0, 0, 70, "F", NORMAL, 0, 102, 103, "g", NORMAL, 0, 0, 71, "G",
    NORMAL, 0, 103, 104, "h", NORMAL, 0, 0, 72, "H", NORMAL, 0, 104, 105, "i",
    NORMAL, 0, 0, 209, "i   circumflex", NORMAL, "{\\\\^\\\\i}", 0, 217,
    "i   grave", NORMAL, "{\\\\`\\\\i}", 0, 213, "i   acute", NORMAL,
    "{\\\\'\\\\i}", 0, 221, "i   dieresis", NORMAL, "{\\\\\\\"\\\\i}", 0, 73,
    "I", NORMAL, 0, 105, 166, "I   circumflex", NORMAL, "\\\\^I", 209, 230,
    "I   grave", NORMAL, "\\\\`I", 217, 229, "I   acute", NORMAL, "\\\\'I", 213,
    167, "I   dieresis", NORMAL, "\\\\\\\"I", 221, 106, "j", NORMAL, 0, 0, 74,
    "J", NORMAL, 0, 106, 107, "k", NORMAL, 0, 0, 75, "K", NORMAL, 0, 107, 108,
    "l", NORMAL, 0, 0, 76, "L", NORMAL, 0, 108, 109, "m", NORMAL, 0, 0, 77, "M",
    NORMAL, 0, 109, 110, "n", NORMAL, 0, 0, 183, "n   tilde", NORMAL, "\\\\~n",
    0, 78, "N", NORMAL, 0, 110, 182, "N   tilde", NORMAL, "\\\\~N", 183, 111,
    "o", NORMAL, 0, 0, 194, "o   circumflex", NORMAL, "\\\\^o", 0, 202,
    "o   grave", NORMAL, "\\\\`o", 0, 198, "o   acute", NORMAL, "\\\\'o", 0,
    206, "o   dieresis", NORMAL, "\\\\\\\"o", 0, 234, "o   tilde", NORMAL,
    "\\\\~o", 0, 214, "o   slash", NORMAL, "{\\\\o}", 0, 79, "O", NORMAL, 0,
    111, 223, "O   circumflex", NORMAL, "\\\\^O", 194, 232, "O   grave", NORMAL,
    "\\\\`O", 202, 231, "O   acute", NORMAL, "\\\\'O", 198, 218, "O   dieresis",
    NORMAL, "\\\\\\\"O", 206, 233, "O   tilde", NORMAL, "\\\\~O", 234, 210,
    "O   slash", NORMAL, "{\\\\O}", 214, 112, "p", NORMAL, 0, 0, 80, "P",
    NORMAL, 0, 112, 113, "q", NORMAL, 0, 0, 81, "Q", NORMAL, 0, 113, 114, "r",
    NORMAL, 0, 0, 82, "R", NORMAL, 0, 114, 115, "s", NORMAL, 0, 0, 236,
    "s   caron", NORMAL, "\\\\v{s}", 0, 222, "SS  ligature", NORMAL, "{\\\\ss}",
    0, 83, "S", NORMAL, 0, 115, 235, "S   caron", NORMAL, "\\\\v{S}", 236, 116,
    "t", NORMAL, 0, 0, 84, "T", NORMAL, 0, 116, 117, "u", NORMAL, 0, 0, 195,
    "u   circumflex", NORMAL, "\\\\^u", 0, 203, "u   grave", NORMAL, "\\\\`u",
    0, 199, "u   acute", NORMAL, "\\\\'u", 0, 207, "u   dieresis", NORMAL,
    "\\\\\\\"u", 0, 85, "U", NORMAL, 0, 117, 174, "U   circumflex", NORMAL,
    "\\\\^U", 195, 173, "U   grave", NORMAL, "\\\\`U", 203, 237, "U   acute",
    NORMAL, "\\\\'U", 199, 219, "U   dieresis", NORMAL, "\\\\\\\"U", 207, 118,
    "v", NORMAL, 0, 0, 86, "V", NORMAL, 0, 118, 119, "w", NORMAL, 0, 0, 87, "W",
    NORMAL, 0, 119, 120, "x", NORMAL, 0, 0, 88, "X", NORMAL, 0, 120, 121, "y",
    NORMAL, 0, 0, 178, "y   acute", NORMAL, "\\\\'y", 0, 239, "y   dieresis",
    NORMAL, "\\\\\\\"y", 0, 89, "Y", NORMAL, 0, 121, 177, "Y   acute", NORMAL,
    "\\\\'Y", 178, 238, "Y   dieresis", NORMAL, "\\\\\\\"Y", 239, 122, "z",
    NORMAL, 0, 0, 90, "Z", NORMAL, 0, 0, 176, "overbar", UNSUPP, 0, 0, 179,
    "degree", UNSUPP, 0, 0, 189, "Section sign", UNSUPP, 0, 0, 191, "Cent sign",
    UNSUPP, 0, 0, 243, "mu", UNSUPP, 0, 0, 244, "paragraph sign", UNSUPP, 0, 0,
    246, "long dash", UNSUPP, 0, 0, 249, "Female ordinal", UNSUPP, 0, 0, 250,
    "Male ordinal", UNSUPP, 0, 0, 254, "Plus over minus sign", UNSUPP, 0, 0,
    175, "Italian Lira", UNSUPP, 0, 0, 186, "currency sign", UNSUPP, 0, 0, 187,
    "pound sterling", UNSUPP, 0, 0, 188, "Yen", UNSUPP, 0, 0, 190, "florin",
    UNSUPP, 0, 0, 227, "Eth", UNSUPP, 0, 0, 228, "eth", UNSUPP, 0, 0, 240,
    "Thorn", UNSUPP, 0, 0, 241, "thorn", UNSUPP, 0, 0, 245, "fraction 3/4",
    UNSUPP, 0, 0, 247, "fraction 1/4", UNSUPP, 0, 0, 248, "fraction 1/2",
    UNSUPP, 0, 0, 251, "French double open quote", UNSUPP, 0, 0, 252,
    "Solid square", UNSUPP, 0, 0, 253, "French double close quote", UNSUPP, 0, 0
