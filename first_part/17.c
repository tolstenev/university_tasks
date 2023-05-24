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
    int n, is_simple = 1;
    printf("Enter the number: ");
    n = get_int();

    if (n < 2) {
      is_simple = 0;
    } else {
      for (int i = 2; i < n; i++) {
        if (n % i == 0) {
          is_simple = 0;
          break;
        }
      }
    }

    if (is_simple == 1) {
      printf("Chislo prostoe\n");
    } else {
      printf("Chislo ne prostoe\n");
    }
    return 0;
}
