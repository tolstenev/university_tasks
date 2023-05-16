#include <stdio.h>
#include <stdlib.h>
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

int main(void) {
    int n1, n2, nok, i;
    printf("Enter first number: ");
    n1 = get_int();
    printf("Enter second number: ");
    n2 = get_int();

    if (n1 >= 0 && n2 >= 0) {
      nok = n2 * n1;
      for (i = nok; i > 0; i--) {
          if (i % n1 == 0 && i % n2 == 0) {
              nok = i;
          }
      }
      printf("%d\n", nok);
    } else {
      printf("0\n");
    }
    return 0;
}
