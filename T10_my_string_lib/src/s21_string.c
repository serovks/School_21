#include "s21_string.h"

#include <stdio.h>

int s21_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int s21_strcmp(const char *a, const char *b) {
    while (*a == *b && *a != '\0') {
        a++;
        b++;
    }

    return *a - *b;
}

char *s21_strcpy(char *str1, const char *str2) {
    char *copy_str1 = str1;

    while (*str2 != '\0') {
        *str1++ = *str2++;
    }

    *str1 = '\0';

    return copy_str1;
}

char *s21_strcat(char *str1, const char *str2) {
    char *copy_str1 = str1;

    while (*str1 != '\0') {
        str1++;
    }

    while (*str2 != '\0') {
        *str1++ = *str2++;
    }

    *str1 = '\0';

    return copy_str1;
}

char *s21_strchr(const char *s, int c) {
    while (*s != '\0') {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }

    if ((char)c == '\0') {
        return (char *)s;
    }

    return NULL;
}

char *s21_strstr(char *str1, const char *str2) {
    if (*str2 == '\0') return (char *)str1;

    for (; *str1 != '\0'; str1++) {
        if (*str1 == *str2) {
            const char *p1 = str1;
            const char *p2 = str2;

            while (*p1 && *p2 && *p1 == *p2) {
                p1++;
                p2++;
            }

            if (*p2 == '\0') {
                return (char *)str1;
            }
        }
    }

    return NULL;
}

char *s21_strtok(char *str, const char *delim) {
    static char *last = NULL;
    if (str) last = str;
    if (!last || !*last) return NULL;

    char *start = last;
    while (*last && s21_strchr(delim, *last)) last++;
    if (!*last) return NULL;

    start = last;
    while (*last && !s21_strchr(delim, *last)) last++;

    if (*last) {
        *last = '\0';
        last++;
    }

    return start;
}
