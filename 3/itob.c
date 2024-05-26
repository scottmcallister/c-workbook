#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
  char str[100];
  int n = 255;
  int b = 16;

  itob(n, str, b);
  printf("%s\n", str);

  return 0;
}

void itob(int n, char s[], int b)
{
  int i = 0;

  do {
    s[i++] = (n % b > 9) ? 
      n % b + 'A' - 10 : 
      n % b + '0';
  } while (n /= b);
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
