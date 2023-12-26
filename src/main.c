// #include "s21_string.h"
#include <string.h>
#include <stdio.h>

int main() {

    char s2[10]="Hello!";
    char s3[] = "WORLD WORLD WORLD WORLD";
    // printf("%d\n", s21_strlen(s2));
    printf("%d\n", strlen(s2));
    size_t n = 30;
    strncat(s2, s3, n);
    printf("%s\n", s2);
    // printf("%d\n", s21_strlen(s2));
    printf("%d\n", strlen(s2));
    // free(s2);

    return 0;
}