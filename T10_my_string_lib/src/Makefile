CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD_DIR = ../build

SRCS = s21_string.c s21_string_test.c

TARGET_LEN = $(BUILD_DIR)/Quest_1
TARGET_CMP = $(BUILD_DIR)/Quest_2
TARGET_CPY = $(BUILD_DIR)/Quest_3
TARGET_CAT = $(BUILD_DIR)/Quest_4
TARGET_CHR = $(BUILD_DIR)/Quest_5
TARGET_STR = $(BUILD_DIR)/Quest_6
TARGET_TOK = $(BUILD_DIR)/Quest_7

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests: $(TARGET_LEN)

$(TARGET_LEN): $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(SRCS) -DSTRLEN -o $@

strcmp_tests: $(TARGET_CMP)

$(TARGET_CMP): $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(SRCS) -DSTRCMP -o $@

strcpy_tests: $(TARGET_CPY)

$(TARGET_CPY): $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(SRCS) -DSTRCPY -o $@

strcat_tests: $(TARGET_CAT)

$(TARGET_CAT): $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(SRCS) -DSTRCAT -o $@

strchr_tests: $(TARGET_CHR)

$(TARGET_CHR): $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(SRCS) -DSTRCHR -o $@

strstr_tests: $(TARGET_STR)

$(TARGET_STR): $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(SRCS) -DSTRSTR -o $@

strtok_tests: $(TARGET_TOK)

$(TARGET_TOK): $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(SRCS) -DSTRTOK -o $@


clean:
	rm -f $(TARGET_LEN) $(TARGET_CMP) $(TARGET_CPY) $(TARGET_CAT) $(TARGET_CHR) $(TARGET_STR) $(TARGET_TOK)

.PHONY: all clean strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests