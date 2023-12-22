#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

START_TEST(memchr_1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "69917020";
  int ch = '3';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "69917020";
  int ch = '6';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "69917020";
  int ch = 'g';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_10) {
  char str[] = "69917020";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memcmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 7;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 13;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_6) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 2;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_10) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 7;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_11) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 4;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_13) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_14) {
  char s1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char s2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  s21_size_t n = 115;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_15) {
  char s1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char s2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2";
  s21_size_t n = 115;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_16) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcpy_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_7) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memset_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_5) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  int ch = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(strncat_1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_2) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 13;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_7) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_8) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "My name is Polina.";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_10) {
  char s1[100] = "Hello\0, world!";
  char s2[100] = "Hello\0, world!";
  char s3[] = "My name is\0 Polina.";
  s21_size_t n = 15;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_11) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_12) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_13) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_14) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_15) {
  char s1[100] = "Hello, world!\0\0\0";
  char s2[100] = "Hello, world!\0\0\0";
  char s3[] = "My name is Polina.";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strncmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, worldj";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_3) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_4) {
  char s1[] = "f";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_5) {
  char s1[] = "";
  char s2[] = "j";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 19;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_7) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 2;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_8) {
  char s1[] = "g124243425";
  char s2[] = "124243424";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_9) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

// START_TEST(strncpy_1) {
//   char s1[20] = "Hello, world!";
//   char s2[20] = "Hello, world!";
//   char s3[] = "Good";
//   s21_size_t n = 5;
//   ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
// }
// END_TEST

// START_TEST(strncpy_2) {
//   char s1[20] = "Hello, world!";
//   char s2[20] = "Hello, world!";
//   char s3[] = "\0";
//   s21_size_t n = 1;
//   ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
// }
// END_TEST

// START_TEST(strncpy_3) {
//   char s1[30] = "Hello, world!";
//   char s2[30] = "Hello, world!";
//   char s3[] = "fг-аг-аг";
//   s21_size_t n = 1;
//   ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
// }
// END_TEST

// START_TEST(strncpy_4) {
//   char s1[5] = "";
//   char s2[5] = "";
//   char s3[] = "";
//   s21_size_t n = 0;
//   ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
// }
// END_TEST

// START_TEST(strncpy_5) {
//   char s1[70] = "";
//   char s2[70] = "";
//   char s3[] =
//       "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
//   s21_size_t n = strlen(s3);
//   ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
// }
// END_TEST

// START_TEST(strncpy_6) {
//   char s1[5] = "";
//   char s2[5] = "";
//   char s3[] = "\0";
//   s21_size_t n = 1;
//   ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
// }
// END_TEST

START_TEST(strcspn_1) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_2) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_3) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strlen_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[] =
      "213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 "
      "21";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  char str[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_8) {
  char str[] = "          00000000           ......  ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  char str[] = "\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_10) {
  char str[] = "\0\0\0\0\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_11) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_12) {
  char str[] = "\t\t";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_13) {
  char str[] = "\0test";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_14) {
  char str[] = "wtf \0 wtf";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strpbrk_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strrchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strstr_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_3) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_4) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "world";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_6) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_7) {
  char s1[] = "";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_8) {
  char s1[] = "69917020";
  char s2[] = "0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_9) {
  char s1[] = "69917020";
  char s2[] = "\0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_10) {
  char s1[] = "69917020";
  char s2[] = "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_11) {
  char s1[] = "1   345 345 345 345 345";
  char s2[] = "345";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_12) {
  char s1[] = "sususususpicioussusususpicious";
  char s2[] = "susp";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_13) {
  char s1[] = "sus";
  char s2[] = "suspi";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strtok_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_2) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_7) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_8) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_9) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_10) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_11) {
  char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_12) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char s3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_13) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(strtok_14) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(strtok_15) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(strtok_16) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
}
END_TEST

START_TEST(strtok_17) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(strtok_18) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(strtok_19) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(S21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(S21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(strtok_20) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(strerror_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite;

  suite = suite_create("s21_string");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, memchr_1);
  tcase_add_test(tcase_core, memchr_2);
  tcase_add_test(tcase_core, memchr_3);
  tcase_add_test(tcase_core, memchr_4);
  tcase_add_test(tcase_core, memchr_5);
  tcase_add_test(tcase_core, memchr_6);
  tcase_add_test(tcase_core, memchr_7);
  tcase_add_test(tcase_core, memchr_8);
  tcase_add_test(tcase_core, memchr_9);
  tcase_add_test(tcase_core, memchr_10);

  tcase_add_test(tcase_core, memcmp_1);
  tcase_add_test(tcase_core, memcmp_2);
  tcase_add_test(tcase_core, memcmp_3);
  tcase_add_test(tcase_core, memcmp_4);
  tcase_add_test(tcase_core, memcmp_5);
  tcase_add_test(tcase_core, memcmp_6);
  tcase_add_test(tcase_core, memcmp_7);
  tcase_add_test(tcase_core, memcmp_8);
  tcase_add_test(tcase_core, memcmp_9);
  tcase_add_test(tcase_core, memcmp_10);
  tcase_add_test(tcase_core, memcmp_11);
  tcase_add_test(tcase_core, memcmp_12);
  tcase_add_test(tcase_core, memcmp_13);
  tcase_add_test(tcase_core, memcmp_14);
  tcase_add_test(tcase_core, memcmp_15);
  tcase_add_test(tcase_core, memcmp_16);

  tcase_add_test(tcase_core, memcpy_1);
  tcase_add_test(tcase_core, memcpy_2);
  tcase_add_test(tcase_core, memcpy_3);
  tcase_add_test(tcase_core, memcpy_4);
  tcase_add_test(tcase_core, memcpy_5);
  tcase_add_test(tcase_core, memcpy_6);
  tcase_add_test(tcase_core, memcpy_7);
  tcase_add_test(tcase_core, memcpy_8);
  tcase_add_test(tcase_core, memcpy_9);
  tcase_add_test(tcase_core, memcpy_10);

  tcase_add_test(tcase_core, memset_1);
  tcase_add_test(tcase_core, memset_2);
  tcase_add_test(tcase_core, memset_3);
  tcase_add_test(tcase_core, memset_4);
  tcase_add_test(tcase_core, memset_5);
  tcase_add_test(tcase_core, memset_6);

  
  tcase_add_test(tcase_core, strncat_1);
  tcase_add_test(tcase_core, strncat_2);
  tcase_add_test(tcase_core, strncat_3);
  tcase_add_test(tcase_core, strncat_4);
  tcase_add_test(tcase_core, strncat_5);
  tcase_add_test(tcase_core, strncat_6);
  tcase_add_test(tcase_core, strncat_7);
  tcase_add_test(tcase_core, strncat_8);
  tcase_add_test(tcase_core, strncat_9);
  tcase_add_test(tcase_core, strncat_10);
  tcase_add_test(tcase_core, strncat_11);
  tcase_add_test(tcase_core, strncat_12);
  tcase_add_test(tcase_core, strncat_13);
  tcase_add_test(tcase_core, strncat_14);
  tcase_add_test(tcase_core, strncat_15);

  tcase_add_test(tcase_core, strchr_1);
  tcase_add_test(tcase_core, strchr_2);
  tcase_add_test(tcase_core, strchr_3);
  tcase_add_test(tcase_core, strchr_4);
  tcase_add_test(tcase_core, strchr_5);
  tcase_add_test(tcase_core, strchr_6);
  tcase_add_test(tcase_core, strchr_7);
  tcase_add_test(tcase_core, strchr_8);

  tcase_add_test(tcase_core, strncmp_1);
  tcase_add_test(tcase_core, strncmp_2);
  tcase_add_test(tcase_core, strncmp_3);
  tcase_add_test(tcase_core, strncmp_4);
  tcase_add_test(tcase_core, strncmp_5);
  tcase_add_test(tcase_core, strncmp_6);
  tcase_add_test(tcase_core, strncmp_7);
  tcase_add_test(tcase_core, strncmp_8);
  tcase_add_test(tcase_core, strncmp_9);

  // tcase_add_test(tcase_core, strncpy_1);
  // tcase_add_test(tcase_core, strncpy_2);
  // tcase_add_test(tcase_core, strncpy_3);
  // tcase_add_test(tcase_core, strncpy_4);
  // tcase_add_test(tcase_core, strncpy_5);
  // tcase_add_test(tcase_core, strncpy_6);

  tcase_add_test(tcase_core, strcspn_1);
  tcase_add_test(tcase_core, strcspn_2);
  tcase_add_test(tcase_core, strcspn_3);
  tcase_add_test(tcase_core, strcspn_4);
  tcase_add_test(tcase_core, strcspn_5);
  tcase_add_test(tcase_core, strcspn_6);
  tcase_add_test(tcase_core, strcspn_7);
  tcase_add_test(tcase_core, strcspn_8);
  tcase_add_test(tcase_core, strcspn_9);
  tcase_add_test(tcase_core, strcspn_10);
  tcase_add_test(tcase_core, strcspn_11);
  tcase_add_test(tcase_core, strcspn_12);

  tcase_add_test(tcase_core, strlen_1);
  tcase_add_test(tcase_core, strlen_2);
  tcase_add_test(tcase_core, strlen_3);
  tcase_add_test(tcase_core, strlen_4);
  tcase_add_test(tcase_core, strlen_5);
  tcase_add_test(tcase_core, strlen_6);
  tcase_add_test(tcase_core, strlen_7);
  tcase_add_test(tcase_core, strlen_8);
  tcase_add_test(tcase_core, strlen_9);
  tcase_add_test(tcase_core, strlen_10);
  tcase_add_test(tcase_core, strlen_11);
  tcase_add_test(tcase_core, strlen_12);
  tcase_add_test(tcase_core, strlen_13);
  tcase_add_test(tcase_core, strlen_14);

  tcase_add_test(tcase_core, strpbrk_1);
  tcase_add_test(tcase_core, strpbrk_2);
  tcase_add_test(tcase_core, strpbrk_3);
  tcase_add_test(tcase_core, strpbrk_4);
  tcase_add_test(tcase_core, strpbrk_5);
  tcase_add_test(tcase_core, strpbrk_6);

  tcase_add_test(tcase_core, strrchr_1);
  tcase_add_test(tcase_core, strrchr_2);
  tcase_add_test(tcase_core, strrchr_3);
  tcase_add_test(tcase_core, strrchr_4);
  tcase_add_test(tcase_core, strrchr_5);
  tcase_add_test(tcase_core, strrchr_6);
  tcase_add_test(tcase_core, strrchr_7);
  tcase_add_test(tcase_core, strrchr_8);

  tcase_add_test(tcase_core, strstr_1);
  tcase_add_test(tcase_core, strstr_2);
  tcase_add_test(tcase_core, strstr_3);
  tcase_add_test(tcase_core, strstr_4);
  tcase_add_test(tcase_core, strstr_5);
  tcase_add_test(tcase_core, strstr_6);
  tcase_add_test(tcase_core, strstr_7);
  tcase_add_test(tcase_core, strstr_8);
  tcase_add_test(tcase_core, strstr_9);
  tcase_add_test(tcase_core, strstr_10);
  tcase_add_test(tcase_core, strstr_11);
  tcase_add_test(tcase_core, strstr_12);
  tcase_add_test(tcase_core, strstr_13);

  tcase_add_test(tcase_core, strtok_1);
  tcase_add_test(tcase_core, strtok_2);
  tcase_add_test(tcase_core, strtok_3);
  tcase_add_test(tcase_core, strtok_4);
  tcase_add_test(tcase_core, strtok_5);
  tcase_add_test(tcase_core, strtok_6);
  tcase_add_test(tcase_core, strtok_7);
  tcase_add_test(tcase_core, strtok_8);
  tcase_add_test(tcase_core, strtok_9);
  tcase_add_test(tcase_core, strtok_10);
  tcase_add_test(tcase_core, strtok_11);
  tcase_add_test(tcase_core, strtok_12);
  tcase_add_test(tcase_core, strtok_13);
  tcase_add_test(tcase_core, strtok_14);
  tcase_add_test(tcase_core, strtok_15);
  tcase_add_test(tcase_core, strtok_16);
  tcase_add_test(tcase_core, strtok_17);
  tcase_add_test(tcase_core, strtok_18);
  tcase_add_test(tcase_core, strtok_19);
  tcase_add_test(tcase_core, strtok_20);

  tcase_add_test(tcase_core, strerror_1);
  tcase_add_test(tcase_core, strerror_2);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}