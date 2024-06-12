#include <stdio.h>

#define MAXLEN 20

int strend(char *s, char *t);

int main()
{
  char haystack[MAXLEN] = "This is The End";
  char needle[MAXLEN] = "End";

  int found = strend(haystack, needle);
  printf("found: %d\n", found);

  return 0;
}


int strend(char *s, char *t)
{
  int len = 0;
  int end_match = 0;
  while (*s != '\0')
    s++;
  while (*t != '\0') {
    t++;
    len++;
  }
  int i;
  for (i = 0; i < len; i++) {
    if (*s != *t) {
      end_match = 1;
    }
    s--;
    t--;
  }
  return end_match;
}
