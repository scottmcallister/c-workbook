#include <stdio.h>

int any(char str1[], char str2[]);

int main() {
  char str1[] = "Scott";
  char str2[] = "McAllister";
  int any_val = any(str1, str2);
  printf("any(Scott, McAllister): %d\n", any_val);
  return 0;
}

int any(char str1[], char str2[]) {
  int i = 0;
  int j = 0;
  while (str1[i] != '\0') {
    for (j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        return i;
      }
    }
    i++;
  }
  return -1;
}
