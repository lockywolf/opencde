# Open Common Desktop Environment

Forked from https://sourceforge.net/p/cdesktopenv

Focused on improving support on OpenBSD, fixing security issues and
better/easier packaging

# OpenBSD Port

Port is based on earlier work by Pascal Stumpf <Pascal.Stumpf@cubes.de>

It currently installs to /usr/local/dt but needs a symlink at /usr/dt in order
for programs to function properly.

## Todo

- [ ] Fix known security issues (see: https://www.cert.org/historical/advisories/CA-1999-11.cfm)
- [ ] Fix installing to directories other than /usr/dt
- [ ] Fix Dtlogin text entry issue
- [ ] Fix screen lock issues

- [ ] Eliminate all compiler warnings in the following:
-   [ ] Dtaction
-   [ ] DtappBuilder
-   [ ] Dtappintegrate
-   [x] Dtcalc
-   [x] Dtcm
-   [ ] Dtconfig
-   [ ] Dtcreate
-   [ ] Dtdbcache
-   [ ] Dtdocbook
-   [ ] Dtdspmsg
-   [ ] Dtexec
-   [ ] Dtfile
-   [ ] Dthello
-   [x] Dthelp
-   [ ] Dticon
-   [ ] Dtimstart
-   [ ] Dtinfo
-   [ ] Dtksh
-   [ ] Dtlogin
-   [ ] Dtmail
-   [ ] Dtpad
-   [ ] Dtpdm
-   [ ] Dtpdmd
-   [ ] Dtprintigrate
-   [ ] Dtprintinfo
-   [ ] Dtscreen
-   [ ] Dtsearchpath
-   [ ] Dtsession
-   [ ] Dtspcd
-   [ ] Dtsr
-   [ ] Dtstyle
-   [ ] Dtterm
-   [ ] Dtudcexch
-   [ ] Dtudcfonted
-   [ ] Dtwm

## Future

* improve support for anti-aliased fonts
* better support for high DPI displays
* better integration of apps, ex: external calendar sources
* support newer protocols in Dtmail (ex: ssl)
* mousewheel scrolling in apps
* additional controls (ex: sound)

