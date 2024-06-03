#include <stdio.h>

int my_strlen(char *s);
int other_strlen(char *s);

int main()
{
  int len = my_strlen("Hello there");
  int len_two = other_strlen("Hello there");
  printf("my_strlen is: \t\t%d\n", len);
  printf("other_strlen is: \t%d\n", len_two);
}

int my_strlen(char *s)
{
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

int other_strlen(char *s)
{
  char *p = s;

  while (*p != '\0')
    p++;
  return p - s;
}
