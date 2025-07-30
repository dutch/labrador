#ifndef LAB__PRIVATE_H
#define LAB__PRIVATE_H

struct lab__uri
{
  char scheme[128];
  char path[128];
};
/*
struct lab__field
{
  char *name;
  char *value;
};
*/
struct lab__response
{
  int status_code;
  char reason_phrase[128];
  /*struct lab__field *fields;*/
};

void lab__parse_uri(const char *, struct lab__uri *);
void lab__parse_response(const char *, struct lab__response *);
int lab__socket(const char *, const char *);

#endif
