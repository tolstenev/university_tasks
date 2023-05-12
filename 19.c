#include <stdio.h>
#include <stdlib.h>
#define K 1024

void get_string(char *str, int size_str) {
  for (int i = 0; i < size_str; i++) {
    str[i] = 0;
  }
   for(int i = 0; i < size_str; i++) {
     str[i] = getchar();
     if (str[i] == '\n') {
       str[i] = '\0';
       break;
     }
   }
}

int string_length(char *str) {
  int l = 0;
  while (str[l] != '\0') l++;
  return l;
}

char lower(char c) {
  if ('A' <= c && c <= 'Z') {
    c = c + 32;
  }
  return c;
}

int main(void) {
  char str[K];
  int size_str = K;

  puts("Enter the string:");
  get_string(str, size_str);

  printf("str: %s\n", str);

  int len = string_length(str);
  printf("len: %d\n", len);

  return 0;
}