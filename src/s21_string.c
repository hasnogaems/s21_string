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

void reset_flags(flag_t* flags) {
  flags->plus = 0;
  flags->minus = 0;
  flags->space = 0;
  flags->is_short = 0;
  flags->is_long = 0;
  flags->precision = -1;
  flags->width = 0;
}

char* print_char(char* str, flag_t* flags, char type, va_list* input) {
  if (flags->minus == 0) {
    for (int i = 0; i < flags->width - 1; i++) {
      *str = ' ';
      str++;
    }
  }

  if (type == '%') {
    *str = '%';
  } else {
    *str = (char)va_arg(*input, int);
  }

  if (flags->minus == 1) {
    str++;
    for (int i = 0; i < flags->width - 1; i++) {
      *str = ' ';
      str++;
    }
    str--;
  }
  return str;
}

char* print_string(char* str, flag_t* flags, va_list* input) {
  char* symbol = va_arg(*input, char*);
  if (symbol == NULL) {
    char* null_message = "(null)";
    symbol = null_message;
  }
  int width_difference = 0;
  if ((unsigned long long)flags->precision < s21_strlen(symbol)) {
    width_difference = flags->width - flags->precision;
  } else {
    width_difference = flags->width - s21_strlen(symbol);
  }
  if (flags->minus == 0) {
    for (int i = 0; i < width_difference; i++) {
      *str = ' ';
      str++;
    }
  }
  for (unsigned int i = 0;
       (i < (unsigned)flags->precision) && (symbol[i] != '\0'); i++) {
    *str = symbol[i];
    str++;
  }
  if (flags->minus == 1) {
    for (int i = 0; i < width_difference; i++) {
      *str = ' ';
      str++;
    }
  }
  str--;
  return str;
}

char* print_number(char* str, flag_t* flags, char type, va_list* input) {
  char buffer[256];

  if (type == 'f') {
    s21_ftos(buffer, va_arg(*input, double), flags);
  } else if (type == 'u') {
    unsigned long input_data;
    if (flags->is_long == 1)
      input_data = (unsigned long)va_arg(*input, unsigned long);
    else if (flags->is_short == 1)
      input_data = (unsigned short)va_arg(*input, int);
    else
      input_data = (unsigned int)va_arg(*input, unsigned int);
    s21_uitos(buffer, input_data, flags);
  } else {
    long long int input_data;
    if (flags->is_long == 1)
      input_data = (long long)va_arg(*input, long);
    else if (flags->is_short == 1)
      input_data = (short)va_arg(*input, int);
    else
      input_data = (int)va_arg(*input, int);
    s21_itos(buffer, input_data, flags);
  }

  for (int i = 0; buffer[i] != '\0'; i++) {
    *str = buffer[i];
    str++;
  }

  str--;
  return str;
}

unsigned long long s21_pow(int base, int exp) {
  unsigned long long result = 1;
  for (int i = 0; i < exp; i++) {
    result *= base;
  }
  return result;
}

void s21_itos(char* str, long long int num, flag_t* flags) {
  if (flags->precision == -1) {
    flags->precision = 1;
  }

  if ((flags->precision != 0) || (num != 0)) {
    int sign = 0;
    if (num < 0) {
      sign = -1;
      flags->width--;
    } else if (flags->plus == 1) {
      sign = 1;
      flags->width--;
    } else if (flags->space == 1) {
      *str = ' ';
      str++;
      flags->width--;
    }

    int num_of_digits = 0;
    long long int complete_part = num;

    while (complete_part != 0) {
      num_of_digits++;
      complete_part = complete_part / 10;
    }
    complete_part = num;

    if (num_of_digits < flags->precision) {
      num_of_digits = flags->precision;
    }
    int width_difference = flags->width - num_of_digits;

    if (flags->minus == 0) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }

    if (sign < 0) {
      *str = '-';
      str++;
    } else if (sign > 0) {
      *str = '+';
      str++;
    }

    do {
      long long int c = s21_pow(10, num_of_digits - 1);
      long long int b = complete_part / c;
      complete_part = complete_part % c;
      if (b < 0) {
        b = -b;
      }
      *str = '0' + b;
      str++;
      num_of_digits--;
    } while (num_of_digits > 0);

    if (flags->minus == 1) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }
  } else {
    if (flags->width > 0) {
      for (int i = 0; i < flags->width; i++) {
        *str = ' ';
        str++;
      }
    }
  }
  *str = '\0';
}

void s21_uitos(char* str, unsigned long num, flag_t* flags) {
  if (flags->precision == -1) {
    flags->precision = 1;
  }

  if ((flags->precision != 0) || (num != 0)) {
    int num_of_digits = 0;
    unsigned long complete_part = num;

    while (complete_part > 0) {
      num_of_digits++;
      complete_part = complete_part / 10;
    }
    complete_part = num;

    if (num_of_digits < flags->precision) {
      num_of_digits = flags->precision;
    }
    int width_difference = flags->width - num_of_digits;

    if (flags->minus == 0) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }

    do {
      unsigned long int c = s21_pow(10, num_of_digits - 1);
      int b = complete_part / c;
      complete_part = complete_part % c;
      *str = '0' + b;
      str++;
      num_of_digits--;
    } while (num_of_digits > 0);

    if (flags->minus == 1) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }
  } else {
    if (flags->width > 0) {
      for (int i = 0; i < flags->width; i++) {
        *str = ' ';
        str++;
      }
    }
  }
  *str = '\0';
}

void s21_ftos(char* str, double num, flag_t* flags) {
  if (flags->precision == -1) {
    flags->precision = 6;
  }

  if (num < 0.0) {
    num -= 5.0 / s21_pow(10, flags->precision + 1);
  } else {
    num += 5.0 / s21_pow(10, flags->precision + 1);
  }

  int sign = 0;
  if (num < 0) {
    sign = -1;
    flags->width--;
  } else if (flags->plus == 1) {
    sign = 1;
    flags->width--;
  } else if (flags->space == 1) {
    flags->width--;
  }

  long int complete_part = num;
  double fractional_part = num - complete_part;
  int num_of_digits = 0;
  if (complete_part == 0) {
    num_of_digits = 1;
  }

  while (complete_part != 0) {
    num_of_digits++;
    complete_part = complete_part / 10;
  }
  complete_part = num;
  int width_difference = flags->width - (num_of_digits + flags->precision);

  if (flags->precision != 0) {
    width_difference--;
  }

  if (flags->minus == 0) {
    if (width_difference > 0) {
      for (int i = 0; i < width_difference; i++) {
        *str = ' ';
        str++;
      }
    }
  }

  if (sign < 0) {
    *str = '-';
    str++;
  } else if (sign > 0) {
    *str = '+';
    str++;
  } else if (flags->space == 1) {
    *str = ' ';
    str++;
  }

  do {
    long int c = s21_pow(10, num_of_digits - 1);
    int b = complete_part / c;
    complete_part = complete_part % c;
    if (b < 0) {
      b = -b;
    }
    *str = '0' + b;
    str++;
    num_of_digits--;
  } while (num_of_digits > 0);

  if (flags->precision > 0) {
    *str = '.';
    str++;
  }

  for (int i = 0; i < flags->precision; i++) {
    fractional_part = fractional_part * 10.0;
    int b = fractional_part;
    fractional_part -= b;
    b = b % 10;
    if (b < 0) {
      b = -b;
    }
    *str = '0' + b;
    str++;
  }

  if (flags->minus == 1) {
    if (width_difference > 0) {
      for (int i = 0; i < width_difference; i++) {
        *str = ' ';
        str++;
      }
    }
  }

  *str = '\0';
}

int s21_sprintf(char* str, const char* format, ...) {
  va_list(input);
  va_start(input, format);
  char* start_str = str;

  flag_t flags;
  reset_flags(&flags);

  int spec_state = 0;
  int spec_found = 0;

  while (*format) {
    if (spec_state == 0) {
      if (*format == '%') {
        spec_state = 1;
      } else {
        *str = *format;
        str++;
      }
      format++;
    } else {
      if (*format == 'c' || *format == '%') {
        str = print_char(str, &flags, *format, &input);
        spec_found = 1;
      }
      if (*format == 's') {
        str = print_string(str, &flags, &input);
        spec_found = 1;
      }
      if (*format == 'd' || *format == 'i' || *format == 'u' ||
          *format == 'f') {
        str = print_number(str, &flags, *format, &input);
        spec_found = 1;
      }
      if (*format == '+') {
        flags.plus = 1;
      }
      if (*format == '-') {
        flags.minus = 1;
      }
      if (*format == ' ') {
        flags.space = 1;
      }
      if (*format == 'h') {
        flags.is_short = 1;
      }
      if (*format == 'l') {
        flags.is_long = 1;
      }
      if ((*format >= '0') && (*format <= '9')) {
        while ((*format >= '0') && (*format <= '9')) {
          flags.width = flags.width * 10 + (*format - 48);
          format++;
        }
        format--;
      }
      if (*format == '.') {
        flags.precision = 0;
        format++;
        while ((*format >= '0') && (*format <= '9')) {
          flags.precision = flags.precision * 10 + (*format - 48);
          format++;
        }
        format--;
      }
      if (spec_found == 1) {
        spec_state = 0;
        spec_found = 0;
        reset_flags(&flags);
        str++;
      }
      format++;
    }
  }
  *str = '\0';
  va_end(input);
  int result = str - start_str;
  return result;
}