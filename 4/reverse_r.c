#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
  char str[] = "Hello";
  reverse(str);
  printf("%s\n", str);
}

void reverse(char s[])
{
  static int i, len;
   
  if (s[i]) {
    int c = s[i++];
    reverse(s);
    s[len - i] = c;
    i--;
  } else {
    len = i;
  }
}
