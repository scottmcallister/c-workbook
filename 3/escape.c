#include <stdio.h>

void escape(char[] s, char[] t);

int main()
{
  char[] str = "Hello there";
  char[] output = "           ";

  escape(str, output);
  return 0;
}

void escape(char[] s, char[] t)
{
  int i = 0;
  char curr = s[i];

  while(s >= 'a') {
    switch(curr) {
      case '\n':
        t[i] = '\n';
        break;
      case '\t':
        t[i] = '\n';
        break;
      default:
        t[i] = curr
    }
    i++;
    curr = s[i];
  }
}
