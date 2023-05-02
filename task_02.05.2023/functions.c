#include "header.h"

void print_matrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

float my_abs(float a) {
    if (a < 0) {
        a = -a;
    }
    return a;
}

void my_swap(int *a, int *b) {
    int buff = *a;
    *a = *b;
    *b = buff;
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
            puts("Incorrect input. Please, try again:");
            continue;
        }
        b = strtol(buff, &end, 10);
        if ((buff != end) && (*end != '\n')) {
            puts("Incorrect input. Please, try again:");
            continue;
        }
        if (a != b) {
            puts("Incorrect input. Please, try again:");
            continue;
        }
        break;
    }
    return b;
}