## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = integration

integration_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonction_etudiant.c fonction_etudiant.h \
	reclamation.c reclamation.h \
	ichrak.c ichrak.h \
	talbi.c talbi.h \
	cap.c cap.h \
	fonction.c fonction.h 
	
	
integration_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

