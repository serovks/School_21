# T06D09 Arrays and sorting

This repository contains solutions for 5 programming tasks with specific constraints. All solutions avoid dynamic memory allocation and standard library usage.

## Tasks

### 1. Basic Sorting (`sort.c`)
- **Input**: Array of 10 integers via stdin
- **Output**: Sorted array in ascending order
- **Constraints**:
  - No `stdlib.h`
  - Array passing by pointer only
  - Must implement separate functions for input, sorting, and output

### 2. Advanced Sorting (`fast_sort.c`)
- **Input**: Array of 10 integers
- **Output**:
  - First line: Result from first O(n log n) algorithm
  - Second line: Result from second O(n log n) algorithm
- **Constraints**:
  - No nested loops/conditions >3 levels
  - Same restrictions as basic sort

### 3. Array Processing (`key9part1.c`)
- **Input**: 
  - Array length (max 10)
  - Integer array
- **Output**:
  - Sum of even elements (0 considered odd)
  - New array containing elements divisible by the sum
- **Note**: Must preserve existing function structure

### 4. Cycle Shift (`cycle_shift.c`)
- **Input**:
  - `n` (array size ≤10)
  - Integer array
  - Shift value `c` (negative = right shift)
- **Output**: Shifted array

### 5. Big Number Arithmetic (`key9part2.c`)
- **Input**: Two numbers as digit arrays (max 100 digits each)
- **Output**:
  - Sum of numbers
  - Difference (or "n/a" if negative)
- **Special Case**: Handles leading zeros
