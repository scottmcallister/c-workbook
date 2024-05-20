#include <stdio.h>

int setbits(int x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);
int invert(int x, int p, int n);

int main() {
  int x = 0b10101010;
  int p = 3;
  int n = 2;
  int y = 0b11110000;
  printf("setbits(%#b, %d, %d, %#b) = %d\n", x, p, n, y, setbits(x, p, n, y));
  return 0;
}


int setbits(int x, int p, int n, int y) {
  int mask = ~(~0 << n);
  int y_masked = y & mask;
  int x_masked = x & ~(mask << (p - n + 1));
  return x_masked | (y_masked << (p - n + 1));
}

int invert(int x, int p, int n) {
  int mask = ~(~0 << n);
  return x ^ (mask << (p - n + 1));
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
