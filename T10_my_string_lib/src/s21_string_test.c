#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test() {
    const char *tests[] = {"hello", "", "a", "hello world", "school21"};
    const int expected[] = {5, 0, 1, 11, 8};
    int test_count = sizeof(tests) / sizeof(tests[0]);
    printf("Tests for: int s21_strlen(const char*)\n");
    for (int i = 0; i < test_count; i++) {
        printf("\n---------- Test %d ----------\n", i + 1);
        printf("Input: \"%s\"\n", tests[i]);
        printf("Output: %d\n", s21_strlen(tests[i]));
        printf("Result: %s\n", (s21_strlen(tests[i]) == expected[i]) ? "SUCCESS" : "FAIL");
        printf("----------------------------\n");
    }
}

void s21_strcmp_test() {
    const char *tests1[] = {"abc", "abc", "ab", "abc"};
    const char *tests2[] = {"abc", "ab", "abc", "abd"};
    const int expected[] = {0, 99, -99, -1};
    int test_count = sizeof(tests1) / sizeof(tests1[0]);
    printf("Tests for: int s21_strcmp(const char*, const char*)\n");
    for (int i = 0; i < test_count; i++) {
        printf("\n---------- Test %d ----------\n", i + 1);
        printf("Input: \"%s\" \"%s\"\n", tests1[i], tests2[i]);
        printf("Output: %d\n", s21_strcmp(tests1[i], tests2[i]));
        printf("Result: %s\n", (s21_strcmp(tests1[i], tests2[i]) == expected[i]) ? "SUCCESS" : "FAIL");
        printf("----------------------------\n");
    }
}

void s21_strcpy_test() {
    const char *src_strings[] = {"", "21", "world", "exam-msk.21-school.ru"};
    char dest_buffers[4][32] = {{"lalalalala"}};  // buffers for writing

    printf("Tests for: char *s21_strcpy(char*, const char*)\n");
    int test_count = sizeof(src_strings) / sizeof(src_strings[0]);
    for (int i = 0; i < test_count; i++) {
        printf("\n---------- Test %d ----------\n", i + 1);
        printf("Input: \"%s\" \"%s\"\n", dest_buffers[i], src_strings[i]);

        char *result = s21_strcpy(dest_buffers[i], src_strings[i]);

        int success = 1;
        const char *s1 = src_strings[i];
        const char *s2 = result;
        while (*s1 || *s2) {
            if (*s1++ != *s2++) {
                success = 0;
                break;
            }
        }
        printf("Output: %s\n", result);
        printf("Result: %s\n", success ? "SUCCESS" : "FAIL");
        printf("----------------------------\n");
    }
}

void s21_strcat_test() {
    const char *src_strings[] = {"", "21", "world", "exam-msk.21-school.ru"};
    char dest_buffers[4][32] = {
        {"lalalalala"}, {"catcatcat"}, {"52  52  52"}, {"qwerty"}};  // buffers for writing
    char *success[] = {"lalalalala", "catcatcat21", "52  52  52world", "qwertyexam-msk.21-school.ru"};

    printf("Tests for: char *s21_strcpy(char*, const char*)\n");
    int test_count = sizeof(src_strings) / sizeof(src_strings[0]);
    for (int i = 0; i < test_count; i++) {
        printf("\n---------- Test %d ----------\n", i + 1);
        printf("Input: \"%s\" \"%s\"\n", dest_buffers[i], src_strings[i]);

        char *result = s21_strcat(dest_buffers[i], src_strings[i]);

        printf("Output: %s\n", result);
        printf("Result: %s\n", success[i] ? "SUCCESS" : "FAIL");
        printf("----------------------------\n");
    }
}

void s21_strchr_test() {
    const char *test_strings[] = {"hello", "21-school", "world", "5252", "abc"};
    int test_chars[] = {'h', 'l', 'a', '2', '\0'};
    int expected_pos[] = {// -1 = NULL
                          0, 8, -1, 1, 3};

    int test_count = sizeof(test_strings) / sizeof(test_strings[0]);
    printf("Tests for: char *s21_strchr(const char*, int)\n");

    for (int i = 0; i < test_count; i++) {
        printf("\n---------- Test %d ----------\n", i + 1);
        printf("Input: \"%s\" '%c'\n", test_strings[i], test_chars[i]);

        char *result = s21_strchr(test_strings[i], test_chars[i]);

        if (expected_pos[i] == -1) {  // NULL
            printf("Expected: NULL (symbol not found)\n");
            printf("Output: %s\n", result ? "NOT NULL" : "NULL");
            printf("Result: %s\n", result == NULL ? "SUCCESS" : "FAIL");
        } else {  // not     NULL
            int pos = result - test_strings[i];
            char expected_char = test_strings[i][expected_pos[i]];
            printf("Expected: pos %d ('%c')\n", expected_pos[i], expected_char);
            printf("Output: pos %d ('%c')\n", pos, *result);
            printf("Result: %s\n", (pos == expected_pos[i] && *result == expected_char) ? "SUCCESS" : "FAIL");
        }
        printf("----------------------------\n");
    }
}

void s21_strstr_test() {
    char *tests1[] = {"hello world", "abcabc", "21-school", "mississippi", "test", ""};
    const char *tests2[] = {"world", "abc", "21", "ss", "xyz", ""};
    int expected_pos[] = {6, 0, 0, 2, -1, 0};

    int test_count = sizeof(tests1) / sizeof(tests1[0]);
    printf("Tests for: char *s21_strstr(char*, const char*)\n");

    for (int i = 0; i < test_count; i++) {
        printf("\n---------- Test %d ----------\n", i + 1);
        printf("Input: \"%s\" \"%s\"\n", tests1[i], tests2[i]);

        char *result = s21_strstr(tests1[i], tests2[i]);

        if (expected_pos[i] == -1) {  // NULL
            printf("Expected: NULL (substring not found)\n");
            printf("Output: %s\n", result ? "NOT NULL" : "NULL");
            printf("Result: %s\n", result == NULL ? "SUCCESS" : "FAIL");
        } else {  // not NULL
            int pos = result - tests1[i];
            printf("Expected: pos %d (\"%s\")\n", expected_pos[i], tests1[i] + expected_pos[i]);
            printf("Output: pos %d (\"%s\")\n", pos, result);
            printf("Result: %s\n", (pos == expected_pos[i]) ? "SUCCESS" : "FAIL");
        }
        printf("----------------------------\n");
    }
}
// ultra mega deepseek chinese helper
void s21_strtok_test() {
    char str1[] = "hello world,test";
    char str2[] = "one,two,three";
    char str3[] = "a-b-c";
    char str4[] = "first||second||third";

    const char *delims[] = {" ,", ",", "-", "|"};
    const char *expected[][4] = {{"hello", "world", "test", NULL},
                                 {"one", "two", "three", NULL},
                                 {"a", "b", "c", NULL},
                                 {"first", "second", "third", NULL}};

    int test_count = 4;
    printf("Tests for: char *s21_strtok(char*, const char*)\n");

    for (int i = 0; i < test_count; i++) {
        char str_copy[32];
        s21_strcpy(str_copy, (i == 0) ? str1 : (i == 1) ? str2 : (i == 2) ? str3 : str4);

        printf("\n---------- Test %d ----------\n", i + 1);
        printf("Input string: \"%s\"\n", str_copy);
        printf("Delimiters: \"%s\"\n", delims[i]);
        printf("Expected tokens:\n");

        for (int j = 0; expected[i][j] != NULL; j++) {
            printf("  [%d] \"%s\"\n", j, expected[i][j]);
        }

        printf("Actual tokens:\n");
        char *token = s21_strtok(str_copy, delims[i]);
        int token_num = 0;
        int success = 1;

        while (token != NULL) {
            printf("  [%d] \"%s\"", token_num, token);

            if (expected[i][token_num] == NULL || s21_strcmp(token, expected[i][token_num]) != 0) {
                printf("  [FAIL: expected \"%s\"]", expected[i][token_num] ? expected[i][token_num] : "NULL");
                success = 0;
            }

            printf("\n");
            token = s21_strtok(NULL, delims[i]);
            token_num++;
        }

        if (expected[i][token_num] != NULL) {
            printf("  [FAIL: missing token \"%s\"]\n", expected[i][token_num]);
            success = 0;
        }

        printf("Result: %s\n", success ? "SUCCESS" : "FAIL");
        printf("----------------------------\n");
    }
}

int main() {
#ifdef STRLEN
    s21_strlen_test();
#endif

#ifdef STRCMP
    s21_strcmp_test();
#endif

#ifdef STRCPY
    s21_strcpy_test();
#endif

#ifdef STRCAT
    s21_strcat_test();
#endif

#ifdef STRCHR
    s21_strchr_test();
#endif

#ifdef STRSTR
    s21_strstr_test();
#endif

#ifdef STRTOK
    s21_strtok_test();
#endif

    return 0;
}