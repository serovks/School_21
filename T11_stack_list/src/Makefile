CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

TARGET_1 = ../build/Quest_1
TARGET_2 = ../build/Quest_2
TARGET_3 = ../build/Quest_3

all: door_struct list_test stack_test

door_struct: $(TARGET_1)
$(TARGET_1): dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) dmanager_module.c -o $(TARGET_1) 

list_test: $(TARGET_2)
$(TARGET_2): list_test.c list.c door_struct.h list.h
	$(CC) $(CFLAGS) list_test.c list.c -o $(TARGET_2)

stack_test: $(TARGET_3)
$(TARGET_3): stack.c stack_test.c stack.h
	$(CC) $(CFLAGS) stack.c stack_test.c -o $(TARGET_3)

clean:
	rm -f $(TARGET_1) $(TARGET_2) $(TARGET_3)

rebuid: clean all

.PHONY: all door_struct  list_test stack_test clean
