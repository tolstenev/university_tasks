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

int main(void) {
    float f;
    int i;

    puts("Enter the 'f' value:");
    f = get_float();

    printf("f: %.2f\n", f);

    i = (int)(f + 0.5);
    printf("i: %d\n", i);

    return 0;
}

