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

    char str6 [10]="01234539";
   // Набор символов, которые не должны входить в искомый сегмент
   char sym [10]="9876";
    int len = strcspn(str6, sym);
    printf("%d\n", len);

    int len1 = s21_strcspn(str6, sym);
    printf("%d\n", len1);
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

int s21_strncmp (const char *str1, const char *str2, size_t n) {
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

size_t s21_strcspn(const char *str1, const char *str2) {
    size_t len = 0;
    for (int i = 0; i < (int)strlen(str1); i++) {
        for (int j = 0; j < (int)strlen(str2); j++) {
            if(str1[i] != str2[j]) {
                
            }
        } 
    }
    return len;
}