#include <stdio.h>

int my_strcmp(char *s, char *t);
int ptr_strcmp(char *s, char *t);

int main()
{
  int val = ptr_strcmp("test", "testing");
  printf("val: %d\n", val);
  return 0;
}

int my_strcmp(char *s, char *t)
{
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

int ptr_strcmp(char *s, char *t)
{
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
