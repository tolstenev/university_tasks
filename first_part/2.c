#include <stdio.h>
#include <stdlib.h>
#define Z 32

float get_float(void) {
  float b;
  char buff[Z];
  char *end;

  while (1) {
    fgets(buff, sizeof(buff), stdin);
    b = strtof(buff, &end);
    if (buff == end || *end != '\n') {
      puts("Incorrect input. Please, try again");
      continue;
    }
    break;
  }
  return b;
}

int get_int(void) {
  int a, amo;
  long long b;
  char buff[Z];
  char *end;

  while (1) {
    fgets(buff, sizeof(buff), stdin);
    amo = sscanf(buff, "%d", &a);
    if (1 != amo) {
      puts("Incorrect input. Please, try again");
      continue;
    }
    b = strtol(buff, &end, 10);
    if ((buff != end) && (*end != '\n')) {
      puts("Incorrect input. Please, try again");
      continue;
    }
    if (a != b) {
      puts("Incorrect input. Please, try again");
      continue;
    }
    break;
  }
  return b;
}

double my_pow(float base, int exp) {
  double n = base;

  if (exp < 0) {
    for (int i = 0; i < -exp - 1; i++) {
      n = n * base;
    }
    n = 1 / n;
  } else if (exp == 0) {
    n = 1;
  } else {
    for (int i = 0; i < exp - 1; i++) {
      n = n * base;
    }
  }
  return n;
}

int main(void) {
  int a, b, c, d;
  float e, f, g;
  double x;

  printf("Enter the 'a' value:\n");
  a = get_int();
  printf("Enter the 'b' value:\n");
  b = get_int();
  printf("Enter the 'c' value:\n");
  c = get_int();
  printf("Enter the 'd' value:\n");
  d = get_int();
  printf("Enter the 'e' value:\n");
  e = get_float();
  printf("Enter the 'f' value:\n");
  f = get_float();
  printf("Enter the 'g' value:\n");
  g = get_float();

  x = my_pow(e, a) * (my_pow(g, b) + my_pow(f, c)) + ((g - e) / my_pow(f, d));
  printf("x: %lf\n", x);
  return 0;
}