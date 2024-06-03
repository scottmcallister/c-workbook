#include <stdio.h>

int my_strlen(char *s);

int main()
{
  int len = my_strlen("Hello there");
  printf("length is: %d\n", len);
}

int my_strlen(char *s)
{
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

