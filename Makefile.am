ACLOCAL_AMFLAGS = -Im4

SUBDIRS = src
dist_doc_DATA = README.md LICENSE.md

maintainer-clean-local:
	-rm -f ${top_srcdir}/aclocal.m4
	-rm -f ${top_srcdir}/m4/libtool.m4
	-rm -f ${top_srcdir}/m4/lt*.m4
	-rm -f ${top_srcdir}/config.h.in*
	-rm -f ${top_srcdir}/configure
	-rm -rf ${top_srcdir}/config
	-find ${top_srcdir} -name Makefile.in -exec rm -f '{}' ';'

.PHONY: bootstrap
bootstrap: maintainer-clean
	./bootstrap
