MAINTAINERCLEANFILES = Makefile.in

bin_PROGRAMS = eflife

AM_CPPFLAGS = -DPACKAGE_DATA_DIR=\"$(datadir)/$(PACKAGE)\" \
-I$(top_builddir)/src/bin/ \
-I$(top_srcdir)/src/bin/ \
-I$(top_builddir)/src/lib/ \
-I$(top_srcdir)/src/lib/ \
@EFL_CFLAGS@

eflife_SOURCES = \
  eflife_life.c \
  eflife_render.c \
  eflife_main.c
eflife_LDADD = @EFL_LIBS@

localedir = $(datadir)/locale
DEFS = -DLOCALEDIR=\"$(localedir)\" @DEFS@

EXTRA_DIST = eflife_private.h

