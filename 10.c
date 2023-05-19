#include <stdio.h>
#include <stdlib.h>
#define M 3
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
    int n = 0;

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter the matrix (%d, %d) element: ", i, j);
            m[i][j] = get_int();
            if (m[i][j] < 0) {
                n++;
            }
        }
    }

    int *neg = (int *)malloc(n * sizeof(int));
    int k = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < 0) {
                neg[k++] = m[i][j];
            }
        }
    }

    printf("Negative elements of matrix: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", neg[i]);
    }
    printf("\n");

    return 0;
}
