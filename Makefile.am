MAINTAINERCLEANFILES = \
	ABOUT-NLS \
	Makefile.in \
	aclocal.m4 \
	compile \
	config.guess \
	config.h.in \
	config.rpath \
	config.sub \
	configure \
	depcomp \
	install-sh \
	ltmain.sh \
	missing \
	m4/libtool.m4 \
	m4/ltoptions.m4 \
	m4/ltsugar.m4 \
	m4/ltversion.m4 \
	m4/lt~obsolete.m4 \
	po/boldquot.sed \
	po/en@boldquot.header \
	po/en@quot.header \
	po/insert-header.sin \
	po/Makefile.in.in \
	po/Makevars.template \
	po/quot.sed \
	po/remove-potcdate.sin \
	po/Rules-quot \
	$(PACKAGE_TARNAME)-$(PACKAGE_VERSION).tar.gz \
	$(PACKAGE_TARNAME)-$(PACKAGE_VERSION).tar.bz2

SUBDIRS = data doc packaging po src

ACLOCAL_AMFLAGS = -I m4

filesdir = $(docdir)
files_DATA = \
	AUTHORS \
	COPYING \
	ChangeLog \
	INSTALL \
	NEWS \
	README \
	TODO

EXTRA_DIST = \
	autogen.sh \
	config.rpath \
	configure \
	m4/efl_attribute.m4 \
	m4/efl_binary.m4 \
	m4/efl_compiler_flag.m4 \
	m4/efl_path_max.m4

# cleaning

clean-local:
	rm -rf benchmark coverage

