#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

    for(int i = 0; i < exp-1; i++) n *= base;

    return n;
}

int main(void) {
    int a, b, c, d;
    float e, f, g;
    double x;

    puts("Enter the 'a' value:");
    a = get_int();
    puts("Enter the 'b' value:");
    b = get_int();
    puts("Enter the 'c' value:");
    c = get_int();
    puts("Enter the 'd' value:");
    d = get_int();
    puts("Enter the 'e' value:");
    e = get_float();
    puts("Enter the 'f' value:");
    f = get_float();
    puts("Enter the 'g' value:");
    g = get_float();

    x = my_pow(e,a) * (my_pow(g,b) - my_pow(f, c)) + ((g - e) / my_pow(f,d));
    double orig = pow(e,a) * (pow(g,b) - pow(f, c)) + ((g - e) / pow(f,d));
    printf("x: %lf\n", x);
    printf("o: %lf\n", orig);
    return 0;
}

