#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Z 32

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

int main() {
  printf("Enter the number: ");
  int a = get_int();
  int max, min, b;

  printf("a: %d\n", a);
  if (a < 0) {
    a = a * (-1);
  }
  max = a % 10;
  min = a % 10;
  while(a!=0){
    b = a % 10;
    if (b > max){
      max = b;
    } else if (b < min){
      min = b;
    }
    a = a / 10;
  }
  printf("Max digit in the number: %d\n", max);
  printf("Min digit in the number: %d\n", min);

  return 0;
}