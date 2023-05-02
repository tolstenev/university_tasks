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
#include <stdlib.h>

#define N 3
#define Z 32

float my_abs(float a);

void my_swap(int *a, int *b);

int get_int(void);

void print_matrix(int m[N][N]);

void print_matrix(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

float my_abs(float a) {
    if (a < 0) {
        a = -a;
    }
    return a;
}

void my_swap(int *a, int *b) {
    int buff = *a;
    *a = *b;
    *b = buff;
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
            puts("Incorrect input. Please, try again:");
            continue;
        }
        b = strtol(buff, &end, 10);
        if ((buff != end) && (*end != '\n')) {
            puts("Incorrect input. Please, try again:");
            continue;
        }
        if (a != b) {
            puts("Incorrect input. Please, try again:");
            continue;
        }
        break;
    }
    return b;
}

int main(void) {
    int m[N][N];
    int n = N * N;
    float min_div = 0.0;
    float now_div = 0.0;
    float sum = 0.0;
    int goal_i = 0;
    int goal_j = 0;

    // Инициализация матрицы
    // и вычисление суммы всех её элементов
    puts("Enter the martix elements by new line:");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = get_int();
            sum += m[i][j];
        }
    }

    // Вывод исходной матрицы на экран
    printf("Source matrix:\n");
    print_matrix(m);

    // Перебор всех элементов матрицы,
    // вычисление для каждого необходимой разности
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
            // Поиск наименьшей разности,
            // и запоминание координат целевого элемента,
            // который будем заменять
            if (now_div < min_div) {
                min_div = now_div;
                goal_i = i;
                goal_j = j;
            }
        }
    }

    // Смена мест элементов матрицы, таким образом,
    // чтобы найденный элемент оказался в центре
    my_swap(&m[1][1], &m[goal_i][goal_j]);

    // Вывод модифицированной матрицы на экран
    printf("Modified matrix:\n");
    print_matrix(m);

    return (0);
}
