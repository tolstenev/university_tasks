#include <stdio.h>
#include <stdlib.h>
#define Z 32

float get_float() {
    float b;
    char buff[Z];
    char *end;

    while (1) {
        fgets (buff,sizeof(buff),stdin);
        b = strtof(buff, &end);
        if(buff == end || *end != '\n') {
            printf("Incorrect input, please try again: ");
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

int main() {
    printf("Enter the number of rows: ");
    int n = get_int();
    printf("Enter the number of columns: ");
    int k = get_int();
    float **m = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; ++i) {
        m[i] = (float *)malloc(k * sizeof(float));
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("Enter the matrix (%d, %d) element: ", i, j);
            m[i][j] = get_float();
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }

    if (m != NULL) {
        for (int i = 0; i < n; ++i) {
            free(m[i]);
        }
        free(m);
    }
    return 0;
}
