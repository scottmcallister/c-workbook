#include <stdio.h>

void escape(char * s, char * t);

int main()
{
  char str[50] = "Hello \t there\n";
  char output[51];
  
  printf("Original string: %s\n", str);

  escape(output, str);

  printf("Escaped string: %s\n", output);

  return 0;
}

// escape: converts characters like newline and tab into visible escape sequences
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

// void escape(char[] s, char[] t)
// {
//   int i = 0;
//   char curr = s[i];
// 
//   while(s >= 'a') {
//     switch(curr) {
//       case '\n':
//         t[i] = '\n';
//         break;
//       case '\t':
//         t[i] = '\n';
//         break;
//       default:
//         t[i] = curr
//     }
//     i++;
//     curr = s[i];
//   }
// }
