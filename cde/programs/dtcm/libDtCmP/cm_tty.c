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
**  cm_tty.c
**
**  $TOG: cm_tty.c /main/9 1998/04/17 11:22:38 mgreess $
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
static  char sccsid[] = "@(#)cm_tty.c 1.91 95/07/27 Copyr 1993 Sun Microsystems, Inc.";
#endif

#include <EUSCompat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <nl_types.h>
#include <sys/param.h>
#include <sys/types.h>
#include "cm_tty.h"
#include "getdate.h"
#include "util.h"

/*******************************************************************************
**
**  Globals
**
*******************************************************************************/
static char *separator_strs[] = {
	" ",
	"/",
	".",
	"-"
};

static char *repeat_strs[11];

static char *default_repeat_cnt_strs[] = {
	"\0",
	"365",
	"52",
	"26",
	"12",
	"12",
	"2",
	"52",
	"52",
	"52",
	"5"
};

static char *default_repeat_scope_strs[11];

static char *for_strs[] = {
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"10",
	"11",
	"12",
	"13",
	"14",
	"forever"
};

static char *time_scope_strs_i18n[3];
static char *time_scope_strs[] = {
	"Mins",
	"Hrs",
	"Days"
};

static char *repeat_scope_strs[3];

static char *day_strs[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"
};

static char *month_strs[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

typedef enum {
	TTY_Delete,
	TTY_Insert,
	TTY_Lookup
} Op_Type;

nl_catd catd_global;

static char *new_appt_begin_delimiter = NULL;
static char *new_appt_end_delimiter = NULL;

extern int _csa_iso8601_to_tick(char *, time_t*);
extern int _csa_tick_to_iso8601(time_t, char *);
extern int _csa_iso8601_to_duration(char *, int*);
extern int _csa_duration_to_iso8601(int, char *);

/*******************************************************************************
**
**  Static functions
**
*******************************************************************************/
static void
copy_and_pad_newlines(register char *dest, register char *source) {
	while (*source)
		if ((*dest++ = *source++) == '\n')
			*dest++ =  '\t';
}

static int
count_newlines(register char *string) {
	int count = 0;

	if (string == NULL)
		return(0);
	while (*string)
		if (*string++ == '\n')
			count++;

	return count;
}

static void
mini_err_msg(
	nl_catd catd,
	char *appt_what,
	Op_Type	type) {

	char	*buf, *ptr;

	if (type == TTY_Insert)
		fprintf(stderr, "%s",
			catgets(catd, 1, 1042, "Insert Access Denied: "));
	else if (type == TTY_Delete)
		fprintf(stderr, "%s",
			catgets(catd, 1, 1043, "Delete Access Denied: "));
	else
		fprintf(stderr, "%s",
			catgets(catd, 1, 1044, "Lookup Access Denied: "));

	if (appt_what && appt_what[0] != '\0') {
		buf = cm_strdup(appt_what);
		if ( (ptr = strrchr(buf, '\n')) )
			*ptr = '\0';
		fprintf(stderr, "%s '%s'\n",
				catgets(catd, 1, 1045, "Cancelled for"),
				buf);
		free(buf);
	} else
		fprintf(stderr, "%s\n",
				catgets(catd, 1, 1046,
					"Appointment Cancelled\n"));
}

static boolean_t
query_user(void *client_data) {
	char	ans[MAXNAMELEN], *what_str = (char *)client_data;

	/* NL_COMMENT

	   The following four messages (1047-1050) will be printed to stdout
	   and can have the following two forms:

		"This appointment: '<appt text>' has an end
		 time earlier than its begin time.  Do you
		 want to schedule it into the next day? [Y/N]  "

	   or

		"This appointment has an end
		 time earlier than its begin time.  Do you
		 want to schedule it into the next day? [Y/N]  "

	   The text <appt text> and [Y/N] should not be translated.

	*/

	if (what_str && what_str[0] != '\0')
		fprintf(stdout, catgets(catd_global, 1, 1047,
			"This appointment: '%s' has an end\n"), what_str);
	else
		fprintf(stdout, "%s", catgets(catd_global, 1, 1048,
			"This appointment has an end\n"));
	fprintf(stdout, "%s", catgets(catd_global, 1, 1049,
			"time earlier than its begin time.  Do you\n"));
	fprintf(stdout, "%s", catgets(catd_global, 1, 1050,
			"want to schedule it into the next day? [Y/N]  "));
	fgets(ans, sizeof(ans)-1, stdin);
	fprintf(stdout, "\n");
	if (*ans == 'y' || *ans == 'Y')
		return B_TRUE;
	return B_FALSE;
}

/*******************************************************************************
**
**  External functions
**
*******************************************************************************/
extern char*
boolean_str(boolean_t val) {
	return (val ? "True" : "False");
}

/*
 * Delete an appointment.  index is the nth appointment in the passed array.
 */
extern int
cm_tty_delete(
	nl_catd		catd,
	CSA_session_handle session,
	int version,
	int index,
	CSA_entry_handle *list) {

	char			ans[10];
	Dtcm_appointment	*appt;

	if (index < 0 || !list[index])
		return -1;

	appt = allocate_appt_struct(appt_read,
				    version,
				    CSA_ENTRY_ATTR_SUMMARY_I,
				    CSA_X_DT_ENTRY_ATTR_REPEAT_TYPE_I,
				    NULL);

	if (query_appt_struct(session, list[index], appt) != CSA_SUCCESS) {
		mini_err_msg(catd, appt->what->value->item.string_value,
			     TTY_Delete);
		return(0);
	}

	if (appt->repeat_type->value->item.sint32_value == CSA_X_DT_REPEAT_ONETIME)
		*ans = '1';
	else {
		/* NL_COMMENT

		   Message numbers 1051-1057 are printed to stdout and
		   should appear like:

		   "The appointment '<appt text>' is part of a repeating series. Do you want to:
			1.  Delete all of them
			2.  Delete this on only
			3.  Delete forward
			4.  Cancel
			Option [1-4]: "

		*/
		fprintf(stdout, catgets(catd, 1, 1051,
		     "The appointment '%s' is part of a repeating series.  "),
		      appt->what->value->item.string_value);
		fprintf(stdout, "%s", catgets(catd, 1, 1052, "Do you want to:"));
		fprintf(stdout, "%s", catgets(catd, 1, 1053,
					"\n\t1.  Delete all of them"));
		fprintf(stdout, "%s", catgets(catd, 1, 1054,
					"\n\t2.  Delete this one only"));
		fprintf(stdout, "%s", catgets(catd, 1, 1055, "\n\t3.  Delete forward"));
		fprintf(stdout, "%s", catgets(catd, 1, 1056, "\n\t4.  Cancel"));
		fprintf(stdout, "%s", catgets(catd, 1, 1057, "\n\tOption [1-4]: "));
		fgets(ans, sizeof(ans)-1, stdin);
		fprintf(stdout, "\n");
	}

	switch(*ans) {
	case '1':
		if (csa_delete_entry(session, list[index], CSA_SCOPE_ALL, NULL)
		    != CSA_SUCCESS)
			mini_err_msg(catd, appt->what->value->item.string_value,
				TTY_Delete);
		break;
	case '2':
		if (csa_delete_entry(session, list[index], CSA_SCOPE_ONE, NULL)
		    != CSA_SUCCESS)
			mini_err_msg(catd, appt->what->value->item.string_value,
				TTY_Delete);
		break;
	case '3':
		if (csa_delete_entry(session, list[index], CSA_SCOPE_FORWARD,
		    NULL) != CSA_SUCCESS)
			mini_err_msg(catd, appt->what->value->item.string_value,
				TTY_Delete);
		break;
	case '4':
	default:
		break;
	}
	free_appt_struct(&appt);

	return 0;
}

/*
 * Build ascii date/time line from integer (tick)
 */
extern void
cm_tty_format_header(Props *p, Tick tick, char *buf) {
	Days_op		d_op;
	Months_op	m_op;

	if (!buf)
		return;

	d_op = (Days_op)dow(tick);
	m_op = (Months_op)(month(tick) - 1);

	switch(get_int_prop(p, CP_DATEORDERING)) {
	case ORDER_MDY:
		snprintf(buf, sizeof(buf), "%s %s %d, %d", day_str(d_op), month_str(m_op),
			dom(tick), year(tick));
		break;
	case ORDER_DMY:
		snprintf(buf, sizeof(buf), "%s %d %s, %d", day_str(d_op), dom(tick),
			month_str(m_op), year(tick));
		break;
	case ORDER_YMD:
		snprintf(buf, sizeof(buf), "%s, %d %s %d", day_str(d_op), year(tick),
			month_str(m_op), dom(tick));
		break;
	default:
		buf[0] = '\0';
		break;
	}
}

extern void
scrub_attr_list(Dtcm_appointment *appt) {

	int	i;

	for (i = 0; i < appt->count; i++) {
		if (appt->attrs[i].value->type == CSA_VALUE_REMINDER) {
			if ((appt->attrs[i].value->item.reminder_value->lead_time == NULL) ||
			     (appt->attrs[i].value->item.reminder_value->lead_time[0] == '\0')) {
				free(appt->attrs[i].name);
				appt->attrs[i].name = NULL;
			}
		}
		else if ((appt->attrs[i].value->type == CSA_VALUE_ACCESS_LIST) && (appt->attrs[i].value->item.access_list_value == NULL)) {
			free(appt->attrs[i].name);
			appt->attrs[i].name = NULL;
		}
		else if ((appt->attrs[i].value->type == CSA_VALUE_STRING) && (appt->attrs[i].value->item.string_value == NULL)) {
			free(appt->attrs[i].name);
			appt->attrs[i].name = NULL;
		}
		else if ((appt->attrs[i].value->type == CSA_VALUE_DATE_TIME) && (appt->attrs[i].value->item.date_time_value == NULL)) {
			free(appt->attrs[i].name);
			appt->attrs[i].name = NULL;
		}
	}
}

/*
 * Insert an appointment!
 */
extern int
cm_tty_insert(nl_catd catd, CSA_session_handle target, int version,
	      char *date, char *start, char *end,
	      char *repeat, char *repeatfor, char *what, char *filename,
	      Props *p) {
	int			ret_stat = 0, cnt;
	char			*t1 = NULL;
	CSA_entry_handle	new_entry;
	CmDataList		*list = CmDataListCreate();
	Validate_op		op;
	CSA_attribute		*attrs;
	CSA_return_code		status;
	Dtcm_appointment	*appt;

	/* XXX: This is ugly but the query_user() function needs the catd
	 * and this is the easiest way to get it there.
	 */
	catd_global = catd;

	if (filename) {
		op = parse_appt_from_file(catd, filename, list, p, query_user,
					  NULL, version);
		appt = (Dtcm_appointment *)CmDataListGetData(list, 1);
	} else {
		appt = allocate_appt_struct(appt_write, version, NULL);
		load_appt_defaults(appt, p);

		op = validate_appt(catd, appt, start, end, date, 0, what,
			repeat, repeatfor, query_user, what, version);

		CmDataListAdd(list, (void *)appt, 0);
	}
	for (cnt = 1; cnt <= list->count; cnt++) {
		if ((appt = (Dtcm_appointment *)CmDataListGetData(list, cnt)) == NULL)
			continue;

		switch(op) {
		case INVALID_DATE:
			t1 = catgets(catd, 1, 1058, "Invalid Date specified.\n");
			break;
		case INVALID_START:
			t1 = catgets(catd, 1, 1059,
					"Invalid Start time specified.\n");
			break;
		case INVALID_TIME:
			t1 = "Invalid Due time specified.\n";
			break;
		case INVALID_STOP:
			t1 = catgets(catd, 1, 1060,
					"Invalid Stop time specified.\n");
			break;
		case MISSING_DATE:
			t1 = catgets(catd, 1, 1061,
					"Empty or missing Date field.\n");
			break;
		case MISSING_START:
			t1 = catgets(catd, 1, 1062,
					"Empty or missing Start field.\n");
			break;
		case MISSING_TIME:
			t1 = "Empty or missing Due time field.\n";
			break;
		case MISSING_WHAT:
			t1 = catgets(catd, 1, 1063,
					"Empty or missing What field.\n");
			break;
		case REPEAT_FOR_MISMATCH:
			t1 = catgets(catd, 1, 1064,
					"Repeat and For field mismatch.\n");
			break;
		case VALID_APPT:
		case CANCEL_APPT:
			t1 = "";
			break;
		default:
			op = CANCEL_APPT;
			t1 = catgets(catd, 1, 1065,
					"Insert appointment was cancelled\n");
			break;
		}

		if (op == VALID_APPT) {
			scrub_attr_list(appt);

			if ((status = csa_add_entry(target, appt->count, appt->attrs, &new_entry, NULL)) != CSA_SUCCESS) {
				mini_err_msg(catd,
					appt->what->value->item.string_value,
					TTY_Insert);
				ret_stat = -1;
			} else
				csa_free((CSA_buffer)new_entry);
		} else {
		  	char *msg = strdup(t1);
			fprintf(stderr, "%s%s\n", msg, catgets(catd, 1, 1066,
					"Appointment was not inserted."));
			free(msg);
			ret_stat = -1;
		}
	}

	if ((list->count == 0) && (op != VALID_APPT || op != CANCEL_APPT))
		ret_stat = -1;

	for (cnt = 1; cnt <= list->count; cnt++)
		if ( (appt = (Dtcm_appointment *)CmDataListGetData(list, cnt)) )
			free_appt_struct(&appt);
	CmDataListDestroy(list, B_FALSE);

	return ret_stat;
}

void
cm_tty_load_props(Props **p) {
	int	start, stop;

	if (*p)
		free(*p);

        *p = (Props *)ckalloc(sizeof(Props));
        read_props(*p);
        cal_convert_cmrc(*p);

	if ((start = get_int_prop(*p, CP_DAYBEGIN)) < 0)
		start = 0;
	else if (start > 22)
		start = 22;
	if ((stop = get_int_prop(*p, CP_DAYEND)) <= start)
		stop = start + 1;
	else if (stop > 23)
		stop = 23;
	set_int_prop(*p, CP_DAYBEGIN, start);
	set_int_prop(*p, CP_DAYEND, stop);
}

extern int
cm_tty_lookup(nl_catd catd, CSA_session_handle target, int version, char *date, char *view, CSA_entry_handle **list,
	      Props *p) {
	int			span, day, lineno = 1, last_day = -1, i;
	CSA_uint32		a_total;
	char			start_buf[MAXNAMELEN], end_buf[MAXNAMELEN];
	char			buf[MAXNAMELEN], date_str[MAXNAMELEN], *what;
	time_t			tick, start, stop;
	Lines			*lines = NULL, *next_line;
	DisplayType		dt;
	CSA_enum		*ops;
	CSA_attribute		*range_attrs;
	Dtcm_appointment	*appt;
	Tick			start_tick, end_tick = 0;
	CSA_return_code		status;

	/*
	 * Preliminary stuff - set defaults
	 */
	if (!view) {
		switch(get_int_prop(p, CP_DEFAULTVIEW)) {
		case 1:
			view = "month";
			break;
		case 2:
			view = "week";
			break;
		default:
			view = "day";
			break;
		}
	}
	if (!date)
		tick = now();
	else if ((tick = cm_getdate(date, NULL)) < 0) {
		fprintf(stdout,	"\n%s %s\n\n",
				catgets(catd, 1, 1067, "Invalid date specified:"),
				date);
		return(0);
	}

	/*
	 * Compute day and span for view specified
	 */
	if (strncasecmp(view, "week", 4) == 0) {
		day = dow(tick);
		span = 7;
	} else if (strncasecmp(view, "month", 5) == 0) {
		day = dom(tick) - 1;
		span = monthlength(tick);
	} else {
		day = 0;
		span = 1;
	}

	start = lowerbound(tick - (day * daysec));
	stop = next_ndays(start, span) - 1;
	setup_range(&range_attrs, &ops, &i, start, stop, CSA_TYPE_EVENT,
		    0, B_FALSE, version);
	status = csa_list_entries(target, i, range_attrs, ops, &a_total, list, NULL);
	free_range(&range_attrs, &ops, i);

	appt = allocate_appt_struct(appt_read,
				    version,
				    CSA_ENTRY_ATTR_START_DATE_I,
				    CSA_ENTRY_ATTR_SUMMARY_I,
				    CSA_X_DT_ENTRY_ATTR_SHOWTIME_I,
				    CSA_ENTRY_ATTR_END_DATE_I,
				    NULL);
	for (i = 0; i < a_total; i++) {

		if (query_appt_struct(target, (*list)[i], appt) != CSA_SUCCESS) {
			mini_err_msg(catd, appt->what->value->item.string_value,
				TTY_Lookup);
			continue;
		}

		_csa_iso8601_to_tick(appt->time->value->item.date_time_value, &start_tick);
		if (appt->end_time)
			_csa_iso8601_to_tick(appt->end_time->value->item.\
				date_time_value, &end_tick);
		day = dom(start_tick);
		if (day != last_day) {
			cm_tty_format_header(p, start_tick, date_str);
			fprintf(stdout,	"\n%s %s:\n",
				catgets(catd, 1, 1068, "Appointments for"),
				date_str);
		}
		last_day = day;

		memset(buf, '\0', MAXNAMELEN);
		if (appt->show_time->value->item.sint32_value &&
		    !magic_time(start_tick)) {
			dt = get_int_prop(p, CP_DEFAULTDISP);
			format_time(start_tick, dt, start_buf, MAXNAMELEN);
			if (appt->end_time)
				format_time(end_tick, dt, end_buf, MAXNAMELEN);
			else
				*end_buf = '\0';
			snprintf(buf, MAXNAMELEN, "%s%c%7s ", start_buf,
				(*end_buf ? '-' : ' '), end_buf);
		}

		fprintf(stdout,	"\t%3d) %s", lineno++, buf);
		if ((lines = text_to_lines(appt->what->value->item.string_value,		    5)) && lines->s) {

			fprintf(stdout, "%s\n", lines->s);
			next_line = lines->next;
			while(next_line) {
				fprintf(stdout,
					"\t%21s%s\n", " ", next_line->s);
				next_line = next_line->next;
			}
		} else
			fprintf(stdout, "\n");

		destroy_lines(lines);
		fprintf(stdout,	"\n");
	}
	free_appt_struct(&appt);

	if (*list == NULL) {
		cm_tty_format_header(p, start + 1, date_str);
		fprintf(stdout,	"\n%s %s\n\n",
				catgets(catd, 1, 1069, "No Appointments for"),
				date_str);
	}
	return a_total;
}

/*
 *  These functions will convert a string to the enumerated value
 */
extern boolean_t
convert_boolean_str(char *val) {
	if (strncasecmp(val, "T", 1) == 0 || strcasecmp(val, "B_TRUE") == 0)
		return B_TRUE;
	return B_FALSE;
}

extern int
convert_privacy_str_to_op(char *val) {
	int	i = 2;


	/*
	 * i defaults to 1 = CSA_CLASS_PRIVATE, so no need to check for that
	 * string.
	 */
	if (strcmp(val, privacy_str(0)) == 0 ||
	    strcmp(val, privacy_str_old(0)) == 0 ||
	    strcmp(val, privacy_str_411(0)) == 0)
		i = 0;
	else if (strcmp(val, privacy_str(1)) == 0 ||
		 strcmp(val, privacy_str_old(1)) == 0 ||
		 strcmp(val, privacy_str_411(1)) == 0)
		i = 1;

	return i;
}

extern CSA_sint32
convert_privacy_str(char *val) {
	CSA_sint32	ret_val = CSA_CLASS_PRIVATE;

	if ((strcasecmp(val, privacy_str(0)) == 0) ||
	    (strcasecmp(val, privacy_str_old(0)) == 0) ||
	    (strcasecmp(val, privacy_str_411(0)) == 0))
		ret_val = CSA_CLASS_PUBLIC;
	else if ((strcasecmp(val, privacy_str(1)) == 0) ||
		 (strcasecmp(val, privacy_str_old(1)) == 0) ||
		 (strcasecmp(val, privacy_str_411(1)) == 0))
		ret_val = CSA_CLASS_CONFIDENTIAL;
	else if ((strcasecmp(val, privacy_str(2)) == 0) ||
		 (strcasecmp(val, privacy_str_old(2)) == 0) ||
		 (strcasecmp(val, privacy_str_411(2)) == 0))
		ret_val = CSA_CLASS_PRIVATE;

	return ret_val;
}

extern SeparatorType
convert_separator_str(char *val) {
	SeparatorType	op = SEPARATOR_BLANK;
	char		*search_val = separator_str(op);

	while (search_val && strcasecmp(search_val, val) != 0)
		search_val = separator_str(++op);
	return op;
}

extern Time_scope_menu_op
convert_time_scope_str(char *val) {
	Time_scope_menu_op	op = TIME_MINS;
	char			*search_val = time_scope_str(op);

	while(search_val && strcasecmp(search_val, val) != 0)
		search_val = time_scope_str(++op);
	return op;
}

extern char*
day_str(Days_op op) {
	if (op >= SUNDAY && op <= SATURDAY)
		return day_strs[op];
	return NULL;
}

extern char*
default_repeat_cnt_str(Repeat_menu_op  op) {

	if (op >= ONE_TIME && op <= REPEAT_EVERY)
		return default_repeat_cnt_strs[op];
	return NULL;
}

extern char*
default_repeat_scope_str(
	nl_catd		catd,
	Repeat_menu_op  op)
{
	if (!default_repeat_scope_strs[DAILY]) {
		default_repeat_scope_strs[ONE_TIME] = strdup("\0");
		default_repeat_scope_strs[DAILY] =
				strdup(catgets(catd, 1, 994, "days"));
		default_repeat_scope_strs[WEEKLY] =
				strdup(catgets(catd, 1, 995, "weeks"));
		default_repeat_scope_strs[EVERY_TWO_WEEKS] =
				strdup(catgets(catd, 1, 996, "biweeks"));
		default_repeat_scope_strs[MONTHLY_BY_DATE] =
				strdup(catgets(catd, 1, 997, "months"));
		default_repeat_scope_strs[MONTHLY_BY_WEEKDAY] =
				default_repeat_scope_strs[MONTHLY_BY_DATE];
		default_repeat_scope_strs[YEARLY] =
				strdup(catgets(catd, 1, 998, "years"));
		default_repeat_scope_strs[MONDAY_THRU_FRIDAY] =
				default_repeat_scope_strs[WEEKLY];
		default_repeat_scope_strs[MON_WED_FRI] =
				default_repeat_scope_strs[WEEKLY];
		default_repeat_scope_strs[TUESDAY_THURSDAY] =
				default_repeat_scope_strs[WEEKLY];
		default_repeat_scope_strs[REPEAT_EVERY] = strdup("\0");
	}

	if (op >= ONE_TIME && op <= REPEAT_EVERY)
		return default_repeat_scope_strs[op];
	return NULL;
}

extern char*
for_str(For_menu_op op) {
	if (op >= TWO && op <= FOR_EVER)
		return for_strs[op];
	return NULL;
}

/*
**  Return a date label according to order and sep
*/
extern char*
get_datemsg(OrderingType order, SeparatorType sep) {
	char	*str = separator_str(sep);
	char	buf[20];

	switch (order) {
	case ORDER_DMY:
		snprintf(buf, 20, "%s %s %s %s %s", "Day", str, "Month", str, "Year");
		break;
	case ORDER_YMD:
		snprintf(buf, 20, "%s %s %s %s %s", "Year", str, "Month", str, "Day");
		break;
	case ORDER_MDY:
	default:
		snprintf(buf, 20, "%s %s %s %s %s", "Month", str, "Day", str, "Year");
		break;
	}
	return(cm_strdup(buf));
}

/*
 * This function is used by the appointment file parsing routines to return
 * whether or not the value in the passed buffer is a key word
 */
extern Parse_key_op
identify_parse_key(char *str) {

	if (!new_appt_begin_delimiter) {
		int size = strlen(CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER) + 14;
		new_appt_begin_delimiter = malloc(size);
		snprintf(new_appt_begin_delimiter, size, "%s%s",
			CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER,
			":string:begin");
	}

	if (strncasecmp(str, "** Calendar Appointment **",
		cm_strlen("** Calendar Appointment **")) == 0)
		return APPOINTMENT_START;
	if (strncasecmp(str, "date:", cm_strlen("date:")) == 0)
		return DATE_KEY;
	if (strncasecmp(str, "time:", cm_strlen("time:")) == 0 ||
		strncasecmp(str, "start:", cm_strlen("start:")) == 0 ||
		strncasecmp(str, "from:", cm_strlen("from:")) == 0)
		return START_KEY;
	if(strncasecmp(str, "end:", cm_strlen("end:")) == 0 ||
		strncasecmp(str, "until:", cm_strlen("until:")) == 0 ||
		strncasecmp(str, "stop:", cm_strlen("stop:")) == 0 ||
		strncasecmp(str, "to:", cm_strlen("to:")) == 0)
		return STOP_KEY;
	if (strncasecmp(str, "duration:", cm_strlen("duration:")) == 0)
		return DURATION_KEY;
	if (strncasecmp(str, "what:", cm_strlen("what:")) == 0)
		return WHAT_KEY;
	if (strncasecmp(str, "repeat:", cm_strlen("repeat:")) == 0)
		return REPEAT_KEY;
	if (strncasecmp(str, "for:", cm_strlen("for:")) == 0)
		return FOR_KEY;
	if (strncasecmp(str, new_appt_begin_delimiter, cm_strlen(new_appt_begin_delimiter)) == 0)
		return NEW_APPT_KEY;

	return NOT_A_KEY;
}

/*
 * This function will fill in the default values using the properties database
 * for a given appointment
 */
extern void
load_appt_defaults(Dtcm_appointment *a, Props *p) {
	a->type->value->item.sint32_value = CSA_TYPE_EVENT;
	a->subtype->value->item.string_value = strdup(CSA_SUBTYPE_APPOINTMENT);
	a->state->value->item.sint32_value = CSA_X_DT_STATUS_ACTIVE;
	if (a->repeat_type && a->repeat_type->value)
		a->repeat_type->value->item.sint32_value = CSA_X_DT_REPEAT_ONETIME;
	if (a->repeat_times && a->repeat_times->value)
		a->repeat_times->value->item.uint32_value = 0;
	a->private->value->item.sint32_value =
		convert_privacy_str(get_char_prop(p, CP_PRIVACY));

	load_reminder_props(a, p);
}

extern void
load_reminder_props(Dtcm_appointment *a, Props *p) {
	if (convert_boolean_str(get_char_prop(p, CP_BEEPON))) {
		a->beep->value->item.reminder_value->lead_time = malloc(BUFSIZ);
		_csa_duration_to_iso8601(get_int_prop(p, CP_BEEPADV) *
			timescopestring_to_tick(get_char_prop(p, CP_BEEPUNIT)),
		a->beep->value->item.reminder_value->lead_time);
		a->beep->value->item.reminder_value->reminder_data.data = NULL;
		a->beep->value->item.reminder_value->reminder_data.size = 0;
	}
	if (convert_boolean_str(get_char_prop(p, CP_FLASHON))) {
		a->flash->value->item.reminder_value->lead_time = malloc(BUFSIZ);
		_csa_duration_to_iso8601(get_int_prop(p, CP_FLASHADV) *
			timescopestring_to_tick(get_char_prop(p, CP_FLASHUNIT)),
		a->flash->value->item.reminder_value->lead_time);
		a->flash->value->item.reminder_value->reminder_data.data = NULL;
		a->flash->value->item.reminder_value->reminder_data.size = 0;
	}
	if (convert_boolean_str(get_char_prop(p, CP_OPENON))) {
		a->popup->value->item.reminder_value->lead_time = malloc(BUFSIZ);
		_csa_duration_to_iso8601(get_int_prop(p, CP_OPENADV) *
			timescopestring_to_tick(get_char_prop(p, CP_OPENUNIT)),
		a->popup->value->item.reminder_value->lead_time);
		a->popup->value->item.reminder_value->reminder_data.data = NULL;
		a->popup->value->item.reminder_value->reminder_data.size = 0;
	}
	if (convert_boolean_str(get_char_prop(p, CP_MAILON))) {
		a->mail->value->item.reminder_value->lead_time = malloc(BUFSIZ);
		_csa_duration_to_iso8601(get_int_prop(p, CP_MAILADV) *
			timescopestring_to_tick(get_char_prop(p, CP_MAILUNIT)),
		a->mail->value->item.reminder_value->lead_time);
		a->mail->value->item.reminder_value->reminder_data.data = (CSA_uint8 *) strdup(get_char_prop(p, CP_MAILTO));
		a->mail->value->item.reminder_value->reminder_data.size = strlen(get_char_prop(p, CP_MAILTO)) + 1;
	}
}

extern char*
month_str(Months_op op) {
	if (op >= JANUARY && op <= DECEMBER)
		return month_strs[op];
	return NULL;
}

void
build_new_attrval(CSA_attribute *attrval, char *name, char *tag, char *value)

{
	CSA_attribute_value *vptr = calloc(sizeof(CSA_attribute_value), 1);
	char	*s_ptr, *b_ptr;
	CSA_access_list l_ptr;
	boolean_t	done = B_FALSE;
	CSA_access_list	*link_location;

	attrval->name = cm_strdup(name);
	attrval->value = vptr;

	if (!strcmp(tag, "string")) {
		vptr->type = CSA_VALUE_STRING;
		vptr->item.string_value = cm_strdup(value);
	}

	if (!strcmp(tag, "datetime")) {
		vptr->type = CSA_VALUE_DATE_TIME;
		vptr->item.date_time_value = cm_strdup(value);
	}

	if (!strcmp(tag, "caluser")) {
		vptr->type = CSA_VALUE_CALENDAR_USER;
		s_ptr = strchr(value, ':');
		*s_ptr = '\0';
		vptr->item.calendar_user_value = calloc(sizeof(CSA_calendar_user), 1);
		vptr->item.calendar_user_value->user_name = cm_strdup(s_ptr + 1);
		vptr->item.calendar_user_value->user_type = atoi(value);
	}

	if (!strcmp(tag, "uinteger")) {
		vptr->type = CSA_VALUE_UINT32;
		vptr->item.sint32_value = atoi(value);
	}

	if (!strcmp(tag, "sinteger")) {
		vptr->type = CSA_VALUE_SINT32;
		vptr->item.sint32_value = atoi(value);
	}

	if (!strcmp(tag, "reminder")) {
		vptr->type = CSA_VALUE_REMINDER;
		s_ptr = strchr(value, ':');
		*s_ptr = '\0';

		vptr->item.reminder_value = calloc(sizeof(CSA_reminder), 1);

		vptr->item.reminder_value->lead_time = malloc(BUFSIZ);
		_csa_duration_to_iso8601(atoi(value), vptr->item.reminder_value->lead_time);
		vptr->item.reminder_value->reminder_data.data = (CSA_uint8 *) strdup(s_ptr + 1);
		vptr->item.reminder_value->reminder_data.size = strlen(s_ptr + 1) + 1;
	}

	if (!strcmp(tag, "accesslist")) {

		/* The access list format is that each member in the
		   list is written out on a separate line.  So after
		   the initial newline in the value, the pattern is a
		   TAB followed by the mask value followed by a colon,
		   followed by the string. */

		vptr->type = CSA_VALUE_ACCESS_LIST;
		link_location = &vptr->item.access_list_value;
		b_ptr = value + 1;
		if (value && *b_ptr) {

			/* we have an initial value. */

			while (!done) {
				l_ptr = calloc(sizeof(CSA_access_rights), 1);

				s_ptr = strchr(b_ptr, ':');
				*s_ptr = '\0';

				l_ptr->rights = atoi(b_ptr);

				b_ptr = s_ptr + 1;
				if ( (s_ptr = strchr(b_ptr, '\n')) )
					*s_ptr = '\0';

				l_ptr->user->user_name = cm_strdup(b_ptr);

				if (s_ptr)
					b_ptr = s_ptr + 1;
				else
					done = B_TRUE;

				*link_location = l_ptr;
				link_location = &l_ptr->next;

			}
		}
	}

}

static void
read_new_appt(FILE *fp, Dtcm_appointment **appt, Props *p, int version)

{
	int			attrs_allocated, attrs_written = 0;
	char			line[MAXNAMELEN], *b_ptr, *c_ptr;
	char			*a_name = NULL, *a_tag = NULL, *a_value = NULL;
	Dtcm_appointment	*avlist;

	if (!new_appt_end_delimiter) {
		int size = strlen(CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER) + 14;
		new_appt_end_delimiter = malloc(size);
		snprintf(new_appt_end_delimiter, size, "%s%s",
			CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER,
			":string:end");
	}
	avlist = allocate_appt_struct(appt_write, DATAVER_ARCHIVE, NULL);
	load_appt_defaults(avlist, p);

	/* At this point, we really want to negate all of the links set
	   up by tha appointment allocation routine.  The following code is
	   almost certain to invalidate them, and some trailing links would
	   be harmful */

	avlist->identifier = NULL;
	avlist->modified_time = NULL;
	avlist->author = NULL;
	avlist->time = NULL;
	avlist->type = NULL;
	avlist->subtype = NULL;
	avlist->private = NULL;
	avlist->end_time = NULL;
	avlist->show_time = NULL;
	avlist->what = NULL;
	avlist->state = NULL;
	avlist->repeat_type = NULL;
	avlist->repeat_times = NULL;
	avlist->repeat_interval = NULL;
	avlist->repeat_week_num = NULL;
	avlist->recurrence_rule = NULL;
	avlist->beep = NULL;
	avlist->flash = NULL;
	avlist->mail = NULL;
	avlist->popup = NULL;

	attrs_allocated = avlist->count;

	/* should be starting a new attribute definition */

	while (fgets(line, MAXNAMELEN - 1, fp))
	{

		/* look for new end marker on appointment */

		if (strncmp(line, new_appt_end_delimiter, strlen(new_appt_end_delimiter)) == 0)
			break;

		if (line[0] == '\t') {

			/* This is a continuation line from the previous
			   attribute definition.  The value here should
			   be catenated onto the previously yanked value */

			b_ptr = line + 1;

			/* a line with only a tab on it, and no text
			   means that a newline should be inserted
			   into the stream */

			if (!*b_ptr)
				b_ptr = "\n";


			a_value = realloc(a_value, strlen(a_value) +
					  strlen(b_ptr) + 2);
			strlcat(a_value, "\n", sizeof(a_value));
			strlcat(a_value, b_ptr, sizeof(a_value));

			a_value[strlen(a_value) - 1] = '\0';

			continue;
		}
		else if (line[0] == '\n') {

			/* An empty line.  This means the end of
			   the appointment definition */

			break;
		}

		/* if the line is neither a termination line, nor
		   a continuation line, then the entry must be a new
		   attribute name.  We should declare the previous
		   triple complete. */

		if (a_name && a_tag && a_value)
		{

		/* see if the allocated buffer is large enough to
		   contain another attibute.  If not, make it a bit
		   larger, and then copy the attribute. */

			if (ident_name_ro(a_name, DATAVER_ARCHIVE) == B_FALSE) {
				if ((attrs_written) == attrs_allocated) {
					attrs_allocated += 10;
					avlist->attrs = realloc(avlist->attrs,
						sizeof(CSA_attribute) *
						attrs_allocated);
				}

				build_new_attrval(&avlist->attrs[attrs_written],
						  a_name, a_tag, a_value);
				++attrs_written;
			}

			free(a_name);
			free(a_tag);
			free(a_value);
		}

		/* this should pull off the new attribute name */

		a_name = a_tag = a_value = NULL;

		b_ptr = line;
		if ( (c_ptr = strchr(line, ':')) )
		{
			*c_ptr = '\0';
			a_name = cm_strdup(b_ptr);
		}
		else
			/* big problem.  Malformed attribute specification */

			break;

		b_ptr = c_ptr + 1;
		if (!*b_ptr)
			break;

		if ( (c_ptr = strchr(b_ptr, ':')) )
                {
                        *c_ptr = '\0';
                        a_tag = cm_strdup(b_ptr);
                }
                else
                        /* big problem.  Malformed attribute specification */

                        break;

		b_ptr = c_ptr + 1;
		if (!*b_ptr)
			break;
		else
			b_ptr[strlen(b_ptr) - 1] = '\0';

		a_value =  cm_strdup(b_ptr);
	}

	/* finished due to end of file.  Early termination, but not too bad */

	if (a_name && a_tag && a_value)
	{

	/* see if the allocated buffer is large enough to
	   contain another attibute.  If not, make it a bit
	   larger, and then copy the attribute. */

		if (ident_name_ro(a_name, DATAVER_ARCHIVE) == B_FALSE) {
			if ((attrs_written) == attrs_allocated) {
				attrs_allocated += 10;
				avlist->attrs = realloc(avlist->attrs,
					sizeof(CSA_attribute) *
					attrs_allocated);
			}

			build_new_attrval(&avlist->attrs[attrs_written],
					  a_name, a_tag, a_value);
			++attrs_written;
		}

		free(a_name);
		free(a_tag);
		free(a_value);
	}

	avlist->count = attrs_written;
	set_appt_links(avlist);
	*appt = avlist;
}


static char *
dow_str(
	time_t 	tick)
{
	switch (dow(tick)) {
	case 0:
		return (cm_strdup("SU"));
	case 1:
		return (cm_strdup("MO"));
	case 2:
		return (cm_strdup("TU"));
	case 3:
		return (cm_strdup("WE"));
	case 4:
		return (cm_strdup("TH"));
	case 5:
		return (cm_strdup("FR"));
	case 6:
	default:
		return (cm_strdup("SA"));
	}
}

/* this routine is designed to take in an appintment, and generate the
   DATAVER4 recurrence rule for that appointment.  It is also responsible
   for crushing out the old style attributes that may not be inserted
   into a newer style data model. */

static void
generate_recurrence_rule(Dtcm_appointment *appt, int version) {

	char            *str,
                         rule_buf1[32],
                         rule_buf2[32];
	int             rule_buf_size = 32;
	CSA_sint32	repeat_type;
	CSA_uint32	repeat_nth;
	CSA_uint32	repeat_for;
	Tick		appt_time;
	int     	wk;

        rule_buf1[0] = '\0';
        rule_buf2[0] = '\0';

	if (appt->repeat_type && appt->repeat_type->value)
		repeat_type = appt->repeat_type->value->item.sint32_value;
	else
		repeat_type = CSA_X_DT_REPEAT_ONETIME;

	if (appt->repeat_interval && appt->repeat_interval->value)
		repeat_nth = appt->repeat_interval->value->item.uint32_value;

	if (appt->repeat_times && appt->repeat_times->value)
		repeat_for = appt->repeat_times->value->item.uint32_value;

	_csa_iso8601_to_tick(appt->time->value->item.date_time_value, &appt_time);

	if (!appt->recurrence_rule || !appt->recurrence_rule->value) {
		switch (repeat_type) {

		case CSA_X_DT_REPEAT_ONETIME :
			strlcpy(rule_buf1, "D1 ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_DAILY :
			strlcpy(rule_buf1, "D1 ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_WEEKLY :
			strlcpy(rule_buf1, "W1 ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_BIWEEKLY :
			strlcpy(rule_buf1, "W2 ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_MONTHLY_BY_WEEKDAY :

			if (weekofmonth(appt_time, &wk) && wk == 5)
                       		snprintf(rule_buf1, rule_buf_size, "MP1 1- %s ", dow_str(appt_time));
               		else
                       		strlcpy(rule_buf1, "MP1 ", rule_buf_size);

			break;

		case CSA_X_DT_REPEAT_MONTHLY_BY_DATE :
			strlcpy(rule_buf1, "MD1 ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_YEARLY :
			strlcpy(rule_buf1, "YM1 ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_MON_TO_FRI :
			strlcpy(rule_buf1, "W1 MO TU WE TH FR ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_MONWEDFRI :
			strlcpy(rule_buf1, "W1 MO WE FR ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_TUETHUR :
			strlcpy(rule_buf1, "W1 TU TH ", rule_buf_size);
			break;

		case CSA_X_DT_REPEAT_EVERY_NDAY :
			snprintf(rule_buf1, rule_buf_size, "D%ld ", repeat_nth);
			break;

		case CSA_X_DT_REPEAT_EVERY_NWEEK :
			snprintf(rule_buf1, rule_buf_size, "W%ld ", repeat_nth);
			break;

		case CSA_X_DT_REPEAT_EVERY_NMONTH :
			snprintf(rule_buf1, rule_buf_size, "MD%ld ", repeat_nth);
			break;
		}

        	if (repeat_for == 0)
                	strlcat(rule_buf2, "#1", rule_buf_size);
        	else
                	snprintf(rule_buf2, rule_buf_size, "#%ld", repeat_for);

		strlcat (rule_buf1, rule_buf2, rule_buf_size);

		appt->attrs = realloc(appt->attrs,
                                      sizeof(CSA_attribute) * (appt->count + 1));

		build_new_attrval(&appt->attrs[appt->count],
                                  CSA_ENTRY_ATTR_RECURRENCE_RULE,
				  "string",
				  rule_buf1);

		appt->count++;

		set_appt_links(appt);
	}

	if (version == DATAVER_ARCHIVE)
		return;

	/* crush out the old values, if they exist */

	if (appt->repeat_type && appt->repeat_type->name) {
		free(appt->repeat_type->name);
		appt->repeat_type->name = NULL;
	}

	if (appt->repeat_times && appt->repeat_times->name) {
		free(appt->repeat_times->name);
		appt->repeat_times->name = NULL;
	}

	if (appt->repeat_interval && appt->repeat_interval->name) {
		free(appt->repeat_interval->name);
		appt->repeat_interval->name = NULL;
	}

	if (appt->repeat_week_num && appt->repeat_week_num->name) {
		free(appt->repeat_week_num->name);
		appt->repeat_week_num->name = NULL;
	}

}

/*
 * Given a file name, we're going to parse the file and create an appointment
 * for the calling routine.
 *
 * This function will scan for X number of appointments in the file and add
 * each to the linked list unless the validation routine returns an error.
 * If this happens, the invalid appointment is still added to the list so the
 * calling routine can do further processing if neccessary, but the remaining
 * appointments in the file (if any) are not read.
 */
extern Validate_op
parse_appt_from_file(nl_catd catd, char *file, CmDataList *list, Props *p,
		     boolean_t(*query)(), void *key_data, int version) {
	int			len, dur;
	char			line[MAXNAMELEN], *tmp, *key_str, *val_str,
				s_buf[MAXNAMELEN], e_buf[MAXNAMELEN],
				d_buf[MAXNAMELEN], r_buf[MAXNAMELEN],
				f_buf[MAXNAMELEN], *w_buf = NULL;
	FILE			*fp;
	boolean_t		processing_appt = B_FALSE,
				processing_what = B_FALSE;
	int			what_lines = 0;
	Validate_op		valid_op = VALID_APPT;
	Parse_key_op		pko = NOT_A_KEY;
	Dtcm_appointment	*appt;
	boolean_t		found_appt = B_FALSE;

	if (!file || *file == '\0' || (fp = fopen(file, "r")) == NULL)
		return COULD_NOT_OPEN_FILE;

	appt = allocate_appt_struct(appt_write, version, NULL);
	load_appt_defaults(appt, p);
	while (valid_op == VALID_APPT && fgets(line, MAXNAMELEN - 1, fp)) {
		/*
		 * Point key_str at the first non-space character
		 */
		key_str = line;

                if ((*line != ' ' && *line != '\t') || blank_buf(line)) {
			processing_what = B_FALSE;
			what_lines = 0;
		}

		/*
		 * The check for '*' handles the case when the appt header
		 * ``** Calendar Appointment **'' has no white space to its
		 * left.
		 */
		if (*key_str == '\0' ||
		    (!isspace((u_char)*key_str) && (u_char)*key_str != '*'))
			continue;

		while (*key_str != '\0' && isspace((u_char)*key_str))
			++key_str;

		pko = identify_parse_key(key_str);

		/*
		 * Remove any ending white space
		 */
		tmp = strrchr(line, '\0'); --tmp;
		while(isspace((u_char)*tmp)) {
			*tmp = '\0';
			--tmp;
		}

		/*
		 * If we're not currently processing the what string and we
		 * haven't identified a key, continue the loop.  Otherwise,
		 * we've identified a key, so we can't be in the middle of
		 * processing the what string -- set the flag accordingly.
		 *
		 */
		if (pko == NOT_A_KEY) {
			if (!processing_what || what_lines >= 5)
				continue;
			pko = WHAT_KEY;
		} else
		{
			processing_what = B_FALSE;
			what_lines = 0;
		}

		/*
		 * Point val_str at the next non-space character after the key
		 */
		val_str = key_str;
		while(*val_str != '\0' && !isspace((u_char)*val_str))
			++val_str;
		while(*val_str != '\0' && isspace((u_char)*val_str))
			++val_str;

		/*
		 * Now, based on the keyword, set the necessary stuff in the
		 * new appointment structure.
		 */
		switch(pko) {
		case APPOINTMENT_START:
			if (processing_appt) {
				/*
				 * We've reached another appointment.  Add the
				 * current to the linked list, reset flags, and
				 * check it's validity ...
				 */
				CmDataListAdd(list, (void *)appt, 0);

				valid_op = validate_appt(catd, appt, s_buf,
					e_buf, d_buf, dur, w_buf, r_buf, f_buf,
					query, key_data, version);
				if (valid_op == VALID_APPT) {
					appt = allocate_appt_struct(appt_write, version, NULL);
					load_appt_defaults(appt, p);
				}
				else
					processing_appt = B_FALSE;
			} else
				processing_appt = B_TRUE;

			found_appt = B_TRUE;

			dur = 0;
			memset(s_buf, '\0', MAXNAMELEN);
			memset(e_buf, '\0', MAXNAMELEN);
			memset(d_buf, '\0', MAXNAMELEN);
			memset(r_buf, '\0', MAXNAMELEN);
			memset(f_buf, '\0', MAXNAMELEN);
			if (w_buf)
				free(w_buf);
			w_buf = NULL;
			break;
		case DATE_KEY:
			cm_strlcpy(d_buf, val_str, MAXNAMELEN);
			break;
		case START_KEY:
			cm_strlcpy(s_buf, val_str, MAXNAMELEN);
			len = cm_strlen(s_buf) - 1;
			if (s_buf[len] == 'a' || s_buf[len] == 'p')
				cm_strlcat(s_buf, "m", MAXNAMELEN);
			break;
		case STOP_KEY:
			cm_strlcpy(e_buf, val_str, MAXNAMELEN);
			len = cm_strlen(e_buf) - 1;
			if (e_buf[len] == 'a' || e_buf[len] == 'p')
				cm_strlcat(e_buf, "m", MAXNAMELEN);
			break;
		case DURATION_KEY:
			dur = atoi(val_str);

			/*
			 * Check for a unit specification
			 */
			while(*val_str != '\0' && !isspace((u_char)*val_str))
				++val_str;
			while(*val_str != '\0' && isspace((u_char)*val_str))
				++val_str;

			switch(*val_str) {
			case 'h':
			case 'H':
				dur *= 3600;
				break;
			case 'd':
			case 'D':
				dur *= 86400;
				break;
			case 's':
			case 'S':
				break;
			case 'm':
			case 'M':
			default:
				dur *= 60;
				break;
			}
			break;
		case WHAT_KEY:
			/*
			 * If we're not currently processing a what string
			 * and we've got a what value, there were more than one
			 * what strings in the file - delete the first one and
			 * take the second.
			 *
			 * Otherwise, we in process, so alloc more space and
			 * concatinate the new string to the end of the last.
			 */
			if (!processing_what) {
				if (w_buf != NULL)
					free(w_buf);
				w_buf = cm_strdup(val_str);
				what_lines = 1;
			} else {
				tmp = w_buf;
				int size = cm_strlen(tmp) + cm_strlen(key_str) + 2;
				w_buf = (char *)ckalloc(size);
				cm_strlcpy(w_buf, tmp, size);
				cm_strlcat(w_buf, "\n", size);
				cm_strlcat(w_buf, key_str, size);
				free(tmp);
				what_lines++;
			}

			processing_what = B_TRUE;
			break;
		case REPEAT_KEY:
			cm_strlcpy(r_buf, val_str, MAXNAMELEN);
			break;
		case FOR_KEY:
			cm_strlcpy(f_buf, val_str, MAXNAMELEN);
			break;
		case NEW_APPT_KEY:
			if ((version >= DATAVER4) ||
			    (version == DATAVER_ARCHIVE)) {
				read_new_appt(fp, &appt, p, version);
				generate_recurrence_rule(appt, version);
				CmDataListAdd(list, (void *)appt, 0);
				processing_appt = B_FALSE;
				found_appt = B_TRUE;
			}
			break;
		case NOT_A_KEY:
		default:
			break;
		}
	}

	/*
	 * Because the appointment read is only saved when we start reading the
	 * next appointment, the last appointment (which doesn't have a next)
	 * will always be left off ... so, providing we're processing an
	 * appointment -- meaning we've found at least one header -- save the
	 * appointment in process.
	 */

	if (found_appt == B_FALSE) {
		fclose(fp);
		return(INVALID_DATE);
	}

	if (processing_appt) {
		CmDataListAdd(list, (void *)appt, 0);
		valid_op = validate_appt(catd, appt, s_buf, e_buf, d_buf, dur,
					 w_buf, r_buf, f_buf, query, key_data,
					 version);
		if (w_buf)
			free(w_buf);
	}

	scrub_attr_list(appt);

	fclose(fp);
	return valid_op;
}

void
growcat(char **source, char *new)
{
	int length = strlen(*source) + strlen(new) + 2;
	*source = (char *) realloc(*source, length);
	strlcat(*source, new, length);
}

void
cat_indented_string(char **catbuf, char *string)
{
	register char 	*p_str = string;
	int		nl_count = 0;
	char		*buf;
	register char	*b_ptr;

	nl_count = count_newlines(string);

	b_ptr = buf = malloc(strlen(string) + nl_count + 1);

	while (*p_str) {
		*b_ptr++ = *p_str;
		if (*p_str == '\n')
			*b_ptr++ = '\t';
		p_str++;
	}
	*b_ptr = '\0';

	growcat(catbuf, buf);

	free(buf);
}

char *
attrs_to_string(CSA_attribute * attrs, int num_attrs)
{
	int i;
	CSA_access_list  a_ptr;
	char		*buffer = malloc(1);
	char		tmp_buf[MAXNAMELEN];
	int		advance_time;

	buffer[0] = '\0';
        for (i = 0; i < num_attrs; i++) {
		if (!attrs[i].name || (attrs[i].value == NULL))
			continue;

		tmp_buf[0] = '\0';
                snprintf(tmp_buf, MAXNAMELEN, "%s:", attrs[i].name);
		switch (attrs[i].value->type) {
		case CSA_VALUE_SINT32:
				growcat(&buffer, tmp_buf);
				snprintf(tmp_buf, MAXNAMELEN, "sinteger:%ld\n",
					attrs[i].value->item.sint32_value);
				growcat(&buffer, tmp_buf);
				break;

		case CSA_VALUE_UINT32:
				growcat(&buffer, tmp_buf);
				snprintf(tmp_buf, MAXNAMELEN, "uinteger:%ld\n",
					attrs[i].value->item.uint32_value);
				growcat(&buffer, tmp_buf);
				break;

		case CSA_VALUE_DATE_TIME:
				if (attrs[i].value->item.string_value == NULL)
					continue;

				growcat(&buffer, tmp_buf);
				growcat(&buffer, "datetime:");
				if (attrs[i].value->item.date_time_value)
					cat_indented_string(&buffer,
						attrs[i].value->item.string_value);
				growcat(&buffer, "\n");
				break;

		case CSA_VALUE_STRING:
				if (attrs[i].value->item.string_value == NULL)
					continue;

				growcat(&buffer, tmp_buf);
				growcat(&buffer, "string:");
				if (attrs[i].value->item.string_value)
					cat_indented_string(&buffer,
						attrs[i].value->item.string_value);
				growcat(&buffer, "\n");
				break;
		case CSA_VALUE_CALENDAR_USER:
				if (attrs[i].value->item.calendar_user_value == NULL)
					continue;

				growcat(&buffer, tmp_buf);
				snprintf(tmp_buf, MAXNAMELEN, "caluser:%ld:", attrs[i].value->item.calendar_user_value->user_type);
				growcat(&buffer, tmp_buf);
				if (attrs[i].value->item.calendar_user_value->user_name)
					cat_indented_string(&buffer,
						attrs[i].value->item.calendar_user_value->user_name);

				growcat(&buffer, "\n");
				break;

		case CSA_VALUE_REMINDER:
				if (attrs[i].value->item.reminder_value->lead_time == NULL)
					continue;

				growcat(&buffer, tmp_buf);
				_csa_iso8601_to_duration(attrs[i].value->item.reminder_value->lead_time, &advance_time);
				snprintf(tmp_buf, MAXNAMELEN, "reminder:%d:", advance_time);
				growcat(&buffer, tmp_buf);
				if (attrs[i].value->item.reminder_value->reminder_data.data)
					cat_indented_string(&buffer,
						(char *) attrs[i].value->item.reminder_value->reminder_data.data);
				growcat(&buffer, "\n");
				break;

		case CSA_VALUE_ACCESS_LIST:
				if (attrs[i].value->item.access_list_value == NULL)
					continue;

				growcat(&buffer, tmp_buf);
				growcat(&buffer, "accesslist:\n");
				a_ptr = attrs[i].value->item.access_list_value;
				while (a_ptr) {
					snprintf(tmp_buf, MAXNAMELEN, "\t%d:%s\n",
						(int) a_ptr->rights, a_ptr->user->user_name);
					growcat(&buffer, tmp_buf);
					a_ptr = a_ptr->next;
				}
				break;
		}
	}

	return(buffer);
}

char *
entry_to_attrval_string(CSA_session_handle target, CSA_entry_handle entry)
{
	int 			i;
	char			*ptr;
	CSA_attribute_reference *names;
	CSA_attribute   	*attrs_ret;
	CSA_uint32		num_attrs, num_attrs_ret;

	csa_list_entry_attributes(target, entry, &num_attrs, &names, NULL);
	csa_read_entry_attributes(target, entry, num_attrs, names, &num_attrs_ret,
		&attrs_ret, NULL);

	ptr = attrs_to_string(attrs_ret, num_attrs_ret);

/* PORTING NOTE:
**   Need to check that library's memory management will
**   properly free this.  Old scheme had a special fn to
**   to it, which took a pointer and a count. - dac
**
**	[old version: DtCmFreeAttributeValues(attrs, num_attrs); ]
*/
	csa_free(attrs_ret);
	csa_free(names);

	return(ptr);
}

char *
calendar_to_attrval_string(CSA_session_handle cal)
{
	int 			i;
	CSA_uint32		num_attrs, num_attrs_ret;
	CSA_attribute_reference	*names;
	char			*ptr;
	CSA_attribute 		*attrs_ret;

	csa_list_calendar_attributes(cal, &num_attrs, &names, NULL);
	csa_read_calendar_attributes(cal, num_attrs, names, &num_attrs_ret,
		&attrs_ret, NULL);

	ptr = attrs_to_string(attrs_ret, num_attrs_ret);

	csa_free(attrs_ret);
	csa_free(names);

	return(ptr);
}

/*
 * Given an appointment structure, return a character string that can be used
 * for DnD or written to a file.
 */
extern char*
parse_appt_to_string(CSA_session_handle target, CSA_entry_handle entry, Props *p, int version) {
	char			*ret_val, *attr_string;
	Dtcm_appointment	*appt;
	CSA_uint32      	na_ret; /* num of attributes actually read */
	CSA_attribute   	a_ret;  /* list of attrs actually read */

	attr_string = entry_to_attrval_string(target, entry);

	/*
	 * Extract the info we need from the back-end entry
	 */
	appt = allocate_appt_struct(appt_read,
					version,
				    	NULL);

	query_appt_struct(target, entry, appt);
	ret_val = parse_attrs_to_string(appt, p, attr_string);
	free_appt_struct(&appt);
	free (attr_string);

	return ret_val;
}

extern char*
parse_attrs_to_string(Dtcm_appointment *appt, Props *p, char *attr_string) {
	int		nlcount, duration, repeat_nth, repeat_wk, wk;
	char		*whatstr, d_buf[MAXNAMELEN],
			s_buf[MAXNAMELEN], e_buf[MAXNAMELEN], w_buf[MAXNAMELEN],
			r_buf[MAXNAMELEN], f_buf[MAXNAMELEN], *appt_what,
			*b_ptr;
	time_t		tick, end_tick = 0;
	CSA_sint32	repeat_type = -1;
	CSA_uint32	repeat_times;
        static char *format_string = "\n\n\t** Calendar Appointment **\n%s:string:begin\n%s%s:string:end\n\tDate: %s\n\tStart: %s\n\tEnd: %s\n\tRepeat: %s\n\tFor: %s\n\tWhat: %s";

	s_buf[0] = '\0';
	e_buf[0] = '\0';
	w_buf[0] = '\0';
	r_buf[0] = '\0';
	f_buf[0] = '\0';

	_csa_iso8601_to_tick(appt->time->value->item.date_time_value, &tick);
	if (appt->end_time)
		if (appt->end_time->value != NULL)
			_csa_iso8601_to_tick(appt->end_time->value->item.\
				date_time_value, &end_tick);

	appt_what = appt->what->value->item.string_value;

	if (appt->repeat_type && appt->repeat_type->value)
		repeat_type = appt->repeat_type->value->item.sint32_value;

	if (appt->repeat_times && appt->repeat_times->value)
		repeat_times = appt->repeat_times->value->item.uint32_value;
	else
		repeat_times = 0;

	if (appt->repeat_interval && appt->repeat_interval->value)
		repeat_nth = appt->repeat_interval->value->item.uint32_value;
	else
		repeat_nth = 0;

	if (appt->repeat_week_num && appt->repeat_week_num->value)
		repeat_wk = appt->repeat_week_num->value->item.sint32_value;
	else
		repeat_wk = 0;

	/*
	 * Format the date and start/stop strings
	 */
        format_tick(tick, ORDER_MDY, SEPARATOR_SLASH, d_buf, MAXNAMELEN);
	format_time(tick, get_int_prop(p, CP_DEFAULTDISP), s_buf, MAXNAMELEN);
	format_time(end_tick, get_int_prop(p, CP_DEFAULTDISP), e_buf, MAXNAMELEN);

	/*
	 * Handle the what string
	 */
        whatstr = appt_what;
	if ((nlcount = count_newlines(appt_what)) > 0) {
		whatstr = (char *)ckalloc(cm_strlen(appt_what) + nlcount + 1);
		copy_and_pad_newlines(whatstr, appt_what);
	}
        if (whatstr && !blank_buf(whatstr)) {
                cm_strlcat(w_buf, whatstr, MAXNAMELEN);
                cm_strlcat(w_buf, "\n\t", MAXNAMELEN);
        }

	/*
	 * Repeat and For stuff
	 */
        cm_strlcpy(r_buf, periodstr_from_period(repeat_type, repeat_nth), MAXNAMELEN);
	if (repeat_type == CSA_X_DT_REPEAT_MONTHLY_BY_WEEKDAY) {
		if (weekofmonth(tick, &wk) && wk == 4) {
			if (repeat_wk == -1)
				strlcat(r_buf, ", last", MAXNAMELEN);
			else if (repeat_wk == 4)
				strlcat(r_buf, ", 4th", MAXNAMELEN);
		}
	}

        snprintf(f_buf, MAXNAMELEN, "%ld", repeat_times);

	/*
	 * Put it all together
	 */

	int b_ptr_length = cm_strlen(d_buf) +
                             (2 * cm_strlen(CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER)) +
                             cm_strlen(s_buf) +
                             cm_strlen(e_buf) +
                             cm_strlen(r_buf) +
                             cm_strlen(f_buf) +
                             cm_strlen(w_buf) +
                             cm_strlen(format_string) +
                             cm_strlen(attr_string) +
                             1;

	b_ptr = malloc(b_ptr_length);

        snprintf(b_ptr, b_ptr_length, format_string,
		CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER,
		attr_string,
		CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER,
		d_buf, s_buf, e_buf, r_buf, f_buf, w_buf);

	if (nlcount > 0)
		free(whatstr);
	return(b_ptr);
}

/* This routine takes a list of buffers that represent a number
   of message attachments, and glues them into a mime format
   message for eventual submission to the dtmail mailer.  These
   objects do nor *need* to be cm appointment objects. */

char *
create_rfc_message(char *address_list,
		char *subject,
		char **appointment_objects,
		int  num_objects) {

	char *unique_label;

	/* do *not* put these header strings in a message catalog.
	   These are invariants specified by MIME */

	char *address_header = "To: ";
	char *subject_header = "Subject: ";
	char *x_content_name = "X-Content-Name: CalendarAppointment\n";
	char *content_label = "Mime-Version: 1.0\nContent-Type: multipart/mixed;boundary=";
    	char divider_string[36];

	int  buffer_size;
	int  i;
	boolean_t  done = B_FALSE;
	char *return_buffer;

	/* A MIME mesage is a rather specialized beast.  It consists of
	   a series of headers describing the mail message, followed by
	   the message, and then followed by a set of attachments.
	   Each attachments is separated by a magic unique string
	   flagging the boundaries between the attached objects.  The
	   first header is the address list.  The second header is the
	   subject line for the message.  The third header describes the
	   MIME version of the message.  The forth describes the type of
	   information within the message and the magic string used for
	   part divisions.

	   Each division is two dashes, the unique string, and a newline
	   The last dividing string is trailed by two more dashes. */


	/* we need to generate a unique dividing string that will
	   not be found in any of the parts of the MIME message.
	   The following printf will be tried until it generates
	   something that isn't in any of the body parts. */

	while (done != B_TRUE) {
    		snprintf(divider_string, sizeof(divider_string), "%x_%x-%x_%x-%x_%x", arc4random(), arc4random(),
			arc4random(), arc4random(), arc4random(), arc4random());

		done = B_TRUE;

		for (i = 0; i < num_objects; i++) {
			if (strstr(appointment_objects[i], divider_string) != NULL)
				done = B_FALSE;
		}
	}

	buffer_size = 	strlen(address_header) +
			strlen(address_list) +
			1 +			     /* newline */
			strlen(subject_header) +
			strlen(subject) +
			1 +			     /* newline */
			strlen(content_label) +  2 +
			(num_objects + 2) * strlen(divider_string) +
						     /* one definition copy,
							one terminating copy,
							and one per body
							part */

	    		5 + strlen(divider_string) + /* empty body part */

	    		num_objects * strlen(x_content_name) +
						     /* one X-Content-Name
							line for each
							body part */

			(2 * num_objects) + 4 +	     /* bracketing on unique
							strings */
			(num_objects * 3) + 2;	     /* newlines...3 per
						        body part boundary
							and 2 for the
							terminating boundary */

	for (i = 0; i < num_objects; i++)
		buffer_size += strlen(appointment_objects[i]);

	/* extra byte is added for null char */
	return_buffer = (char *)calloc(buffer_size + 1, 1);

	snprintf(return_buffer, buffer_size + 1, "%s%s\n%s%s\n%s%s\n\n",
			address_header,
			address_list,
			subject_header,
			subject,
			content_label,
			divider_string);

	/*
	 * Add an empty body part.  This is a hack to get dtmail to
	 * display the object(s) as an attachment.
	 */
	strlcat(return_buffer, "\n--", buffer_size + 1);
	strlcat(return_buffer, divider_string, buffer_size + 1);
	strlcat(return_buffer, "\n\n", buffer_size + 1);

	for (i = 0; i <num_objects; i++) {
		strlcat(return_buffer, "\n--", buffer_size + 1);
		strlcat(return_buffer, divider_string, buffer_size + 1);
		strlcat(return_buffer, "\n", buffer_size + 1);
		strlcat(return_buffer, x_content_name, buffer_size + 1);
		strlcat(return_buffer, "\n", buffer_size + 1);
		strlcat(return_buffer, appointment_objects[i], buffer_size + 1);
	}
	strlcat(return_buffer, "\n--", buffer_size + 1);
	strlcat(return_buffer, divider_string, buffer_size + 1);
	strlcat(return_buffer, "--", buffer_size + 1);
	strlcat(return_buffer, "\n", buffer_size + 1);

	return(return_buffer);
}

boolean_t
appointments_to_file(CSA_session_handle target, CSA_entry_handle *appointment_list,
		     int num_appts,
		     char *file_name) {

	int i;
	char *entry_string;

	FILE *f_ptr = fopen(file_name,  "w");

	if (f_ptr == NULL)
		return(B_FALSE);

	if (num_appts == 0)
		return(B_FALSE);

	fprintf(f_ptr, "DTCM Archive 1.0\n");
	for (i = 0; i < num_appts; i++) {
		entry_string = entry_to_attrval_string(target, appointment_list[i]);

		fprintf(f_ptr, "\n-%s:string:begin\n%s%s:string:end\n\n",
			CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER,
			entry_string,
			CSA_X_DT_ENTRY_ATTR_ENTRY_DELIMITER);

		free(entry_string);
	}

	fclose(f_ptr);

	return(B_TRUE);
}

/*
 * NOTE!!  These are strings used in versions 1-4 - the repeat strings read
 * from a file or passed to the cm_tty_insert routine are checked against
 * these strings as well as the V5 API strings.
 */
static char *periodstrings[] = {
	"One Time",
	"Daily",
	"Weekly",
	"Every Two Weeks",
	"Monthly By Date",
	"Yearly",
	"Monthly By Weekday",
	"days",
	"weeks",
	"months",
	"other",
	"Monday thru Friday",
	"Mon, Wed, Fri",
	"Tuesday, Thursday",
	"Weekday Combo",
	"Every"
};

extern void
str_to_period(char *ps, CSA_sint32 *repeat_type, int *repeat_nth) {
	boolean_t	compute_times = B_FALSE;
	char		*ps2, *ptr, *ptr2, *unit;

	*repeat_type = '\0';
	*repeat_nth = 0;
        if (ps == NULL)
		return;

        if (strcasecmp(ps, periodstrings[0]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_ONETIME;
        else if (strcasecmp(ps, periodstrings[1]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_DAILY;
        else if (strcasecmp(ps, periodstrings[2]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_WEEKLY;
        else if (strcasecmp(ps, periodstrings[3]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_BIWEEKLY;
        else if (strcasecmp(ps, periodstrings[4]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_MONTHLY_BY_DATE;
        else if (strcasecmp(ps, periodstrings[5]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_YEARLY;
        else if (strncasecmp(ps, periodstrings[6],
			     strlen(periodstrings[6])) == 0)
		*repeat_type = CSA_X_DT_REPEAT_MONTHLY_BY_WEEKDAY;
        else if (strcasecmp(ps, periodstrings[10]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_OTHER;
        else if (strcasecmp(ps, periodstrings[11]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_MON_TO_FRI;
        else if (strcasecmp(ps, periodstrings[12]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_MONWEDFRI;
        else if (strcasecmp(ps, periodstrings[13]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_TUETHUR;
        else if (strcasecmp(ps, periodstrings[14]) == 0)
		*repeat_type = CSA_X_DT_REPEAT_WEEKDAYCOMBO;
	else if (strncasecmp(ps, periodstrings[15], strlen(periodstrings[15])) == 0) {
		compute_times = B_TRUE;
	}
	else
		*repeat_type = CSA_X_DT_REPEAT_ONETIME;

	if ((compute_times) && (unit = strchr(ps, ' '))) {
		while (*unit == ' ')
			unit++;
                ps2 = cm_strdup(unit);
                ptr = strchr(ps2, ' ');
		if (ptr != NULL)
                	*ptr = '\0';
		else
			return;

		ptr++;
		while (*ptr == ' ')
			ptr++;

                *repeat_nth = atoi(ps2);
        	if (strcasecmp(ptr, periodstrings[7]) == 0) {
			*repeat_type = CSA_X_DT_REPEAT_EVERY_NDAY;
		}
        	else if (strcasecmp(ptr, periodstrings[8]) == 0) {
			*repeat_type = CSA_X_DT_REPEAT_EVERY_NWEEK;
		}
        	else if (strcasecmp(ptr, periodstrings[9]) == 0) {
			*repeat_type = CSA_X_DT_REPEAT_EVERY_NMONTH;
		}
                free(ps2);
        }
}

extern char*
periodstr_from_period(CSA_sint32 repeat_type, int repeat_nth) {
        int length = 80;
	static char pstr[80];

	switch (repeat_type) {
        case CSA_X_DT_REPEAT_ONETIME:
		snprintf(pstr, length, "%s", periodstrings[0]);
		break;
        case CSA_X_DT_REPEAT_DAILY:
		snprintf(pstr, length, "%s", periodstrings[1]);
		break;
        case CSA_X_DT_REPEAT_WEEKLY:
		snprintf(pstr, length, "%s", periodstrings[2]);
		break;
        case CSA_X_DT_REPEAT_BIWEEKLY:
		snprintf(pstr, length, "%s", periodstrings[3]);
		break;
        case CSA_X_DT_REPEAT_MONTHLY_BY_DATE:
		snprintf(pstr, length, "%s", periodstrings[4]);
		break;
        case CSA_X_DT_REPEAT_YEARLY:
		snprintf(pstr, length, "%s", periodstrings[5]);
		break;
        case CSA_X_DT_REPEAT_MONTHLY_BY_WEEKDAY:
		snprintf(pstr, length, "%s", periodstrings[6]);
		break;
        case CSA_X_DT_REPEAT_EVERY_NDAY:
		snprintf(pstr, length, "Every %d %s", repeat_nth, periodstrings[7]);
		break;
        case CSA_X_DT_REPEAT_EVERY_NWEEK:
		snprintf(pstr, length, "Every %d %s", repeat_nth, periodstrings[8]);
		break;
        case CSA_X_DT_REPEAT_EVERY_NMONTH:
		snprintf(pstr, length, "Every %d %s", repeat_nth, periodstrings[9]);
		break;
        case CSA_X_DT_REPEAT_OTHER:
		snprintf(pstr, length, "%s", periodstrings[10]);
		break;
        case CSA_X_DT_REPEAT_MON_TO_FRI:
		snprintf(pstr, length, "%s", periodstrings[11]);
		break;
        case CSA_X_DT_REPEAT_MONWEDFRI:
		snprintf(pstr, length, "%s", periodstrings[12]);
		break;
        case CSA_X_DT_REPEAT_TUETHUR:
		snprintf(pstr, length, "%s", periodstrings[13]);
		break;
        case CSA_X_DT_REPEAT_WEEKDAYCOMBO:
		snprintf(pstr, length, "%s", periodstrings[14]);
		break;
	default:
		snprintf(pstr, length, "Unknown repeat type");
		break;
	}

        return pstr;
}

/*
 * NOTE!!  These first set of these strings are used in versions 1-4 - the
 * privacy strings read from a file or passed to the cm_tty_insert routine are
 * checked against these strings as well as the V5 API strings and the new
 * strings.
 */
static char *privacy_strs_old[] = {
	"Show Time And Text",
	"Show Time Only",
	"Show Nothing"
};

static char *privacy_strs[] = {
	"Others See Time And Text",
	"Others See Time Only",
	"Others See Nothing"
};

static char *privacy_strs_411[] = {
	"none",
	"cm_what",
	"all"
};

extern char*
privacy_str_old(int op) {
	if (op >= 0 && op <= 2)
		return privacy_strs_old[op];
	return NULL;
}

extern char*
privacy_str(int op) {
	if (op >= 0 && op <= 2)
		return privacy_strs[op];
	return NULL;
}

static void
init_repeat_strs(
	nl_catd		catd,
	char	      **repeat_strs)
{
	repeat_strs[ONE_TIME] = strdup(catgets(catd, 1, 852, "One Time"));
	repeat_strs[DAILY] = strdup(catgets(catd, 1, 853, "Daily"));
	repeat_strs[WEEKLY] = strdup(catgets(catd, 1, 854, "Weekly"));
	repeat_strs[EVERY_TWO_WEEKS] =
			strdup(catgets(catd, 1, 855, "Every Two Weeks"));
	repeat_strs[MONTHLY_BY_DATE] =
			strdup(catgets(catd, 1, 856, "Monthly By Date"));
	repeat_strs[MONTHLY_BY_WEEKDAY] =
			strdup(catgets(catd, 1, 857, "Monthly By Weekday"));
	repeat_strs[YEARLY] =
			strdup(catgets(catd, 1, 858, "Yearly"));
	repeat_strs[MONDAY_THRU_FRIDAY] =
			strdup(catgets(catd, 1, 859, "Monday Thru Friday"));
	repeat_strs[MON_WED_FRI] =
			strdup(catgets(catd, 1, 860, "Mon, Wed, Fri"));
	repeat_strs[TUESDAY_THURSDAY] =
			strdup(catgets(catd, 1, 861, "Tuesday, Thursday"));
	repeat_strs[REPEAT_EVERY] =
			strdup(catgets(catd, 1, 862, "Repeat Every..."));
}

extern char*
repeat_str(
	nl_catd		catd,
	Repeat_menu_op  op)
{
	if (!repeat_strs[0])
		init_repeat_strs(catd, repeat_strs);

	if (op >= ONE_TIME && op <= REPEAT_EVERY)
		return repeat_strs[op];
	return NULL;
}

extern char*
privacy_str_411(int op) {
	if (op >= 0 && op <= 2)
		return privacy_strs_411[op];
	return NULL;
}

extern char*
repeat_scope_str(
	nl_catd		     catd,
	Repeat_scope_menu_op op)
{
	if (!repeat_scope_strs[0]) {
		repeat_scope_strs[REPEAT_DAYS] =
				strdup(catgets(catd, 1, 994, "days"));
		repeat_scope_strs[REPEAT_WEEKS] =
				strdup(catgets(catd, 1, 995, "weeks"));
		repeat_scope_strs[REPEAT_MONTHS] =
				strdup(catgets(catd, 1, 997, "months"));
	}

	if (op >= REPEAT_DAYS && op <= REPEAT_MONTHS)
		return repeat_scope_strs[op];
	return NULL;
}

extern char*
separator_str(SeparatorType op) {
	if (op >= SEPARATOR_BLANK && op <= SEPARATOR_DASH)
		return separator_strs[op];
	return NULL;
}

extern int
timescopestring_to_tick(char *str) {
	if (strcasecmp(time_scope_strs[1], str) == 0)
		return hrsec;
	else if (strcasecmp(time_scope_strs[2], str) == 0)
		return daysec;
	return minsec;
}

extern char*
time_scope_str(Time_scope_menu_op op) {
	if (op >= TIME_MINS && op <= TIME_DAYS)
		return time_scope_strs[op];
	return NULL;
}

extern char*
time_scope_str_i18n(
	nl_catd			catd,
	Time_scope_menu_op 	op)
{
	if (!time_scope_strs_i18n[0]) {
		time_scope_strs_i18n[TIME_MINS] =
					strdup(catgets(catd, 1, 877, "Mins"));
		time_scope_strs_i18n[TIME_HRS] =
					strdup(catgets(catd, 1, 878, "Hrs"));
		time_scope_strs_i18n[TIME_DAYS] =
					strdup(catgets(catd, 1, 879, "Days"));
	}

	if (op >= TIME_MINS && op <= TIME_DAYS)
		return time_scope_strs_i18n[op];
	return NULL;
}

/*
**  Determine whether or not the time passed is a valid format
*/
extern boolean_t
valid_time(Props *p, char *time_str) {
	char		*ptr;
	register int	num_minutes = 0, num_colons = 0;
	boolean_t	after_colon = B_FALSE;
	DisplayType	dt = get_int_prop(p, CP_DEFAULTDISP);

	for (ptr = time_str; ptr != NULL && *ptr != '\0'; ptr++) {
		if (dt == HOUR12) {
			if (*ptr == ':') {
				after_colon = B_TRUE;
				if ((++num_colons) > 1)
					return B_FALSE;
				if (*(ptr+1) == '\0')
					return B_FALSE;
			}
			else if (*ptr != ' ' && (*ptr < '0' || *ptr > '9') )
				return B_FALSE;
			if ((after_colon) && (*ptr != ':'))
				num_minutes++;
			if (num_minutes > 2)
				return B_FALSE;
			else if (num_minutes == 2) {
				++ptr;
				if (strncasecmp(ptr, "am", 2) == 0 ||
				    strncasecmp(ptr, "pm", 2) == 0)
					*ptr = '\0';
				--ptr;
			}
		}
		else if (dt == HOUR24) {
			if (*ptr != ' ' && (*ptr < '0' || *ptr > '9') )
				return B_FALSE;
			if (++num_minutes > 4)
				return B_FALSE;
		}
	}
	if (dt == HOUR12 && ((int)atoi(time_str) > 12))
		return B_FALSE;
	else if ((dt == HOUR24)
		&& ((int)atoi(time_str) > 2359))
		return B_FALSE;

        return B_TRUE;
}

/*
 * This method will validate the passed appointment data.
 *
 * Checks made:
 *	Date string incorrect		INVALID_DATE
 *	Tick for start is < 0		INVALID_START
 *	Tick for stop is < 0		INVALID_STOP
 *	Blank date			MISSING_DATE
 *	End time but no start time	MISSING_START
 *	Blank what with no times	MISSING_WHAT
 *	Period = single & for > 0	REPEAT_FOR_MISMATCH
 *	Period != single & for = 0	REPEAT_FOR_MISMATCH
 *
 * Note the function pointer passed to this function - if the end time is
 * before the start time, this function will be executed and should return
 * B_TRUE if the appointment should be scheduled to the next day, B_FALSE if
 * it should be canceled.
 */
extern Validate_op
validate_appt(nl_catd catd, Dtcm_appointment *a, char *s_buf, char *e_buf,
	      char *d_buf, int dur, char *w_buf, char *r_buf, char *f_buf,
	      boolean_t(*query)(void*), void *key_data, int version) {
	Validate_op	op;

	if ((op = validate_dssw(a, s_buf, e_buf, d_buf, dur, w_buf, query,
				key_data)) != VALID_APPT)
		return op;
	if ((op = validate_rfp(catd, a, r_buf, f_buf, version)) != VALID_APPT)
		return op;
	if ((op = validate_reminders(a)) != VALID_APPT)
		return op;

	return VALID_APPT;
}

extern Validate_op
validate_dssw(Dtcm_appointment *a, char *s_buf, char *e_buf, char *d_buf,
	      int dur, char *w_buf, boolean_t(*query)(), void *key_data) {
	Tick	end_tick = 0;
	char	buf[MAXNAMELEN];
	Tick	appt_time = 0;

	if (blank_buf(d_buf))
		return MISSING_DATE;

	a->time->value->item.date_time_value = malloc(BUFSIZ);
	_csa_tick_to_iso8601(0, a->time->value->item.date_time_value);

	a->show_time->value->item.sint32_value = B_TRUE;

	if (w_buf && w_buf[0] != '\0') {
		a->what->value->item.string_value = cm_strdup(w_buf);
		expand_esc_chars(a->what->value->item.string_value);
	} else
		a->what->value->item.string_value = NULL;

	if (!blank_buf(s_buf)) {
		/*
		 * We have something in the start buffer, is it valid?
		 */
		snprintf(buf, MAXNAMELEN, "%s %s", d_buf, s_buf);
		if ((appt_time = cm_getdate(buf, NULL)) < 0)
			return INVALID_START;

		_csa_tick_to_iso8601(appt_time, a->time->value->item.date_time_value);
		/*
		 * Okay, we have a valid start time - do we have a duration
		 * specified?
		 */
		if (dur > 0) {
			/*
			 * Duration is specified - add duration to start time
			 */
			end_tick = appt_time + dur;
			a->end_time->value->item.date_time_value = malloc(BUFSIZ);
			_csa_tick_to_iso8601(end_tick, a->end_time->value->item.date_time_value);
		} else if (!blank_buf(e_buf)) {
			/*
			 * No duration, but something in the end buffer.  If
			 * it's valid set the end tick to it's value.
			 */
			snprintf(buf, MAXNAMELEN, "%s %s", d_buf, e_buf);
			if ((end_tick = cm_getdate(buf, NULL)) < 0)
				return INVALID_STOP;
			a->end_time->value->item.date_time_value = malloc(BUFSIZ);
			_csa_tick_to_iso8601(end_tick, a->end_time->value->item.date_time_value);
		} else {
			/*
			 * No duration or end buffer - set end_tick to starting
			 * tick and duration to 0
			 */
			a->end_time->value->item.date_time_value =
				strdup(a->time->value->item.date_time_value);
		}
	} else if (dur > 0 || !blank_buf(e_buf))
		return MISSING_START;
	else {
		if (blank_buf(a->what->value->item.string_value))
			return MISSING_WHAT;

		/*
		 * If we're here, there was a date with no start or stop time,
		 * so set time to magic time (3:41 am - don't ask where that
		 * came from, 'cause I certainly don't know) and make sure the
		 * date was correct.  If so, set duration to 1 minute and
		 * showtime to false.
		 */
		snprintf(buf, MAXNAMELEN, "%s 3:41am", d_buf);

		if ((appt_time = cm_getdate(buf, NULL)) < 0)
			return INVALID_DATE;

                a->time->value->item.date_time_value = malloc(BUFSIZ);
		_csa_tick_to_iso8601(appt_time, a->time->value->item.date_time_value);

		end_tick = appt_time + minsec;

                a->end_time->value->item.date_time_value = malloc(BUFSIZ);
		_csa_tick_to_iso8601(end_tick, a->end_time->value->item.date_time_value);

		a->show_time->value->item.sint32_value = B_FALSE;
	}

	/*
	 * Finally, if the ending tick is before the starting tick, execute the
	 * passed function which should return B_TRUE if we should schedule
	 * this into the next day and B_FALSE if not.
	 *
	 * This allows for methods calling this function to be UI oriented or
	 * command line oriented as they can "query" the user appropriately.
	 */
	if (end_tick < appt_time) {
		if ((*query)(key_data) == B_TRUE) {
			while (end_tick < appt_time)
				end_tick += daysec;

	                _csa_tick_to_iso8601(end_tick, a->end_time->value->item.date_time_value);

		}
		else
			return CANCEL_APPT;
	}

	return VALID_APPT;
}

extern Validate_op
validate_reminders(Dtcm_appointment *a) {
	return VALID_APPT;
}

extern Validate_op
validate_rfp(
	nl_catd 		 catd,
	Dtcm_appointment 	*a,
	char 			*r_buf,
	char 			*f_buf,
	int 			 version)
{
	int			 repeat_nth,
				 repeat_wk = -1,
				 repeat_every = 0,
				 repeat_forever = False;
	CSA_sint32		 repeat_type = -1;
	CSA_uint32		 repeat_times = 0;

	int rule_buf_size = 32;
	char rule_buf[rule_buf_size];

	if (r_buf) {
		str_to_period(r_buf, &repeat_type, &repeat_nth);
		if (repeat_type == CSA_X_DT_REPEAT_MONTHLY_BY_WEEKDAY) {
		        r_buf += strlen(periodstrings[6]);
			while(*r_buf != '\0' && !isspace((u_char)*r_buf))
				++r_buf;
			while(*r_buf != '\0' && isspace((u_char)*r_buf))
				++r_buf;

			if (strncasecmp(r_buf, "last", 4) != 0)
				repeat_wk = atoi(r_buf);
		}
	}

	if (f_buf) {
		/* Repeat forever is represented by either:
			f_buf == ``forever''   or
			f_buf == ``0''.
		   If it is a CSA_X_DT_REPEAT_ONETIME then
			f_buf == ``0''.
		 */
		if (strcasecmp(f_buf, catgets(catd, 1, 876, "forever")) == 0) {
			repeat_times = CSA_X_DT_DT_REPEAT_FOREVER;
			repeat_forever = True;
		} else {
			repeat_times = atoi(f_buf);
			if (repeat_times == CSA_X_DT_DT_REPEAT_FOREVER &&
			    repeat_type != CSA_X_DT_REPEAT_ONETIME)
				repeat_forever = True;
		}
	}

	/* If it is a onetime event then it cannot repeat.
	 * If it is a repeating event then repeat_times must be greater
	 * than 0 unless it is supposed to repeat forever.
	 */
	if (((repeat_type != CSA_X_DT_REPEAT_ONETIME) &&
	    (repeat_times == 0) && (repeat_forever != True)) ||
	    ((repeat_type == CSA_X_DT_REPEAT_ONETIME) &&
	     ((repeat_times != 0) || (repeat_forever == True))))
		return REPEAT_FOR_MISMATCH;

	if (a->repeat_type && a->repeat_type->value)
		a->repeat_type->value->item.sint32_value = repeat_type;
	if (a->repeat_times && a->repeat_times->value)
		a->repeat_times->value->item.uint32_value = repeat_times;
	if (a->repeat_interval && a->repeat_interval->value)
		a->repeat_interval->value->item.uint32_value = repeat_nth;
	if (a->repeat_week_num && a->repeat_week_num->value)
		a->repeat_week_num->value->item.sint32_value = repeat_wk;

	/* If we are less than data version 4, we're done. */
	if (version < DATAVER4)
		return VALID_APPT;

	/* Data version 4 appts use a recurrence rule. */
	memset (rule_buf, 0, 32);

	switch(repeat_type) {
	case CSA_X_DT_REPEAT_ONETIME:
	case CSA_X_DT_REPEAT_DAILY:
		strlcpy(rule_buf, "D1 ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_WEEKLY:
		strlcpy(rule_buf, "W1 ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_BIWEEKLY:
		strlcpy(rule_buf, "W2 ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_MONTHLY_BY_DATE:
		strlcpy(rule_buf, "MD1 ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_MONTHLY_BY_WEEKDAY: {
		int 	wk;
		Tick	tick = 0;

		if (a && a->time && a->time->value) {
			_csa_iso8601_to_tick(
					a->time->value->item.date_time_value,
				     	&tick);
		}

		/*
                 * The current behavior of cm/dtcm is that if an appt is
                 * scheduled for the 5 wk of the month, it repeats on the
                 * last week of the month.
                 */
                if (tick && weekofmonth(tick, &wk) && wk == 5)
                        snprintf(rule_buf, rule_buf_size, "MP1 1- %s ", dow_str(tick));
                else
                        strlcpy(rule_buf, "MP1 ", rule_buf_size);
                break;
        }
	case CSA_X_DT_REPEAT_YEARLY:
		strlcpy(rule_buf, "YM1 ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_MON_TO_FRI:
		strlcpy(rule_buf, "W1 MO TU WE TH FR ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_MONWEDFRI:
		strlcpy(rule_buf, "W1 MO WE FR ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_TUETHUR:
		strlcpy(rule_buf, "W1 TU TH ", rule_buf_size);
		break;
	case CSA_X_DT_REPEAT_EVERY_NDAY:
		snprintf(rule_buf, rule_buf_size, "D%d ", repeat_nth);
		repeat_every = True;
		break;
	case CSA_X_DT_REPEAT_EVERY_NWEEK:
		snprintf(rule_buf, rule_buf_size, "W%d ", repeat_nth);
		repeat_every = True;
		break;
	case CSA_X_DT_REPEAT_EVERY_NMONTH:
		snprintf(rule_buf, rule_buf_size, "MD%d ", repeat_nth);
		repeat_every = True;
		break;
	default:
		return CANCEL_APPT;
	}

	/* If the for buffer is NULL then we default to repeating one time.
	 * If the repeat_type is onetime then we default repeat times to
	 * one time.
	 */
	if (!f_buf || repeat_type == CSA_X_DT_REPEAT_ONETIME)
		repeat_times = 1;

	if (repeat_times == CSA_X_DT_DT_REPEAT_FOREVER) {
		strlcat(rule_buf, "#0", rule_buf_size);
	} else {
		int buf_length = 16;
		char buf[buf_length];

		if (repeat_every) {
			int duration;

			if (repeat_times % repeat_nth)
				duration = 1 + repeat_times/repeat_nth;
			else
				duration = repeat_times/repeat_nth;
			snprintf(buf, buf_length, "#%d", duration);
		} else
			snprintf(buf, buf_length, "#%ld", repeat_times);

		strlcat(rule_buf, buf, buf_length);
	}
	a->recurrence_rule->value->item.string_value = strdup(rule_buf);

	return VALID_APPT;
}
