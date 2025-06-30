# RPN Calculator (C)

This is a modular C program that:

1. Converts an infix mathematical expression (e.g., `2 + sin(3 * x)`) to postfix (RPN),
2. Evaluates the result with optional support for the variable `x`,
3. Supports standard math functions: `sin`, `cos`, `tg`, `ctg`, `ln`, `sqrt`.

---

## Files

- `main.c` – entry point
- `parser.c` / `parser.h` – infix to RPN conversion, evaluation
- `stack.c` / `stack.h` – linked list stack with dummy node
- `monads.c` / `monads.h` – simple Maybe monad with `bind`, `bind2`
- `mat.c` / `mat.h` – math helper functions used in monads

---

## Build

### Requirements

- Standard C compiler (`gcc`, `clang`, etc.)

```bash
make
```

---

Then type an expression like:
```
sin (cos (2 + x))
```

---

## Supported Features

- **Operators:** `+`, `-`, `*`, `/`, `^`
- **Functions:** `sin`, `cos`, `tg`, `ctg`, `ln`, `sqrt`
- **Variable:** `x` (prompted at runtime)
- **Floating point literals:** `3.14`, `2`, `0.5`, etc.
- **Parentheses:** `( ... )` supported and correctly handled

---

## Internals

- Uses a **linked list stack with a dummy node** for safe stack operations.
- Uses a **Maybe monad** to safely apply binary/unary operations.
- Converts the infix string into a `Token[]`, then evaluates it using stack-based RPN logic.
- All parsing is custom; no use of regex or third-party libraries.