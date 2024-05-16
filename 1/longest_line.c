#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char to[], char from[]);
void copy(char to[], char from[]);

int main() {
  int len;               // current line length
  int max;               // max length seen so far
  char line[MAXLINE];    // current input line
  char longest[MAXLINE]; // longest line saved here
  char reversed[MAXLINE]; // reversed longest line saved here

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  reverse(reversed, longest);
  if (max > 0)
    printf("%s\n", reversed);
  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void reverse(char to[], char from[]) {
 
  // count the length of the string
  int i;
  for (i = 0; from[i] != '\0'; ++i)
    ;
  --i; // skip the null character
  // reverse the string
  int j;
  for (j = 0; i >= 0; ++j, --i)
    to[j] = from[i];

}
