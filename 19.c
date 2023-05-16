#include <stdio.h>
#include <stdlib.h>
#define Z 1024

// Вариант с фиксированным буфером размера Z
void get_string(char *str) {
  for (int i = 0; i < Z; i++) {
    str[i] = 0;
  }
  for(int i = 0; i < Z; i++) {
    str[i] = getchar();
    if (str[i] == '\n') {
      str[i] = '\0';
      break;
    } 
  }
}

int len_string(char *s) {
  int l = 0;
  while (s[l] != '\0') {
    l++;
  }
  return l;
}

int main(void) {
  char str[Z];
  int len = 0;
  char c;
  int letter_counts[127] = {0};
  
  printf("Enter the string:\n");
  get_string(str);
  len = len_string(str);
  
  for (int i = 0; i < len; i++) {
    c = str[i];
    if (0 < c && c < 127) {
      letter_counts[c]++;
    }
  }

  printf("Frequency of letters:\n");
  for (int i = 0; i < 127; i++) {
    if (letter_counts[i] != 0)
      printf("%c : %d\n", i, letter_counts[i]);
  }

  return 0;
}
