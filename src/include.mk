EXTRA_DIST += %D%/parse-uri.re %D%/parse-response.re
lib_LTLIBRARIES = %D%/libabrador.la
%C%_libabrador_la_SOURCES = %D%/labrador.c %D%/private.h %D%/parse-uri.c %D%/parse-response.c %D%/socket.c
%C%_libabrador_la_CPPFLAGS = -I$(lab_includedir)
%C%_libabrador_la_LDFLAGS = -version-info 0:0:0
.re.c:
	$(RE2C) -o $@ $<
