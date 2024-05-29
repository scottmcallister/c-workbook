#include <stdio.h>
#include <string.h>

int itoa(int n, char s[], unsigned int i);


int main()
{
  int n = 125235;
  char str[100];

  itoa(n, str, 0);
 
  printf("%s\n", str);

  return 0;
}   

int itoa(int n, char s[], unsigned int i)
{
  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }
  if (n / 10)
    i = itoa(n / 10, s, i++);
  s[i++] = n % 10 + '0';
  s[i] = '\0';
  return i;
}
