#include <stdio.h>

int strindex(char str[], int t);

int main()
{
  char str[] = "Hello";
  char t = 'e'; 

  printf("str: \"%s\"\n", str);

  int index = strindex(str, t);

  printf("index 'e': %d\n", index);

  char t_alt = 'z';

  index = strindex(str, t_alt);

  printf("index 'z': %d\n", index);

  return 0;
}

int strindex(char str[], int t)
{
  char c = str[0];
  int i = 0;
  while (c != '\0') {
    if (c == t)
      return i;
    i++;
    c = str[i];
  } 
  return -1;
}
