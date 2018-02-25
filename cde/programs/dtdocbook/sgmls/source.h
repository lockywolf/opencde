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
/* $XConsortium: source.h /main/3 1996/06/19 17:18:30 drk $ */
/* SOURCE.H: Entity and source control block structures and definitions.
 */
#define ENTHASH 503 /* Size of entity hash table.  Must be prime. */
/* Entity storage class values for estore member of entity structure. */
#define EST 1   /* String: Tag (usually a fixed STARTGI). */
                /* <MDENTITY sets these:> */
#define ESMD 2  /* String: Markup declaration. */
#define ESMS 3  /* String: Marked section. */
#define ESM 4   /* String: ordinary text. */
                /* <ENTOPEN treats these specially:> */
#define ESS 5   /* ETD: Start-tag. */
#define ESE 6   /* ETD: End-tag. */
#define ESI 7   /* String: PI. */
#define ESX 8   /* String: SDATA general entity. */
#define ESC 9   /* String: CDATA general entity. */
                /* </MDENTITY> <MDEXTID sets these:> */
#define ESFM 10 /* LPU: minimum external (file) storage class. */
#define ESN 10  /* XCB: N/C/SDATA or SUBDOC control block. */
                /* </ENTOPEN> */
#define ESF 11  /* LPU: General entity. */
#define ESP 12  /* LPU: Parameter entity. */
#define ESD 13  /* LPU: Document type definition. */
#define ESL 14  /* LPU: Link process definition. */
#define ESK 15  /* LPU: Data content notation. */
                /* </MDEXTID> */

union etext {         /* Entity text. */
        UNIV x;       /* External ID generated by system. */
        UNCH *c;      /* Character string. */
        struct ne *n; /* N/C/SDATA or SUBDOC entity control block. */
};
#define ETEXTSZ sizeof(union etext)
struct entity {               /* Entity control block. */
        struct entity *enext; /* Next entity in chain. */
        UNCH *ename;          /* Entity name with length and EOS. */
        UNCH estore;          /* Storage class (see values above). */
        UNCH dflt;            /* Declared as default entity. */
        UNCH mark;            /* For use by for sgmlment. */
        union etext etx;      /* Entity text. */
};
#define ENTSZ sizeof(struct entity)
typedef struct entity *PECB;  /* Ptr to entity control block. */
typedef struct entity **TECB; /* Table of entity control blocks. */

struct source {             /* Source control block. */
        struct entity ecb;  /* Entity control block. */
        unsigned long rcnt; /* Source record number. */
        int ccnt;           /* Source record chars since last RS. */
        int curoff;         /* Offset of curchar (chars read in this block).*/
        UNCH curchar;       /* Current character. */
        UNCH nextchar;      /* If curchar was DELNONCH, next character. */
        UNIV fcb;           /* SGMLIO fcb ptr returned by OPEN. */
        UNCH *fbuf;         /* 1st char in buffer (0=PEND) or entity text. */
        UNCH *fpos;         /* Current char in buffer or entity text. */
        UNCH pushback;      /* Character before pend position */
        char copied;        /* Is this a copy of the internal entity? */
};
#define SCBSZ sizeof(struct source)
typedef struct source *PSCB; /* Ptr to source control block. */

extern int es;              /* Index of current source in stack. */
extern struct source *scbs; /* Stack of open sources ("SCB stack"). */

/* Member definitions for source and entity control blocks.
 */
#define SCB (scbs[es]) /* Ptr to current source control block. */

#define ECB SCB.ecb           /* Pointer to current entity control block. */
#define FBUF SCB.fbuf         /* Pointer to start of entity buffer. */
#define FPOS SCB.fpos         /* Pointer to current char of current source. */
#define RSCC SCB.ccnt         /* CCNT at start of block (across EOB/EOS/EOF). */
#define CCO SCB.curoff        /* Offset in read buffer of current char. */
#define CC SCB.curchar        /* Current character of current source entity. */
#define NEXTC SCB.nextchar    /* Next character in current source entity. */
#define CCNT (SCB.ccnt + CCO) /* Position of CC in current record (RS=0). */
#define RCNT SCB.rcnt         /* Position of record in entity (origin=1). */
#define SCBFCB SCB.fcb        /* Current file control block (if FILESW). */
#define ECBPTR ((ECB.enext))  /* Pointer to this entity's ECB. */
#define ENTITY ((ECB.ename))  /* Current entity name. */
#define FILESW (ECB.estore >= ESFM) /* 1=Entity is external file; 0=internal.  \
                                     */
#define NEWCC (++FPOS)              /* Get next current character. */
#define REPEATCC (--FPOS)           /* Repeat previous current character. */
#define COPIEDSW SCB.copied         /* Non-zero means entity was copied. */

struct srh {               /* Short reference map header. */
        struct srh *enext; /* Next short reference map in chain. */
        UNCH *ename;       /* Short reference map name. */
        TECB srhsrm;       /* Ptr to short reference map. */
};
#define SRHSZ (sizeof(struct srh))
typedef struct srh *PSRH;  /* Ptr to short reference map header. */
#define SRMNULL (&dumpecb) /* Dummy ptr to empty short reference map. */

/* Definitions for ENTOPEN/ENTREF return codes.
 */
#define ENTUNDEF -1 /* Callers of ENTOPEN: entity undefined. */
#define ENTLOOP -2  /* ENTOPEN: endless loop entity. */
#define ENTMAX -3   /* ENTOPEN: too many open entities. */
#define ENTFILE -4  /* ENTOPEN: file I/O error. */
#define ENTDATA -5  /* ENTOPEN: CDATA or SDATA entity. */
#define ENTPI -6    /* ENTOPEN: PI entity. */

/* Definitions for ENTDATA switches set in contersw.
 */
#define CDECONT 2 /* 0010 CDATA entity referenced. */
#define SDECONT 4 /* 0100 SDATA entity referenced. */
#define NDECONT 8 /* 1000 NDATA entity referenced. */

/* Definitions for manipulating signed source character counters.
 */
#define CTRSET(CTR) (CTR = (int)-(FPOS + 1 - FBUF)) /* Init source char ctr.   \
                                                     */
#define CTRGET(CTR) (CTR + (int)(FPOS + 1 - FBUF))  /* Read source char ctr. */
