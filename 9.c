#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 3
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
    int m[M][N];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter the matrix (%d, %d) element: ", i, j);
            m[i][j] = get_int();
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    printf("Peripheral elements: ");
    for (int j = 0; j < N; j++) {
        printf("%d ", m[0][j]);
    }
    for (int i = 1; i < M; i++) {
        printf("%d ", m[i][N-1]);
    }
    if (N > 1 && M > 1) {
        for (int j = N - 2; j >= 0; j--) {
            printf("%d ", m[M - 1][j]);
        }
        for (int i = M - 2; i >= 1; i--) {
            printf("%d ", m[i][0]);
        }
    }
    printf("\n");

    return 0;
}
