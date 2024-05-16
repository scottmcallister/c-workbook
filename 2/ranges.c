#include <stdio.h>

int main()
{
  // determine the range of char and short (int and long are kind of crazy)

  // char
  char c;
  c = 0;
  while (c >= 0) {
    ++c;
    printf("char: %d\n", c);
  }
  
  // short
  short s;
  s = 0;
  while (s >= 0) {
    ++s;
    printf("short: %d\n", s);
  }
}
