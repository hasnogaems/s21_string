#include "s21_string.h"
#include <string.h>
int main() {
  for (int i = 0; i < 150; i++) {
    printf("strerror_%d: %s\n", i, strerror(i));
    printf("s21_strerror_%d: %s\n", i, s21_strerror(i));
  }
}