#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int
lab__socket(const char *path, const char *port)
{
  struct addrinfo hints, *addrinfo, *p;
  int ret, result, desc;

  ret = -1;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((result = getaddrinfo(path, port, &hints, &addrinfo)) != 0)
    goto done;

  for (p = addrinfo; p; p = p->ai_next) {
    if ((desc = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
      continue;
    if (connect(desc, p->ai_addr, p->ai_addrlen) == -1) {
      close(desc);
      continue;
    }
    break;
  }

  if (p)
    ret = desc;

  freeaddrinfo(addrinfo);

done:
  return ret;
}

