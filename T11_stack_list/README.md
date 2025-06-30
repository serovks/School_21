# T11D17 - Structures and Data Structures

## Project Overview
This project focuses on implementing core data structures in C using structs and unions. The tasks involve creating door management systems, linked lists, and stack implementations.

## Tasks

### 1. Door Management System
- **Files**: `door_struct.h`, `dmanager_module.c`
- **Requirements**:
  - Define `struct door` with:
    - `id`: integer
    - `status`: integer (0=closed, 1=open)
  - Implement door sorting by ID
  - Close all doors (set status to 0)
  - Output format: "id, status" per line
- **Build**: `make door_struct` → `build/Quest_1`

### 2. Linked List Implementation
- **Files**: `list.h`, `list.c`, `list_test.c`
- **Functions**:
  - `init()` - Initialize list with door struct
  - `add_door()` - Insert new door after specified node
  - `find_door()` - Search by door ID
  - `remove_door()` - Delete list element
  - `destroy()` - Free list memory
- **Testing**:
  - Verify `add_door` and `remove_door` functionality
  - Return SUCCESS/FAIL for each test case
- **Build**: `make list_test` → `build/Quest_2`

### 3. Stack Implementation
- **Files**: `stack.h`, `stack.c`, `stack_test.c`
- **Operations**:
  - `init` - Initialize stack
  - `push` - Add integer to stack
  - `pop` - Remove and return top element
  - `destroy` - Free stack memory
- **Testing**:
  - Verify `push` and `pop` operations
  - Return SUCCESS/FAIL for each test case
- **Build**: `make stack_test` → `build/Quest_3`

## Key Requirements
- ✅ Memory-safe implementations
- ✅ Comprehensive test coverage
- ✅ Proper error handling
- ❌ No system() calls
- ✅ Style compliance (Google C Style Guide)
- ✅ CPPCheck validation for linked list and stack

## Testing Notes
- Each test should:
  - Print input parameters
  - Show expected vs actual results
  - Clearly indicate SUCCESS/FAIL status
- Test cases must cover:
  - Normal operation
  - Edge cases
  - Error conditions

## Build System
Example Makefile targets:
```makefile
all: door_struct list_test stack_test

door_struct:
    gcc -o build/Quest_1 src/dmanager_module.c

list_test:
    gcc -o build/Quest_2 src/list_test.c src/list.c

stack_test:
    gcc -o build/Quest_3 src/stack_test.c src/stack.c