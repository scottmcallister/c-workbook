#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int min_w);
void reverse(char s[]);


int main()
{
  int n = 125;
  int w = 10;
  char str[100];

  itoa(n, str, w);
 
  printf("%s", str);

  return 0;
}   

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
