#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(const char *str);
int s21_strcmp(const char *a, const char *b);
char *s21_strcpy(char *str1, const char *str2);
char *s21_strcat(char *str1, const char *str2);
char *s21_strchr(const char *s, int c);
char *s21_strstr(char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);

#endif