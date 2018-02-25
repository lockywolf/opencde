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
/* $XConsortium: msg.h /main/3 1996/06/19 17:16:18 drk $ */
/*
Severity codes:
I information (not an SGML error at all)
W warning (an SGML markup error but it knows what you mean)
E error
C critical (fatal)

Type codes:
R resource
C ?context/content
M minimization
Q quantity
S syntax
D declaration
U unsupported feature
*/
struct {
        char *text;
        char severity;
        char type;
} messages[] = {
    /*   0 */ {0},
    /*   1 */ {"%s element not allowed at this point in %s element", 'E', 'C'},
    /*   2 */
    {"%s markup declaration not permitted here; declaration ended", 'E', 'D'},
    /*   3 */
    {"Length of name, number, or token exceeded NAMELEN or LITLEN limit", 'E',
     'Q'},
    /*   4 */ {"Non-SGML character ignored", 'E', 'S'},
    /*   5 */
    {"%s end-tag ignored: doesn't end any open element (current is %s)", 'E',
     'C'},
    /*   6 */
    {"%s start-tag exceeds open element limit; possible lies from %s on", 'E',
     'Q'},
    /*   7 */ {"Start-tag omitted from %s with empty content", 'E', 'M'},
    /*   8 */ {"Illegal entity end in markup or delimited text", 'E', 'S'},
    /*   9 */ {"Incorrect character in markup; markup terminated", 'E', 'S'},
    /*  10 */ {"Data not allowed at this point in %s element", 'E', 'C'},
    /*  11 */
    {"No element declaration for %s end-tag GI; end-tag ignored", 'E', 'C'},
    /*  12 */
    {"%s name ignored: not a syntactically valid SGML name", 'E', 'S'},
    /*  13 */
    {"%s = \"%s\" attribute ignored: not defined for this element", 'E', 'C'},
    /*  14 */
    {"%s = \"%s\" attribute value defaulted: invalid character", 'E', 'S'},
    /*  15 */
    {"%s = \"%s\" attribute value defaulted: token too long", 'E', 'Q'},
    /*  16 */
    {"%s = \"%s\" attribute value defaulted: too many tokens", 'E', 'C'},
    /*  17 */
    {"%s = \"%s\" attribute value defaulted: wrong token type", 'E', 'C'},
    /*  18 */
    {"%s = \"%s\" attribute value defaulted: token not in group", 'E', 'C'},
    /*  19 */
    {"Required %s attribute was not specified; may affect processing", 'E',
     'C'},
    /*  20 */ {"%s end-tag implied by %s end-tag; not minimizable", 'E', 'M'},
    /*  21 */
    {"%s start-tag implied by %s start-tag; not minimizable", 'W', 'M'},
    /*  22 */
    {"Possible attributes treated as data because none were defined", 'E', 'C'},
    /*  23 */
    {"Duplicate specification occurred for \"%s\"; may affect processing", 'E',
     'D'},
    /*  24 */ {"\"%s\" keyword invalid; declaration terminated", 'E', 'D'},
    /*  25 */
    {"%s = \"%s\" attribute defaulted: empty string not allowed for token", 'E',
     'C'},
    /*  26 */ {"Marked section end ignored; not in a marked section", 'E', 'S'},
    /*  27 */
    {"Marked section start ignored; %s marked sections open already", 'E', 'Q'},
    /*  28 */ {"One or more parameters missing; declaration ignored", 'E', 'D'},
    /*  29 */
    {"\"PUBLIC\" or \"SYSTEM\" required; declaration terminated", 'E', 'D'},
    /*  30 */ {"%s element ended prematurely; required %s omitted", 'E', 'C'},
    /*  31 */ {"Entity \"%s\" terminated: could not read file", 'E', 'R'},
    /*  32 */
    {"Could not open file for entity \"%s\"; entity reference ignored", 'E',
     'R'},
    /*  33 */
    {"Insufficient main memory; unable to continue parsing", 'C', 'R'},
    /*  34 */
    {"%s entity reference ignored; exceeded open entity limit (%s)", 'E', 'Q'},
    /*  35 */ {"No declaration for entity \"%s\"; reference ignored", 'E', 'C'},
    /*  36 */
    {"%s entity reference occurred within own text; reference ignored", 'E',
     'C'},
    /*  37 */ {"Entity nesting level out of sync", 'E', 'S'},
    /*  38 */
    {"Parameter entity text cannot have %s keyword; keyword ignored", 'E', 'D'},
    /*  39 */ {"%s end-tag implied by %s start-tag; not minimizable", 'W', 'M'},
    /*  40 */
    {"Start-tag minimization ignored; element has required attribute", 'E',
     'D'},
    /*  41 */
    {"Required %s element cannot be excluded from %s element", 'E', 'C'},
    /*  42 */ {"No DOCTYPE declaration; document type is unknown", 'E', 'C'},
    /*  43 */
    {"Undefined %1$s start-tag GI was used in DTD; \"%1$s O O ANY\" assumed",
     'E', 'C'},
    /*  44 */
    {"Invalid character(s) ignored; attempting to resume DOCTYPE subset", 'E',
     'S'},
    /*  45 */
    {"No declaration for entity \"%s\"; default definition used", 'I', 'C'},
    /*  46 */
    {"%s end-tag implied by NET delimiter; not minimizable", 'W', 'M'},
    /*  47 */ {"%s end-tag implied by data; not minimizable", 'W', 'M'},
    /*  48 */
    {"%s end-tag implied by short start-tag (no GI); not minimizable", 'W',
     'M'},
    /*  49 */ {"%s start-tag implied by data; not minimizable", 'W', 'M'},
    /*  50 */
    {"%s start-tag implied by short start-tag (no GI); not minimizable", 'W',
     'M'},
    /*  51 */ {"Short end-tag (no GI) ignored: no open elements", 'E', 'C'},
    /*  52 */
    {"No definition for %1$s document type; \"%1$s O O ANY\" assumed", 'E',
     'C'},
    /*  53 */
    {"No definition for %1$s implied start-tag; \"%1$s O O ANY\" assumed", 'E',
     'C'},
    /*  54 */
    {"%s element ended prematurely; required subelement omitted", 'E', 'C'},
    /*  55 */
    {"Content model token %s: connectors conflict; first was used", 'E', 'D'},
    /*  56 */
    {"Duplicate specification occurred for \"%s\"; duplicate ignored", 'E',
     'D'},
    /*  57 */
    {"Bad end-tag in R/CDATA element; treated as short (no GI) end-tag", 'E',
     'S'},
    /*  58 */
    {"Start-tag minimization should be \"-\" for element with declared content",
     'I', 'D'},
    /*  59 */
    {"Reference to PI entity not permitted here; reference ignored", 'E', 'S'},
    /*  60 */
    {"Non-SGML character found; should have been character reference", 'W',
     'S'},
    /*  61 */
    {"Numeric character reference exceeds 255; reference ignored", 'E', 'S'},
    /*  62 */ {"Invalid alphabetic character reference ignored", 'E', 'S'},
    /*  63 */
    {"Invalid character in minimum literal; character ignored", 'E', 'S'},
    /*  64 */
    {"Keyword %s ignored; \"%s\" is not a valid marked section keyword", 'E',
     'D'},
    /*  65 */
    {"Parameter entity name longer than (NAMELEN-1); truncated", 'E', 'Q'},
    /*  66 */
    {"Start-tag length exceeds TAGLEN limit; parsed correctly", 'W', 'Q'},
    /*  67 */
    {"%s attribute defaulted: FIXED attribute must equal default", 'W', 'C'},
    /*  68 */
    {"Duplicate specification occurred for \"%s\"; duplicate ignored", 'I',
     'D'},
    /*  69 */
    {"%s = \"%s\" IDREF attribute ignored: referenced ID does not exist", 'E',
     'C'},
    /*  70 */
    {"%s = \"%s\" IDREF attribute ignored: number of IDs in list exceeds "
     "GRPCNT limit",
     'E', 'Q'},
    /*  71 */
    {"%s = \"%s\" ID attribute ignored: ID in use for another element", 'E',
     'C'},
    /*  72 */
    {"%s = \"%s\" ENTITY attribute not general entity; may affect processing",
     'E', 'C'},
    /*  73 */
    {"%s = \"%s\" attribute ignored: previously specified in same list", 'W',
     'C'},
    /*  74 */
    {"\"?\" = \"%s\" name token ignored: not in any group in this list", 'E',
     'C'},
    /*  75 */
    {"Normalized attribute specification length over ATTSPLEN limit", 'E', 'Q'},
    /*  76 */
    {"%s = \"%s\" NOTATION ignored: element content is empty", 'E', 'C'},
    /*  77 */
    {"%s = \"%s\" NOTATION undefined: may affect processing", 'E', 'C'},
    /*  78 */ {"Entity \"%2$s\" has undefined notation \"%1$s\"", 'E', 'C'},
    /*  79 */
    {"%s = \"%s\" default attribute value not in group; #IMPLIED used", 'E',
     'C'},
    /*  80 */
    {"#CURRENT default value treated as #IMPLIED for %s ID attribute", 'E',
     'D'},
    /*  81 */
    {"ID attribute %s cannot have a default value; treated as #IMPLIED", 'E',
     'D'},
    /*  82 */
    {"%s attribute must be token, not empty string; treated as #IMPLIED", 'E',
     'D'},
    /*  83 */ {"NOTATION attribute ignored for EMPTY element", 'E', 'D'},
    /*  84 */
    {"%s = \"%s\" NOTATION ignored: content reference specified", 'E', 'C'},
    /*  85 */
    {"#CONREF default value treated as #IMPLIED for EMPTY element", 'W', 'D'},
    /*  86 */
    {"%s = \"%s\" entity not data entity; may affect processing", 'E', 'C'},
    /*  87 */
    {"End-tag minimization should be \"O\" for EMPTY element", 'I', 'D'},
    /*  88 */
    {"Formal public identifier \"%s\" invalid; treated as informal", 'E', 'S'},
    /*  89 */
    {"Out-of-context %2$s start-tag ended %1$s document element (and parse)",
     'E', 'C'},
    /*  90 */
    {"\"%s\" keyword is for unsupported feature; declaration terminated", 'E',
     'D'},
    /*  91 */
    {"Attribute specification list in prolog cannot be empty", 'E', 'D'},
    /*  92 */
    {"Document ended invalidly within a literal; parsing ended", 'C', 'S'},
    /*  93 */
    {"Short ref in map \"%2$s\" to undeclared entity \"%1$s\" treated as data",
     'E', 'C'},
    /*  94 */
    {"Could not reopen file to continue entity \"%s\"; entity terminated", 'E',
     'R'},
    /*  95 */
    {"Out-of-context data ended %s document element (and parse)", 'E', 'C'},
    /*  96 */
    {"Short start-tag (no GI) ended %s document element (and parse)", 'E', 'C'},
    /*  97 */
    {"DSO delimiter (%s) omitted from marked section declaration", 'E', 'D'},
    /*  98 */
    {"Group token %s: duplicate name or name token \"%s\" ignored", 'E', 'D'},
    /*  99 */ {"Attempt to redefine %s attribute ignored", 'E', 'D'},
    /* 100 */
    {"%s definition ignored: %s is not a valid declared value keyword", 'E',
     'D'},
    /* 101 */
    {"%s definition ignored: NOTATION attribute already defined", 'E', 'D'},
    /* 102 */ {"%s definition ignored: ID attribute already defined", 'E', 'D'},
    /* 103 */ {"%s definition ignored: no declared value specified", 'E', 'D'},
    /* 104 */
    {"%s definition ignored: invalid declared value specified", 'E', 'D'},
    /* 105 */
    {"%s definition ignored: number of names or name tokens in group exceeded "
     "GRPCNT limit",
     'E', 'D'},
    /* 106 */
    {"%s definition ignored: name group omitted for NOTATION attribute", 'E',
     'D'},
    /* 107 */
    {"#CONREF default value treated as #IMPLIED for %s ID attribute", 'E', 'D'},
    /* 108 */
    {"%s definition ignored: %s is not a valid default value keyword", 'E',
     'D'},
    /* 109 */ {"%s definition ignored: no default value specified", 'E', 'D'},
    /* 110 */
    {"%s definition ignored: invalid default value specified", 'E', 'D'},
    /* 111 */
    {"More than ATTCNT attribute names and/or name (token) values; terminated",
     'E', 'D'},
    /* 112 */
    {"Attempted redefinition of attribute definition list ignored", 'E', 'D'},
    /* 113 */
    {"Content model token %s: more than GRPCNT model group tokens; terminated",
     'E', 'Q'},
    /* 114 */
    {"Content model token %s: more than GRPGTCNT content model tokens; "
     "terminated",
     'E', 'Q'},
    /* 115 */
    {"Content model token %s: more than GRPLVL nested model groups; terminated",
     'E', 'Q'},
    /* 116 */
    {"Content model token %s: %s invalid; declaration terminated", 'E', 'D'},
    /* 117 */
    {"\"PUBLIC\" specified without public ID; declaration terminated", 'E',
     'D'},
    /* 118 */
    {"\"%s\" keyword invalid (only %s permitted); declaration terminated", 'E',
     'D'},
    /* 119 */
    {"\"%s\" specified without notation name; declaration terminated", 'E',
     'D'},
    /* 120 */ {"Parameter must be a name; declaration terminated", 'E', 'D'},
    /* 121 */
    {"Parameter must be a GI or a group of them; declaration terminated", 'E',
     'D'},
    /* 122 */
    {"Parameter must be a name or PERO (%%); declaration terminated", 'E', 'D'},
    /* 123 */ {"Parameter must be a literal; declaration terminated", 'E', 'D'},
    /* 124 */
    {"\"%s\" not valid short reference delimiter; declaration terminated", 'E',
     'D'},
    /* 125 */ {"Map does not exist; declaration ignored", 'E', 'C'},
    /* 126 */
    {"MDC delimiter (>) expected; following text may be misinterpreted", 'E',
     'D'},
    /* 127 */
    {"Document ended invalidly within prolog; parsing ended", 'C', 'S'},
    /* 128 */
    {"\"PUBLIC\" or \"SYSTEM\" or DSO ([) required; declaration terminated",
     'E', 'D'},
    /* 129 */
    {"Minimization must be \"-\" or \"O\" (not \"%s\"); declaration terminated",
     'E', 'D'},
    /* 130 */
    {"Content model or keyword expected; declaration terminated", 'E', 'D'},
    /* 131 */
    {"Rank stem \"%s\" + suffix \"%s\" more than NAMELEN characters; not "
     "defined",
     'E', 'D'},
    /* 132 */ {"Undefined %s start-tag GI ignored; not used in DTD", 'E', 'C'},
    /* 133 */
    {"Document ended invalidly within a markup declaration; parsing ended", 'C',
     'S'},
    /* 134 */
    {"Normalized length of literal exceeded %s; markup terminated", 'E', 'Q'},
    /* 135 */
    {"R/CDATA marked section in declaration subset; prolog terminated", 'E',
     'D'},
    /* 136 */
    {"%s = \"%s\" ENTITIES attribute ignored: more than GRPCNT in list", 'E',
     'Q'},
    /* 137 */ {"Content model is ambiguous", 'W', 'D'},
    /* 138 */ {"Invalid parameter entity name \"%s\"", 'E', 'S'},
    /* 139 */
    {"Document ended invalidly within a marked section; parsing ended", 'C',
     'S'},
    /* 140 */ {"Element \"%s\" used in DTD but not defined", 'I', 'D'},
    /* 141 */
    {"Invalid NDATA or SUBDOC entity reference occurred; ignored", 'E', 'S'},
    /* 142 */
    {"Associated element type not allowed in document instance", 'E', 'C'},
    /* 143 */ {"Illegal DSC character; in different entity from DSO", 'E', 'C'},
    /* 144 */ {"Declared value of data attribute cannot be ID", 'E', 'D'},
    /* 145 */
    {"Invalid reference to external CDATA or SDATA entity; ignored", 'E', 'S'},
    /* 146 */ {"Could not find external document type \"%s\"", 'E', 'R'},
    /* 147 */ {"Could not find external general entity \"%s\"", 'I', 'R'},
    /* 148 */ {"Could not find external parameter entity \"%s\"", 'I', 'R'},
    /* 149 */
    {"Reference to non-existent general entity \"%s\" ignored", 'E', 'R'},
    /* 150 */
    {"Could not find entity \"%s\" using default declaration", 'E', 'R'},
    /* 151 */
    {"Could not find entity \"%2$s\" in attribute %1$s using default "
     "declaration",
     'E', 'R'},
    /* 152 */
    {"Short reference map \"%s\" used in DTD but not defined", 'I', 'D'},
    /* 153 */
    {"End-tag minimization should be \"O\" for element with CONREF attribute",
     'I', 'D'},
    /* 154 */
    {"Declared value of data attribute cannot be ENTITY or ENTITIES", 'E', 'D'},
    /* 155 */
    {"Declared value of data attribute cannot be IDREF or IDREFS", 'E', 'D'},
    /* 156 */ {"Declared value of data attribute cannot be NOTATION", 'E', 'D'},
    /* 157 */ {"CURRENT cannot be specified for a data attribute", 'E', 'D'},
    /* 158 */ {"CONREF cannot be specified for a data attribute", 'E', 'D'},
    /* 159 */
    {"Short reference map for element \"%s\" not defined; ignored", 'E', 'C'},
    /* 160 */ {"Cannot create temporary file", 'C', 'R'},
    /* 161 */ {"Document ended invalidly within SGML declaration", 'C', 'D'},
    /* 162 */ {"Capacity limit %s exceeded by %s points", 'W', 'Q'},
    /* 163 */
    {"Amendment 1 requires \"ISO 8879:1986\" instead of \"ISO 8879-1986\"", 'W',
     'D'},
    /* 164 */
    {"Non-markup, non-minimum data character in SGML declaration", 'E', 'D'},
    /* 165 */ {"Parameter cannot be a literal", 'E', 'D'},
    /* 166 */ {"Invalid concrete syntax scope \"%s\"", 'E', 'D'},
    /* 167 */ {"Parameter must be a number", 'E', 'D'},
    /* 168 */ {"\"%s\" should have been \"%s\"", 'E', 'D'},
    /* 169 */
    {"Character number %s is not supported as an additional name character",
     'E', 'U'},
    /* 170 */ {"Parameter must be a literal or \"%s\"", 'E', 'D'},
    /* 171 */ {"Bad character description for character %s", 'E', 'D'},
    /* 172 */ {"Character number %s is described more than once", 'W', 'D'},
    /* 173 */
    {"Character number plus number of characters exceeds 256", 'E', 'D'},
    /* 174 */
    {"No description for upper half of character set: assuming \"128 128 "
     "UNUSED\"",
     'W', 'D'},
    /* 175 */
    {"Character number %s was not described; assuming UNUSED", 'E', 'D'},
    /* 176 */
    {"Non-significant shunned character number %s not declared UNUSED", 'E',
     'D'},
    /* 177 */ {"Significant character \"%s\" cannot be non-SGML", 'E', 'D'},
    /* 178 */ {"Unknown capacity set \"%s\"", 'E', 'U'},
    /* 179 */ {"No capacities specified.", 'E', 'D'},
    /* 180 */ {"Unknown concrete syntax \"%s\"", 'E', 'U'},
    /* 181 */ {"Character number exceeds 255", 'E', 'D'},
    /* 182 */ {"Concrete syntax SWITCHES not supported", 'E', 'U'},
    /* 183 */ {"\"INSTANCE\" scope not supported", 'E', 'U'},
    /* 184 */ {"Value of \"%s\" feature must be one or more", 'E', 'D'},
    /* 185 */ {"\"%s\" invalid; must be \"YES\" or \"NO\"", 'E', 'D'},
    /* 186 */ {"\"%s\" invalid; must be \"PUBLIC\" or \"SGMLREF\"", 'E', 'D'},
    /* 187 */ {"Feature \"%s\" is not supported", 'E', 'U'},
    /* 188 */ {"Too many open subdocument entities", 'E', 'Q'},
    /* 189 */ {"Invalid formal public identifier", 'I', 'D'},
    /* 190 */ {"Public text class should have been \"%s\"", 'I', 'D'},
    /* 191 */ {"Character number %s must be non-SGML", 'W', 'D'},
    /* 192 */ {"Notation \"%s\" not defined in DTD", 'W', 'D'},
    /* 193 */ {"Unclosed start or end tag requires \"SHORTTAG YES\"", 'W', 'M'},
    /* 194 */ {"Net-enabling start tag requires \"SHORTTAG YES\"", 'W', 'M'},
    /* 195 */ {"Attribute name omission requires \"SHORTTAG YES\"", 'W', 'M'},
    /* 196 */
    {"Undelimited attribute value requires \"SHORTTAG YES\"", 'W', 'M'},
    /* 197 */
    {"Attribute specification omitted for \"%s\": requires markup minimization",
     'W', 'M'},
    /* 198 */
    {"Concrete syntax does not have any short reference delimiters", 'E', 'D'},
    /* 199 */
    {"Character number %s does not exist in the base character set", 'E', 'D'},
    /* 200 */
    {"Character number %s is UNUSED in the syntax reference character set", 'E',
     'D'},
    /* 201 */
    {"Character number %s was not described in the syntax reference character "
     "set",
     'E', 'D'},
    /* 202 */
    {"Character number %s in the syntax reference character set has no "
     "corresponding character in the system character set",
     'E', 'D'},
    /* 203 */
    {"Character number %s was described using an unknown base set", 'E', 'D'},
    /* 204 */ {"Duplication specification for added funtion \"%s\"", 'E', 'D'},
    /* 205 */ {"Added function character cannot be \"%s\"", 'E', 'D'},
    /* 206 */
    {"Only reference concrete syntax function characters supported", 'E', 'U'},
    /* 207 */
    {"Only reference concrete syntax general delimiters supported", 'E', 'U'},
    /* 208 */
    {"Only reference concrete syntax short reference delimiters supported", 'E',
     'U'},
    /* 209 */ {"Unrecognized keyword \"%s\"", 'E', 'D'},
    /* 210 */ {"Unrecognized quantity name \"%s\"", 'E', 'D'},
    /* 211 */
    {"Interpretation of \"%s\" is not a valid name in the declared concrete "
     "syntax",
     'E', 'D'},
    /* 212 */
    {"Replacement reserved name \"%s\" cannot be reference reserved name", 'E',
     'D'},
    /* 213 */ {"Duplicate replacement reserved name \"%s\"", 'E', 'D'},
    /* 214 */ {"Quantity \"%s\" must not be less than %s", 'E', 'D'},
    /* 215 */
    {"Only values up to %2$s are supported for quantity \"%1$s\"", 'E', 'U'},
    /* 216 */
    {"Exclusions attempt to change required status of group in \"%s\"", 'E',
     'C'},
    /* 217 */
    {"Exclusion cannot apply to token \"%s\" in content model for \"%s\"", 'E',
     'C'},
    /* 218 */
    {"Required %s attribute was not specified for entity %s", 'E', 'C'},
    /* 219 */
    {"UCNMSTRT must have the same number of characters as LCNMSTRT", 'E', 'D'},
    /* 220 */
    {"UCNMCHAR must have the same number of characters as LCNMCHAR", 'E', 'D'},
    /* 221 */
    {"Character number %s assigned to both LCNMSTRT or UCNMSTRT and LCNMCHAR "
     "or UCNMCHAR",
     'E', 'D'},
    /* 222 */
    {"Character number %s cannot be an additional name character", 'E', 'D'},
    /* 223 */
    {"It is unsupported for \"-\" not to be assigned to UCNMCHAR or LCNMCHAR",
     'E', 'U'},
    /* 224 */
    {"Normalized length of value of attribute \"%s\" exceeded LITLEN", 'E',
     'Q'},
    /* 225 */
    {"Length of interpreted parameter literal exceeds LITLEN less the length "
     "of the bracketing delimiters",
     'E', 'Q'},
    /* 226 */
    {"Start tag of document element omitted; not minimizable", 'W', 'M'},
    /* 227 */ {"Unrecognized designating escape sequence \"%s\"", 'I', 'U'},
    /* 228 */
    {"Earlier reference to entity \"%s\" used default entity", 'I', 'D'},
    /* 229 */
    {"Reference to non-existent parameter entity \"%s\" ignored", 'E', 'R'},
};
