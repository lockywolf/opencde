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
/*******************************************************************************
**
**  format.c
**
**  $XConsortium: format.c /main/5 1996/11/21 19:42:52 drk $
**
**  RESTRICTED CONFIDENTIAL INFORMATION:
**
**  The information in this document is subject to special
**  restrictions in a confidential disclosure agreement between
**  HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
**  document outside HP, IBM, Sun, USL, SCO, or Univel without
**  Sun's specific written approval.  This document and all copies
**  and derivative works thereof must be returned or destroyed at
**  Sun's request.
**
**  Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
**
*******************************************************************************/

/*									*
 * (c) Copyright 1993, 1994 Hewlett-Packard Company			*
 * (c) Copyright 1993, 1994 International Business Machines Corp.	*
 * (c) Copyright 1993, 1994 Sun Microsystems, Inc.			*
 * (c) Copyright 1993, 1994 Novell, Inc. 				*
 */

#ifndef lint
static char sccsid[] =
    "@(#)format.c 1.27 95/01/19 Copyr 1991 Sun Microsystems, Inc.";
#endif

#include <EUSCompat.h>
#include <stdio.h>
#include <sys/time.h>
#if defined(sun) && defined(_XOPEN_SOURCE)
#include <time.h>
#endif
#include <Xm/Xm.h>
#include <csa.h>
#include "util.h"
#include "cm_tty.h"
#include "timeops.h"
#include "format.h"
#include "gettext.h"
#include "datefield.h"
#include "props.h"

#define XOS_USE_XT_LOCKING
#define X_INCLUDE_TIME_H
#if defined(linux)
#undef SVR4
#endif
#include <X11/Xos_r.h>

/*
 *  Convert tick to m, d, y string.  e.g. May 1, 1988
 */
extern void format_date(Tick t, OrderingType order, char *buf, int buf_size,
                        int day_and_date, int and_date, int full_day) {
        int m, d, y, wd;
        struct tm *tm;
        _Xltimeparams localtime_buf;

        buf[0] = '\0';
        tm = _XLocaltime(&t, localtime_buf);
        m = tm->tm_mon + 1;
        d = tm->tm_mday;
        y = tm->tm_year + 1900;
        wd = tm->tm_wday;

        switch (order) {
        case ORDER_DMY:
                /* STRING_EXTRACTION SUNW_DESKSET_CM_MSG :
                 *
                 * %s, %d %s %4d is a form of the date format.
                 * Change this to reflect your local convention.
                 * eg. In the German locale, "%s, %d %s %4d" may be changed
                 * to "%s. %d %s %4d".
                 */
                if (day_and_date)
                        if (full_day)
                                (void)snprintf(buf, buf_size, "%s, %d %s %4d",
                                               days2[wd], d, months[m], y);
                        else
                                (void)snprintf(buf, buf_size, "%s, %d %s %4d",
                                               days[wd], d, months[m], y);
                else if (and_date)
                        (void)snprintf(buf, buf_size, "%d %s %4d", d, months[m],
                                       y);

                else
                        (void)snprintf(buf, buf_size, "%s %4d", months[m], y);
                break;
        case ORDER_YMD:
                if (day_and_date)
                        if (full_day)
                                (void)snprintf(buf, buf_size, "%s, %4d %s %d",
                                               days2[wd], y, months[m], d);
                        else
                                (void)snprintf(buf, buf_size, "%s, %4d %s %d",
                                               days[wd], y, months[m], d);
                else if (and_date)
                        (void)snprintf(buf, buf_size, "%4d %s %d", y, months[m],
                                       d);
                else
                        (void)snprintf(buf, buf_size, "%4d %s", y, months[m]);
                break;
        case ORDER_MDY:
        default:
                if (day_and_date)
                        if (full_day)
                                (void)snprintf(buf, buf_size, "%s, %s %d %4d",
                                               days2[wd], months[m], d, y);
                        else
                                (void)snprintf(buf, buf_size, "%s, %s %d %4d",
                                               days[wd], months[m], d, y);
                else if (and_date)
                        (void)snprintf(buf, buf_size, "%s %d %4d", months[m], d,
                                       y);
                else
                        (void)snprintf(buf, buf_size, "%s %4d", months[m], y);
                break;
        }
}

/*
 *  Convert tick to m/d
 */
extern void format_date3(Tick t, OrderingType order, SeparatorType sep,
                         char *buf, int buf_size) {
        int m, d;
        struct tm *tm;
        char *str = (char *)separator_str(sep);
        _Xltimeparams localtime_buf;

        buf[0] = '\0';
        tm = _XLocaltime(&t, localtime_buf);

        m = tm->tm_mon + 1;
        d = tm->tm_mday;
        switch (order) {
        case ORDER_YMD:
        case ORDER_MDY:
        default:
                (void)snprintf(buf, buf_size, "%d%s%.2d", m, str, d);
                break;
        case ORDER_DMY:
                (void)snprintf(buf, buf_size, "%.2d%s%d", d, str, m);
                break;
        }
}

/*
 *  Format 1 line of appt data.  Returns True if begin hour is < 10 - thus
 *  padding needs to be done.
 */
extern Boolean format_line(Tick tick, char *what, char *buf, int buf_size,
                           int end_tick, Boolean showtime,
                           DisplayType display) {
        int hr, hr1, mn, mn1;
        Boolean am = True;
        Boolean am_end = True;
        struct tm *tm;
        Boolean pad = FALSE;
        _Xltimeparams localtime_buf;

        if (buf == NULL)
                return pad;
        buf[0] = '\0';
        tm = _XLocaltime(&tick, localtime_buf);
        hr = tm->tm_hour;
        mn = tm->tm_min;
        if (showtime && !magic_time(tick)) {
                if (display == HOUR12)
                        am = adjust_hour(&hr);
                if (end_tick && end_tick != tick) {
                        hr1 = hour(end_tick);
                        mn1 = minute(end_tick);
                        if (display == HOUR12) {
                                am_end = adjust_hour(&hr1);
                                if (am_end != am) {
                                        (void)snprintf(buf, buf_size,
                                                       "%d:%.2d - %d:%.2d%s ",
                                                       hr, mn, hr1, mn1,
                                                       am_end ? "am" : "pm");
                                } else {
                                        (void)snprintf(buf, buf_size,
                                                       "%d:%.2d - %d:%.2d ", hr,
                                                       mn, hr1, mn1);
                                }
                                if (hr < 10)
                                        pad = TRUE;
                        } else
                                (void)snprintf(buf, buf_size,
                                               "%02d%02d - %02d%02d ", hr, mn,
                                               hr1, mn1);
                } else {
                        /* Check to see if there are 2 digits in
                        in initial time format. If so, pad with
                        1 space; if not 2.  The font is not fixed
                        width, so I have to line it up myself.. */
                        if (display == HOUR12) {
                                if (hr > 9)
                                        snprintf(buf, buf_size, "%2d:%.2d%s ",
                                                 hr, mn, am ? "a" : "p");
                                else {
                                        snprintf(buf, buf_size, "%d:%.2d%s ",
                                                 hr, mn, am ? "a" : "p");
                                        pad = TRUE;
                                }
                        } else
                                snprintf(buf, buf_size, "%02d%02d ", hr, mn);
                }
        }
        if (what)
                (void)cm_strlcat(buf, what, buf_size);

        return pad;
}

/*
 *  Format 2 lines of appt data
 */
extern void format_maxchars(Dtcm_appointment *appt, char *buf1, int buf_size,
                            int maxchars, DisplayType display) {
        Tick tick, end_tick = 0;
        int hour1, min1, hour2, min2;
        Lines *lines;
        char *s1, *s2;
        struct tm *tm;
        _Xltimeparams localtime_buf;

        _csa_iso8601_to_tick(appt->time->value->item.string_value, &tick);
        if (appt->end_time)
                _csa_iso8601_to_tick(appt->end_time->value->item.string_value,
                                     &end_tick);
        *buf1 = '\0';
        if (appt == NULL || appt->what->value->item.string_value == NULL)
                return;
        tm = _XLocaltime(&tick, localtime_buf);
        hour1 = tm->tm_hour;
        min1 = tm->tm_min;
        if (showtime_set(appt) && !magic_time(tick)) {
                s1 = s2 = "am";
                if (display == HOUR12 && !adjust_hour(&hour1))
                        s1 = "pm";

                if (end_tick) {
                        hour2 = hour(end_tick);
                        if (display == HOUR12 && !adjust_hour(&hour2))
                                s2 = "pm";

                        min2 = minute(end_tick);
                }

                if ((end_tick == 0 || hour1 == hour2) && min1 == min2) {
                        if (display == HOUR24)
                                snprintf(buf1, buf_size, "%02d%02d  ", hour1,
                                         min1);
                        else
                                snprintf(buf1, buf_size, "%d:%.2d%s  ", hour1,
                                         min1, s1);
                } else {
                        if (display == HOUR12)
                                snprintf(buf1, buf_size,
                                         "%d:%.2d%s-%d:%.2d%s  ", hour1, min1,
                                         s1, hour2, min2, s2);
                        else
                                snprintf(buf1, buf_size, "%02d%02d-%02d%02d  ",
                                         hour1, min1, hour2, min2);
                }
        }

        lines =
            (Lines *)text_to_lines(appt->what->value->item.string_value, 10);

        while (lines != NULL) {
                if ((cm_strlen(buf1) + cm_strlen(lines->s)) < (maxchars - 2)) {
                        cm_strlcat(buf1, lines->s, buf_size);
                        lines = lines->next;
                        if (lines != NULL)
                                cm_strlcat(buf1, " - ", buf_size);
                } else {
                        strncat(buf1, lines->s,
                                (maxchars - cm_strlen(buf1) - 1));
                        break;
                }
        }
        destroy_lines(lines);
}

/*
 *  Format 2 lines of appt data
 */
extern void format_line2(Dtcm_appointment *appt, char *buf1, int buf1_size,
                         char *buf2, int buf2_size, DisplayType display) {
        Tick tick, end_tick = 0;
        int hour1, min1, hour2, min2;
        Lines *lines;
        char *s1, *s2;
        struct tm *tm;
        _Xltimeparams localtime_buf;

        _csa_iso8601_to_tick(appt->time->value->item.string_value, &tick);
        if (appt->end_time)
                _csa_iso8601_to_tick(appt->end_time->value->item.string_value,
                                     &end_tick);

        /*
         * Extract an appointment and format it into 2 lines of no more
         * then maxchars
         */
        *buf1 = *buf2 = '\0';
        if (appt == NULL || appt->what->value->item.string_value == NULL)
                return;
        tm = _XLocaltime(&tick, localtime_buf);
        hour1 = tm->tm_hour;
        min1 = tm->tm_min;

        if (!showtime_set(appt) || magic_time(tick)) {
                lines = (Lines *)text_to_lines(
                    appt->what->value->item.string_value, 1);
                if (lines == NULL)
                        return;
                strncpy(buf2, lines->s, 256);
                destroy_lines(lines);
                return;
        }

        s1 = s2 = "am";
        if (display == HOUR12 && !adjust_hour(&hour1))
                s1 = "pm";

        if (end_tick) {
                hour2 = hour(end_tick);
                min2 = minute(end_tick);
                if (display == HOUR12 && !adjust_hour(&hour2))
                        s2 = "pm";
        }

        if (end_tick == 0 ||
            (hour1 == hour2 && min1 == min2 && (strcmp(s1, s2) == 0))) {
                if (display == HOUR24)
                        snprintf(buf1, buf1_size, "%02d%.2d", hour1, min1);
                else
                        snprintf(buf1, buf1_size, "%d:%.2d%s", hour1, min1, s1);
        } else {
                if (display == HOUR12)
                        snprintf(buf1, buf1_size, "%d:%.2d%s-%d:%.2d%s", hour1,
                                 min1, s1, hour2, min2, s2);
                else
                        snprintf(buf1, buf1_size, "%02d%02d-%02d%02d", hour1,
                                 min1, hour2, min2);
        }

        lines = (Lines *)text_to_lines(appt->what->value->item.string_value, 1);

        if (lines == NULL || lines->s == NULL ||
            (cm_strlen(lines->s) == 1 && lines->s[0] == ' '))
                buf2[0] = '\0';
        else
                snprintf(buf2, buf2_size, " %s", lines->s);
        destroy_lines(lines);
}

/*
 *  Format the appointment in the character array passed (assumed to be pointing
 *  to allocated space) to contain the time followed by the what string.  The
 *  appointment string is truncated at "max" chars or at DEFAULT_APPT_LEN if
 *  max is 0.
 */
extern void format_appt(Dtcm_appointment *appt, char *b, int b_size,
                        DisplayType display, int max) {
        int hr, mn, len, i = 0, j = 0;
        Tick tick;
        struct tm *tm;
        register char *what_ptr;
        _Xltimeparams localtime_buf;

        if (!appt || !b)
                return;

        _csa_iso8601_to_tick(appt->time->value->item.string_value, &tick);
        tm = _XLocaltime(&tick, localtime_buf);
        hr = tm->tm_hour;
        mn = tm->tm_min;

        if (showtime_set(appt) && !magic_time(tick)) {
                if (display == HOUR12) {
                        adjust_hour(&hr);
                        snprintf(b, b_size, "%2d:%02d ", hr, mn);
                } else
                        snprintf(b, b_size, "%02d%02d ", hr, mn);
                i = cm_strlen(b);
        }

        if (appt->what->value->item.string_value) {
                if (max <= 0)
                        max = DEFAULT_APPT_LEN;
                len = max - i;
                what_ptr = appt->what->value->item.string_value;
                while ((i < len) && *what_ptr != '\n' && *what_ptr)
                        b[i++] = *what_ptr++;
                b[i] = '\0';
        }
}

/*
 *  Format the appointment in the character array passed (assumed to be pointing
 *  to allocated space) to contain the formatted string for the group
 *  appointment editor.  The string is truncated at "max" chars or at
 *  DEFAULT_GAPPT_LEN if max is 0.
 */
extern void format_gappt(Dtcm_appointment *appt, char *name, char *b,
                         int b_size, DisplayType display, int max) {
        int hr, mn, i, j;
        Tick tick;
        char *what_ptr;
        struct tm *tm;
        _Xltimeparams localtime_buf;

        if (!appt || !b)
                return;

        _csa_iso8601_to_tick(appt->time->value->item.string_value, &tick);
        if ((tick > 0) && !magic_time(tick) && showtime_set(appt)) {
                tm = _XLocaltime(&tick, localtime_buf);
                hr = tm->tm_hour;
                mn = tm->tm_min;

                if (display == HOUR12) {
                        adjust_hour(&hr);
                        snprintf(b, b_size, "%2d:%02d ", hr, mn);
                } else
                        snprintf(b, b_size, "%02d%02d  ", hr, mn);
        } else
                snprintf(b, b_size, "%6s", " ");

        if (max <= 0)
                max = DEFAULT_GAPPT_LEN;
        i = cm_strlen(b);

        j = 0;
        while (j < 10 && i < max && name && name[j])
                b[i++] = name[j++];
        while (j < 11 && i < max)
                b[i++] = ' ', ++j;

        if (i >= max) {
                b[i - 1] = '\0';
                return;
        }
        b[i] = '\0';

        if (appt->what->value->item.string_value) {
                what_ptr = appt->what->value->item.string_value;
                while (i < max && *what_ptr != '\n' && *what_ptr)
                        b[i++] = *what_ptr++;
                b[i] = '\0';
        }
}
