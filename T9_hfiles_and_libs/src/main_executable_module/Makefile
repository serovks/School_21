CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../data_libs -I../data_module -I../yet_another_decision_module
LDFLAGS = -ldl

SRCS = main_executable_module.c \
       ../data_libs/data_io.c \
       ../data_libs/data_stat.c \
       ../data_module/data_process.c \
       ../yet_another_decision_module/decision.c \
       sort.c

OBJS = $(SRCS:.c=.o)

TARGET_DEFAULT = ../../build/Quest_3
TARGET_MACRO = ../../build/Quest_4
TARGET_STATIC = ../../build/Quest_5
TARGET_DYNAMIC = ../../build/Quest_6
STATIC_LIB = ../../build/data_stat.a
LIB_DIR = ../../build
DYNAMIC_LIB = $(LIB_DIR)/data_process.so

all: CFLAGS += -DUSE_IO_MACROS=0 
all: $(TARGET_DEFAULT)

build_with_macro: CFLAGS += -DUSE_IO_MACROS=1
build_with_macro: $(TARGET_MACRO)

$(STATIC_LIB): ../data_libs/data_stat.o
	ar rcs $@ $^
	@echo "Static library built: $@"

build_with_static: CFLAGS += -DUSE_STATIC_LIB=1
build_with_static: $(STATIC_LIB) $(filter-out ../data_libs/data_stat.o, $(OBJS))
	$(CC) $(CFLAGS) $(filter-out ../data_libs/data_stat.o, $(OBJS)) $(STATIC_LIB) -o $(TARGET_STATIC)
	@echo "Build with static lib successful! Output: $(TARGET_STATIC)"

# Сборка динамической библиотеки из уже скомпилированных .o-файлов
$(DYNAMIC_LIB): ../data_module/data_process.o ../data_libs/data_stat.o
	$(CC) -shared -fPIC $^ -o $@
	@echo "Dynamic library built: $@"

# Сборка основной программы с динамической библиотекой
build_with_dynamic: CFLAGS += -DDYNAMIC_LIB
build_with_dynamic: $(DYNAMIC_LIB) $(filter-out ../data_module/data_process.o, $(OBJS))
	$(CC) $(CFLAGS) $(filter-out ../data_module/data_process.o, $(OBJS)) -o $(TARGET_DYNAMIC) $(LDFLAGS)
	@echo "Build with dynamic lib successful! Output: $(TARGET_DYNAMIC)"

$(TARGET_DEFAULT): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_MACRO): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(STATIC_LIB) $(DYNAMIC_LIB) $(TARGET_DEFAULT) $(TARGET_MACRO) $(TARGET_STATIC) $(TARGET_DYNAMIC)

rebuild: clean all

.PHONY: all clean rebuild build_with_macro build_with_static build_with_dynamic