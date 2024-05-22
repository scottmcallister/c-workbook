#include <stdio.h>

int bitcount(unsigned x);
int speedcount(unsigned x);

int main()
{
  int thing = 1337;
  int bcount = bitcount(thing);
  int spcount = speedcount(thing);
  printf("thing: %d\n", thing);
  printf("bcount: %d\n", bcount);
  printf("speedcount: %d\n", spcount);
  return 0;
}

int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

int speedcount(unsigned x)
{
  int b = 0;

  for (b = 0; x != 0; x &= (x - 1))
    b++;

  return b;
}

