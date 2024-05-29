#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
double print_top(void);
void duplicate(void);
void swap(void);
void clear(void);

int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: can't divide by zero\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push((int)pop() % (int)op2);
      else
        printf("error: can't divide by zero\n");
      break;
    case 'p':
      print_top();
      break;
    case 'd':
      duplicate();
      break;
    case 's':
      swap();
      break;
    case 'c':
      clear();
      break;
    case 'S':
      push(sin(pop()));
      break;
    case 'E':
      op2 = exp(pop());
      if (op2 != HUGE_VAL && op2 != -HUGE_VAL && errno != ERANGE)
        push(op2);
      else
        printf("error: out of range: %g\n", op2), errno = 0;
      break;
    case 'P':
      op2 = pop();
      op2 = pow(op2, pop());
      if (errno == EDOM)
        printf("error: see domain of pow function\n"), errno = 0;
      else if (errno == ERANGE && (op2 == HUGE_VAL || op2 == -HUGE_VAL))
        printf("error: out of range: %g\n", op2), errno = 0;
      else
        push(op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g \n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  i = 0;
  if (c == '-' && isdigit(c = getch()) || c == '.') {
    s[++i] = c;
  } else if (!isdigit(c) && c != '.') {
    return c;
  }

  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
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

double print_top(void)
{
  if (sp > 0)
    return val[sp - 1];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void duplicate(void)
{
  push(print_top());
}

void swap(void)
{
  if (sp < 2) {
    printf("error: not enough elements to swap\n");
    return;
  }
  double first, second;
  first = pop();
  second = pop();
  push(first);
  push(second);
}

void clear(void)
{
  while (--sp >= 0) {
    val[sp] = 0.0;
  }
  sp = 0;
}
