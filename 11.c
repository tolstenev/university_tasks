 #include <stdio.h>
 #include <stdlib.h>

 int main(void) {
   float *a = NULL;
   int n = 0;
   int i = 0;
   int tmp = 0;
   float sum = 0;

   printf("Vvedite dlinu massiva: ");
   scanf("%d", &n);

   // Выделение памяти под массив. Т.к. мы заранее не знаем, сколько в нём элементов и рассчитываем это уже в процессе выполнения программы

   a = (float *)malloc(n * sizeof(float));

// sizeof(float) - возращает размер ячейки памяти типа float (в байтах)
// n * sizeof(float) - количество памят под весь массив
// malloc - функция, которая выделяет память в количестве n * sizeof(float) байт и возвращает указатель на эту выделенную память. Причём этот указатель имеет тип void*
// Для того, чтобы корректно присвоить этот указтель в 'a' мы делаем явное приведение типа с помощью (float *)malloc(...)

   if (a == NULL) {
       printf("Malloc error\n");
   } else {
       printf("Vvedite elementy massiva: ");
       for (i = 0; i < n; i++) {
         scanf("%f", &a[i]);
       }

       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n - 1; ++j) {
               if (a[j] > a[j + 1]) {
                   tmp = a[j + 1];
                   a[j + 1] = a[j];
                   a[j] = tmp;
               }
           }
       }

       printf("sorted a: ");
       for (i = 0; i < n; i++) {
         printf("%.2f ", a[i]);
         sum += a[i];
       }
       printf("\n");

       printf("the sum of 'a' elements: %.2f\n", sum);
       printf("the average of 'a' elements: %.2f\n", sum / n);


       free(a); // Освобождение выделенной malloc памяти. ОБЯЗАТЕЛЬНО!
   }

   return 0;
 }