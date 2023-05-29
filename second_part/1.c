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

int main() {
    printf("Enter the number of rows: ");
    int n = get_int();
    printf("Enter the number of columns: ");
    int k = get_int();
    int m[n][k];
    int tmp[n][k];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("Enter the matrix (%d, %d) element: ", i, j);
            m[i][j] = get_int();
        }
    }

    printf("Source matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            tmp[i][j] = m[j][k - 1 - i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            m[i][j] = tmp[i][j];
        }
    }

    printf("Turned matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
