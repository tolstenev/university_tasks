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
    float first = 0, second = 0, tmp;

    printf("Enter the first number: ");
    first = get_float();
    printf("Enter the second number: ");
    second = get_float();

    if (first > second) {
        tmp = second;
        second = first;
        first = tmp;
    }

    int min = (int)first;
    int max = (int)second;

    if ((float)max == second) max--;

    while (max > min) {
        printf("%d ", max--);
    }
    printf("\n");
    return (0);
}

//./test
//Enter the first number: 33
//Enter the second number: 31
//max: 32
//min: 31
//32

//#include <stdio.h>
//#include <stdlib.h>
//#define K 32
//
//float get_float() {
//    float b;
//    char buff[K];
//    char *end;
//
//    while (1) {
//        fgets(buff, sizeof(buff), stdin);
//        b = strtof(buff, &end);
//        if (buff == end || *end != '\n') {
//            printf("Incorrect input, please try again: ");
//            continue;
//        }
//        break;
//    }
//    return b;
//}
//
//int main(){
//    float first;
//    float second;
//    printf("Vvedite pervoe chislo: ");
//    a = get_float();
//    printf("Vvedite vtoroe chislo: ");
//    b = get_float();
//
//    int min = (int)a;
//    int max = (int)b;
//    int k;
//
//    printf("max: %d\n", max);
//    printf("min: %d\n", min);
//
//
//    if ((float)min == a) min--;
//    if ((float)max == b) max--;
//
//    if (max < min) {
//        k = max;
//        max = min;
//        min = k;
//    }
//
//    printf("max: %d\n", max);
//    printf("min: %d\n", min);
//
//    while (max > min)
//        printf("%d ", max--);
//    printf("\n");
//    return 0;
//}
//




