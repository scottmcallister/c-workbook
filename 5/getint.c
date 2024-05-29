#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int*);

int main()
{
  int test_int;
  int status = getint(&test_int);
  if (status != 0) {
    printf("Read integer: %d\n", test_int);
  } else {
    printf("No number was read.\n");
  }
  return 0;
}

int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  while (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c) || c == EOF)
      return 0;
  }
  for (*pn = 0; isdigit(c); c = getch())
       *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
