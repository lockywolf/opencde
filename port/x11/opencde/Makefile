# $OpenBSD$

V =		0.1
COMMENT =
DISTNAME =	opencde-${V}
CATEGORIES =	x11

HOMEPAGE =	https://github.com/wmoxam/opencde
MAINTAINER =	Wesley Moxam <wes@wmoxam.com>

CDE_SHVERSION = 0.0
.for l in DtHelp DtMrm DtPrint DtSearch DtSvc DtTerm DtWidget csa tt
SHARED_LIBS +=  ${l}                      ${CDE_SHVERSION}
.endfor

# Apache 2.0
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ICE Mrm SM Uil X11 Xau Xdmcp Xext Xm Xmu Xt c
WANTLIB += m stdc++ util

# Requires a pre-built bootstrap compiler.
MASTER_SITES =	https://github.com/wmoxam/opencde/archive/
DISTFILES =${V}.tar.gz

# Only builds with clang
COMPILER =	base-clang ports-clang

BUILD_DEPENDS = shells/ksh93
RUN_DEPENDS = shells/ksh93
LIB_DEPENDS = x11/motif

CFLAGS = -g
NO_TEST =	Yes

CDEDIR = ${TRUEPREFIX}/dt

BOOTSTRAPCFLAGS =	${CFLAGS} -I${X11BASE}/include -I${X11BASE}/include/X11
MAKE_FLAGS =		BOOTSTRAPCFLAGS="${BOOTSTRAPCFLAGS}" \
			IMAKE_DEFINES="-DX11ProjectRoot=${X11BASE} \
			-DCplusplusCmd=${CXX} \
			-DLibraryCplusplusCmd=${CXX} \
			-DProjectRoot=${LOCALBASE} \
			-DCDEProjectRoot=${CDEDIR} \
			-DCdeInstallationTop=${CDEDIR} \
			-DTopMotifInclude=${LOCALBASE}/include \
			-DCdeConfigurationTop=${SYSCONFDIR} \
			-DCdeLogfilesTop=${LOCALSTATEDIR} \
			-DUseInstalledX11=YES \
			-DOptimizedCDebugFlags=\"${CFLAGS}\" \
			-DCDESharedRev=${CDE_SHVERSION} \
			-DTclLibrary=${MODTCL_LIBDIR}"

# .udb files containing files to install
UDBS =  C DE DEMOS ES FR HELP-C HELP-DE HELP-ES HELP-FR \
 			  HELP-IT ICONS INC INFO INFOLIB-C \
			  IT MAN-DEV MAN MIN MSG-C MSG-DE \
			  MSG-ES MSG-FR MSG-IT RUN HELP-RUN HELP-PRG PRG SHLIBS \
			  TT

pre-configure:
		# XXX use SUBST_CMD for most of this
		perl -pi -e "s,/usr/dt/lib,${PREFIX}/lib,g; \
		 			       s,/usr/local/dt/lib,${PREFIX}/lib,g; \
			   		     s,2\.1,${CDE_SHVERSION},g" \
		   		${WRKSRC}/cde/databases/CDE-SHLIBS.src
		cd ${WRKSRC}/cde/databases/ && perl -pi -e \
						"s,/usr/dt,${CDEDIR},g" *.udb *.src

do-build:
	cd ${WRKSRC}/cde && make World ${MAKE_FLAGS}

do-install:
.for _udb in ${UDBS}
	/bin/sh ${WRKSRC}/cde/admin/IntegTools/dbTools/udbToAny.ksh -toLst \
	-ReleaseStream openbsd ${WRKSRC}/cde//databases/CDE-${_udb}.udb | /bin/sh \
	${WRKSRC}/cde/admin/IntegTools/dbTools/mkProd -D ${WRKINST} -S ${WRKSRC}/cde -
.endfor
	chmod u+s ${PREFIX}/dt/bin/dtsession

.include <bsd.port.mk>
