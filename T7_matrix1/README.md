# T07D10 - Matrix and Memory Operations

## Project Tasks

### Core Memory Tasks
1. **Dynamic Array Sort** (`sort.c`)  
   - Input: `n` + array of `n` integers  
   - Output: Sorted array  
   - Key Requirement: Dynamic allocation with `malloc`/`calloc`

2. **Memory Leak Fix** (`sort_no_leak.c`)  
   - Fixes memory leaks in `sort.c`  
   - Same I/O as original

### Matrix Operations
3. **Matrix Handler** (`matrix.c`)  
   - 4 allocation methods:  
     1. Static (100x100 max)  
     2. Single malloc 1D array  
     3. Array of row pointers  
     4. Double pointer with contiguous memory  
   - Menu-driven interface

4. **Extended Matrix** (`matrix_extended.c`)  
   - Adds row max/column min calculations  
   - Output: Matrix + max/min arrays

5. **Matrix Sorter** (`matrix_sort.c`)  
   - Sorts rows by sum (ascending)  
   - Dynamic allocation required

6. **Matrix Arithmetic** (`matrix_arithmetic.c`)  
   - Operations:  
     - 1: Addition  
     - 2: Multiplication  
     - 3: Transpose  
   - Handles dimension errors

### Special Tasks
7. **ASCII Art** (`picture.c`)  
   - Recreates predefined pattern  
   - Uses existing static arrays

8. **Magic Square** (`key10.txt`)  
   - Solve matrix puzzle  
   - Save solution in text file

## Requirements
- ✅ Strict memory management  
- ❌ Zero memory leaks  
- ✅ Error output: "n/a"  
- ❌ No system calls  
- ✅ Clean, modular code

## Testing
All solutions verified for:
- Memory leaks
- Code style compliance
- Functional correctness
- Edge case handling