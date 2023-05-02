/*
Написать программу, которая запрашивает с клавиатуры матрицу 3 на 3.
Программа должна переставить элементы матрицы таким образом,
чтобы средняя сумма элементов переферии была максимально близка элементу в центре.
Доп. требования.
1. Безопасный ввод.
2. Дружественный интерфейс
3. Программа написана в функцинально ориентированном стиле
4. Разбить программу на несколько исходных файлов.
*/

#include <stdio.h>

#define N 3

float my_abs(float a) {
    if (a < 0) {
        a = -a;
    }
    return a;
}

int main(void) {
    int m[N][N];
    int n = N * N;
    int k = 0;
    float min_div = 0.0;
    float now_div = 0.0;
    float sum = 0.0;
    int goal_i = 0;
    int goal_j = 0;

    puts("Enter the martix elements:");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = k++;  // m[i][j] = get_int();
            sum += m[i][j];

        }
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Разница для текущего элемента:
            // модуль разности элемента и среднего
            // арифметического остальных элементов
            now_div = my_abs((sum - m[i][j]) / (n - 1) - m[i][j]);

            // Присваивание min_div первой разницы
            // для корректного поиска наименьшего значения
            if (i == 0 && j == 0) {
                min_div = now_div;
            }
            // Поиск наименьшего значения
            if (now_div < min_div) {
                min_div = now_div;
                goal_i = i;
                goal_j = j;
            }

//            printf("\n");
//            printf("i: %d\n", i);
//            printf("j: %d\n", j);
//            printf("m[i][j]: %d\n", m[i][j]);
//            printf("sum: %.2f\n", sum);
//            printf("calc: %.2f\n", (sum / (n - 1)) - i);
//            printf("now_div: %.2f\n", now_div);
//            printf("min_div: %.2f\n", min_div);
//            printf("goal_i: %d\n", goal_i);
//            printf("goal_j: %d\n", goal_j);

        }
//        printf("\n");
//        printf("min_div: %.2f\n", min_div);
//        printf("goal_i: %d\n", goal_i);
//        printf("goal_j: %d\n", goal_j);


        // Своп элементов матрицы, чтобы найденный элемент
        // оказался в центре

    }
    return (0);
}
