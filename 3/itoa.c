#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
    

void itoa(int n, char s[], int min_w)
{
  int i, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;

  do {
    s[i++] = '-';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  while (i < min_w)
    s[i++] = ' ';

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[])
{
  int c, i, j;
  
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
