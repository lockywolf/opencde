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
/* $XConsortium: builtins.c /main/3 1995/11/01 15:50:47 rswiston $ */
/***************************************************************
 *                                                              *
 *                      AT&T - PROPRIETARY                      *
 *                                                              *
 *        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
 *                    AT&T BELL LABORATORIES                    *
 *         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
 *            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
 *                                                              *
 *          Copyright (c) 1994 AT&T Bell Laboratories           *
 *              Unpublished & Not for Publication               *
 *                     All Rights Reserved                      *
 *                                                              *
 *       The copyright notice above does not evidence any       *
 *      actual or intended publication of such source code      *
 *                                                              *
 *               This software was created by the               *
 *           Advanced Software Technology Department            *
 *                    AT&T Bell Laboratories                    *
 *                                                              *
 *               For further information contact                *
 *                    {research,attmail}!dgk                    *
 *                     dgk@research.att.com                     *
 *                   David Korn 908-582-7975                    *
 *                                                              *
 ***************************************************************/

/* : : generated by proto : : */

#line 1

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) ||            \
    defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__ "C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x) x
#define __OTORP__(x)
#define __PARAM__(n, o) n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void int
#define volatile
#define __V_ char
#else
#define __V_ void
#endif
#else
#define __PROTO__(x) ()
#define __OTORP__(x) x
#define __PARAM__(n, o) o
#define __MANGLE__
#define __V_ char
#define const
#define signed
#define void int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__ ...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p, a) va_start(p, a)
#else
#define __VA_START__(p, a) va_start(p)
#endif
#endif

#line 3
#define mount _AST_mount
#include <shell.h>
#include <signal.h>
#include "shtable.h"
#include "name.h"
#ifdef KSHELL
#include "builtins.h"
#include "jobs.h"
#include "FEATURE/cmds"
#if defined(__STDC__) || defined(__STDPP__)
#define bltin(x) (b_##x)
#else
#define bltin(x) (b_ /**/ x)
#endif

#line 13
#else
#define bltin(x) 0
#endif

#include <X11/X.h>
#include <X11/Intrinsic.h>
#include <X11/IntrinsicP.h>
#define NO_AST
#include "dtksh.h"
#undef NO_AST
#include "dtextra.h"
#include "xmextra.h"
#include "msgs.h"

/*
 * The order up through "[" is significant
 */
const struct shtable3 shtab_builtins[] = {
    "login",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(login),
    "exec",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(exec),
    "set",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(set),
    ":",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(true),
    "true",
    NV_BLTIN | BLT_ENV,
    bltin(true),
    "command",
    NV_BLTIN | BLT_ENV | BLT_EXIT,
    bltin(command),
    "cd",
    NV_BLTIN | BLT_ENV,
    bltin(cd),
    "break",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(brk_cont),
    "continue",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(brk_cont),
    "typeset",
    NV_BLTIN | BLT_ENV | BLT_SPC | BLT_DCL,
    bltin(typeset),
    "test",
    NV_BLTIN | BLT_ENV | NV_NOFREE,
    bltin(test),
    "[",
    NV_BLTIN | BLT_ENV,
    bltin(test),
#ifdef _bin_newgrp
    "newgrp",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(login),
#endif /* _bin_newgrp */
    ".",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(dot_cmd),
    "alias",
    NV_BLTIN | BLT_SPC | BLT_DCL,
    bltin(alias),
    "hash",
    NV_BLTIN | BLT_SPC | BLT_DCL,
    bltin(alias),
    "exit",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(ret_exit),
    "export",
    NV_BLTIN | BLT_SPC | BLT_DCL,
    bltin(read_export),
    "eval",
    NV_BLTIN | BLT_ENV | BLT_SPC | BLT_EXIT,
    bltin(eval),
    "fc",
    NV_BLTIN | BLT_ENV | BLT_EXIT,
    bltin(hist),
    "hist",
    NV_BLTIN | BLT_ENV | BLT_EXIT,
    bltin(hist),
    "readonly",
    NV_BLTIN | BLT_ENV | BLT_SPC | BLT_DCL,
    bltin(read_export),
    "return",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(ret_exit),
    "shift",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(shift),
    "trap",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(trap),
    "unalias",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(unalias),
    "unset",
    NV_BLTIN | BLT_ENV | BLT_SPC,
    bltin(unset),
    "builtin",
    NV_BLTIN,
    bltin(builtin),
#ifdef SHOPT_ECHOPRINT
    "echo",
    NV_BLTIN | BLT_ENV,
    bltin(print),
#else
    "echo",
    NV_BLTIN | BLT_ENV,
    bltin(echo),
#endif /* SHOPT_ECHOPRINT */
#ifdef JOBS
#ifdef SIGTSTP
    "bg",
    NV_BLTIN | BLT_ENV,
    bltin(bg_fg),
    "fg",
    NV_BLTIN | BLT_ENV | BLT_EXIT,
    bltin(bg_fg),
    "disown",
    NV_BLTIN | BLT_ENV,
    bltin(bg_fg),
    "kill",
    NV_BLTIN | BLT_ENV | NV_NOFREE,
    bltin(kill),
#else
    "/bin/kill",
    NV_BLTIN | BLT_ENV | NV_NOFREE,
    bltin(kill),
#endif /* SIGTSTP */
    "jobs",
    NV_BLTIN | BLT_ENV,
    bltin(jobs),
#endif /* JOBS */
    "false",
    NV_BLTIN | BLT_ENV,
    bltin(false),
    "getconf",
    NV_BLTIN | BLT_ENV,
    bltin(getconf),
    "getopts",
    NV_BLTIN | BLT_ENV,
    bltin(getopts),
    "let",
    NV_BLTIN | BLT_ENV,
    bltin(let),
    "print",
    NV_BLTIN | BLT_ENV,
    bltin(print),
    "printf",
    NV_BLTIN | NV_NOFREE,
    bltin(printf),
    "pwd",
    NV_BLTIN | NV_NOFREE,
    bltin(pwd),
    "read",
    NV_BLTIN | BLT_ENV,
    bltin(read),
    "sleep",
    NV_BLTIN | NV_NOFREE,
    bltin(sleep),
    "alarm",
    NV_BLTIN,
    bltin(alarm),
    "ulimit",
    NV_BLTIN | BLT_ENV,
    bltin(ulimit),
    "umask",
    NV_BLTIN | BLT_ENV,
    bltin(umask),
#ifdef _cmd_universe
    "universe",
    NV_BLTIN | BLT_ENV,
    bltin(universe),
#endif /* _cmd_universe */
#ifdef SHOPT_FS_3D
    "vpath",
    NV_BLTIN | BLT_ENV,
    bltin(vpath_map),
    "vmap",
    NV_BLTIN | BLT_ENV,
    bltin(vpath_map),
#endif /* SHOPT_FS_3D */
    "wait",
    NV_BLTIN | BLT_ENV | BLT_EXIT,
    bltin(wait),
    "type",
    NV_BLTIN | BLT_ENV,
    bltin(whence),
    "whence",
    NV_BLTIN | BLT_ENV,
    bltin(whence),
#ifdef apollo
    "inlib",
    NV_BLTIN | BLT_ENV,
    bltin(inlib),
    "rootnode",
    NV_BLTIN,
    bltin(rootnode),
    "ver",
    NV_BLTIN,
    bltin(ver),
#endif /* apollo */
    "/bin/basename",
    NV_BLTIN | NV_NOFREE,
    bltin(basename),
    "/bin/chmod",
    NV_BLTIN | NV_NOFREE,
    bltin(chmod),
    "/bin/dirname",
    NV_BLTIN | NV_NOFREE,
    bltin(dirname),
    "/bin/head",
    NV_BLTIN | NV_NOFREE,
    bltin(head),
    "/bin/mkdir",
    NV_BLTIN | NV_NOFREE,
    bltin(mkdir),
#if defined(_usr_bin_logname) && !defined(_bin_logname)
    "/usr/bin/logname",
    NV_BLTIN | NV_NOFREE,
    bltin(logname),
#else
    "/bin/logname",
    NV_BLTIN | NV_NOFREE,
    bltin(logname),
#endif
    "/bin/cat",
    NV_BLTIN | NV_NOFREE,
    bltin(cat),
    "/bin/cmp",
    NV_BLTIN | NV_NOFREE,
    bltin(cmp),
#if defined(_usr_bin_cut) && !defined(_bin_cut)
    "/usr/bin/cut",
    NV_BLTIN | NV_NOFREE,
    bltin(cut),
#else
    "/bin/cut",
    NV_BLTIN | NV_NOFREE,
    bltin(cut),
#endif
    "/bin/uname",
    NV_BLTIN | NV_NOFREE,
    bltin(uname),
#if defined(_usr_bin_wc) && !defined(_bin_wc)
    "/usr/bin/wc",
    NV_BLTIN | NV_NOFREE,
    bltin(wc),
#else
#if defined(_usr_ucb_wc) && !defined(_bin_wc)
    "/usr/ucb/wc",
    NV_BLTIN | NV_NOFREE,
    bltin(wc),
#else
    "/bin/wc",
    NV_BLTIN | NV_NOFREE,
    bltin(wc),
#endif
#endif
    DTK_EXTRA_TABLE DTK_EXTRA_TABLE2 DTK_TK_EXTRA_TABLE DTK_TK_LIST_TABLE
        DTK_TK_TEXT_TABLE "",
    0,
    0};

const char sh_optalarm[] = "r [varname seconds]";
const char sh_optalias[] = "ptx [name=[value]...]";
const char sh_optbuiltin[] = "dsf:[library] [name...]";
const char sh_optcd[] = "LP [dir] [change]";
const char sh_optcflow[] = " [n]";
const char sh_optcommand[] = "pvV name [arg]...";
const char sh_optdot[] = " name [arg...]";
#ifndef ECHOPRINT
const char sh_optecho[] = " [-n] [arg...]";
#endif /* !ECHOPRINT */
const char sh_opteval[] = " [arg...]";
const char sh_optexec[] = "a:[name]c [command [args...] ]";
const char sh_optexport[] = "p [name[=value]...]";
const char sh_optgetopts[] = ":a:[name] optstring name [args...]";
const char sh_optgetconf[] = " [name [pathname] ]";
const char sh_optjoblist[] = " [job...]";
const char sh_opthist[] = "e:[editor]lnrsN# [first] [last]";
const char sh_optjobs[] = "nlp [job...]";
const char sh_optkill[] = "ln#[signum]s:[signame] sig...";
const char sh_optlet[] = " expr...";
const char sh_optprint[] = "f:[format]enprsu:[filenum] [arg...]";
const char sh_optprintf[] = " format [arg...]";
const char sh_optpwd[] = "LP";
const char sh_optread[] = "Ad:[delim]prst#[timeout]u#[filenum] [name...]";
#ifdef SHOPT_KIA
const char sh_optksh[] = "+DircabefhkmnpstuvxCR:[file]o:?[option] [arg...]";
const char sh_optset[] = "+abefhkmnpstuvxCR:[file]o:?[option]A:[name] [arg...]";
#else
const char sh_optksh[] = "+DircabefhkmnpstuvxCo:?[option] [arg...]";
const char sh_optset[] = "+abefhkmnpstuvxCo:?[option]A:[name] [arg...]";
#endif /* SHOPT_KIA */
const char sh_optsleep[] = " seconds";
const char sh_opttrap[] = "p [action condition...]";
#ifdef SHOPT_OO
const char sh_opttypeset[] =
    "+AC:E#?F#?H:[name]L#?R#?Z#?fi#?[base]lnprtux [name=[value]...]";
#else
const char sh_opttypeset[] =
    "+AE#?F#?HL#?R#?Z#?fi#?[base]lnprtux [name=[value]...]";
#endif /* SHOPT_OO */
const char sh_optulimit[] = "HSacdfmnstv [limit]";
const char sh_optumask[] = "S [mask]";
const char sh_optuniverse[] = " [name]";
const char sh_optunset[] = "fnv name...";
const char sh_optunalias[] = "a name...";
#ifdef SHOPT_FS_3D
const char sh_optvpath[] = " [top] [base]";
const char sh_optvmap[] = " [dir] [list]";
#endif /* SHOPT_FS_3D */
const char sh_optwhence[] = "afpv name...";

const char e_alrm1[] = "alarm -r %s +%.3g\n";
const char e_alrm2[] = "alarm %s %.3f\n";
const char e_badfun[] = "%s: illegal function name";
const char e_baddisc[] = "%s: invalid discipline function";
const char e_nospace[] = "out of memory";
const char e_nofork[] = "cannot fork";
const char e_nosignal[] = "%s: unknown signal name";
const char e_numeric[] = "*([0-9])?(.)*([0-9])";
const char e_condition[] = "condition(s) required";
const char e_cneedsarg[] = "-c requires argument";
