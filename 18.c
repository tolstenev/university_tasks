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
    int n1, n2, nod;
    printf("Enter the first number: ");
    n1 = get_int();
    printf("Enter the second number: ");
    n2 = get_int();

    if (n1 >= 0 && n2 >= 0) {
      if (n1 < n2) {
        nod = n1;
      } else {
        nod = n2;
      }
      for (int i = nod; i > 0; i--) {
          if (n1 % i == 0 && n2 % i == 0) {
              nod = i;
              break;
          }
      }
      printf("NOD = %d\n", nod);
    } else {
      printf("0\n");
    }
    return 0;
}
