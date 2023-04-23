#include <stdio.h>
#include <stdlib.h>
#define K 32

/* Организовать безопасный ввод с клавиатуры двух вещественных чисел.
 * Вывести на экран в порядке убывания целые числа, расположенные
 * на координатной оси между двумя введенными числами.*/

float

int main(void) {
//    float first = 5.6, second = 1.3;
    float first = 0, second = 0;
    char buff[K];
    char buff2[K];
    char *end;

    do {
        printf("Enter the first number: ");
        fgets(buff, sizeof(buff), stdin);
        first = strtof(buff, &end);

        if(!first) {
            printf("Incorrect input, please try again\n");
            continue;
        }

        printf("Enter the second number: ");
        fgets(buff2, sizeof(buff2), stdin);
        second = strtof(buff2, &end);

        if(!second) {
            printf("Incorrect input, please try again\n");
            continue;
        }

    } while(first == 0 || second == 0);

    int min = (int)first;
    int max = (int)second;
    int tmp;

    if (min > max) {
        tmp = min;
        min = max;
        max = tmp;
    }
    while (max > min) {
        printf("%d ", max--);
    }
    printf("\n");
    return (0);
}
