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

void sorting_array(int *m, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (m[j] < m[j + 1]) {
                int buff = m[j];
                m[j] = m[j + 1];
                m[j + 1] = buff;
            }
        }
    }
}

int main() {
    int m[N][K];
    int a = 0;
    int arr[N * K];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            m[i][j] = get_int();
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            arr[a++] = m[i][j];
        }
    }
    sorting_array(arr, N * K);

    a = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            m[i][j] = arr[a++];
        }
    }

    printf("Matrix sorted in descending mode:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
