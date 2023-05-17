#include <stdio.h>
#include <stdlib.h>
#define Z 32

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

int main(void){
  int a, b, buff;
  printf("Vvedite kolichestvo elementov massiva:");
  a = get_int();
  int *n;
  n = (int *)malloc(a*sizeof(int));
  for (int i = 0; i < a; i++){
    n[i] = get_int();
  }
  for (int i = 0; i < a; i++){
    for (int j = 0; j < a-1; j++){
      if (n[j] > n[j+1]){
        buff = n[j];
        n[j] = n[j+1];
        n[j+1]=buff;
      }
    }
  }
  
  b = a / 2;
  if (a % 2 == 1){
    printf("mediana: %d\n", n[b]);  
  } else {
    printf("mediana: %.2f\n", (n[b] + n[b-1]) / 2.0);
  }
  printf("razmah: %d\n", n[a-1] - n[0]);  

  return 0;  
}
