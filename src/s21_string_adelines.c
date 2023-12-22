#include <stdint.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

// void s21_reverse(char *str, int length) {
//   int start = 0;
//   int end = length - 1;
//   while (start < end) {
//     char temp = str[start];
//     str[start] = str[end];
//     str[end] = temp;
//     start++;
//     end--;
//   }
// }

// int s21_itoa(int num, char *str, int base) {
//   int i = 0;
//   int isNegative = 0;

//   if (num == 0) {
//     str[i++] = '0';
//     str[i] = '\0';
//     return i;
//   }

//   if (num < 0 && base == 10) {
//     isNegative = 1;
//     num = -num;
//   }

//   while (num != 0) {
//     int rem = num % base;
//     str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
//     num = num / base;
//   }

//   if (isNegative) {
//     str[i++] = '-';
//   }

//   str[i] = '\0';

//   s21_reverse(str, i);

//   return i;
// }

// int s21_atoi(const char *str) {
//   int result = 0;
//   int sign = 1;
//   int i = 0;

//   if (str[0] == '-') {
//     sign = -1;
//     i++;
//   }

//   while (str[i] != '\0') {
//     result = result * 10 + str[i] - '0';
//     i++;
//   }

//   return sign * result;
// }

// int s21_sprintf(char *str, const char *format, ...) {
//   va_list args;
//   va_start(args, format);

//   int chars_written = 0;

//   while (*format != '\0') {
//     if (*format == '%') {
//       format++;

//       // Flags
//       // int left_justify = 0;
//       // int force_sign = 0;
//       // int space_for_positive = 0;
//       // int alternate_form = 0;
//       // int zero_padding = 0;

//       while (*format == '-' || *format == '+' || *format == ' ' ||
//              *format == '#' || *format == '0') {
//         // if (*format == '-') {
//         //     left_justify = 1;
//         // } else if (*format == '+') {
//         //     force_sign = 1;
//         // } else if (*format == ' ') {
//         //     space_for_positive = 1;
//         // } else if (*format == '#') {
//         //     alternate_form = 1;
//         // } else if (*format == '0') {
//         //     zero_padding = 1;
//         // }
//         format++;
//       }

//       // Width
//       int width = 0;
//       if (*format == '*') {
//         width = va_arg(args, int);
//         format++;
//       } else {
//         while (*format >= '0' && *format <= '9') {
//           width = width * 10 + (*format - '0');
//           format++;
//         }
//       }

//       // Precision
//       int precision = -1;
//       if (*format == '.') {
//         format++;
//         if (*format == '*') {
//           precision = va_arg(args, int);
//           format++;
//         } else {
//           precision = 0;
//           while (*format >= '0' && *format <= '9') {
//             precision = precision * 10 + (*format - '0');
//             format++;
//           }
//         }
//       }

//       // Length
//       int long_double = 0;
//       while (*format == 'L') {
//         long_double = 1;
//         format++;
//       }

//       // Specifier
//       switch (*format) {
//         case 'c': {
//           char ch = (char)va_arg(args, int);
//           // Обработка ширины поля
//           if (width > 0) {
//             int padding = width - 1;
//             if (*format != '-') {
//               char pad_char = (*format == '0') ? '0' : ' ';
//               while (padding-- > 0) {
//                 *str = pad_char;
//                 str++;
//                 chars_written++;
//               }

//             }
//           }
//           *str = ch;
//           str++;
//           chars_written++;

//           // Обработка ширины поля
//           if (width > 0 && *format == '-') {
//             int padding = width - 1;
//             while (padding-- > 0) {
//               *str = ' ';
//               str++;
//               chars_written++;
//             }
//           }
//           break;
//         }

//         case 'd':
//         case 'i': {
//           int num = va_arg(args, int);
//           chars_written += s21_itoa(num, str, 10);
//           str += strlen(str);
//           break;
//         }
//         case 'f': {
//           if (long_double) {
//             // Handle long double (not fully supported here)
//             long double num = va_arg(args, long double);
//             chars_written += s21_itoa((int)num, str, 10);
//             str += strlen(str);
//           } else {
//             double num = va_arg(args, double);
//             chars_written += s21_itoa((int)num, str, 10);
//             str += strlen(str);
//           }
//           break;
//         }
//         case 's': {
//           char *str = va_arg(args, char *);
//           while (*str != '\0' && (precision == -1 || precision-- > 0)) {
//             *str = *str;
//             str++;
//             chars_written++;
//             str++;
//           }
//           break;
//         }
//         case 'u': {
//           unsigned int num = va_arg(args, unsigned int);
//           chars_written += s21_itoa(num, str, 10);
//           str += strlen(str);
//           break;
//         }
//         case '%': {
//           *str = '%';
//           str++;
//           chars_written++;
//           break;
//         }
//         case 'g':
//         case 'G':
//           chars_written += s21_itoa(va_arg(args, double), str, 10);
//           str += strlen(str);
//           break;
//         case 'e':
//         case 'E':
//           chars_written += s21_itoa(va_arg(args, int), str, 10);
//           str += strlen(str);
//           break;
//         case 'x':
//         case 'X': {
//           unsigned int num = va_arg(args, unsigned int);
//           chars_written += s21_itoa(num, str, 16);
//           str += strlen(str);
//           if (*format == 'X') {
//             for (int i = 0; str[i] != '\0'; i++) {
//               if (str[i] >= 'a' && str[i] <= 'z') {
//                 str[i] = str[i] - 32;
//               }
//             }
//           }
//           break;
//         }
//         case 'o': {
//           unsigned int num = va_arg(args, unsigned int);
//           chars_written += s21_itoa(num, str, 8);
//           str += strlen(str);
//           break;
//         }
//         case 'p': {
//           uintptr_t ptr_val = (uintptr_t)va_arg(args, void *);
//           chars_written += s21_itoa((int)ptr_val, str, 16);
//           str += strlen(str);
//           break;
//         }
//         default:
//           // Handle unsupported specifiers if needed.
//           break;
//       }
//     } else {
//       *str = *format;
//       str++;
//       chars_written++;
//     }

//     format++;
//   }

//   va_end(args);

//   *str = '\0';  // Null-terminate the str string

//   return chars_written;
// }

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

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            // Flags
            int left_justify = 0;
            int force_sign = 0;
            int space_for_positive = 0;
            int alternate_form = 0;
            int zero_padding = 0;

            while (*format == '-' || *format == '+' || *format == ' ' ||
                   *format == '#' || *format == '0') {
                if (*format == '-') {
                    left_justify = 1;
                } else if (*format == '+') {
                    force_sign = 1;
                } else if (*format == ' ') {
                    space_for_positive = 1;
                } else if (*format == '#') {
                    alternate_form = 1;
                } else if (*format == '0') {
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
            int long_double = 0;
            while (*format == 'l' || *format == 'L') {
                long_double = 1;
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
int main() {
  char str1[100];
  char str2[100];
  char *str3 = "%-010c Test % -10c Test %-lc";
  int a = 74;
  unsigned long int b = 74;
  printf("%d\n %d", sprintf(str1, str3, a, a, b),
         s21_sprintf(str1, str3, a, a, b));
  if (sprintf(str1, str3, a, a, b) == s21_sprintf(str2, str3, a, a, b)) {
    printf("s");
  }
  if (strcmp(str1, str2) == 0) {
    printf("a");
  }
  printf("\n%s\n", str1);
  printf("%s", str2);

  return 0;
}
