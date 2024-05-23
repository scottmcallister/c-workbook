#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
  int arr[] = {2, 4, 3, 5, 6, 7, 8};
  int index = binsearch(3, arr, 6);
  printf("index: %d\n", index);
  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;

  while (low <= high && x != v[mid]) {
    if (x < v[mid]) {
      high = mid + 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }

  if (x == v[mid]) {
    return mid;
  }
  return -1;
}
