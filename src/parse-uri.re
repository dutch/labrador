#include "private.h"
#include <stdio.h>
#include <stdlib.h>

/*!re2c re2c:flags:tags = 1; */

void
lab__parse_uri(const char *uristr, struct lab__uri *uri)
{
  const char *YYCURSOR, *s1, *s2, *s3, *s4, *mar;
  /*!stags:re2c format = "const char *@@;\n"; */

  YYCURSOR = uristr;
  s1 = s2 = s3 = s4 = NULL;

  /*!re2c
  re2c:define:YYCTYPE = char;
  re2c:define:YYMARKER = mar;
  re2c:yyfill:enable = 0;

  end = "\x00";
  scheme = [a-zA-Z]+;
  path = [a-zA-Z.]+;
  uri = @s1 scheme @s2 "://" @s3 path @s4;

  * { return; }
  end { return; }
  uri {
    snprintf(uri->scheme, 128, "%.*s", (int)(s2 - s1), s1);
    snprintf(uri->path, 128, "%.*s", (int)(s4 - s3), s3);
  }
  */
}
