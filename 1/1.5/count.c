#include <stdio.h>

// count characters in input

int main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("\n\n%ld\n", nc);
}
