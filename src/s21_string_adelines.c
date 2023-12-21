#include "s21_string.h"
#include <string.h>
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
            // int left_justify = 0;
            // int force_sign = 0;
            // int space_for_positive = 0;
            // int alternate_form = 0;
            // int zero_padding = 0;

            while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' || *format == '0') {
                // if (*format == '-') {
                //     left_justify = 1;
                // } else if (*format == '+') {
                //     force_sign = 1;
                // } else if (*format == ' ') {
                //     space_for_positive = 1;
                // } else if (*format == '#') {
                //     alternate_form = 1;
                // } else if (*format == '0') {
                //     zero_padding = 1;
                // }
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

            // Precision
            int precision = -1;
            if (*format == '.') {
                format++;
                if (*format == '*') {
                    precision = va_arg(args, int);
                    format++;
                } else {
                    precision = 0;
                    while (*format >= '0' && *format <= '9') {
                        precision = precision * 10 + (*format - '0');
                        format++;
                    }
                }
            }

            // Length
            int long_double = 0;
            while (*format == 'L') {
                long_double = 1;
                format++;
            }

            // Specifier
            switch (*format) {
                case 'c': {
                    char ch = (char)va_arg(args, int);
                    *output = ch;
                    output++;
                    chars_written++;
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    chars_written += s21_itoa(num, output, 10);
                    output += strlen(output);
                    break;
                }
                case 'f': {
                    if (long_double) {
                        // Handle long double (not fully supported here)
                        long double num = va_arg(args, long double);
                        chars_written += s21_itoa((int)num, output, 10);
                        output += strlen(output);
                    } else {
                        double num = va_arg(args, double);
                        chars_written += s21_itoa((int)num, output, 10);
                        output += strlen(output);
                    }
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str != '\0' && (precision == -1 || precision-- > 0)) {
                        *output = *str;
                        output++;
                        chars_written++;
                        str++;
                    }
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    chars_written += s21_itoa(num, output, 10);
                    output += strlen(output);
                    break;
                }
                case '%': {
                    *output = '%';
                    output++;
                    chars_written++;
                    break;
                }
                case 'g':
                case 'G':
                    chars_written += s21_itoa(va_arg(args, double), output, 10);
                    output += strlen(output);
                    break;
                case 'e':
                case 'E':
                    chars_written += s21_itoa(va_arg(args, int), output, 10);
                    output += strlen(output);
                    break;
                case 'x':
                case 'X': {
                    unsigned int num = va_arg(args, unsigned int);
                    chars_written += s21_itoa(num, output, 16);
                    output += strlen(output);
                    if (*format == 'X') {
                        for (int i = 0; output[i] != '\0'; i++) {
                            if (output[i] >= 'a' && output[i] <= 'z') {
                                output[i] = output[i] - 32;
                            }
                        }
                    }
                    break;
                }
                case 'o': {
                    unsigned int num = va_arg(args, unsigned int);
                    chars_written += s21_itoa(num, output, 8);
                    output += strlen(output);
                    break;
                }
                case 'p': {
                    uintptr_t ptr_val = (uintptr_t)va_arg(args, void *);
                    chars_written += s21_itoa((int)ptr_val, output, 16);
                    output += strlen(output);
                    break;
                }
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

// int main() {
//     char output_str[100];

//     // Test cases for different specifiers
//     s21_sprintf(output_str, "Char: %c\n", 'A');
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Integer: %d\n", 12345);
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Float: %f\n", 45.67);
//     printf("%s", output_str);

//     s21_sprintf(output_str, "String: %s\n", "Hello");
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Unsigned: %u\n", 98765u);
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Percent: %%\n");
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Scientific Notation: %e\n", 1234.5678);
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Hexadecimal: %x\n", 255);
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Hexadecimal (uppercase): %X\n", 255);
//     printf("%s", output_str);

//     s21_sprintf(output_str, "Octal: %o\n", 255);
//     printf("%s", output_str);

//     int value = 42;
//     s21_sprintf(output_str, "Pointer: %p\n", (void *)(uintptr_t)&value);
//     printf("%s", output_str);

//     return 0;
// }
