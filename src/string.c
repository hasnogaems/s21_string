#include "s21_string.h"
#include <string.h>
int main() {
char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  char s3[] = "";

  printf("strtok_1: %s\n", strtok(s1, s3));
  printf("s21_strtok_1: %s\n", s21_strtok(s2, s3));
}