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
/* $XConsortium: chartype.h /main/3 1995/11/08 10:28:12 rswiston $ */
/* Copyright (c) 1988, 1989 Hewlett-Packard Co. */
/* This table defines the subset of the HP Roman8 character set
supported by HP Tag.  Characters defined in Roman8 but not supported
by HP Tag are marked "(invalid)". */

M_CHARTYPE m_ctarray[M_CHARSETLEN] = {
    /* Char Name                         Type, Upper, Lower */
    /*   0: ^@  NUL                   */ {M_NONNAME, 0, 0},
    /*   1: ^A  SOH                   */ {M_NONNAME, 1, 1},
    /*   2: ^B  STX                   */ {M_NONNAME, 2, 2},
    /*   3: ^C  ETX                   */ {M_NONNAME, 3, 3},
    /*   4: ^D  EOT                   */ {M_NONNAME, 4, 4},
    /*   5: ^E  ENQ                   */ {M_NONNAME, 5, 5},
    /*   6: ^F  ACK                   */ {M_NONNAME, 6, 6},
    /*   7: ^G  BEL                   */ {M_NONNAME, 7, 7},
    /*   8: ^H  BS                    */ {M_NONNAME, 8, 8},
    /*   9: ^I  HT                    */ {M_NONNAME, 9, 9},
    /*  10: ^J  LF                    */ {M_NONNAME, 10, 10},
    /*  11: ^K  VT                    */ {M_NONNAME, 11, 11},
    /*  12: ^L  FF                    */ {M_NONNAME, 12, 12},
    /*  13: ^M  CR                    */ {M_NONNAME, 13, 13},
    /*  14: ^N  SO                    */ {M_NONNAME, 14, 14},
    /*  15: ^O  SI                    */ {M_NONNAME, 15, 15},
    /*  16: ^P  DLE                   */ {M_NONNAME, 16, 16},
    /*  17: ^Q  DC1                   */ {M_NONNAME, 17, 17},
    /*  18: ^R  DC2                   */ {M_NONNAME, 18, 18},
    /*  19: ^S  DC3                   */ {M_NONNAME, 19, 19},
    /*  20: ^T  DC4                   */ {M_NONNAME, 20, 20},
    /*  21: ^U  NAK                   */ {M_NONNAME, 21, 21},
    /*  22: ^V  SYN                   */ {M_NONNAME, 22, 22},
    /*  23: ^W  ETB                   */ {M_NONNAME, 23, 23},
    /*  24: ^X  CAN                   */ {M_NONNAME, 24, 24},
    /*  25: ^Y  EM                    */ {M_NONNAME, 25, 25},
    /*  26: ^Z  SUB                   */ {M_NONNAME, 26, 26},
    /*  27: ^[  ESC                   */ {M_NONNAME, 27, 27},
    /*  28: ^\  FS                    */ {M_NONNAME, 28, 28},
    /*  29: ^]  GS                    */ {M_NONNAME, 29, 29},
    /*  30: ^^  RS                    */ {M_NONNAME, 30, 30},
    /*  31: ^_  US                    */ {M_NONNAME, 31, 31},
    /*  32: SP                        */ {M_NONNAME, 32, 32},
    /*  33: !                         */ {M_NONNAME, 33, 33},
    /*  34: "                         */ {M_NONNAME, 34, 34},
    /*  35: #                         */ {M_NONNAME, 35, 35},
    /*  36: $                         */ {M_NONNAME, 36, 36},
    /*  37: %                         */ {M_NONNAME, 37, 37},
    /*  38: &                         */ {M_NONNAME, 38, 38},
    /*  39: '                         */ {M_NONNAME, 39, 39},
    /*  40: (                         */ {M_NONNAME, 40, 40},
    /*  41: )                         */ {M_NONNAME, 41, 41},
    /*  42: *                         */ {M_NONNAME, 42, 42},
    /*  43: +                         */ {M_NAMECHAR, 43, 43},
    /*  44: ,                         */ {M_NONNAME, 44, 44},
    /*  45: -                         */ {M_NAMECHAR, 45, 45},
    /*  46: .                         */ {M_NAMECHAR, 46, 46},
    /*  47: /                         */ {M_NONNAME, 47, 47},
    /*  48: 0                         */ {M_DIGIT, 48, 48},
    /*  49: 1                         */ {M_DIGIT, 49, 49},
    /*  50: 2                         */ {M_DIGIT, 50, 50},
    /*  51: 3                         */ {M_DIGIT, 51, 51},
    /*  52: 4                         */ {M_DIGIT, 52, 52},
    /*  53: 5                         */ {M_DIGIT, 53, 53},
    /*  54: 6                         */ {M_DIGIT, 54, 54},
    /*  55: 7                         */ {M_DIGIT, 55, 55},
    /*  56: 8                         */ {M_DIGIT, 56, 56},
    /*  57: 9                         */ {M_DIGIT, 57, 57},
    /*  58: :                         */ {M_NONNAME, 58, 58},
    /*  59: ;                         */ {M_NONNAME, 59, 59},
    /*  60: <                         */ {M_NONNAME, 60, 60},
    /*  61: =                         */ {M_NONNAME, 61, 61},
    /*  62: >                         */ {M_NONNAME, 62, 62},
    /*  63: ?                         */ {M_NONNAME, 63, 63},
    /*  64: @                         */ {M_NONNAME, 64, 64},
    /*  65: A                         */ {M_NMSTART, 65, 97},
    /*  66: B                         */ {M_NMSTART, 66, 98},
    /*  67: C                         */ {M_NMSTART, 67, 99},
    /*  68: D                         */ {M_NMSTART, 68, 100},
    /*  69: E                         */ {M_NMSTART, 69, 101},
    /*  70: F                         */ {M_NMSTART, 70, 102},
    /*  71: G                         */ {M_NMSTART, 71, 103},
    /*  72: H                         */ {M_NMSTART, 72, 104},
    /*  73: I                         */ {M_NMSTART, 73, 105},
    /*  74: J                         */ {M_NMSTART, 74, 106},
    /*  75: K                         */ {M_NMSTART, 75, 107},
    /*  76: L                         */ {M_NMSTART, 76, 108},
    /*  77: M                         */ {M_NMSTART, 77, 109},
    /*  78: N                         */ {M_NMSTART, 78, 110},
    /*  79: O                         */ {M_NMSTART, 79, 111},
    /*  80: P                         */ {M_NMSTART, 80, 112},
    /*  81: Q                         */ {M_NMSTART, 81, 113},
    /*  82: R                         */ {M_NMSTART, 82, 114},
    /*  83: S                         */ {M_NMSTART, 83, 115},
    /*  84: T                         */ {M_NMSTART, 84, 116},
    /*  85: U                         */ {M_NMSTART, 85, 117},
    /*  86: V                         */ {M_NMSTART, 86, 118},
    /*  87: W                         */ {M_NMSTART, 87, 119},
    /*  88: X                         */ {M_NMSTART, 88, 120},
    /*  89: Y                         */ {M_NMSTART, 89, 121},
    /*  90: Z                         */ {M_NMSTART, 90, 122},
    /*  91: [                         */ {M_NONNAME, 91, 91},
    /*  92: \\                        */ {M_NONNAME, 92, 92},
    /*  93: ]                         */ {M_NONNAME, 93, 93},
    /*  94: ^                         */ {M_NONNAME, 94, 94},
    /*  95: _                         */ {M_NONNAME, 95, 95},
    /*  96: `                         */ {M_NONNAME, 96, 96},
    /*  97: a                         */ {M_NMSTART, 65, 97},
    /*  98: b                         */ {M_NMSTART, 66, 98},
    /*  99: c                         */ {M_NMSTART, 67, 99},
    /* 100: d                         */ {M_NMSTART, 68, 100},
    /* 101: e                         */ {M_NMSTART, 69, 101},
    /* 102: f                         */ {M_NMSTART, 70, 102},
    /* 103: g                         */ {M_NMSTART, 71, 103},
    /* 104: h                         */ {M_NMSTART, 72, 104},
    /* 105: i                         */ {M_NMSTART, 73, 105},
    /* 106: j                         */ {M_NMSTART, 74, 106},
    /* 107: k                         */ {M_NMSTART, 75, 107},
    /* 108: l                         */ {M_NMSTART, 76, 108},
    /* 109: m                         */ {M_NMSTART, 77, 109},
    /* 110: n                         */ {M_NMSTART, 78, 110},
    /* 111: o                         */ {M_NMSTART, 79, 111},
    /* 112: p                         */ {M_NMSTART, 80, 112},
    /* 113: q                         */ {M_NMSTART, 81, 113},
    /* 114: r                         */ {M_NMSTART, 82, 114},
    /* 115: s                         */ {M_NMSTART, 83, 115},
    /* 116: t                         */ {M_NMSTART, 84, 116},
    /* 117: u                         */ {M_NMSTART, 85, 117},
    /* 118: v                         */ {M_NMSTART, 86, 118},
    /* 119: w                         */ {M_NMSTART, 87, 119},
    /* 120: x                         */ {M_NMSTART, 88, 120},
    /* 121: y                         */ {M_NMSTART, 89, 121},
    /* 122: z                         */ {M_NMSTART, 90, 122},
    /* 123: {                         */ {M_NONNAME, 123, 123},
    /* 124: |                         */ {M_NONNAME, 124, 124},
    /* 125: }                         */ {M_NONNAME, 125, 125},
    /* 126: ~                         */ {M_NONNAME, 126, 126},
    /* 127: DEL                       */ {M_NONNAME, 127, 127},
    /* 128: undefined                 */ {M_NONNAME, 128, 128},
    /* 129: undefined                 */ {M_NONNAME, 129, 129},
    /* 130: undefined                 */ {M_NONNAME, 130, 130},
    /* 131: undefined                 */ {M_NONNAME, 131, 131},
    /* 132: undefined                 */ {M_NONNAME, 132, 132},
    /* 133: undefined                 */ {M_NONNAME, 133, 133},
    /* 134: undefined                 */ {M_NONNAME, 134, 134},
    /* 135: undefined                 */ {M_NONNAME, 135, 135},
    /* 136: undefined                 */ {M_NONNAME, 136, 136},
    /* 137: undefined                 */ {M_NONNAME, 137, 137},
    /* 138: undefined                 */ {M_NONNAME, 138, 138},
    /* 139: undefined                 */ {M_NONNAME, 139, 139},
    /* 140: undefined                 */ {M_NONNAME, 140, 140},
    /* 141: undefined                 */ {M_NONNAME, 141, 141},
    /* 142: undefined                 */ {M_NONNAME, 142, 142},
    /* 143: undefined                 */ {M_NONNAME, 143, 143},
    /* 144: undefined                 */ {M_NONNAME, 144, 144},
    /* 145: undefined                 */ {M_NONNAME, 145, 145},
    /* 146: undefined                 */ {M_NONNAME, 146, 146},
    /* 147: undefined                 */ {M_NONNAME, 147, 147},
    /* 148: undefined                 */ {M_NONNAME, 148, 148},
    /* 149: undefined                 */ {M_NONNAME, 149, 149},
    /* 150: undefined                 */ {M_NONNAME, 150, 150},
    /* 151: undefined                 */ {M_NONNAME, 151, 151},
    /* 152: undefined                 */ {M_NONNAME, 152, 152},
    /* 153: undefined                 */ {M_NONNAME, 153, 153},
    /* 154: undefined                 */ {M_NONNAME, 154, 154},
    /* 155: undefined                 */ {M_NONNAME, 155, 155},
    /* 156: undefined                 */ {M_NONNAME, 156, 156},
    /* 157: undefined                 */ {M_NONNAME, 157, 157},
    /* 158: undefined                 */ {M_NONNAME, 158, 158},
    /* 159: undefined                 */ {M_NONNAME, 159, 159},
    /* 160: undefined                 */ {M_NONNAME, 160, 160},
    /* 161: A   grave                 */ {M_NMSTART, 161, 200},
    /* 162: A   circumflex            */ {M_NMSTART, 162, 192},
    /* 163: E   grave                 */ {M_NMSTART, 163, 201},
    /* 164: E   circumflex            */ {M_NMSTART, 164, 193},
    /* 165: E   dieresis              */ {M_NMSTART, 165, 205},
    /* 166: I   circumflex            */ {M_NMSTART, 166, 209},
    /* 167: I   dieresis              */ {M_NMSTART, 167, 221},
    /* 168: acute accent              */ {M_NONNAME, 168, 168},
    /* 169: grave accent              */ {M_NONNAME, 169, 169},
    /* 170: circumflex                */ {M_NONNAME, 170, 170},
    /* 171: dieresis                  */ {M_NONNAME, 171, 171},
    /* 172: tilde                     */ {M_NONNAME, 172, 172},
    /* 173: U   grave                 */ {M_NMSTART, 173, 203},
    /* 174: U   circumflex            */ {M_NMSTART, 174, 195},
    /* 175: Italian Lira  (invalid)   */ {M_NONNAME, 175, 175},
    /* 176: overbar       (invalid)   */ {M_NONNAME, 176, 176},
    /* 177: Y   acute                 */ {M_NMSTART, 177, 178},
    /* 178: y   acute                 */ {M_NMSTART, 177, 178},
    /* 179: degree        (invalid)   */ {M_NONNAME, 179, 179},
    /* 180: C   cedilla               */ {M_NMSTART, 180, 181},
    /* 181: c   cedilla               */ {M_NMSTART, 180, 181},
    /* 182: N   tilde                 */ {M_NMSTART, 182, 183},
    /* 183: n   tilde                 */ {M_NMSTART, 182, 183},
    /* 184: inverted exclamation mark */ {M_NONNAME, 184, 184},
    /* 185: inverted question mark    */ {M_NONNAME, 185, 185},
    /* 186: currency sign  (invalid)  */ {M_NONNAME, 186, 186},
    /* 187: pound sterling (invalid)  */ {M_NONNAME, 187, 187},
    /* 188: Yen                       */ {M_NONNAME, 188, 188},
    /* 189: Section sign  (invalid)   */ {M_NONNAME, 189, 189},
    /* 190: florin    (invalid)       */ {M_NONNAME, 190, 190},
    /* 191: Cent sign (invalid)       */ {M_NONNAME, 191, 191},
    /* 192: a   circumflex            */ {M_NMSTART, 162, 192},
    /* 193: e   circumflex            */ {M_NMSTART, 164, 193},
    /* 194: o   circumflex            */ {M_NMSTART, 223, 194},
    /* 195: u   circumflex            */ {M_NMSTART, 174, 195},
    /* 196: a   acute                 */ {M_NMSTART, 224, 196},
    /* 197: e   acute                 */ {M_NMSTART, 220, 197},
    /* 198: o   acute                 */ {M_NMSTART, 231, 198},
    /* 199: u   acute                 */ {M_NMSTART, 237, 199},
    /* 200: a   grave                 */ {M_NMSTART, 161, 200},
    /* 201: e   grave                 */ {M_NMSTART, 163, 201},
    /* 202: o   grave                 */ {M_NMSTART, 232, 202},
    /* 203: u   grave                 */ {M_NMSTART, 173, 203},
    /* 204: a   dieresis              */ {M_NMSTART, 216, 204},
    /* 205: e   dieresis              */ {M_NMSTART, 165, 205},
    /* 206: o   dieresis              */ {M_NMSTART, 218, 206},
    /* 207: u   dieresis              */ {M_NMSTART, 219, 207},
    /* 208: A   angstrom              */ {M_NMSTART, 208, 212},
    /* 209: i   circumflex            */ {M_NMSTART, 166, 209},
    /* 210: O   slash                 */ {M_NMSTART, 210, 214},
    /* 211: AE  ligature              */ {M_NMSTART, 211, 215},
    /* 212: a   angstrom              */ {M_NMSTART, 208, 212},
    /* 213: i   acute                 */ {M_NMSTART, 229, 213},
    /* 214: o   slash                 */ {M_NMSTART, 210, 214},
    /* 215: ae  ligature              */ {M_NMSTART, 211, 215},
    /* 216: A   dieresis              */ {M_NMSTART, 216, 204},
    /* 217: i   grave                 */ {M_NMSTART, 230, 217},
    /* 218: O   dieresis              */ {M_NMSTART, 218, 206},
    /* 219: U   dieresis              */ {M_NMSTART, 219, 207},
    /* 220: E   acute                 */ {M_NMSTART, 220, 197},
    /* 221: i   dieresis              */ {M_NMSTART, 167, 221},
    /* 222: SS  ligature              */ {M_NMSTART, 222, 222},
    /* 223: O   circumflex            */ {M_NMSTART, 223, 194},
    /* 224: A   acute                 */ {M_NMSTART, 224, 196},
    /* 225: A   tilde                 */ {M_NMSTART, 225, 226},
    /* 226: a   tilde                 */ {M_NMSTART, 225, 226},
    /* 227: Eth      (invalid)        */ {M_NMSTART, 227, 228},
    /* 228: eth      (invalid)        */ {M_NMSTART, 227, 228},
    /* 229: I   acute                 */ {M_NMSTART, 229, 213},
    /* 230: I   grave                 */ {M_NMSTART, 230, 217},
    /* 231: O   acute                 */ {M_NMSTART, 231, 198},
    /* 232: O   grave                 */ {M_NMSTART, 232, 202},
    /* 233: O   tilde                 */ {M_NMSTART, 233, 234},
    /* 234: o   tilde                 */ {M_NMSTART, 233, 234},
    /* 235: S   caron                 */ {M_NMSTART, 235, 236},
    /* 236: s   caron                 */ {M_NMSTART, 235, 236},
    /* 237: U   acute                 */ {M_NMSTART, 237, 199},
    /* 238: Y   dieresis              */ {M_NMSTART, 238, 239},
    /* 239: y   dieresis              */ {M_NMSTART, 238, 239},
    /* 240: Thorn      (invalid)      */ {M_NMSTART, 240, 241},
    /* 241: thorn      (invalid)      */ {M_NMSTART, 240, 241},
    /* 242: undefined                 */ {M_NONNAME, 242, 242},
    /* 243: mu          (invalid)     */ {M_NONNAME, 243, 243},
    /* 244: paragraph sign  (invalid) */ {M_NONNAME, 244, 244},
    /* 245: fraction 3/4  (invalid)   */ {M_NONNAME, 245, 245},
    /* 246: long dash      (invalid)  */ {M_NONNAME, 246, 246},
    /* 247: fraction 1/4   (invalid)  */ {M_NONNAME, 247, 247},
    /* 248: fraction 1/2   (invalid)  */ {M_NONNAME, 248, 248},
    /* 249: Female ordinal (invalid)  */ {M_NONNAME, 249, 249},
    /* 250: Male ordinal   (invalid)  */ {M_NONNAME, 250, 250},
    /* 251: French double open quote(invalid)  */ {M_NONNAME, 251, 251},
    /* 252: Solid square  (invalid)   */ {M_NONNAME, 252, 252},
    /* 253: French double close quote(invalid) */ {M_NONNAME, 253, 253},
    /* 254: Plus over minus sign(invalid)*/ {M_NONNAME, 254, 254},
    /* 255: undefined                 */ {M_NONNAME, 255, 255},
};
