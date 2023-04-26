#include <stdio.h>
#include <stdlib.h>
#define Z 32
#define N 6

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
    float g, m[N], ms[N];
    float sign;
    float tmp;

    puts("Enter the 'g' value:");
    g = get_float();

    printf("g: %.2f\n", g);
    printf("m:       ");

    for (int i = 0; i < N; i++) {
        if (i % 2) {
            sign = -1.0;
        } else {
            sign = 1.0;
        }
        m[i] = sign * g * (i + 1) * (N - 2 * i);
        printf(" %.2f", m[i]);
    }
    printf("\n");


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (m[j] < m[j + 1]) {
                tmp = m[j + 1];
                m[j + 1] = m[j];
                m[j] = tmp;
            }
        }
    }

    printf("sorted m:");
    for (int i = 0; i < N; ++i) {
        printf(" %.2f", m[i]);
    }
    printf("\n");

    return 0;
}

