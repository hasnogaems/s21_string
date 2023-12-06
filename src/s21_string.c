#include "s21_string.h"

int main() {
    char * str = s21_memchr("string", 't', 6);

    int s21memcmp = s21_memcmp("asd", "asd", 20);
    int origmemcmp = memcmp("asd", "asd", 20);
    printf("%s: %d\n", "Memcmp", origmemcmp);
    printf("%s: %d\n", "s21_Mamcmp", s21memcmp);
    printf("%s: %s\n", "s21_memchr", str);


    char source[10] = "string";
    // s21_memcpy(dest2, source, 10);
    // memcpy(dest, source, 10);
    // printf("memcpy: %s\n", dest);
    // printf("s21_memcpy: %s\n", dest2);

    // memset(dest, '1', 4);
    // s21_memset(dest2, '1', 4);

    // printf("memset: %s\n", dest);
    // printf("s21_memset: %s\n", dest2);

    // strncat(dest, source, 4);
    // printf("strncat: %s\n", dest);
    
    // s21_strncat(dest2, source, 4);
    // printf("s21_strncat: %s\n", dest2);
    int ch = 'r';
    char * c = strchr(source, ch);
    printf("strchr: %p\n", c);

    int i = strncmp("string", "strina", 10);
    int j = s21_strncmp("string", "strina", 10);
    printf("strncmp: %d\n", i);
    printf("s21_strncmp: %d\n", j);

    char str6 [10]="123456780";
    char sym [10]="9876";
    int len = strcspn(str6, sym);
    printf("strcspn: %d\n", len);

    int len1 = s21_strcspn(str6, sym);
    printf("s21_strcspn: %d\n", len1);

    printf("strerror: %s\n", strerror(108));
    printf("s21_strerror: %s\n", s21_strerror(108));

    printf("s21_strlen: %ld\n", s21_strlen("sdfbsgjfsw24645g"));
    printf("strlen: %ld\n", strlen("sdfbsgjfsw24645g"));

    char mas1[10] = "12345";
    char mas2[10] = "67891";
    char *sdf = strpbrk(mas1, mas2);
    printf("%s", sdf);
}

void *s21_memchr(const void *str, int c, size_t n) {
    for(int i = 0; i < (int)n; i++) {
        if(((char *)str)[i] == c) {
            return ((char *)str) + i;
        }
    }
    return NULL;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int cmp = 0;
    for (int i = 0; i < (int)n; i++) {
        if (((char *)str1)[i] > ((char *)str2)[i]) {
            return cmp = ((char *)str1)[i] - ((char *)str2)[i];
        } else if (((char *)str1)[i] < ((char *)str2)[i]) {
            return cmp = ((char *)str1)[i] - ((char *)str2)[i];
        }
    }
    return cmp;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    for (int i = 0; i < (int)n; i++) {
        ((char *)dest)[i] = ((char *)src)[i];
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    for (int i = 0; i < (int)n; i++) {
        ((char *)str)[i] = c;
    }
    return str;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    for (int i = 0; i < (int)n && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[strlen(dest)] = '\0';
    return dest;
}


// char *s21_strchr(const char *str, int c) {

// }


int s21_strncmp(const char *str1, const char *str2, size_t n) {
    int cmp = 0;
    for (int i = 0; i < (int)n; i++) {
        if (str1[i] > str2[i]) {
            return cmp = str1[i] - str2[i];
        } else if (((char *)str1)[i] < ((char *)str2)[i]) {
            return cmp = str1[i] - str2[i];
        }
    }
    return cmp;
}

// char *s21_strncpy(char *dest, const char *src, size_t n) {

// }

size_t s21_strcspn(const char *str1, const char *str2) {
    size_t len = 0;
    
    for (int i = 0; i < (int)strlen(str1); i++) {
        int check = 0;
        for (int j = 0; j < (int)strlen(str2); j++) {
            if(str1[i] == str2[j]) {
                check = 1;
                break;
            }
        }
        if(!check) {
            len++;
        } else {
            break;
        }
    }
    return len;
}

char *s21_strerror(int errnum) {
    char *str = (char*)malloc(50 * sizeof(char));
    if(errnum <= 106 && errnum >= 1) {
        str = errorStrings[errnum - 1];
    } else {
        snprintf(str, 50, "Unknown error: %d", errnum);
    }
    free(str);
    return str;
}

size_t s21_strlen(const char *str) {
    const char *ptr = str;
    while(*ptr != '\0') {
        ptr++;
    }
    return (size_t)(ptr - str);
}


// char *s21_strpbrk(const char *str1, const char *str2) {
    
//     for (int i = 0; i < (int)strlen(str1); i++) {
//         for (int j = 0; j < (int)strlen(str2); j++) {
//             if(str1[i] == str2[j]) {

//             }
//         }
//     }
// }