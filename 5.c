 #include <stdio.h>
 #include <stdlib.h>

 int main(void) {
   int *a = NULL;
   int n = 0;
   int i = 0;
   int tmp = 0;
   int c = 0;

   printf("Vvedite dlinu massiva: ");
   scanf("%d", &n);

   // Выделение памяти под массив. Т.к. мы заранее не знаем, сколько в нём элементов и рассчитываем это уже в процессе выполнения программы

   a = (int *)malloc(n * sizeof(int));

// sizeof(float) - возращает размер ячейки памяти типа float (в байтах)
// n * sizeof(float) - количество памят под весь массив
// malloc - функция, которая выделяет память в количестве n * sizeof(float) байт и возвращает указатель на эту выделенную память. Причём этот указатель имеет тип void*
// Для того, чтобы корректно присвоить этот указтель в 'a' мы делаем явное приведение типа с помощью (float *)malloc(...)

   if (a == NULL) {
       printf("Malloc error\n");
   } else {
       printf("Vvedite elementy massiva: ");
       for (i = 0; i < n; i++) {
         scanf("%d", &a[i]);
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
         printf("%d ", a[i]);
         if (!(a[i] % 2)) {
             c++;
         }
       }
       printf("\n");

       printf("the number of even elements: %d\n", c);


       free(a); // Освобождение выделенной malloc памяти. ОБЯЗАТЕЛЬНО!
   }

   return 0;
 }