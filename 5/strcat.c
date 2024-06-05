#include <stdio.h>

#define MAXLINE 20

void my_strcat(char *s, char *t);

int main()
{
  char first[MAXLINE] = "Lilly";
  char last[MAXLINE]  = " McAllister";
  my_strcat(first, last);
  printf("name: %s\n", first);
  return 0;
}

void my_strcat(char *s, char *t)
{

  while (*s != '\0')
    s++;
  while ((*s++ = *t++) != '\0')
    ;
}
