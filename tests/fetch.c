#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <labrador.h>

void
usage(void)
{
  fputs("usage: fetch url ...\n", stderr);
  exit(EXIT_FAILURE);
}

int
main(int argc, char **argv)
{
  char ch;
  int i;

  while ((ch = getopt(argc, argv, ":")) != -1) {
    switch (ch) {
    default:
      usage();
    }
  }

  argc -= optind;
  argv += optind;

  if (argc < 1)
    usage();

  for (i = 0; i < argc; ++i)
    lab_fetch(argv[i]);

  return 0;
}
