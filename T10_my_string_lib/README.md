# T10D16 - String Library Implementation


## String Functions to Implement

### Core Functions
1. **s21_strlen**
   - Calculate length of null-terminated string
   - Test cases: normal, empty string, max length

2. **s21_strcmp**
   - Compare two strings lexicographically
   - Test cases: equal strings, different strings, edge cases

3. **s21_strcpy**
   - Copy source string to destination
   - Test cases: normal copy, empty string, buffer boundaries

4. **s21_strcat**
   - Concatenate two strings
   - Test cases: normal concat, empty strings, buffer overflow

5. **s21_strchr**
   - Locate first occurrence of character
   - Test cases: found, not found, null character

6. **s21_strstr**
   - Find substring in string
   - Test cases: substring present, absent, at boundaries

7. **s21_strtok**
   - Tokenize string using delimiters
   - Test cases: multiple tokens, no tokens, edge cases

## Testing Requirements
- Each function must have:
  - Minimum 3 test cases (normal, edge, error)
  - Clear output showing:
    ```
    Test #1 [Normal case]:
    Input: "hello"
    Expected: 5
    Result: 5
    Status: SUCCESS
    ```
- Tests executed via Makefile targets

## Build System
1. Navigate to module directory
2. Run make with desired target:
   ```bash
   make all              # all build
   make s21_strlen
   make s21_strcmp       # etc...

