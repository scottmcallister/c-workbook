#include <stdio.h>

void squeeze(char s[], int c);
void squeezier(char s1[], char s2[]);

int main() {
  // test squeeze
  char str[] = "Hello world";
  int chr = 'e';
  squeeze(str, chr);
  printf("%s\n", str);

  // test squeezier
  char str1[] = "Hello world";
  char str2[] = "lo";
  squeezier(str1, str2);
  printf("%s\n", str1);
  return 0;
}

void squeeze(char s[], int c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

void squeezier(char s1[], char s2[]) {
  int i, c;
  for (i = 0; s2[i] != '\0'; i++) {
    c = s2[i];
    squeeze(s1, c);
  }
}
