#include <stdio.h>
#include <stdlib.h>
#define K 32

float get_float() {
    float b;
    char buff[K];
    char *end;

    while (1) {
        fgets (buff, sizeof(buff), stdin);
        b = strtof(buff, &end);
        if(buff == end || *end != '\n') {
            printf("Incorrect input, please try again: ");
            continue;
        }
        break;
    }
    return b;
}

int main(void) {
    float k, b, x;
    printf("Enter the 'k' number: ");
    k = get_float();
    printf("Enter the 'b' number: ");
    b = get_float();

    if (k == 0 && b == 0) {
      printf("'x': lyuboye chislo\n");
    } else if (k == 0 && b != 0) {
      printf("net resheniy\n");
    } else if (k != 0) {
      x = -b / k;
      printf("'x': %.2f\n", x);
    }

    return 0;
}
