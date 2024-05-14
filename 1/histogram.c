#include <stdio.h>

#define MAXLENGTH 45

// count digits, white space, others
int main()
{
  int c, i, currlen, longest;
  currlen = longest = 0;

  int nlength[MAXLENGTH];

  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t')
    {
      nlength[currlen]++;
      if (currlen > longest)
        longest = currlen;
      currlen = 0;
    }
    else
      ++currlen;

  printf("longest: %d\n", longest);

  for (i = 1; i < longest; ++i)
  {
    printf("%d: \t", i);
    currlen = nlength[i];
    for (int j = 0; j < currlen; ++j)
      printf("*");
    printf("\n");
  }

  return 0;
}
