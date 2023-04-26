#include <stdio.h>
#include <stdlib.h>
#define K 32

float get_float() {
    float b;
    char buff[K];
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

int main(void) {
    float first = 0, second = 0, tmp = 0;
    int min = 0, max = 0;

    printf("Enter the first number: ");
    first = get_float();
    printf("Enter the second number: ");
    second = get_float();

    if (first < second) {
        tmp = first;
        first = second;
        second = tmp;
    }

    max = (int)first;
    min = (int)second;

    if ((float)max == first) max--;

    while (max > min) {
        printf("%d ", max--);
    }
    printf("\n");
    return (0);
}

