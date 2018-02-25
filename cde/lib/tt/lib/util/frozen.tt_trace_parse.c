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
#include <stdio.h>
#define U(x) x
#define NLSTATE tt_trace_previous = TT_TRACE_NEWLINE
#define BEGIN tt_trace_bgin = tt_trace_svec + 1 +
#define INITIAL 0
#define TT_TRACE_LERR tt_trace_svec
#define TT_TRACE_STATE (tt_trace_estate - tt_trace_svec - 1)
#define TT_TRACE_OPTIM 1
#define TT_TRACE_LMAX BUFSIZ
#ifndef __cplusplus
#define output(c) (void)putc(c, tt_trace_out)
#else
#define lex_output(c) (void)putc(c, tt_trace_out)
#endif

#if defined(__cplusplus) || defined(__STDC__)

#if defined(__cplusplus) && defined(__EXTERN_C__)
extern "C" {
#endif
int tt_trace_back(int *, int);
int tt_trace_input(void);
int tt_trace_look(void);
void tt_trace_output(int);
int tt_trace_racc(int);
int tt_trace_reject(void);
void tt_trace_unput(int);
int tt_trace_lex(void);
#ifdef TT_TRACE_LEX_E
void tt_trace_woutput(wchar_t);
wchar_t tt_trace_winput(void);
#endif
#ifndef tt_trace_less
void tt_trace_less(int);
#endif
#ifndef tt_trace_wrap
int tt_trace_wrap(void);
#endif
#ifdef LEXDEBUG
void allprint(char);
void sprint(char *);
#endif
#if defined(__cplusplus) && defined(__EXTERN_C__)
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
void exit(int);
#ifdef __cplusplus
}
#endif

#endif
#define unput(c)                                                               \
        {                                                                      \
                tt_trace_tchar = (c);                                          \
                if (tt_trace_tchar == '\n')                                    \
                        tt_trace_lineno--;                                     \
                *tt_trace_sptr++ = tt_trace_tchar;                             \
        }
#define tt_trace_more() (tt_trace_morfg = 1)
#ifndef __cplusplus
#define input()                                                                \
        (((tt_trace_tchar = tt_trace_sptr > tt_trace_sbuf                      \
                                ? U(*--tt_trace_sptr)                          \
                                : getc(tt_trace_in)) == 10                     \
              ? (tt_trace_lineno++, tt_trace_tchar)                            \
              : tt_trace_tchar) == EOF                                         \
             ? 0                                                               \
             : tt_trace_tchar)
#else
#define lex_input()                                                            \
        (((tt_trace_tchar = tt_trace_sptr > tt_trace_sbuf                      \
                                ? U(*--tt_trace_sptr)                          \
                                : getc(tt_trace_in)) == 10                     \
              ? (tt_trace_lineno++, tt_trace_tchar)                            \
              : tt_trace_tchar) == EOF                                         \
             ? 0                                                               \
             : tt_trace_tchar)
#endif
#define ECHO fprintf(tt_trace_out, "%s", tt_trace_text)
#define REJECT                                                                 \
        {                                                                      \
                nstr = tt_trace_reject();                                      \
                goto tt_trace_fussy;                                           \
        }
int tt_trace_leng;
extern char tt_trace_text[];
int tt_trace_morfg;
extern char *tt_trace_sptr, tt_trace_sbuf[];
int tt_trace_tchar;
FILE *tt_trace_in = {stdin}, *tt_trace_out = {stdout};
extern int tt_trace_lineno;
struct tt_trace_svf {
        struct tt_trace_work *tt_trace_stoff;
        struct tt_trace_svf *tt_trace_other;
        int *tt_trace_stops;
};
struct tt_trace_svf *tt_trace_estate;
extern struct tt_trace_svf tt_trace_svec[], *tt_trace_bgin;

#line 2 "util/tt_trace_parse.l"
/*%% 	$XConsortium: frozen.tt_trace_parse.c /main/3 1995/10/23 10:35:52
 * rswiston $							 */

#line 3 "util/tt_trace_parse.l"
/*%% 									 */

#line 4 "util/tt_trace_parse.l"
/*%%  	RESTRICTED CONFIDENTIAL INFORMATION:                             */

#line 5 "util/tt_trace_parse.l"
/*%% 									 */

#line 6 "util/tt_trace_parse.l"
/*%% 	The information in this document is subject to special		 */

#line 7 "util/tt_trace_parse.l"
/*%% 	restrictions in a confidential disclosure agreement between	 */

#line 8 "util/tt_trace_parse.l"
/*%% 	HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this	 */

#line 9 "util/tt_trace_parse.l"
/*%% 	document outside HP, IBM, Sun, USL, SCO, or Univel without	 */

#line 10 "util/tt_trace_parse.l"
/*%% 	Sun's specific written approval.  This document and all copies	 */

#line 11 "util/tt_trace_parse.l"
/*%% 	and derivative works thereof must be returned or destroyed at	 */

#line 12 "util/tt_trace_parse.l"
/*%% 	Sun's request.							 */

#line 13 "util/tt_trace_parse.l"
/*%% 									 */

#line 14 "util/tt_trace_parse.l"
/*%% 	Copyright 1993 Sun Microsystems, Inc.  All rights reserved.	 */

#line 15 "util/tt_trace_parse.l"
/*%% 									 */

#line 18 "util/tt_trace_parse.l"
/*
 *
 * tt_trace_parse.l
 *
 * Copyright (c) 1993 by Sun Microsystems, Inc.
 */

#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include <api/c/tt_c.h>
#include "util/tt_trace.tab.h"

#undef input
#undef unput
#define input _tt_trace_input
#define unput(c) _tt_trace_unput(c)

extern int _tt_trace_input();
extern void _tt_trace_unput(int);

static char *fname_chars =
    "/0123456789:;=@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_,.";

#line 43 "util/tt_trace_parse.l"
/*
 * macros for common character classes
 */
#define TT_TRACE_NEWLINE 10
tt_trace_lex() {
        int nstr;
        extern int tt_trace_previous;
#ifdef __cplusplus
        /* to avoid CC and lint complaining tt_trace_fussy not being used ...*/
        static int __lex_hack = 0;
        if (__lex_hack)
                goto tt_trace_fussy;
#endif
        while ((nstr = tt_trace_look()) >= 0)
        tt_trace_fussy:
                switch (nstr) {
                case 0:
                        if (tt_trace_wrap())
                                return (0);
                        break;
                case 1:

#line 58 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_LINETERM;
                } break;
                case 2:

#line 60 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_PARSE_EOF;
                } break;
                case 3:

#line 61 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_PARSE_EOF;
                } break;
                case 4:

#line 62 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_PARSE_EOF;
                } break;
                case 5:

#line 64 "util/tt_trace_parse.l"
                    ;
                        break;
                case 6:

#line 65 "util/tt_trace_parse.l"
                    ;
                        break;
                case 7:

#line 67 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_FOLLOW;
                } break;
                case 8:

#line 68 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_SINK_APPEND;
                } break;
                case 9:

#line 69 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_SINK;
                } break;
                case 10:

#line 70 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_FUNCTIONS;
                } break;
                case 11:

#line 71 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_ATTRIBUTES;
                } break;
                case 12:

#line 72 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_STATES;
                } break;
                case 13:

#line 73 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_OPS;
                } break;
                case 14:

#line 74 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_SENDER_PTYPES;
                } break;
                case 15:

#line 75 "util/tt_trace_parse.l"
                {
                        return _TT_TRACE_HANDLER_PTYPES;
                } break;
                case 16:

#line 77 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.tokenval = _TT_TRACE_OFF;
                        return _TT_TRACE_IVAL;
                } break;
                case 17:

#line 82 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.tokenval = _TT_TRACE_ON;
                        return _TT_TRACE_IVAL;
                } break;
                case 18:

#line 87 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.tokenval = _TT_TRACE_ALL;
                        return _TT_TRACE_IVAL;
                } break;
                case 19:

#line 92 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.tokenval = _TT_TRACE_NONE;
                        return _TT_TRACE_IVAL;
                } break;
                case 20:

#line 97 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type =
                            _TT_TRACE_STATES_NEDD;
                        tt_trace_lval.stateval.state_val = _TT_TRACE_EDGE;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 21:

#line 104 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type =
                            _TT_TRACE_STATES_NEDD;
                        tt_trace_lval.stateval.state_val = _TT_TRACE_DELIVER;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 22:

#line 111 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type =
                            _TT_TRACE_STATES_NEDD;
                        tt_trace_lval.stateval.state_val = _TT_TRACE_DISPATCH;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 23:

#line 118 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type = _TT_TRACE_STATES_TT;
                        tt_trace_lval.stateval.state_val = TT_CREATED;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 24:

#line 124 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type = _TT_TRACE_STATES_TT;
                        tt_trace_lval.stateval.state_val = TT_SENT;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 25:

#line 130 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type = _TT_TRACE_STATES_TT;
                        tt_trace_lval.stateval.state_val = TT_HANDLED;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 26:

#line 136 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type = _TT_TRACE_STATES_TT;
                        tt_trace_lval.stateval.state_val = TT_FAILED;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 27:

#line 142 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type = _TT_TRACE_STATES_TT;
                        tt_trace_lval.stateval.state_val = TT_QUEUED;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 28:

#line 148 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type = _TT_TRACE_STATES_TT;
                        tt_trace_lval.stateval.state_val = TT_STARTED;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 29:

#line 154 "util/tt_trace_parse.l"
                {
                        tt_trace_lval.stateval.state_type = _TT_TRACE_STATES_TT;
                        tt_trace_lval.stateval.state_val = TT_REJECTED;
                        return _TT_TRACE_STATES_VAL;
                } break;
                case 30:

#line 160 "util/tt_trace_parse.l"
                {
                        strcpy(tt_trace_lval.string, tt_trace_text);
                        return _TT_TRACE_ALPHANUM;
                } break;
                case 31:

#line 165 "util/tt_trace_parse.l"
                {
                        strcpy(tt_trace_lval.string, tt_trace_text);
                        return _TT_TRACE_FILENAME;
                } break;
                case 32:

#line 170 "util/tt_trace_parse.l"
                {
                        int vers;
                        char *num_ptr = strpbrk(tt_trace_text, "0123456789");
                        sscanf(num_ptr, "%d", &vers);
                        tt_trace_lval.tokenval = vers;

                        return _TT_TRACE_VERSION;
                } break;
                case -1:
                        break;
                default:
                        (void)fprintf(tt_trace_out,
                                      "bad switch tt_trace_look %d", nstr);
                }
        return (0);
}
/* end of tt_trace_lex */
int tt_trace_vstop[] = {0,

                        2,  0,

                        2,  0,

                        6,  0,

                        1,  0,

                        5,  0,

                        31, 0,

                        30, 31, 0,

                        9,  0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        4,  0,

                        8,  0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        17, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        18, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        16, 30, 31, 0,

                        13, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        20, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        19, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        7,  30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        12, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        24, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        21, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        22, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        26, 30, 31, 0,

                        30, 31, 0,

                        27, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        10, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        32, 0,

                        23, 30, 31, 0,

                        25, 30, 31, 0,

                        30, 31, 0,

                        28, 30, 31, 0,

                        11, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        29, 30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        30, 31, 0,

                        14, 30, 31, 0,

                        15, 30, 31, 0, 0};
#define TT_TRACE_TYPE unsigned char
struct tt_trace_work {
        TT_TRACE_TYPE verify, advance;
} tt_trace_crank[] = {
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   1,   3,   1,   4,   3,   3,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   1,   3,   0,   0,   3,   3,   1,   5,   0,
    0,   0,   0,   0,   0,   1,   6,   6,   20,  0,   0,   0,   0,   0,   0,
    1,   7,   0,   0,   1,   7,   1,   7,   1,   8,   1,   8,   1,   8,   1,
    8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   7,
    1,   4,   0,   0,   1,   7,   1,   9,   0,   0,   1,   7,   1,   8,   1,
    8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,
    1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,
    8,   1,   8,   1,   8,   1,   10,  1,   8,   1,   8,   1,   8,   1,   8,
    1,   8,   1,   8,   9,   21,  0,   0,   0,   0,   0,   0,   1,   8,   0,
    0,   1,   11,  1,   8,   1,   8,   1,   12,  1,   13,  1,   14,  1,   8,
    1,   15,  1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   16,  1,
    17,  1,   8,   1,   8,   1,   8,   1,   18,  1,   8,   1,   8,   1,   19,
    1,   8,   1,   8,   1,   8,   1,   8,   5,   5,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   5,   5,   5,   0,   138, 138,
    138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138,
    138, 138, 138, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   5,   5,   0,   0,   0,   0,   0,   0,   5,   5,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   5,   5,   0,   0,   0,   0,   0,   0,   0,   0,   7,
    7,   5,   5,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   0,
    0,   0,   0,   7,   7,   0,   0,   0,   0,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   0,   0,   0,   0,   0,   0,   0,   0,   7,   7,   0,   0,
    7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
    7,   7,   7,   7,   7,   7,   7,   8,   8,   8,   8,   8,   8,   8,   8,
    8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   8,   8,   8,   8,
    8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,
    8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,
    8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,
    8,   8,   8,   0,   0,   0,   0,   0,   0,   0,   0,   8,   8,   0,   0,
    8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,
    8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,
    8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,
    8,   8,   8,   8,   8,   8,   8,   10,  8,   10,  8,   10,  8,   10,  8,
    10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   10,  8,   10,  8,
    10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,
    8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,
    10,  8,   10,  8,   10,  22,  10,  8,   10,  8,   10,  8,   10,  8,   10,
    8,   10,  8,   0,   0,   0,   0,   0,   0,   0,   0,   10,  8,   0,   0,
    10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,
    8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,
    10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,  8,   10,
    8,   10,  8,   10,  8,   10,  8,   11,  8,   11,  8,   11,  8,   11,  8,
    11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   11,  8,   11,  8,
    11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,
    8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,
    11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,
    8,   11,  8,   0,   0,   0,   0,   0,   0,   0,   0,   11,  8,   0,   0,
    11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,  8,   11,
    8,   11,  8,   11,  8,   11,  8,   11,  23,  11,  8,   11,  8,   11,  8,
    11,  8,   11,  8,   11,  8,   11,  8,   11,  24,  11,  8,   11,  8,   11,
    8,   11,  8,   11,  8,   11,  8,   12,  8,   12,  8,   12,  8,   12,  8,
    12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   12,  8,   12,  8,
    12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,
    8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,
    12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,
    8,   12,  8,   0,   0,   0,   0,   0,   0,   0,   0,   12,  8,   0,   0,
    12,  8,   12,  8,   12,  8,   12,  8,   12,  25,  12,  8,   12,  8,   12,
    8,   12,  26,  12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,
    12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,  8,   12,
    8,   12,  8,   12,  8,   12,  8,   13,  8,   13,  8,   13,  8,   13,  8,
    13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   13,  8,   13,  8,
    13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,
    8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,
    13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,
    8,   13,  8,   0,   0,   0,   0,   0,   0,   0,   0,   13,  8,   0,   0,
    13,  8,   13,  8,   13,  8,   13,  27,  13,  8,   13,  8,   13,  8,   13,
    8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,
    13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,  8,   13,
    8,   13,  8,   13,  8,   13,  8,   14,  8,   14,  8,   14,  8,   14,  8,
    14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   14,  8,   14,  8,
    14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,
    8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,
    14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,
    8,   14,  8,   0,   0,   0,   0,   0,   0,   0,   0,   14,  8,   0,   0,
    14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,
    8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  28,
    14,  8,   14,  8,   14,  8,   14,  8,   14,  8,   14,  29,  14,  8,   14,
    8,   14,  8,   14,  8,   14,  8,   15,  8,   15,  8,   15,  8,   15,  8,
    15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   15,  8,   15,  8,
    15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,
    8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,
    15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,
    8,   15,  8,   0,   0,   0,   0,   0,   0,   0,   0,   15,  8,   0,   0,
    15,  30,  15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,
    8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,
    15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,  8,   15,
    8,   15,  8,   15,  8,   15,  8,   16,  8,   16,  8,   16,  8,   16,  8,
    16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   16,  8,   16,  8,
    16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,
    8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,
    16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,
    8,   16,  8,   0,   0,   0,   0,   0,   0,   0,   0,   16,  8,   0,   0,
    16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,
    8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  31,
    16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,  8,   16,
    8,   16,  8,   16,  8,   16,  8,   17,  8,   17,  8,   17,  8,   17,  8,
    17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   17,  8,   17,  8,
    17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,
    8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,
    17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,
    8,   17,  8,   0,   0,   0,   0,   0,   0,   0,   0,   17,  8,   0,   0,
    17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  32,  17,  8,   17,
    8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  33,  17,  8,
    17,  34,  17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,  8,   17,
    8,   17,  8,   17,  8,   17,  8,   18,  8,   18,  8,   18,  8,   18,  8,
    18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   18,  8,   18,  8,
    18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,
    8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,
    18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,
    8,   18,  8,   0,   0,   0,   0,   0,   0,   0,   0,   18,  8,   0,   0,
    18,  8,   18,  8,   18,  8,   18,  8,   18,  35,  18,  8,   18,  8,   18,
    8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,   18,  8,
    18,  8,   18,  8,   18,  8,   18,  8,   18,  36,  18,  8,   18,  8,   18,
    8,   18,  8,   18,  8,   18,  8,   19,  8,   19,  8,   19,  8,   19,  8,
    19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   19,  8,   19,  8,
    19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,
    8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,
    19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,
    8,   19,  8,   0,   0,   0,   0,   0,   0,   0,   0,   19,  8,   0,   0,
    19,  8,   19,  8,   19,  8,   19,  8,   19,  37,  19,  8,   19,  8,   19,
    8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,
    19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,  8,   19,
    8,   19,  8,   19,  8,   19,  8,   22,  8,   22,  8,   22,  8,   22,  8,
    22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   22,  8,   22,  8,
    22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,
    8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,
    22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,
    8,   22,  8,   0,   0,   0,   0,   0,   0,   0,   0,   22,  38,  0,   0,
    22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,
    8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,
    22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,  8,   22,
    8,   22,  8,   22,  8,   22,  8,   23,  8,   23,  8,   23,  8,   23,  8,
    23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   23,  8,   23,  8,
    23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,
    8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,
    23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,
    8,   23,  8,   0,   0,   0,   0,   0,   0,   0,   0,   23,  8,   0,   0,
    23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,
    8,   23,  8,   23,  8,   23,  8,   23,  39,  23,  8,   23,  8,   23,  8,
    23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,  8,   23,
    8,   23,  8,   23,  8,   23,  8,   24,  8,   24,  8,   24,  8,   24,  8,
    24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   24,  8,   24,  8,
    24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,
    8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,
    24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,
    8,   24,  8,   0,   0,   0,   0,   0,   0,   0,   0,   24,  8,   0,   0,
    24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,
    8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,   24,  8,
    24,  8,   24,  8,   24,  8,   24,  8,   24,  40,  24,  8,   24,  8,   24,
    8,   24,  8,   24,  8,   24,  8,   25,  8,   25,  8,   25,  8,   25,  8,
    25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   25,  8,   25,  8,
    25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,
    8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,
    25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,
    8,   25,  8,   0,   0,   0,   0,   0,   0,   0,   0,   25,  8,   0,   0,
    25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,
    8,   25,  8,   25,  8,   25,  8,   25,  41,  25,  8,   25,  8,   25,  8,
    25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,  8,   25,
    8,   25,  8,   25,  8,   25,  8,   26,  8,   26,  8,   26,  8,   26,  8,
    26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   26,  8,   26,  8,
    26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,
    8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,
    26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,
    8,   26,  8,   0,   0,   0,   0,   0,   0,   0,   0,   26,  8,   0,   0,
    26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,
    8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,   26,  8,
    26,  8,   26,  8,   26,  8,   26,  42,  26,  8,   26,  8,   26,  8,   26,
    8,   26,  8,   26,  8,   26,  8,   27,  8,   27,  8,   27,  8,   27,  8,
    27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   27,  8,   27,  8,
    27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,
    8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,
    27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,
    8,   27,  8,   0,   0,   0,   0,   0,   0,   0,   0,   27,  8,   0,   0,
    27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  43,  27,
    8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,
    27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,  8,   27,
    8,   27,  8,   27,  8,   27,  8,   28,  8,   28,  8,   28,  8,   28,  8,
    28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   28,  8,   28,  8,
    28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,
    8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,
    28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,
    8,   28,  8,   0,   0,   0,   0,   0,   0,   0,   0,   28,  8,   0,   0,
    28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,
    8,   28,  8,   28,  8,   28,  8,   28,  44,  28,  8,   28,  8,   28,  8,
    28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,  8,   28,
    8,   28,  8,   28,  8,   28,  8,   29,  8,   29,  8,   29,  8,   29,  8,
    29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   29,  8,   29,  8,
    29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,
    8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,
    29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,
    8,   29,  8,   0,   0,   0,   0,   0,   0,   0,   0,   29,  8,   0,   0,
    29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,
    8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  45,  29,  8,
    29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,  8,   29,
    8,   29,  8,   29,  8,   29,  8,   30,  8,   30,  8,   30,  8,   30,  8,
    30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   30,  8,   30,  8,
    30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,
    8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,
    30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,
    8,   30,  8,   0,   0,   0,   0,   0,   0,   0,   0,   30,  8,   0,   0,
    30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,
    8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  46,  30,  8,
    30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,  8,   30,
    8,   30,  8,   30,  8,   30,  8,   31,  8,   31,  8,   31,  8,   31,  8,
    31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   31,  8,   31,  8,
    31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,
    8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,
    31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,
    8,   31,  8,   0,   0,   0,   0,   0,   0,   0,   0,   31,  8,   0,   0,
    31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,
    8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  47,  31,  8,
    31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,  8,   31,
    8,   31,  8,   31,  8,   31,  8,   32,  8,   32,  8,   32,  8,   32,  8,
    32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   32,  8,   32,  8,
    32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,
    8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,
    32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,
    8,   32,  8,   0,   0,   0,   0,   0,   0,   0,   0,   32,  8,   0,   0,
    32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  48,  32,  8,   32,
    8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,
    32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,  8,   32,
    8,   32,  8,   32,  8,   32,  8,   33,  8,   33,  8,   33,  8,   33,  8,
    33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   33,  8,   33,  8,
    33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,
    8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,
    33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,
    8,   33,  8,   0,   0,   0,   0,   0,   0,   0,   0,   33,  8,   0,   0,
    33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,
    8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,
    33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,  8,   33,
    8,   33,  8,   33,  8,   33,  8,   34,  8,   34,  8,   34,  8,   34,  8,
    34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   34,  8,   34,  8,
    34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,
    8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,
    34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,
    8,   34,  8,   0,   0,   0,   0,   0,   0,   0,   0,   34,  8,   0,   0,
    34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,
    8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,   34,  8,
    34,  8,   34,  8,   34,  8,   34,  49,  34,  8,   34,  8,   34,  8,   34,
    8,   34,  8,   34,  8,   34,  8,   35,  8,   35,  8,   35,  8,   35,  8,
    35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   35,  8,   35,  8,
    35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,
    8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,
    35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,
    8,   35,  8,   0,   0,   0,   0,   0,   0,   0,   0,   35,  8,   0,   0,
    35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,
    8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  50,  35,  8,
    35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,  8,   35,
    8,   35,  8,   35,  8,   35,  8,   36,  8,   36,  8,   36,  8,   36,  8,
    36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   36,  8,   36,  8,
    36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,
    8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,
    36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,
    8,   36,  8,   0,   0,   0,   0,   0,   0,   0,   0,   36,  8,   0,   0,
    36,  51,  36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,
    8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,
    36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,  8,   36,
    8,   36,  8,   36,  8,   36,  8,   37,  8,   37,  8,   37,  8,   37,  8,
    37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   37,  8,   37,  8,
    37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,
    8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,
    37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,
    8,   37,  8,   0,   0,   0,   0,   0,   0,   0,   0,   37,  8,   0,   0,
    37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,
    8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,   37,  8,
    37,  8,   37,  8,   37,  52,  37,  8,   37,  8,   37,  8,   37,  8,   37,
    8,   37,  8,   37,  8,   37,  8,   38,  8,   38,  8,   38,  8,   38,  8,
    38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   38,  8,   38,  8,
    38,  53,  38,  8,   38,  8,   38,  54,  38,  8,   38,  55,  38,  8,   38,
    8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  56,
    38,  57,  38,  58,  38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,
    8,   38,  8,   0,   0,   0,   0,   0,   0,   0,   0,   38,  8,   0,   0,
    38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,
    8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,
    38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,  8,   38,
    8,   38,  8,   38,  8,   38,  8,   39,  8,   39,  8,   39,  8,   39,  8,
    39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   39,  8,   39,  8,
    39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,
    8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,
    39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,
    8,   39,  8,   0,   0,   0,   0,   0,   0,   0,   0,   39,  8,   0,   0,
    39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,
    8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,
    39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,  8,   39,
    8,   39,  8,   39,  8,   39,  8,   40,  8,   40,  8,   40,  8,   40,  8,
    40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   40,  8,   40,  8,
    40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,
    8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,
    40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,
    8,   40,  8,   0,   0,   0,   0,   0,   0,   0,   0,   40,  8,   0,   0,
    40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,
    8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,   40,  8,
    40,  8,   40,  8,   40,  59,  40,  8,   40,  8,   40,  8,   40,  8,   40,
    8,   40,  8,   40,  8,   40,  8,   41,  8,   41,  8,   41,  8,   41,  8,
    41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   41,  8,   41,  8,
    41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,
    8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,
    41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,
    8,   41,  8,   0,   0,   0,   0,   0,   0,   0,   0,   41,  8,   0,   0,
    41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,
    8,   41,  60,  41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,
    41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,  8,   41,
    8,   41,  8,   41,  8,   41,  8,   42,  8,   42,  8,   42,  8,   42,  8,
    42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   42,  8,   42,  8,
    42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,
    8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,
    42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,
    8,   42,  8,   0,   0,   0,   0,   0,   0,   0,   0,   42,  8,   0,   0,
    42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,
    8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,
    42,  61,  42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,  8,   42,
    8,   42,  8,   42,  8,   42,  8,   43,  8,   43,  8,   43,  8,   43,  8,
    43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   43,  8,   43,  8,
    43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,
    8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,
    43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,
    8,   43,  8,   0,   0,   0,   0,   0,   0,   0,   0,   43,  8,   0,   0,
    43,  8,   43,  8,   43,  8,   43,  8,   43,  62,  43,  8,   43,  8,   43,
    8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,
    43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,  8,   43,
    8,   43,  8,   43,  8,   43,  8,   44,  8,   44,  8,   44,  8,   44,  8,
    44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   44,  8,   44,  8,
    44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,
    8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,
    44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,
    8,   44,  8,   0,   0,   0,   0,   0,   0,   0,   0,   44,  8,   0,   0,
    44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,
    8,   44,  8,   44,  8,   44,  8,   44,  63,  44,  8,   44,  8,   44,  8,
    44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,  8,   44,
    8,   44,  8,   44,  8,   44,  8,   45,  8,   45,  8,   45,  8,   45,  8,
    45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   45,  8,   45,  8,
    45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,
    8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,
    45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,
    8,   45,  8,   0,   0,   0,   0,   0,   0,   0,   0,   45,  8,   0,   0,
    45,  8,   45,  8,   45,  64,  45,  8,   45,  8,   45,  8,   45,  8,   45,
    8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,
    45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,  8,   45,
    8,   45,  8,   45,  8,   45,  8,   46,  8,   46,  8,   46,  8,   46,  8,
    46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   46,  8,   46,  8,
    46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,
    8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,
    46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,
    8,   46,  8,   0,   0,   0,   0,   0,   0,   0,   0,   46,  8,   0,   0,
    46,  8,   46,  8,   46,  8,   46,  65,  46,  8,   46,  8,   46,  8,   46,
    8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,
    46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,  8,   46,
    8,   46,  8,   46,  8,   46,  8,   47,  8,   47,  8,   47,  8,   47,  8,
    47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   47,  8,   47,  8,
    47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,
    8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,
    47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,
    8,   47,  8,   0,   0,   0,   0,   0,   0,   0,   0,   47,  8,   0,   0,
    47,  8,   47,  8,   47,  8,   47,  8,   47,  66,  47,  8,   47,  8,   47,
    8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,
    47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,  8,   47,
    8,   47,  8,   47,  8,   47,  8,   48,  8,   48,  8,   48,  8,   48,  8,
    48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   48,  8,   48,  8,
    48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,
    8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,
    48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,
    8,   48,  8,   0,   0,   0,   0,   0,   0,   0,   0,   48,  8,   0,   0,
    48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,
    8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,
    48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,  8,   48,
    8,   48,  8,   48,  8,   48,  8,   49,  8,   49,  8,   49,  8,   49,  8,
    49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   49,  8,   49,  8,
    49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,
    8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,
    49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,
    8,   49,  8,   0,   0,   0,   0,   0,   0,   0,   0,   49,  8,   0,   0,
    49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,
    8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,
    49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,  8,   49,
    8,   49,  8,   49,  8,   49,  8,   50,  8,   50,  8,   50,  8,   50,  8,
    50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   50,  8,   50,  8,
    50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,
    8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,
    50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,
    8,   50,  8,   0,   0,   0,   0,   0,   0,   0,   0,   50,  8,   0,   0,
    50,  8,   50,  8,   50,  8,   50,  67,  50,  8,   50,  8,   50,  8,   50,
    8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,
    50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,  8,   50,
    8,   50,  8,   50,  8,   50,  8,   51,  8,   51,  8,   51,  8,   51,  8,
    51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   51,  8,   51,  8,
    51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,
    8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,
    51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,
    8,   51,  8,   0,   0,   0,   0,   0,   0,   0,   0,   51,  8,   0,   0,
    51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,
    8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,   51,  8,
    51,  8,   51,  8,   51,  8,   51,  8,   51,  68,  51,  8,   51,  8,   51,
    8,   51,  8,   51,  8,   51,  8,   52,  8,   52,  8,   52,  8,   52,  8,
    52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   52,  8,   52,  8,
    52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,
    8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,
    52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,
    8,   52,  8,   0,   0,   0,   0,   0,   0,   0,   0,   52,  8,   0,   0,
    52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,
    8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,   52,  8,
    52,  8,   52,  8,   52,  8,   52,  69,  52,  8,   52,  8,   52,  8,   52,
    8,   52,  8,   52,  8,   52,  8,   53,  8,   53,  8,   53,  8,   53,  8,
    53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   53,  8,   53,  8,
    53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,
    8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,
    53,  70,  53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,
    8,   53,  8,   0,   0,   0,   0,   0,   0,   0,   0,   53,  8,   0,   0,
    53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,
    8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,
    53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,  8,   53,
    8,   53,  8,   53,  8,   53,  8,   54,  8,   54,  8,   54,  8,   54,  8,
    54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   54,  71,  54,  8,
    54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,
    8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,
    54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,
    8,   54,  8,   0,   0,   0,   0,   0,   0,   0,   0,   54,  8,   0,   0,
    54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,
    8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,
    54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,  8,   54,
    8,   54,  8,   54,  8,   54,  8,   55,  8,   55,  8,   55,  8,   55,  8,
    55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   55,  72,  55,  8,
    55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,
    8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,
    55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,
    8,   55,  8,   0,   0,   0,   0,   0,   0,   0,   0,   55,  8,   0,   0,
    55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,
    8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,
    55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,  8,   55,
    8,   55,  8,   55,  8,   55,  8,   56,  8,   56,  8,   56,  8,   56,  8,
    56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   56,  8,   56,  8,
    56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,
    8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,
    56,  8,   56,  8,   56,  8,   56,  73,  56,  8,   56,  8,   56,  8,   56,
    8,   56,  8,   0,   0,   0,   0,   0,   0,   0,   0,   56,  8,   0,   0,
    56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,
    8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,
    56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,  8,   56,
    8,   56,  8,   56,  8,   56,  8,   57,  8,   57,  8,   57,  8,   57,  8,
    57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   57,  8,   57,  8,
    57,  8,   57,  8,   57,  74,  57,  8,   57,  8,   57,  8,   57,  8,   57,
    8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,
    57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,
    8,   57,  8,   0,   0,   0,   0,   0,   0,   0,   0,   57,  8,   0,   0,
    57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,
    8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,
    57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,  8,   57,
    8,   57,  8,   57,  8,   57,  8,   58,  8,   58,  8,   58,  8,   58,  8,
    58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   58,  8,   58,  8,
    58,  8,   58,  8,   58,  75,  58,  8,   58,  8,   58,  8,   58,  8,   58,
    8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,
    58,  8,   58,  8,   58,  76,  58,  8,   58,  8,   58,  8,   58,  8,   58,
    8,   58,  8,   0,   0,   0,   0,   0,   0,   0,   0,   58,  8,   0,   0,
    58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,
    8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,
    58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,  8,   58,
    8,   58,  8,   58,  8,   58,  8,   59,  8,   59,  8,   59,  8,   59,  8,
    59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   59,  8,   59,  8,
    59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,
    8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,
    59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,
    8,   59,  8,   0,   0,   0,   0,   0,   0,   0,   0,   59,  8,   0,   0,
    59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,
    8,   59,  77,  59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,
    59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,  8,   59,
    8,   59,  8,   59,  8,   59,  8,   60,  8,   60,  8,   60,  8,   60,  8,
    60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   60,  8,   60,  8,
    60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,
    8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,
    60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,
    8,   60,  8,   0,   0,   0,   0,   0,   0,   0,   0,   60,  8,   0,   0,
    60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,
    8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,
    60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  8,   60,  78,  60,
    8,   60,  8,   60,  8,   60,  8,   61,  8,   61,  8,   61,  8,   61,  8,
    61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   61,  8,   61,  8,
    61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,
    8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,
    61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,
    8,   61,  8,   0,   0,   0,   0,   0,   0,   0,   0,   61,  8,   0,   0,
    61,  79,  61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,
    8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,
    61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,  8,   61,
    8,   61,  8,   61,  8,   61,  8,   62,  8,   62,  8,   62,  8,   62,  8,
    62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   62,  8,   62,  8,
    62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,
    8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,
    62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,
    8,   62,  8,   0,   0,   0,   0,   0,   0,   0,   0,   62,  8,   0,   0,
    62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,
    8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,
    62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,  8,   62,
    8,   62,  8,   62,  8,   62,  8,   63,  8,   63,  8,   63,  8,   63,  8,
    63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   63,  8,   63,  8,
    63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,
    8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,
    63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,
    8,   63,  8,   0,   0,   0,   0,   0,   0,   0,   0,   63,  8,   0,   0,
    63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,
    8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  80,
    63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,  8,   63,
    8,   63,  8,   63,  8,   63,  8,   64,  8,   64,  8,   64,  8,   64,  8,
    64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   64,  8,   64,  8,
    64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,
    8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,
    64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,
    8,   64,  8,   0,   0,   0,   0,   0,   0,   0,   0,   64,  8,   0,   0,
    64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,
    8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,   64,  8,
    64,  8,   64,  8,   64,  8,   64,  8,   64,  81,  64,  8,   64,  8,   64,
    8,   64,  8,   64,  8,   64,  8,   65,  8,   65,  8,   65,  8,   65,  8,
    65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   65,  8,   65,  8,
    65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,
    8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,
    65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,
    8,   65,  8,   0,   0,   0,   0,   0,   0,   0,   0,   65,  8,   0,   0,
    65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,
    8,   65,  8,   65,  8,   65,  8,   65,  82,  65,  8,   65,  8,   65,  8,
    65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,  8,   65,
    8,   65,  8,   65,  8,   65,  8,   66,  8,   66,  8,   66,  8,   66,  8,
    66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   66,  8,   66,  8,
    66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,
    8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,
    66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,
    8,   66,  8,   0,   0,   0,   0,   0,   0,   0,   0,   66,  8,   0,   0,
    66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,
    8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,
    66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,  8,   66,
    8,   66,  8,   66,  8,   66,  8,   67,  8,   67,  8,   67,  8,   67,  8,
    67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   67,  8,   67,  8,
    67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,
    8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,
    67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,
    8,   67,  8,   0,   0,   0,   0,   0,   0,   0,   0,   67,  8,   0,   0,
    67,  8,   67,  8,   67,  8,   67,  8,   67,  83,  67,  8,   67,  8,   67,
    8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,
    67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,  8,   67,
    8,   67,  8,   67,  8,   67,  8,   68,  8,   68,  8,   68,  8,   68,  8,
    68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   68,  8,   68,  8,
    68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,
    8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,
    68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,
    8,   68,  8,   0,   0,   0,   0,   0,   0,   0,   0,   68,  8,   0,   0,
    68,  8,   68,  8,   68,  8,   68,  8,   68,  84,  68,  8,   68,  8,   68,
    8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,
    68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,  8,   68,
    8,   68,  8,   68,  8,   68,  8,   69,  8,   69,  8,   69,  8,   69,  8,
    69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   69,  8,   69,  8,
    69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,
    8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,
    69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,
    8,   69,  8,   0,   0,   0,   0,   0,   0,   0,   0,   69,  8,   0,   0,
    69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,
    8,   69,  85,  69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,
    69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,  8,   69,
    8,   69,  8,   69,  8,   69,  8,   70,  8,   70,  8,   70,  8,   70,  8,
    70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   70,  8,   70,  8,
    70,  8,   70,  8,   70,  86,  70,  8,   70,  8,   70,  8,   70,  8,   70,
    8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,
    70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,
    8,   70,  8,   0,   0,   0,   0,   0,   0,   0,   0,   70,  8,   0,   0,
    70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,
    8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,
    70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,  8,   70,
    8,   70,  8,   70,  8,   70,  8,   71,  8,   71,  8,   71,  8,   71,  8,
    71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   71,  8,   71,  8,
    71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  87,  71,
    8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,
    71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,
    8,   71,  8,   0,   0,   0,   0,   0,   0,   0,   0,   71,  8,   0,   0,
    71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,
    8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,
    71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,  8,   71,
    8,   71,  8,   71,  8,   71,  8,   72,  8,   72,  8,   72,  8,   72,  8,
    72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   72,  8,   72,  8,
    72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,
    8,   72,  8,   72,  8,   72,  8,   72,  88,  72,  8,   72,  8,   72,  8,
    72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,
    8,   72,  8,   0,   0,   0,   0,   0,   0,   0,   0,   72,  8,   0,   0,
    72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,
    8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,
    72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,  8,   72,
    8,   72,  8,   72,  8,   72,  8,   73,  8,   73,  8,   73,  8,   73,  8,
    73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   73,  8,   73,  8,
    73,  8,   73,  8,   73,  89,  73,  8,   73,  8,   73,  8,   73,  8,   73,
    8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,
    73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,
    8,   73,  8,   0,   0,   0,   0,   0,   0,   0,   0,   73,  8,   0,   0,
    73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,
    8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,
    73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,  8,   73,
    8,   73,  8,   73,  8,   73,  8,   74,  8,   74,  8,   74,  8,   74,  8,
    74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   74,  8,   74,  8,
    74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,
    90,  74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,
    74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,
    8,   74,  8,   0,   0,   0,   0,   0,   0,   0,   0,   74,  8,   0,   0,
    74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,
    8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,
    74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,  8,   74,
    8,   74,  8,   74,  8,   74,  8,   75,  8,   75,  8,   75,  8,   75,  8,
    75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   75,  8,   75,  8,
    75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,
    8,   75,  8,   75,  8,   75,  8,   75,  91,  75,  8,   75,  8,   75,  8,
    75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,
    8,   75,  8,   0,   0,   0,   0,   0,   0,   0,   0,   75,  8,   0,   0,
    75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,
    8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,
    75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,  8,   75,
    8,   75,  8,   75,  8,   75,  8,   76,  8,   76,  8,   76,  8,   76,  8,
    76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   76,  92,  76,  8,
    76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,
    8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,
    76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,
    8,   76,  8,   0,   0,   0,   0,   0,   0,   0,   0,   76,  8,   0,   0,
    76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,
    8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,
    76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,  8,   76,
    8,   76,  8,   76,  8,   76,  8,   77,  8,   77,  8,   77,  8,   77,  8,
    77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   77,  8,   77,  8,
    77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,
    8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,
    77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,
    8,   77,  8,   0,   0,   0,   0,   0,   0,   0,   0,   77,  8,   0,   0,
    77,  8,   77,  93,  77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,
    8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,
    77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,  8,   77,
    8,   77,  8,   77,  8,   77,  8,   78,  8,   78,  8,   78,  8,   78,  8,
    78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   78,  8,   78,  8,
    78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,
    8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,
    78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,
    8,   78,  8,   0,   0,   0,   0,   0,   0,   0,   0,   78,  8,   0,   0,
    78,  8,   78,  8,   78,  8,   78,  8,   78,  94,  78,  8,   78,  8,   78,
    8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,
    78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,  8,   78,
    8,   78,  8,   78,  8,   78,  8,   79,  8,   79,  8,   79,  8,   79,  8,
    79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   79,  8,   79,  8,
    79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,
    8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,
    79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,
    8,   79,  8,   0,   0,   0,   0,   0,   0,   0,   0,   79,  8,   0,   0,
    79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,
    8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,   79,  8,
    79,  8,   79,  8,   79,  8,   79,  8,   79,  95,  79,  8,   79,  8,   79,
    8,   79,  8,   79,  8,   79,  8,   80,  8,   80,  8,   80,  8,   80,  8,
    80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   80,  8,   80,  8,
    80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,
    8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,
    80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,
    8,   80,  8,   0,   0,   0,   0,   0,   0,   0,   0,   80,  8,   0,   0,
    80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,
    8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,
    80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,  8,   80,
    96,  80,  8,   80,  8,   80,  8,   81,  8,   81,  8,   81,  8,   81,  8,
    81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   81,  8,   81,  8,
    81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,
    8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,
    81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,
    8,   81,  8,   0,   0,   0,   0,   0,   0,   0,   0,   81,  8,   0,   0,
    81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,
    8,   81,  97,  81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,
    81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,  8,   81,
    8,   81,  8,   81,  8,   81,  8,   82,  8,   82,  8,   82,  8,   82,  8,
    82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   82,  8,   82,  8,
    82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,
    8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,
    82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,
    8,   82,  8,   0,   0,   0,   0,   0,   0,   0,   0,   82,  8,   0,   0,
    82,  8,   82,  8,   82,  8,   82,  8,   82,  98,  82,  8,   82,  8,   82,
    8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,
    82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,  8,   82,
    8,   82,  8,   82,  8,   82,  8,   83,  8,   83,  8,   83,  8,   83,  8,
    83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   83,  8,   83,  8,
    83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,
    8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,
    83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,
    8,   83,  8,   0,   0,   0,   0,   0,   0,   0,   0,   83,  8,   0,   0,
    83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,
    8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,   83,  8,
    83,  8,   83,  8,   83,  99,  83,  8,   83,  8,   83,  8,   83,  8,   83,
    8,   83,  8,   83,  8,   83,  8,   84,  8,   84,  8,   84,  8,   84,  8,
    84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   84,  8,   84,  8,
    84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,
    8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,
    84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,
    8,   84,  8,   0,   0,   0,   0,   0,   0,   0,   0,   84,  8,   0,   0,
    84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,
    8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,   84,  8,
    84,  8,   84,  8,   84,  8,   84,  100, 84,  8,   84,  8,   84,  8,   84,
    8,   84,  8,   84,  8,   84,  8,   85,  8,   85,  8,   85,  8,   85,  8,
    85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   85,  8,   85,  8,
    85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,
    8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,
    85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,
    8,   85,  8,   0,   0,   0,   0,   0,   0,   0,   0,   85,  8,   0,   0,
    85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,
    8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  101,
    85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,  8,   85,
    8,   85,  8,   85,  8,   85,  8,   86,  8,   86,  8,   86,  8,   86,  8,
    86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   86,  102, 86,  8,
    86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,
    8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,
    86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,
    8,   86,  8,   0,   0,   0,   0,   0,   0,   0,   0,   86,  8,   0,   0,
    86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,
    8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,
    86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,  8,   86,
    8,   86,  8,   86,  8,   86,  8,   87,  8,   87,  8,   87,  8,   87,  8,
    87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   87,  8,   87,  8,
    87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,
    8,   87,  8,   87,  103, 87,  8,   87,  8,   87,  8,   87,  8,   87,  8,
    87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,
    8,   87,  8,   0,   0,   0,   0,   0,   0,   0,   0,   87,  8,   0,   0,
    87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,
    8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,
    87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,  8,   87,
    8,   87,  8,   87,  8,   87,  8,   88,  8,   88,  8,   88,  8,   88,  8,
    88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   88,  8,   88,  8,
    88,  8,   88,  104, 88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,
    8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,
    88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,
    8,   88,  8,   0,   0,   0,   0,   0,   0,   0,   0,   88,  8,   0,   0,
    88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,
    8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,
    88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,  8,   88,
    8,   88,  8,   88,  8,   88,  8,   89,  8,   89,  8,   89,  8,   89,  8,
    89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   89,  8,   89,  8,
    89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,
    8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,
    89,  8,   89,  8,   89,  8,   89,  105, 89,  8,   89,  8,   89,  8,   89,
    8,   89,  8,   0,   0,   0,   0,   0,   0,   0,   0,   89,  8,   0,   0,
    89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,
    8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,
    89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,  8,   89,
    8,   89,  8,   89,  8,   89,  8,   90,  8,   90,  8,   90,  8,   90,  8,
    90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   90,  8,   90,  8,
    90,  8,   90,  8,   90,  106, 90,  8,   90,  8,   90,  8,   90,  8,   90,
    8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,
    90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,
    8,   90,  8,   0,   0,   0,   0,   0,   0,   0,   0,   90,  8,   0,   0,
    90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,
    8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,
    90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,  8,   90,
    8,   90,  8,   90,  8,   90,  8,   91,  8,   91,  8,   91,  8,   91,  8,
    91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   91,  8,   91,  8,
    91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,
    8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,
    91,  8,   91,  8,   91,  107, 91,  8,   91,  8,   91,  8,   91,  8,   91,
    8,   91,  8,   0,   0,   0,   0,   0,   0,   0,   0,   91,  8,   0,   0,
    91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,
    8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,
    91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,  8,   91,
    8,   91,  8,   91,  8,   91,  8,   92,  8,   92,  8,   92,  8,   92,  8,
    92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   92,  8,   92,  8,
    92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,
    8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,
    92,  108, 92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,
    8,   92,  8,   0,   0,   0,   0,   0,   0,   0,   0,   92,  8,   0,   0,
    92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,
    8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,
    92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,  8,   92,
    8,   92,  8,   92,  8,   92,  8,   93,  8,   93,  8,   93,  8,   93,  8,
    93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   93,  8,   93,  8,
    93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,
    8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,
    93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,
    8,   93,  8,   0,   0,   0,   0,   0,   0,   0,   0,   93,  8,   0,   0,
    93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,
    8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  8,
    93,  8,   93,  8,   93,  8,   93,  8,   93,  8,   93,  109, 93,  8,   93,
    8,   93,  8,   93,  8,   93,  8,   94,  8,   94,  8,   94,  8,   94,  8,
    94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   94,  8,   94,  8,
    94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,
    8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,
    94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,
    8,   94,  8,   0,   0,   0,   0,   0,   0,   0,   0,   94,  8,   0,   0,
    94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,
    8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,   94,  8,
    94,  8,   94,  8,   94,  110, 94,  8,   94,  8,   94,  8,   94,  8,   94,
    8,   94,  8,   94,  8,   94,  8,   95,  8,   95,  8,   95,  8,   95,  8,
    95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   95,  8,   95,  8,
    95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,
    8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,
    95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,
    8,   95,  8,   0,   0,   0,   0,   0,   0,   0,   0,   95,  8,   0,   0,
    95,  8,   95,  8,   95,  111, 95,  8,   95,  8,   95,  8,   95,  8,   95,
    8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,
    95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,  8,   95,
    8,   95,  8,   95,  8,   95,  8,   96,  8,   96,  8,   96,  8,   96,  8,
    96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   96,  8,   96,  8,
    96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,
    8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,
    96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,
    8,   96,  8,   0,   0,   0,   0,   0,   0,   0,   0,   96,  8,   0,   0,
    96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,
    8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,
    96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,  8,   96,
    8,   96,  8,   96,  8,   96,  8,   97,  8,   97,  8,   97,  8,   97,  8,
    97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   97,  8,   97,  8,
    97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,
    8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,
    97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,
    8,   97,  8,   0,   0,   0,   0,   0,   0,   0,   0,   97,  8,   0,   0,
    97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,
    8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  112,
    97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,  8,   97,
    8,   97,  8,   97,  8,   97,  8,   98,  8,   98,  8,   98,  8,   98,  8,
    98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   98,  8,   98,  8,
    98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,
    8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,
    98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,
    8,   98,  8,   0,   0,   0,   0,   0,   0,   0,   0,   98,  8,   0,   0,
    98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,
    8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,   98,  8,
    98,  8,   98,  8,   98,  113, 98,  8,   98,  8,   98,  8,   98,  8,   98,
    8,   98,  8,   98,  8,   98,  8,   99,  8,   99,  8,   99,  8,   99,  8,
    99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   99,  8,   99,  8,
    99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,
    8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,
    99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,
    8,   99,  8,   0,   0,   0,   0,   0,   0,   0,   0,   99,  114, 0,   0,
    99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,
    8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,
    99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,  8,   99,
    8,   99,  8,   99,  8,   99,  8,   100, 8,   100, 8,   100, 8,   100, 8,
    100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   100, 8,   100, 8,
    100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100,
    8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,
    100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100,
    8,   100, 8,   0,   0,   0,   0,   0,   0,   0,   0,   100, 8,   0,   0,
    100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100,
    8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,
    100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100, 8,   100,
    8,   100, 8,   100, 8,   100, 8,   101, 8,   101, 8,   101, 8,   101, 8,
    101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   101, 8,   101, 8,
    101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101,
    8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,
    101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101,
    8,   101, 8,   0,   0,   0,   0,   0,   0,   0,   0,   101, 8,   0,   0,
    101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101,
    8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 115, 101, 8,
    101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101, 8,   101,
    8,   101, 8,   101, 8,   101, 8,   102, 8,   102, 8,   102, 8,   102, 8,
    102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   102, 8,   102, 8,
    102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102,
    8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,
    102, 8,   102, 8,   102, 116, 102, 8,   102, 8,   102, 8,   102, 8,   102,
    8,   102, 8,   0,   0,   0,   0,   0,   0,   0,   0,   102, 8,   0,   0,
    102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102,
    8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,
    102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102, 8,   102,
    8,   102, 8,   102, 8,   102, 8,   103, 8,   103, 8,   103, 8,   103, 8,
    103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   103, 8,   103, 8,
    103, 8,   103, 8,   103, 117, 103, 8,   103, 8,   103, 8,   103, 8,   103,
    8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,
    103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103,
    8,   103, 8,   0,   0,   0,   0,   0,   0,   0,   0,   103, 8,   0,   0,
    103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103,
    8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,
    103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103, 8,   103,
    8,   103, 8,   103, 8,   103, 8,   104, 8,   104, 8,   104, 8,   104, 8,
    104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   104, 8,   104, 8,
    104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104,
    8,   104, 8,   104, 118, 104, 8,   104, 8,   104, 8,   104, 8,   104, 8,
    104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104,
    8,   104, 8,   0,   0,   0,   0,   0,   0,   0,   0,   104, 8,   0,   0,
    104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104,
    8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,
    104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104, 8,   104,
    8,   104, 8,   104, 8,   104, 8,   105, 8,   105, 8,   105, 8,   105, 8,
    105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   105, 8,   105, 8,
    105, 8,   105, 8,   105, 119, 105, 8,   105, 8,   105, 8,   105, 8,   105,
    8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,
    105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105,
    8,   105, 8,   0,   0,   0,   0,   0,   0,   0,   0,   105, 8,   0,   0,
    105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105,
    8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,
    105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105, 8,   105,
    8,   105, 8,   105, 8,   105, 8,   106, 8,   106, 8,   106, 8,   106, 8,
    106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   106, 8,   106, 8,
    106, 120, 106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106,
    8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,
    106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106,
    8,   106, 8,   0,   0,   0,   0,   0,   0,   0,   0,   106, 8,   0,   0,
    106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106,
    8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,
    106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106, 8,   106,
    8,   106, 8,   106, 8,   106, 8,   107, 8,   107, 8,   107, 8,   107, 8,
    107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   107, 8,   107, 8,
    107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107,
    8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,
    107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107,
    8,   107, 8,   0,   0,   0,   0,   0,   0,   0,   0,   107, 8,   0,   0,
    107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107,
    8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,
    107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107, 8,   107,
    8,   107, 8,   107, 8,   107, 8,   108, 8,   108, 8,   108, 8,   108, 8,
    108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   108, 8,   108, 8,
    108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108,
    8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,
    108, 8,   108, 8,   108, 121, 108, 8,   108, 8,   108, 8,   108, 8,   108,
    8,   108, 8,   0,   0,   0,   0,   0,   0,   0,   0,   108, 8,   0,   0,
    108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108,
    8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,
    108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108, 8,   108,
    8,   108, 8,   108, 8,   108, 8,   109, 8,   109, 8,   109, 8,   109, 8,
    109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   109, 8,   109, 8,
    109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109,
    8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,
    109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109,
    8,   109, 8,   0,   0,   0,   0,   0,   0,   0,   0,   109, 8,   0,   0,
    109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109,
    8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,   109, 8,
    109, 8,   109, 8,   109, 8,   109, 8,   109, 122, 109, 8,   109, 8,   109,
    8,   109, 8,   109, 8,   109, 8,   110, 8,   110, 8,   110, 8,   110, 8,
    110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   110, 8,   110, 8,
    110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110,
    8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,
    110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110,
    8,   110, 8,   0,   0,   0,   0,   0,   0,   0,   0,   110, 8,   0,   0,
    110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110,
    8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,
    110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110, 8,   110,
    8,   110, 8,   110, 8,   110, 8,   111, 8,   111, 8,   111, 8,   111, 8,
    111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   111, 8,   111, 8,
    111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111,
    8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,
    111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111,
    8,   111, 8,   0,   0,   0,   0,   0,   0,   0,   0,   111, 8,   0,   0,
    111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111,
    123, 111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,
    111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111, 8,   111,
    8,   111, 8,   111, 8,   111, 8,   112, 8,   112, 8,   112, 8,   112, 8,
    112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   112, 8,   112, 8,
    112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112,
    8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,
    112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112,
    8,   112, 8,   0,   0,   0,   0,   0,   0,   0,   0,   112, 8,   0,   0,
    112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112,
    8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 124, 112, 8,
    112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112, 8,   112,
    8,   112, 8,   112, 8,   112, 8,   113, 8,   113, 8,   113, 8,   113, 8,
    113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   113, 8,   113, 8,
    113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113,
    8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,
    113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113,
    8,   113, 8,   0,   0,   0,   0,   0,   0,   0,   0,   113, 125, 0,   0,
    113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113,
    8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,
    113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113, 8,   113,
    8,   113, 8,   113, 8,   113, 8,   114, 8,   114, 8,   114, 8,   114, 8,
    114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   114, 8,   114, 8,
    114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114,
    8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,
    114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114,
    8,   114, 8,   0,   0,   0,   0,   0,   0,   0,   0,   114, 8,   0,   0,
    114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114,
    8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,
    114, 126, 114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114, 8,   114,
    8,   114, 8,   114, 8,   114, 8,   115, 127, 0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   115, 127, 0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   115, 8,   115, 8,   115,
    8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   115,
    8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,
    115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115,
    8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,
    115, 8,   115, 8,   115, 8,   0,   0,   0,   0,   0,   0,   0,   0,   115,
    8,   0,   0,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,
    115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115,
    8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   115, 8,
    115, 8,   115, 8,   115, 8,   115, 8,   115, 8,   116, 8,   116, 8,   116,
    8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   116,
    8,   116, 8,   116, 8,   116, 8,   116, 128, 116, 8,   116, 8,   116, 8,
    116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116,
    8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,
    116, 8,   116, 8,   116, 8,   0,   0,   0,   0,   0,   0,   0,   0,   116,
    8,   0,   0,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,
    116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116,
    8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   116, 8,
    116, 8,   116, 8,   116, 8,   116, 8,   116, 8,   117, 8,   117, 8,   117,
    8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   117,
    8,   117, 8,   117, 8,   117, 129, 117, 8,   117, 8,   117, 8,   117, 8,
    117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117,
    8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,
    117, 8,   117, 8,   117, 8,   0,   0,   0,   0,   0,   0,   0,   0,   117,
    8,   0,   0,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,
    117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117,
    8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   117, 8,
    117, 8,   117, 8,   117, 8,   117, 8,   117, 8,   118, 8,   118, 8,   118,
    8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   118,
    8,   118, 8,   118, 8,   118, 8,   118, 130, 118, 8,   118, 8,   118, 8,
    118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118,
    8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,
    118, 8,   118, 8,   118, 8,   0,   0,   0,   0,   0,   0,   0,   0,   118,
    8,   0,   0,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,
    118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118,
    8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   118, 8,
    118, 8,   118, 8,   118, 8,   118, 8,   118, 8,   119, 8,   119, 8,   119,
    8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   119,
    8,   119, 8,   119, 8,   119, 131, 119, 8,   119, 8,   119, 8,   119, 8,
    119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119,
    8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,
    119, 8,   119, 8,   119, 8,   0,   0,   0,   0,   0,   0,   0,   0,   119,
    8,   0,   0,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,
    119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119,
    8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   119, 8,
    119, 8,   119, 8,   119, 8,   119, 8,   119, 8,   120, 8,   120, 8,   120,
    8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   120,
    8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,
    120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120,
    8,   120, 8,   120, 8,   120, 8,   120, 132, 120, 8,   120, 8,   120, 8,
    120, 8,   120, 8,   120, 8,   0,   0,   0,   0,   0,   0,   0,   0,   120,
    8,   0,   0,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,
    120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120,
    8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   120, 8,
    120, 8,   120, 8,   120, 8,   120, 8,   120, 8,   121, 8,   121, 8,   121,
    8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   121,
    8,   121, 8,   121, 8,   121, 8,   121, 133, 121, 8,   121, 8,   121, 8,
    121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121,
    8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,
    121, 8,   121, 8,   121, 8,   0,   0,   0,   0,   0,   0,   0,   0,   121,
    8,   0,   0,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,
    121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121,
    8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   121, 8,
    121, 8,   121, 8,   121, 8,   121, 8,   121, 8,   122, 8,   122, 8,   122,
    8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   122,
    8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,
    122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122,
    8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,
    122, 8,   122, 8,   122, 8,   0,   0,   0,   0,   0,   0,   0,   0,   122,
    8,   0,   0,   122, 8,   122, 8,   122, 8,   122, 8,   122, 134, 122, 8,
    122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122,
    8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   122, 8,
    122, 8,   122, 8,   122, 8,   122, 8,   122, 8,   123, 8,   123, 8,   123,
    8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   123,
    8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,
    123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123,
    8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,
    123, 8,   123, 8,   123, 8,   0,   0,   0,   0,   0,   0,   0,   0,   123,
    8,   0,   0,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,
    123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123,
    8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   123, 8,
    123, 8,   123, 8,   123, 8,   123, 8,   123, 8,   124, 8,   124, 8,   124,
    8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   124,
    8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,
    124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124,
    8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,
    124, 8,   124, 8,   124, 8,   0,   0,   0,   0,   0,   0,   0,   0,   124,
    8,   0,   0,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,
    124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   124,
    8,   124, 8,   124, 8,   124, 8,   124, 8,   124, 135, 124, 8,   124, 8,
    124, 8,   124, 8,   124, 8,   124, 8,   124, 8,   125, 8,   125, 8,   125,
    8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   125,
    8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,
    125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125,
    8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,
    125, 8,   125, 8,   125, 8,   0,   0,   0,   0,   0,   0,   0,   0,   125,
    8,   0,   0,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,
    125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   125,
    8,   125, 8,   125, 136, 125, 8,   125, 8,   125, 8,   125, 8,   125, 8,
    125, 8,   125, 8,   125, 8,   125, 8,   125, 8,   126, 8,   126, 8,   126,
    8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   126,
    8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,
    126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126,
    8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,
    126, 8,   126, 8,   126, 8,   0,   0,   0,   0,   0,   0,   0,   0,   126,
    8,   0,   0,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,
    126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126,
    8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   126, 137, 126, 8,
    126, 8,   126, 8,   126, 8,   126, 8,   126, 8,   127, 127, 0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 127, 0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 138,
    127, 138, 127, 138, 127, 138, 127, 138, 127, 138, 127, 138, 127, 138, 127,
    138, 127, 138, 128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,
    128, 8,   128, 8,   128, 8,   128, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   128, 8,   128, 8,   128, 8,   128, 139,
    128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128,
    8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,
    128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   128, 8,   0,   0,   128, 8,   128, 8,
    128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128,
    8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,
    128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128, 8,   128,
    8,   128, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,
    129, 8,   129, 8,   129, 8,   129, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   129, 8,   129, 8,   129, 8,   129, 8,
    129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129,
    8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,
    129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   129, 8,   0,   0,   129, 8,   129, 8,
    129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129,
    8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,
    129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129, 8,   129,
    8,   129, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,
    130, 8,   130, 8,   130, 8,   130, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   130, 8,   130, 8,   130, 8,   130, 140,
    130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130,
    8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,
    130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   130, 8,   0,   0,   130, 8,   130, 8,
    130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130,
    8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,
    130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130, 8,   130,
    8,   130, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,
    131, 8,   131, 8,   131, 8,   131, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   131, 8,   131, 8,   131, 8,   131, 8,
    131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131,
    8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,
    131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   131, 8,   0,   0,   131, 8,   131, 8,
    131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131,
    8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,
    131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131, 8,   131,
    8,   131, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,
    132, 8,   132, 8,   132, 8,   132, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   132, 8,   132, 8,   132, 8,   132, 8,
    132, 141, 132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132,
    8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,
    132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   132, 8,   0,   0,   132, 8,   132, 8,
    132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132,
    8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,
    132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132, 8,   132,
    8,   132, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,
    133, 8,   133, 8,   133, 8,   133, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   133, 8,   133, 8,   133, 8,   133, 142,
    133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133,
    8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,
    133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   133, 8,   0,   0,   133, 8,   133, 8,
    133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133,
    8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,
    133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133, 8,   133,
    8,   133, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,
    134, 8,   134, 8,   134, 8,   134, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   134, 8,   134, 8,   134, 8,   134, 8,
    134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134,
    8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,
    134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   134, 8,   0,   0,   134, 8,   134, 8,
    134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134,
    8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134, 8,
    134, 8,   134, 143, 134, 8,   134, 8,   134, 8,   134, 8,   134, 8,   134,
    8,   134, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,
    135, 8,   135, 8,   135, 8,   135, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   135, 8,   135, 8,   135, 8,   135, 8,
    135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135,
    8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,
    135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   135, 8,   0,   0,   135, 8,   135, 8,
    135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135,
    8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,
    135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135, 8,   135,
    8,   135, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,
    136, 8,   136, 8,   136, 8,   136, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   136, 8,   136, 8,   136, 8,   136, 8,
    136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136,
    8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,
    136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   136, 8,   0,   0,   136, 8,   136, 8,
    136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136,
    8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,   136, 8,
    136, 8,   136, 8,   136, 144, 136, 8,   136, 8,   136, 8,   136, 8,   136,
    8,   136, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,
    137, 8,   137, 8,   137, 8,   137, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   137, 8,   137, 8,   137, 8,   137, 8,
    137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137,
    8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,
    137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   137, 8,   0,   0,   137, 8,   137, 8,
    137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137,
    8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,
    137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137, 8,   137,
    145, 137, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,
    139, 8,   139, 8,   139, 8,   139, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   139, 8,   139, 8,   139, 8,   139, 8,
    139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139,
    8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,
    139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   139, 8,   0,   0,   139, 8,   139, 8,
    139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139,
    8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,
    139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139, 8,   139,
    8,   139, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,
    140, 8,   140, 8,   140, 8,   140, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   140, 8,   140, 8,   140, 8,   140, 8,
    140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140,
    8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,
    140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   140, 8,   0,   0,   140, 8,   140, 8,
    140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140,
    8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,
    140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140, 8,   140,
    8,   140, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,
    141, 8,   141, 8,   141, 8,   141, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   141, 8,   141, 8,   141, 8,   141, 146,
    141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141,
    8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,
    141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   141, 8,   0,   0,   141, 8,   141, 8,
    141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141,
    8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,
    141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141, 8,   141,
    8,   141, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,
    142, 8,   142, 8,   142, 8,   142, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   142, 8,   142, 8,   142, 8,   142, 8,
    142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142,
    8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,
    142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   142, 8,   0,   0,   142, 8,   142, 8,
    142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142,
    8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,
    142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142, 8,   142,
    8,   142, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,
    143, 8,   143, 8,   143, 8,   143, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   143, 8,   143, 8,   143, 8,   143, 8,
    143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143,
    8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,
    143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   143, 8,   0,   0,   143, 8,   143, 8,
    143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143,
    8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,
    143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143, 8,   143,
    8,   143, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,
    144, 8,   144, 8,   144, 8,   144, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   144, 8,   144, 8,   144, 8,   144, 8,
    144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144,
    8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,
    144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   144, 8,   0,   0,   144, 8,   144, 8,
    144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144,
    8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,
    144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144, 8,   144,
    147, 144, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,
    145, 8,   145, 8,   145, 8,   145, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   145, 8,   145, 8,   145, 8,   145, 8,
    145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145,
    8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,
    145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   145, 8,   0,   0,   145, 8,   145, 8,
    145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145,
    8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 148, 145, 8,
    145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145, 8,   145,
    8,   145, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,
    146, 8,   146, 8,   146, 8,   146, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   146, 8,   146, 8,   146, 8,   146, 8,
    146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146,
    8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,
    146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   146, 8,   0,   0,   146, 8,   146, 8,
    146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146,
    8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,
    146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146, 8,   146,
    8,   146, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,
    147, 8,   147, 8,   147, 8,   147, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   147, 8,   147, 8,   147, 8,   147, 8,
    147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147,
    8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,
    147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   147, 8,   0,   0,   147, 8,   147, 8,
    147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147,
    8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 149, 147, 8,
    147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147, 8,   147,
    8,   147, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,
    148, 8,   148, 8,   148, 8,   148, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   148, 8,   148, 8,   148, 8,   148, 8,
    148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148,
    8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,
    148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   148, 8,   0,   0,   148, 8,   148, 8,
    148, 8,   148, 8,   148, 150, 148, 8,   148, 8,   148, 8,   148, 8,   148,
    8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,
    148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148, 8,   148,
    8,   148, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,
    149, 8,   149, 8,   149, 8,   149, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   149, 8,   149, 8,   149, 8,   149, 8,
    149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149,
    8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,
    149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   149, 8,   0,   0,   149, 8,   149, 8,
    149, 8,   149, 8,   149, 151, 149, 8,   149, 8,   149, 8,   149, 8,   149,
    8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,
    149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149, 8,   149,
    8,   149, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,
    150, 8,   150, 8,   150, 8,   150, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   150, 8,   150, 8,   150, 8,   150, 8,
    150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150,
    8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,
    150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   150, 8,   0,   0,   150, 8,   150, 8,
    150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150,
    8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150, 8,
    150, 8,   150, 152, 150, 8,   150, 8,   150, 8,   150, 8,   150, 8,   150,
    8,   150, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,
    151, 8,   151, 8,   151, 8,   151, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   151, 8,   151, 8,   151, 8,   151, 8,
    151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151,
    8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,
    151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   151, 8,   0,   0,   151, 8,   151, 8,
    151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151,
    8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151, 8,
    151, 8,   151, 153, 151, 8,   151, 8,   151, 8,   151, 8,   151, 8,   151,
    8,   151, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,
    152, 8,   152, 8,   152, 8,   152, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   152, 8,   152, 8,   152, 8,   152, 8,
    152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152,
    8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,
    152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   152, 8,   0,   0,   152, 8,   152, 8,
    152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152,
    8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,
    152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152, 8,   152,
    8,   152, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,
    153, 8,   153, 8,   153, 8,   153, 8,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   153, 8,   153, 8,   153, 8,   153, 8,
    153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153,
    8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,
    153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   0,
    0,   0,   0,   0,   0,   0,   0,   153, 8,   0,   0,   153, 8,   153, 8,
    153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153,
    8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,
    153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153, 8,   153,
    8,   153, 8,   0,   0,   0,   0,   0,   0,   0,   0};
struct tt_trace_svf tt_trace_svec[] = {0,
                                       0,
                                       0,
                                       tt_trace_crank + 1,
                                       0,
                                       tt_trace_vstop + 1,
                                       tt_trace_crank + 0,
                                       tt_trace_svec + 1,
                                       tt_trace_vstop + 3,
                                       tt_trace_crank + 3,
                                       0,
                                       tt_trace_vstop + 5,
                                       tt_trace_crank + 0,
                                       0,
                                       tt_trace_vstop + 7,
                                       tt_trace_crank + -123,
                                       0,
                                       tt_trace_vstop + 9,
                                       tt_trace_crank + 2,
                                       0,
                                       0,
                                       tt_trace_crank + 143,
                                       0,
                                       tt_trace_vstop + 11,
                                       tt_trace_crank + 218,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 13,
                                       tt_trace_crank + 30,
                                       0,
                                       tt_trace_vstop + 16,
                                       tt_trace_crank + 293,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 18,
                                       tt_trace_crank + 368,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 21,
                                       tt_trace_crank + 443,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 24,
                                       tt_trace_crank + 518,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 27,
                                       tt_trace_crank + 593,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 30,
                                       tt_trace_crank + 668,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 33,
                                       tt_trace_crank + 743,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 36,
                                       tt_trace_crank + 818,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 39,
                                       tt_trace_crank + 893,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 42,
                                       tt_trace_crank + 968,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 45,
                                       tt_trace_crank + 0,
                                       0,
                                       tt_trace_vstop + 48,
                                       tt_trace_crank + 0,
                                       0,
                                       tt_trace_vstop + 50,
                                       tt_trace_crank + 1043,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 52,
                                       tt_trace_crank + 1118,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 55,
                                       tt_trace_crank + 1193,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 58,
                                       tt_trace_crank + 1268,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 61,
                                       tt_trace_crank + 1343,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 64,
                                       tt_trace_crank + 1418,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 67,
                                       tt_trace_crank + 1493,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 70,
                                       tt_trace_crank + 1568,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 73,
                                       tt_trace_crank + 1643,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 76,
                                       tt_trace_crank + 1718,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 79,
                                       tt_trace_crank + 1793,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 82,
                                       tt_trace_crank + 1868,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 85,
                                       tt_trace_crank + 1943,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 89,
                                       tt_trace_crank + 2018,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 92,
                                       tt_trace_crank + 2093,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 95,
                                       tt_trace_crank + 2168,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 98,
                                       tt_trace_crank + 2243,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 101,
                                       tt_trace_crank + 2318,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 104,
                                       tt_trace_crank + 2393,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 108,
                                       tt_trace_crank + 2468,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 111,
                                       tt_trace_crank + 2543,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 114,
                                       tt_trace_crank + 2618,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 117,
                                       tt_trace_crank + 2693,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 120,
                                       tt_trace_crank + 2768,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 123,
                                       tt_trace_crank + 2843,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 126,
                                       tt_trace_crank + 2918,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 129,
                                       tt_trace_crank + 2993,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 132,
                                       tt_trace_crank + 3068,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 136,
                                       tt_trace_crank + 3143,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 140,
                                       tt_trace_crank + 3218,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 143,
                                       tt_trace_crank + 3293,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 146,
                                       tt_trace_crank + 3368,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 149,
                                       tt_trace_crank + 3443,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 152,
                                       tt_trace_crank + 3518,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 155,
                                       tt_trace_crank + 3593,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 158,
                                       tt_trace_crank + 3668,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 161,
                                       tt_trace_crank + 3743,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 164,
                                       tt_trace_crank + 3818,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 167,
                                       tt_trace_crank + 3893,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 170,
                                       tt_trace_crank + 3968,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 173,
                                       tt_trace_crank + 4043,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 176,
                                       tt_trace_crank + 4118,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 180,
                                       tt_trace_crank + 4193,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 183,
                                       tt_trace_crank + 4268,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 186,
                                       tt_trace_crank + 4343,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 189,
                                       tt_trace_crank + 4418,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 193,
                                       tt_trace_crank + 4493,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 196,
                                       tt_trace_crank + 4568,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 199,
                                       tt_trace_crank + 4643,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 202,
                                       tt_trace_crank + 4718,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 205,
                                       tt_trace_crank + 4793,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 208,
                                       tt_trace_crank + 4868,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 211,
                                       tt_trace_crank + 4943,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 214,
                                       tt_trace_crank + 5018,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 217,
                                       tt_trace_crank + 5093,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 220,
                                       tt_trace_crank + 5168,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 223,
                                       tt_trace_crank + 5243,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 226,
                                       tt_trace_crank + 5318,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 229,
                                       tt_trace_crank + 5393,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 232,
                                       tt_trace_crank + 5468,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 235,
                                       tt_trace_crank + 5543,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 238,
                                       tt_trace_crank + 5618,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 241,
                                       tt_trace_crank + 5693,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 244,
                                       tt_trace_crank + 5768,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 247,
                                       tt_trace_crank + 5843,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 250,
                                       tt_trace_crank + 5918,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 253,
                                       tt_trace_crank + 5993,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 256,
                                       tt_trace_crank + 6068,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 259,
                                       tt_trace_crank + 6143,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 262,
                                       tt_trace_crank + 6218,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 265,
                                       tt_trace_crank + 6293,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 268,
                                       tt_trace_crank + 6368,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 271,
                                       tt_trace_crank + 6443,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 274,
                                       tt_trace_crank + 6518,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 277,
                                       tt_trace_crank + 6593,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 280,
                                       tt_trace_crank + 6668,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 284,
                                       tt_trace_crank + 6743,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 287,
                                       tt_trace_crank + 6818,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 290,
                                       tt_trace_crank + 6893,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 293,
                                       tt_trace_crank + 6968,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 297,
                                       tt_trace_crank + 7043,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 300,
                                       tt_trace_crank + 7118,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 303,
                                       tt_trace_crank + 7193,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 306,
                                       tt_trace_crank + 7268,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 309,
                                       tt_trace_crank + 7343,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 312,
                                       tt_trace_crank + 7418,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 315,
                                       tt_trace_crank + 7493,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 319,
                                       tt_trace_crank + 7568,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 322,
                                       tt_trace_crank + 7643,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 325,
                                       tt_trace_crank + 7718,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 329,
                                       tt_trace_crank + 7793,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 332,
                                       tt_trace_crank + 7868,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 335,
                                       tt_trace_crank + 7943,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 338,
                                       tt_trace_crank + 8057,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 341,
                                       tt_trace_crank + 8132,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 344,
                                       tt_trace_crank + 8207,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 347,
                                       tt_trace_crank + 8282,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 350,
                                       tt_trace_crank + 8357,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 353,
                                       tt_trace_crank + 8432,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 356,
                                       tt_trace_crank + 8507,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 359,
                                       tt_trace_crank + 8582,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 362,
                                       tt_trace_crank + 8657,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 365,
                                       tt_trace_crank + 8732,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 369,
                                       tt_trace_crank + 8807,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 372,
                                       tt_trace_crank + 8882,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 375,
                                       tt_trace_crank + 8996,
                                       0,
                                       0,
                                       tt_trace_crank + 9006,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 378,
                                       tt_trace_crank + 9081,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 381,
                                       tt_trace_crank + 9156,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 385,
                                       tt_trace_crank + 9231,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 388,
                                       tt_trace_crank + 9306,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 392,
                                       tt_trace_crank + 9381,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 395,
                                       tt_trace_crank + 9456,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 398,
                                       tt_trace_crank + 9531,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 401,
                                       tt_trace_crank + 9606,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 405,
                                       tt_trace_crank + 9681,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 408,
                                       tt_trace_crank + 86,
                                       0,
                                       tt_trace_vstop + 411,
                                       tt_trace_crank + 9756,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 413,
                                       tt_trace_crank + 9831,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 417,
                                       tt_trace_crank + 9906,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 421,
                                       tt_trace_crank + 9981,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 424,
                                       tt_trace_crank + 10056,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 428,
                                       tt_trace_crank + 10131,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 432,
                                       tt_trace_crank + 10206,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 435,
                                       tt_trace_crank + 10281,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 438,
                                       tt_trace_crank + 10356,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 442,
                                       tt_trace_crank + 10431,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 445,
                                       tt_trace_crank + 10506,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 448,
                                       tt_trace_crank + 10581,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 451,
                                       tt_trace_crank + 10656,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 454,
                                       tt_trace_crank + 10731,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 457,
                                       tt_trace_crank + 10806,
                                       tt_trace_svec + 7,
                                       tt_trace_vstop + 461,
                                       0,
                                       0,
                                       0};
struct tt_trace_work *tt_trace_top = tt_trace_crank + 10928;
struct tt_trace_svf *tt_trace_bgin = tt_trace_svec + 1;
char tt_trace_match[] = {
    0,  1,  1,  1,  1,  1,  1,  1,  1,  9,  10, 1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  9,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  44, 1,  44, 44, 48, 48, 48, 48, 48, 48, 48, 48, 48,
    48, 44, 59, 1,  44, 1,  1,  44, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
    65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 1,  1,  1,  1,
    65, 1,  65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
    65, 65, 65, 65, 65, 65, 65, 65, 65, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  0};
char tt_trace_extra[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/*	Copyright (c) 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#pragma ident "@(#)ncform	6.7	93/06/07 SMI"

int tt_trace_lineno = 1;
#define TT_TRACE_U(x) x
#define NLSTATE tt_trace_previous = TT_TRACE_NEWLINE
char tt_trace_text[TT_TRACE_LMAX];
struct tt_trace_svf *tt_trace_lstate[TT_TRACE_LMAX], **tt_trace_lsp,
    **tt_trace_olsp;
char tt_trace_sbuf[TT_TRACE_LMAX];
char *tt_trace_sptr = tt_trace_sbuf;
int *tt_trace_fnd;
extern struct tt_trace_svf *tt_trace_estate;
int tt_trace_previous = TT_TRACE_NEWLINE;
#if defined(__cplusplus) || defined(__STDC__)
int tt_trace_look(void)
#else
tt_trace_look()
#endif
{
        register struct tt_trace_svf *tt_trace_state, **lsp;
        register struct tt_trace_work *tt_trace_t;
        struct tt_trace_svf *tt_trace_z;
        int tt_trace_ch, tt_trace_first;
        struct tt_trace_work *tt_trace_r;
#ifdef LEXDEBUG
        int debug;
#endif
        char *tt_trace_lastch;
        /* start off machines */
#ifdef LEXDEBUG
        debug = 0;
#endif
        tt_trace_first = 1;
        if (!tt_trace_morfg)
                tt_trace_lastch = tt_trace_text;
        else {
                tt_trace_morfg = 0;
                tt_trace_lastch = tt_trace_text + tt_trace_leng;
        }
        for (;;) {
                lsp = tt_trace_lstate;
                tt_trace_estate = tt_trace_state = tt_trace_bgin;
                if (tt_trace_previous == TT_TRACE_NEWLINE)
                        tt_trace_state++;
                for (;;) {
#ifdef LEXDEBUG
                        if (debug)
                                fprintf(tt_trace_out, "state %d\n",
                                        tt_trace_state - tt_trace_svec - 1);
#endif
                        tt_trace_t = tt_trace_state->tt_trace_stoff;
                        if (tt_trace_t == tt_trace_crank &&
                            !tt_trace_first) { /* may not be any transitions */
                                tt_trace_z = tt_trace_state->tt_trace_other;
                                if (tt_trace_z == 0)
                                        break;
                                if (tt_trace_z->tt_trace_stoff ==
                                    tt_trace_crank)
                                        break;
                        }
#ifndef __cplusplus
                        *tt_trace_lastch++ = tt_trace_ch = input();
#else
                        *tt_trace_lastch++ = tt_trace_ch = lex_input();
#endif
                        if (tt_trace_lastch > &tt_trace_text[TT_TRACE_LMAX]) {
                                fprintf(tt_trace_out,
                                        "Input string too long, limit %d\n",
                                        TT_TRACE_LMAX);
                                exit(1);
                        }
                        tt_trace_first = 0;
                tryagain:
#ifdef LEXDEBUG
                        if (debug) {
                                fprintf(tt_trace_out, "char ");
                                allprint(tt_trace_ch);
                                putchar('\n');
                        }
#endif
                        tt_trace_r = tt_trace_t;
                        if ((int)tt_trace_t > (int)tt_trace_crank) {
                                tt_trace_t = tt_trace_r + tt_trace_ch;
                                if (tt_trace_t <= tt_trace_top &&
                                    tt_trace_t->verify + tt_trace_svec ==
                                        tt_trace_state) {
                                        if (tt_trace_t->advance +
                                                tt_trace_svec ==
                                            TT_TRACE_LERR) /* error transitions
                                                            */
                                        {
                                                unput(*--tt_trace_lastch);
                                                break;
                                        }
                                        *lsp++ = tt_trace_state =
                                            tt_trace_t->advance + tt_trace_svec;
                                        if (lsp >
                                            &tt_trace_lstate[TT_TRACE_LMAX]) {
                                                fprintf(tt_trace_out,
                                                        "Input string too "
                                                        "long, limit %d\n",
                                                        TT_TRACE_LMAX);
                                                exit(1);
                                        }
                                        goto contin;
                                }
                        }
#ifdef TT_TRACE_OPTIM
                        else if ((int)tt_trace_t <
                                 (int)tt_trace_crank) { /* r < tt_trace_crank */
                                tt_trace_t = tt_trace_r =
                                    tt_trace_crank +
                                    (tt_trace_crank - tt_trace_t);
#ifdef LEXDEBUG
                                if (debug)
                                        fprintf(tt_trace_out,
                                                "compressed state\n");
#endif
                                tt_trace_t = tt_trace_t + tt_trace_ch;
                                if (tt_trace_t <= tt_trace_top &&
                                    tt_trace_t->verify + tt_trace_svec ==
                                        tt_trace_state) {
                                        if (tt_trace_t->advance +
                                                tt_trace_svec ==
                                            TT_TRACE_LERR) /* error transitions
                                                            */
                                        {
                                                unput(*--tt_trace_lastch);
                                                break;
                                        }
                                        *lsp++ = tt_trace_state =
                                            tt_trace_t->advance + tt_trace_svec;
                                        if (lsp >
                                            &tt_trace_lstate[TT_TRACE_LMAX]) {
                                                fprintf(tt_trace_out,
                                                        "Input string too "
                                                        "long, limit %d\n",
                                                        TT_TRACE_LMAX);
                                                exit(1);
                                        }
                                        goto contin;
                                }
                                tt_trace_t =
                                    tt_trace_r +
                                    TT_TRACE_U(tt_trace_match[tt_trace_ch]);
#ifdef LEXDEBUG
                                if (debug) {
                                        fprintf(tt_trace_out,
                                                "try fall back character ");
                                        allprint(TT_TRACE_U(
                                            tt_trace_match[tt_trace_ch]));
                                        putchar('\n');
                                }
#endif
                                if (tt_trace_t <= tt_trace_top &&
                                    tt_trace_t->verify + tt_trace_svec ==
                                        tt_trace_state) {
                                        if (tt_trace_t->advance +
                                                tt_trace_svec ==
                                            TT_TRACE_LERR) /* error transition
                                                            */
                                        {
                                                unput(*--tt_trace_lastch);
                                                break;
                                        }
                                        *lsp++ = tt_trace_state =
                                            tt_trace_t->advance + tt_trace_svec;
                                        if (lsp >
                                            &tt_trace_lstate[TT_TRACE_LMAX]) {
                                                fprintf(tt_trace_out,
                                                        "Input string too "
                                                        "long, limit %d\n",
                                                        TT_TRACE_LMAX);
                                                exit(1);
                                        }
                                        goto contin;
                                }
                        }
                        if ((tt_trace_state = tt_trace_state->tt_trace_other) &&
                            (tt_trace_t = tt_trace_state->tt_trace_stoff) !=
                                tt_trace_crank) {
#ifdef LEXDEBUG
                                if (debug)
                                        fprintf(tt_trace_out,
                                                "fall back to state %d\n",
                                                tt_trace_state - tt_trace_svec -
                                                    1);
#endif
                                goto tryagain;
                        }
#endif
                        else {
                                unput(*--tt_trace_lastch);
                                break;
                        }
                contin:
#ifdef LEXDEBUG
                        if (debug) {
                                fprintf(tt_trace_out, "state %d char ",
                                        tt_trace_state - tt_trace_svec - 1);
                                allprint(tt_trace_ch);
                                putchar('\n');
                        }
#endif
                        ;
                }
#ifdef LEXDEBUG
                if (debug) {
                        fprintf(tt_trace_out, "stopped at %d with ",
                                *(lsp - 1) - tt_trace_svec - 1);
                        allprint(tt_trace_ch);
                        putchar('\n');
                }
#endif
                while (lsp-- > tt_trace_lstate) {
                        *tt_trace_lastch-- = 0;
                        if (*lsp != 0 &&
                            (tt_trace_fnd = (*lsp)->tt_trace_stops) &&
                            *tt_trace_fnd > 0) {
                                tt_trace_olsp = lsp;
                                if (tt_trace_extra[*tt_trace_fnd]) { /* must
                                                                        backup
                                                                      */
                                        while (tt_trace_back(
                                                   (*lsp)->tt_trace_stops,
                                                   -*tt_trace_fnd) != 1 &&
                                               lsp > tt_trace_lstate) {
                                                lsp--;
                                                unput(*tt_trace_lastch--);
                                        }
                                }
                                tt_trace_previous =
                                    TT_TRACE_U(*tt_trace_lastch);
                                tt_trace_lsp = lsp;
                                tt_trace_leng =
                                    tt_trace_lastch - tt_trace_text + 1;
                                tt_trace_text[tt_trace_leng] = 0;
#ifdef LEXDEBUG
                                if (debug) {
                                        fprintf(tt_trace_out, "\nmatch ");
                                        sprint(tt_trace_text);
                                        fprintf(tt_trace_out, " action %d\n",
                                                *tt_trace_fnd);
                                }
#endif
                                return (*tt_trace_fnd++);
                        }
                        unput(*tt_trace_lastch);
                }
                if (tt_trace_text[0] == 0 /* && feof(tt_trace_in) */) {
                        tt_trace_sptr = tt_trace_sbuf;
                        return (0);
                }
#ifndef __cplusplus
                tt_trace_previous = tt_trace_text[0] = input();
                if (tt_trace_previous > 0)
                        output(tt_trace_previous);
#else
                tt_trace_previous = tt_trace_text[0] = lex_input();
                if (tt_trace_previous > 0)
                        lex_output(tt_trace_previous);
#endif
                tt_trace_lastch = tt_trace_text;
#ifdef LEXDEBUG
                if (debug)
                        putchar('\n');
#endif
        }
}
#if defined(__cplusplus) || defined(__STDC__)
int tt_trace_back(int *p, int m)
#else
tt_trace_back(p, m) int *p;
#endif
{
        if (p == 0)
                return (0);
        while (*p) {
                if (*p++ == m)
                        return (1);
        }
        return (0);
}
        /* the following are only used in the lex library */
#if defined(__cplusplus) || defined(__STDC__)
int tt_trace_input(void)
#else
tt_trace_input()
#endif
{
#ifndef __cplusplus
        return (input());
#else
        return (lex_input());
#endif
}
#if defined(__cplusplus) || defined(__STDC__)
void tt_trace_output(int c)
#else
tt_trace_output(c) int c;
#endif
{
#ifndef __cplusplus
        output(c);
#else
        lex_output(c);
#endif
}
#if defined(__cplusplus) || defined(__STDC__)
void tt_trace_unput(int c)
#else
tt_trace_unput(c) int c;
#endif
{
        unput(c);
}
