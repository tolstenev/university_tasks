#include <stdio.h>
#include <stdlib.h>
#define N 4
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
    int m[N][K];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("Enter the matrix (%d, %d) element: ", i, j);
            m[i][j] = get_int();
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // variant 1
    printf("Peripheral elements: ");
    if (N == 1 && K == 1) {
        printf("%d ", m[0][0]);
    }
    for(int j = 0; j < K - 1; j++){
        printf("%d ", m[0][j]);
    }
    for(int i = 0; i < N - 1; i++){
        printf("%d ", m[i][K-1]);
    }
    for(int j = K - 1; j > 0; j--){
        printf("%d ", m[N-1][j]);
    }
    for(int i = N - 1; i > 0; i--){
        printf("%d ", m[i][0]);
    }
    printf("\n");

//    variant 2
//    printf("Peripheral elements: ");
//    for (int j = 0; j < K; j++) {
//        printf("%d ", m[0][j]);
//    }
//    for (int i = 1; i < N; i++) {
//        printf("%d ", m[i][K-1]);
//    }
//    if (K > 1 && N > 1) {
//        for (int j = K - 2; j >= 0; j--) {
//            printf("%d ", m[N - 1][j]);
//        }
//        for (int i = N - 2; i >= 1; i--) {
//            printf("%d ", m[i][0]);
//        }
//    }
//    printf("\n");

    return 0;
}
