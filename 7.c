#include <stdio.h>
#include <stdlib.h>

#define N 3
#define K 3
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
    int mas[N][K];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            mas[i][j] = get_int();
        }
    }

    printf("Negative elements of the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (mas[i][j] < 0) {
                printf("%d ", mas[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}