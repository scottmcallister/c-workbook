#include <stdio.h>

void escape(char * s, char * t);
void unescape(char * s, char * t);

int main()
{
  char str[50] = "Hello \t there\n";
  char output[51];
  
  printf("Original string:\n %s\n\n", str);

  escape(output, str);
  printf("Escaped string:\n %s\n\n", output);

  unescape(str, output);
  printf("Unescaped string:\n %s\n\n", str);

  return 0;
}

void escape(char * s, char * t)
{
  int i, j;
  i = j = 0;

  while(t[i] != '\0') {
    switch(t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j] = 't';
        break;
      default:
        s[j] = t[i];
        break;
    }
    j++;
    i++;
  }
  s[j] = '\0';
}

void unescape(char * s, char * t)
{
  int i, j;
  i = j = 0;

  while(t[i] != '\0') {
    if (t[i] == '\\') {
      switch(t[++i]) {
        case 'n':
          s[j] = '\n';
          break;
        case 't':
          s[j] = '\t';
          break;
        default:
          s[j++] = '\\';
          s[j] = t[i];
          break;
      }
    } else {
      s[j] = t[i];
    }
    j++;
    i++;
  }
  s[j] = t[i];
}
