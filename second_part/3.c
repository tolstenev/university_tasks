#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024

int get_int_from_file(FILE *fp) {
    int a, amo;
    amo = fscanf(fp, "%d", &a);
    if (1 != amo) {
        puts("Incorrect reading from a file");
    }
    return a;
}

int get_int() {
    int a, amo, b;
    char buff[SIZE], *end;

    while( fgets(buff, sizeof(buff), stdin) ) {
        amo = sscanf(buff, "%d", &a);
        if (1 != amo) {
            puts("Incorrect input");
            continue;
        }

        b = strtol(buff, &end, 10);
        if ((buff != end) && *end != '\n') {
            puts("Incorrect input");
            continue;
        }

        if (a != b) {
            puts("Incorrect input");
            continue;
        }
        break;
    }
    return b;
}

int main(void) {
    FILE *fp = fopen("io.txt", "r");
    int n = get_int_from_file(fp);
    int k = get_int_from_file(fp);
    int m[n][k];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            m[i][j] = get_int_from_file(fp);
        }
    }
    fclose(fp);

    printf("Enter the number of row to show them: ");
    int j = get_int();
    if (j < k) {
        for (int i = 0; i < n; ++i) {
            printf("%d\n", m[i][j]);
        }
    } else {
        printf("Incorrect number of row\n");
    }
    return 0;
}