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
/* $XConsortium: charconv.h /main/3 1995/11/08 10:49:04 rswiston $ */
EXTERN M_WCHAR pc8_to_r8[256]
#if defined(DEFINE)
    = {'\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007', '\010',
       '\011', '\012', '\013', '\014', '\015', '\016', '\017', '\020', '\021',
       '\022', '\023', '\024', '\025', '\026', '\027', '\030', '\031', '\032',
       '\033', '\034', '\035', '\036', '\037', '\040', '\041', '\042', '\043',
       '\044', '\045', '\046', '\047', '\050', '\051', '\052', '\053', '\054',
       '\055', '\056', '\057', '\060', '\061', '\062', '\063', '\064', '\065',
       '\066', '\067', '\070', '\071', '\072', '\073', '\074', '\075', '\076',
       '\077', '\100', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
       '\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117', '\120',
       '\121', '\122', '\123', '\124', '\125', '\126', '\127', '\130', '\131',
       '\132', '\133', '\134', '\135', '\136', '\137', '\140', '\141', '\142',
       '\143', '\144', '\145', '\146', '\147', '\150', '\151', '\152', '\153',
       '\154', '\155', '\156', '\157', '\160', '\161', '\162', '\163', '\164',
       '\165', '\166', '\167', '\170', '\171', '\172', '\173', '\174', '\175',
       '\176', '\177', '\264', '\317', '\305', '\300', '\314', '\310', '\324',
       '\265', '\301', '\315', '\311', '\335', '\321', '\331', '\330', '\320',
       '\334', '\327', '\323', '\302', '\316', '\312', '\303', '\313', '\357',
       '\332', '\333', '\277', '\273', '\274', '\120', '\276', '\304', '\325',
       '\306', '\307', '\267', '\266', '\371', '\372', '\271', '\055', '\052',
       '\370', '\367', '\270', '\373', '\375', '\374', '\374', '\374', '\174',
       '\053', '\043', '\053', '\053', '\043', '\043', '\174', '\043', '\043',
       '\053', '\043', '\053', '\053', '\053', '\053', '\053', '\055', '\053',
       '\043', '\053', '\043', '\043', '\043', '\043', '\043', '\075', '\043',
       '\043', '\053', '\043', '\053', '\053', '\043', '\043', '\053', '\053',
       '\043', '\053', '\053', '\374', '\374', '\374', '\374', '\374', '\052',
       '\336', '\052', '\052', '\052', '\052', '\363', '\052', '\052', '\052',
       '\052', '\052', '\052', '\326', '\052', '\052', '\052', '\376', '\052',
       '\052', '\174', '\174', '\057', '\176', '\263', '\362', '\362', '\052',
       '\052', '\052', '\374', '\377'}
#endif
;

EXTERN M_WCHAR pc8dn_to_r8[256]
#if defined(DEFINE)
    = {'\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007', '\010',
       '\011', '\012', '\013', '\014', '\015', '\016', '\017', '\020', '\021',
       '\022', '\023', '\024', '\025', '\026', '\027', '\030', '\031', '\032',
       '\033', '\034', '\035', '\036', '\037', '\040', '\041', '\042', '\043',
       '\044', '\045', '\046', '\047', '\050', '\051', '\052', '\053', '\054',
       '\055', '\056', '\057', '\060', '\061', '\062', '\063', '\064', '\065',
       '\066', '\067', '\070', '\071', '\072', '\073', '\074', '\075', '\076',
       '\077', '\100', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
       '\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117', '\120',
       '\121', '\122', '\123', '\124', '\125', '\126', '\127', '\130', '\131',
       '\132', '\133', '\134', '\135', '\136', '\137', '\140', '\141', '\142',
       '\143', '\144', '\145', '\146', '\147', '\150', '\151', '\152', '\153',
       '\154', '\155', '\156', '\157', '\160', '\161', '\162', '\163', '\164',
       '\165', '\166', '\167', '\170', '\171', '\172', '\173', '\174', '\175',
       '\176', '\177', '\264', '\317', '\305', '\300', '\314', '\310', '\324',
       '\265', '\301', '\315', '\311', '\335', '\321', '\331', '\330', '\320',
       '\334', '\327', '\323', '\302', '\316', '\312', '\303', '\313', '\357',
       '\332', '\333', '\326', '\273', '\322', '\114', '\154', '\304', '\325',
       '\306', '\307', '\267', '\266', '\352', '\351', '\271', '\342', '\341',
       '\154', '\156', '\270', '\052', '\272', '\374', '\374', '\374', '\174',
       '\053', '\043', '\053', '\053', '\043', '\043', '\174', '\043', '\043',
       '\053', '\043', '\053', '\053', '\053', '\053', '\053', '\055', '\053',
       '\043', '\053', '\043', '\043', '\043', '\043', '\043', '\075', '\043',
       '\043', '\053', '\043', '\053', '\053', '\043', '\043', '\053', '\053',
       '\043', '\053', '\053', '\374', '\374', '\374', '\374', '\374', '\052',
       '\336', '\052', '\052', '\052', '\052', '\363', '\052', '\052', '\052',
       '\052', '\052', '\052', '\326', '\052', '\052', '\052', '\376', '\052',
       '\052', '\174', '\174', '\057', '\176', '\263', '\362', '\362', '\052',
       '\052', '\052', '\374', '\377'}
#endif
;

EXTERN M_WCHAR r8_to_pc8[256]
#if defined(DEFINE)
    = {'\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007', '\010',
       '\011', '\012', '\013', '\014', '\015', '\016', '\017', '\020', '\021',
       '\022', '\023', '\024', '\025', '\026', '\027', '\030', '\031', '\032',
       '\033', '\034', '\035', '\036', '\037', '\040', '\041', '\042', '\043',
       '\044', '\045', '\046', '\047', '\050', '\051', '\052', '\053', '\054',
       '\055', '\056', '\057', '\060', '\061', '\062', '\063', '\064', '\065',
       '\066', '\067', '\070', '\071', '\072', '\073', '\074', '\075', '\076',
       '\077', '\100', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
       '\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117', '\120',
       '\121', '\122', '\123', '\124', '\125', '\126', '\127', '\130', '\131',
       '\132', '\133', '\134', '\135', '\136', '\137', '\140', '\141', '\142',
       '\143', '\144', '\145', '\146', '\147', '\150', '\151', '\152', '\153',
       '\154', '\155', '\156', '\157', '\160', '\161', '\162', '\163', '\164',
       '\165', '\166', '\167', '\170', '\171', '\172', '\173', '\174', '\175',
       '\176', '\177', '\200', '\201', '\202', '\203', '\204', '\205', '\206',
       '\207', '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
       '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227', '\230',
       '\231', '\232', '\233', '\234', '\235', '\236', '\237', '\040', '\101',
       '\101', '\105', '\105', '\105', '\111', '\111', '\047', '\140', '\136',
       '\042', '\176', '\125', '\125', '\234', '\055', '\131', '\171', '\370',
       '\200', '\207', '\245', '\244', '\255', '\250', '\052', '\234', '\235',
       '\052', '\237', '\233', '\203', '\210', '\223', '\226', '\240', '\202',
       '\242', '\243', '\205', '\212', '\225', '\227', '\204', '\211', '\224',
       '\201', '\217', '\214', '\117', '\222', '\206', '\241', '\355', '\221',
       '\216', '\215', '\231', '\232', '\220', '\213', '\341', '\117', '\101',
       '\101', '\141', '\104', '\144', '\111', '\111', '\117', '\117', '\117',
       '\157', '\123', '\163', '\125', '\131', '\230', '\052', '\052', '\372',
       '\346', '\052', '\052', '\304', '\254', '\253', '\246', '\247', '\256',
       '\376', '\257', '\361', '\040'}
#endif
;

EXTERN M_WCHAR r8_to_pc8dn[256]
#if defined(DEFINE)
    = {'\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007', '\010',
       '\011', '\012', '\013', '\014', '\015', '\016', '\017', '\020', '\021',
       '\022', '\023', '\024', '\025', '\026', '\027', '\030', '\031', '\032',
       '\033', '\034', '\035', '\036', '\037', '\040', '\041', '\042', '\043',
       '\044', '\045', '\046', '\047', '\050', '\051', '\052', '\053', '\054',
       '\055', '\056', '\057', '\060', '\061', '\062', '\063', '\064', '\065',
       '\066', '\067', '\070', '\071', '\072', '\073', '\074', '\075', '\076',
       '\077', '\100', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
       '\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117', '\120',
       '\121', '\122', '\123', '\124', '\125', '\126', '\127', '\130', '\131',
       '\132', '\133', '\134', '\135', '\136', '\137', '\140', '\141', '\142',
       '\143', '\144', '\145', '\146', '\147', '\150', '\151', '\152', '\153',
       '\154', '\155', '\156', '\157', '\160', '\161', '\162', '\163', '\164',
       '\165', '\166', '\167', '\170', '\171', '\172', '\173', '\174', '\175',
       '\176', '\177', '\200', '\201', '\202', '\203', '\204', '\205', '\206',
       '\207', '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
       '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227', '\230',
       '\231', '\232', '\233', '\234', '\235', '\236', '\237', '\040', '\101',
       '\101', '\105', '\105', '\105', '\111', '\111', '\047', '\140', '\136',
       '\042', '\176', '\125', '\125', '\234', '\055', '\131', '\171', '\370',
       '\200', '\207', '\245', '\244', '\255', '\250', '\257', '\234', '\131',
       '\052', '\146', '\143', '\203', '\210', '\223', '\226', '\240', '\202',
       '\242', '\243', '\205', '\212', '\225', '\227', '\204', '\211', '\224',
       '\201', '\217', '\214', '\235', '\222', '\206', '\241', '\233', '\221',
       '\216', '\215', '\231', '\232', '\220', '\213', '\341', '\117', '\101',
       '\252', '\251', '\104', '\144', '\111', '\111', '\117', '\117', '\247',
       '\246', '\123', '\163', '\125', '\131', '\230', '\052', '\052', '\372',
       '\346', '\052', '\052', '\304', '\052', '\052', '\052', '\052', '\074',
       '\376', '\076', '\361', '\040'}
#endif
;
