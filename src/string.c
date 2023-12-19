#include "s21_string.h"
#include <string.h>
int main() {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";

  char s3[] = "Hello, world!";
  char s4[] = "!";

  char s5[] = "";
  char s6[] = "";

  char s7[] = "sususususpicioussusususpicious";
  char s8[] = "susp";

  printf("s21_strstr_1: %s\n", s21_strstr(s1, s2));
  printf("strstr_1: %s\n", strstr(s1, s2));

  printf("s21_strstr_2: %s\n", s21_strstr(s3, s4));
  printf("strstr_2: %s\n", strstr(s3, s4));

  printf("s21_strstr_3: %s\n", s21_strstr(s5, s6));
  printf("strstr_3: %s\n", strstr(s5, s6));

  printf("s21_strstr_4: %s\n", s21_strstr(s7, s8));
  printf("strstr_4: %s\n", strstr(s7, s8));  
}