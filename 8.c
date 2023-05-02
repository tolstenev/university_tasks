#include <stdio.h>
#include <stdlib.h>

#define Z 32
#define N 10

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

int main(void) {
    int *a = NULL;
    int n = 0;
    int i = 0;
    int size_arr = 0;

    printf("Enter the length of the array:\n");
    n = get_int();

    a = (int *) malloc(n * sizeof(int));

    if (a == NULL) {
        printf("Malloc error\n");
    } else {
        printf("Enter the elements of the array:\n");
        for (i = 0; i < n; i++) {
            a[i] = get_int();
        }

        while (size_arr * size_arr < n) size_arr++;

        printf("The array in matrix view:");
        for (int i = 0; i < size_arr * size_arr; i++) {
            if (i % size_arr == 0) {
                printf("\n");
            }
            if (i < n) {
                printf("%d\t", a[i]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");

        free(a);
    }
    return 0;
}
