#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 16

int main()
{
  float fahr;
  printf("Fahrenheit\tCelsius\n");

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%10.0f\t%7.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
  }
  
  return 0;
}
