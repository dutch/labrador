#include "private.h"
#include <stdio.h>
#include <stdlib.h>

/*!re2c re2c:flags:tags = 1; */

void
lab__parse_response(const char *responsestr, struct lab__response *response)
{
  const char *YYCURSOR, *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *mar;
  /*!stags:re2c format = "const char *@@\n;"; */

  YYCURSOR = responsestr;
  s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = NULL;

  /*!re2c
  re2c:define:YYCTYPE = char;
  re2c:define:YYMARKER = mar;
  re2c:yyfill:enable = 0;

  end = "\x00";
  digit = [0-9];
  sp = " ";
  crlf = "\r\n";
  status_code = digit{3};
  reason_phrase = [a-zA-Z]*;
  status_line = "HTTP/" @s1 digit @s2 "." @s3 digit @s4 sp @s5 status_code @s6 sp @s7 reason_phrase @s8 crlf;

  * { return; }
  end { return; }
  status_line {
    printf("%.*s\n", (int)(s8 - s7), s7);
    snprintf(response->reason_phrase, 128, "%.*s", (int)(s8 - s7), s7);
  }
  */
}
