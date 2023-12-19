#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *line = S21_NULL;
  for (int i = 0; i < (int)n; i++) {
    if (((char *)str)[i] == c) {
      line = ((char *)str) + i;
      break;
    }
  }
  return line;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {  // to do
  int cmp = 0;
  for (int i = 0; i < (int)n; i++) {
    if (((char *)str1)[i] != ((char *)str2)[i]) {
      cmp = ((char *)str1)[i] - ((char *)str2)[i];
      break;
    }
  }
  return cmp;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (int i = 0; i < (int)n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (int i = 0; i < (int)n; i++) {
    ((char *)str)[i] = c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  for (int i = 0; i < (int)n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[s21_strlen(dest)] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *line = S21_NULL;
  for (int i = 0; i <= (int)s21_strlen(str); i++) {
    if (str[i] == c) {
      line = (char *)&str[i];
      break;
    }
  }
  return line;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int cmp = 0;
  for (int i = 0; i < (int)n; i++) {
    if (str1[i] != str2[i]) {
      cmp = str1[i] - str2[i];
      break;
    }
  }
  return cmp;
}

// char *s21_strncpy(char *dest, const char *src, s21_size_t n) {

// }

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;

  for (int i = 0; i < (int)s21_strlen(str1); i++) {
    int check = 0;
    for (int j = 0; j < (int)s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        check = 1;
        break;
      }
    }
    if (!check) {
      len++;
    } else {
      break;
    }
  }
  return len;
}

// char *s21_strerror(int errnum) {
//   const char *str = S21_NULL;
//   if (errnum <= 106 && errnum >= 1) {
//     str = errorStrings[errnum - 1];
//   } else {
//     snprintf((char *)str, 50, "Unknown error: %d", errnum);
//   }
//   return (char *)str;
// }

s21_size_t s21_strlen(const char *str) {
  const char *ptr = str;
  while (*ptr != '\0') {
    ptr++;
  }
  return (s21_size_t)(ptr - str);
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *line = S21_NULL;
  for (int i = 0; i < (int)s21_strlen(str1); i++) {
    for (int j = 0; j < (int)s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        line = (char *)&str1[i];
        break;
      }
    }
    if (line == (char *)&str1[i]) {
      break;
    }
  }
  return line;
}

char *s21_strrchr(const char *str, int c) {
  char *line = S21_NULL;
  for (int i = 0; i <= (int)s21_strlen(str); i++) {
    if (str[i] == c) {
      line = (char *)&str[i];
    }
  }
  return line;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *line = S21_NULL;
  int j = 0;
  for (int i = 0; i < (int)s21_strlen(haystack); i++) {
    if ((int)s21_strlen(needle) == j) {
      line = (char *)&haystack[i - j];
      break;
    }
    if (haystack[i] == needle[j]) {
      j++;

    } else if (j > 0) {
      j = 0;
      i--;
    }
  }
  return line;
}

char *s21_strtok(char *str, const char *delim) {
  static char *current_position = S21_NULL;
  int check = 1;
  if (str != S21_NULL) {
    current_position = str;
  }
  char *start_position = S21_NULL;
  if (!(current_position == S21_NULL || *current_position == '\0')) {
    start_position = current_position;

    while (*current_position != '\0' && check) {
      for (int j = 0; delim[j] != '\0'; j++) {
        if (*current_position == delim[j]) {
          *current_position = '\0';

          check = 0;
          break;
        }
      }
      current_position++;
    }
  }

  return start_position;
}