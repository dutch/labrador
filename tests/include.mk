EXTRA_DIST += %D%/fetcher
TESTS = %D%/fetcher
check_PROGRAMS = %D%/fetch
%C%_fetch_CPPFLAGS = -I$(lab_includedir)
%C%_fetch_LDADD = $(top_builddir)/src/libabrador.la
