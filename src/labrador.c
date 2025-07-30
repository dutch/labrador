#include "private.h"
#include <sys/socket.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <labrador.h>

void
lab_fetch(const char *uristr)
{
  char buf[4096];
  struct lab__uri uri;
  struct lab__response response;
  int desc;
  size_t len;

  lab__parse_uri(uristr, &uri);

  desc = lab__socket(uri.path, uri.scheme);
  send(desc, "GET /index.html HTTP/1.1\r\nHost: ", 32, 0);
  send(desc, uri.path, strlen(uri.path), 0);
  send(desc, "\r\n\r\n", 4, 0);
  len = recv(desc, buf, 4096, 0);
  close(desc);
  buf[len] = '\0';

  lab__parse_response(buf, &response);
}
