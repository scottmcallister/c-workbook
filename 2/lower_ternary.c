#include <stdio.h>

int lower(int c);
int t_lower(int c);

int main()
{
  int c = 'D';
  printf("lower(%c) = %c\n", c, lower(c));
  printf("t_lower(%c) = %c\n", c, t_lower(c));
  return 0;
}

int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

int t_lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
