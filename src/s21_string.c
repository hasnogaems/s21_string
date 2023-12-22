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
  int i = 0, j = 0;
  char *result = S21_NULL;

  if (needle[0] == '\0') {
    result = (char *)haystack;
  } else {
    for (; haystack[i] != '\0'; i++) {
      if (haystack[i] == needle[j]) {
        int index = i;
        while (haystack[i] == needle[j] && needle[j] != '\0') {
          i++;
          j++;
        }
        if (needle[j] == '\0') {
          result = (char *)&haystack[index];
          break;
        } else {
          i = index + 1;
          j = 0;
        }
      }
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {  // to do
  static char *current_position = S21_NULL;
  int check = 1;
  char *start_position = S21_NULL;

  if (str != S21_NULL) {
    current_position = str;
  } else if (current_position == S21_NULL || *current_position == '\0') {
    start_position = S21_NULL;
  } else if (current_position != S21_NULL) {
    while (*current_position != '\0') {
      int isDelim = 0;
      for (int j = 0; delim[j] != '\0'; j++) {
        if (*current_position == delim[j]) {
          isDelim = 1;
          break;
        }
      }
      if (!isDelim) {
        start_position = current_position;
        break;
      }
      current_position++;
    }

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
// saipa
void s21_reverse(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int s21_itoa(int num, char *str, int base) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }

    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    s21_reverse(str, i);

    return i;
}

int s21_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] != '\0') {
        result = result * 10 + str[i] - '0';
        i++;
    }

    return sign * result;
}

int s21_sprintf(char *output, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int chars_written = 0;
            // Flags
            int left_justify = 0;
            // int force_sign = 0;
            // int space_for_positive = 0;
            // int alternate_form = 0;
            int zero_padding = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++;



            while (*format == '-' || *format == '+' || *format == ' ' ||
                   *format == '#' || *format == '0') {
                if (*format == '-') {
                    left_justify = 1;
                } 
                // else if (*format == '+') {
                //     force_sign = 1;
                // } else if (*format == ' ') {
                //     space_for_positive = 1;
                // } else if (*format == '#') {
                //     alternate_form = 1;
                // }
                 else if (*format == '0') {
                    zero_padding = 1;
                }
                format++;
            }

            // Width
            int width = 0;
            if (*format == '*') {
                width = va_arg(args, int);
                format++;
            } else {
                while (*format >= '0' && *format <= '9') {
                    width = width * 10 + (*format - '0');
                    format++;
                }
            }

            // Length
           // int long_double = 0;
            while (*format == 'l' || *format == 'L') {
                //long_double = 1;
                format++;
            }

            // Specifier
            switch (*format) {
                case 'c': {
                    wchar_t ch = (wchar_t)va_arg(args, wint_t);

                    // Handle width
                    int padding = (width > 1) ? width - 1 : 0;

                    if (!left_justify && !zero_padding) {
                        while (padding > 0) {
                            *output = ' ';
                            output++;
                            chars_written++;
                            padding--;
                        }
                    }

                    // Write the character
                    *output = (char)ch;
                    output++;
                    chars_written++;

                    if (left_justify) {
                        while (padding > 0) {
                            *output = ' ';
                            output++;
                            chars_written++;
                            padding--;
                        }
                    }

                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    int written = s21_itoa(num, output, 10);
                    output += written;
                    chars_written += written;
                    break;
                }
                // ... (other cases for different specifiers)
                default:
                    // Handle unsupported specifiers if needed.
                    break;
            }
        } else {
            *output = *format;
            output++;
            chars_written++;
        }

        format++;
    }

    va_end(args);

    *output = '\0';  // Null-terminate the output string

    return chars_written;
}