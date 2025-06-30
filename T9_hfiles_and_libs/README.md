# T09D15 - Multifile Project Management

## Tasks

### Core Modules
1. **Data Module Refactoring** (`data_module`)
   - Fix `data_module_entry.c` to work correctly
   - Reuse existing functions from `data_libs`
   - Use proper preprocessor directives

2. **Decision Module Refactoring** (`yet_another_decision_module`)
   - Fix `yet_another_decision_module_entry.c`
   - Leverage shared code from `data_libs`
   - Implement correct header includes

### Build System
3. **Makefile Implementation**
   - Create `Makefile` in `main_executable_module`
   - Required targets:
     - `all` - Build main executable
     - `clean` - Remove build artifacts
     - `rebuild` - Clean and rebuild
   - Output executable: `build/Quest_3`

### Advanced Tasks
4. **Macro Implementation** (Bonus)
   - Create `data_io_macro.h` with type-agnostic macros
   - Add `build_with_macro` target
   - Output: `build/Quest_4`

5. **Static Library**
   - Build `data_stat` as static library (.a)
   - Add `build_with_static` target
   - Output: `build/Quest_5`

6. **Dynamic Library**
   - Build `data_process` as shared library (.so)
   - Add `build_with_dynamic` target
   - Modify main executable for dynamic loading
   - Output: `build/Quest_6`

## Requirements
- ✅ Proper header file organization
- ✅ Correct preprocessor usage (#ifndef guards)
- ✅ Relative paths in Makefile
- ❌ No system() calls
- ✅ Memory leak-free implementations
- ✅ Style norm compliance

## Build Instructions
1. Navigate to module directory
2. Run make with desired target:
   ```bash
   make all              # Standard build
   make build_with_macro # Macro version
   make build_with_static # Static lib version
   make build_with_dynamic # Dynamic lib version
   make clean            # Clean build artifacts