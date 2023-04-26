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
    int a, b = 0, c = 0;

    puts("Enter the 'a' value:");
    a = get_int();

    printf("a: %d\n", a);

    do {
        a = a / 10;
        if (a == 0)
            c = 1;
        b++;
    } while (c == 0);

    printf("the number of digits: %d\n", b);

    return 0;
}

