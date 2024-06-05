#include <stdio.h>

void strcpy_arr(char *s, char *t);
void strcpy_ptr(char *s, char *t);
void strcpy_xp(char *s, char *t);

int main()
{
  char *str = "hurr durr";

  char target[100];
  strcpy_arr(target, str);
  printf("strcpy_arr: %s\n", target);

  char target_ptr[100];
  strcpy_ptr(target_ptr, str);
  printf("strcpy_ptr: %s\n", target_ptr);

  char target_xp[100];
  strcpy_ptr(target_xp, str);
  printf("strcpy_xp: %s\n", target_xp);
}

void strcpy_arr(char *s, char *t)
{
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

void strcpy_ptr(char *s, char *t)
{
  int i;

  i = 0;
  while((*s = *t) != '\0') {
    s++;
    t++;
  }
}

void strcpy_xp(char *s, char *t)
{
  // value of *t++ and *s++ is evaluated before being incremented
  // also, comparing to '\0' is redundant
  while (*s++ == *t++)
    ;
}
