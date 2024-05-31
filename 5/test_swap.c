#include <stdio.h>

void shitty_swap(int x, int y);
void good_swap(int *px, int *py);

int main() {
  int a = 69;
  int b = 420;

  shitty_swap(a, b);
  printf("a: %d, b: %d\n", a, b);

  good_swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);
}

void shitty_swap(int x, int y)
{
  int temp;

  temp = x;
  x = y;
  y = temp;
}
void good_swap(int *px, int *py)
{
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
