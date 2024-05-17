#include <stdio.h>

int atoi(char s[]);
int lower(int c);

int main() {
  int intval = atoi("10");
  printf("atoi(10): %d\n", intval);

  int c = 'A';
  int lowcase = lower(c);
  printf("lower(A): %c\n", lowcase);
  return 0;
}

int atoi(char s[])
{
  int i, n;
  
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

int lower(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
