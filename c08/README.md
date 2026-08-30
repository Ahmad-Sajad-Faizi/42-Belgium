# C08 — Typedefs, Structs & Headers

A conceptual module rather than an algorithmic one: it's about learning to organize code across headers, and to build your own types instead of only using `int`/`char`/pointers.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft.h | Writing a clean header file with declarations |
| `ex01` ft_boolean.h | `typedef` for a boolean type (pre-`stdbool.h` style) |
| `ex02` ft_abs.h | Writing a macro (or `static inline` function) |
| `ex03` ft_point.h | Defining a `struct` to represent a 2D point |
| `ex04` ft_strs_to_tab.c | Parsing input into your custom struct/array type |
| `ex05` ft_show_tab.c | Printing/using your custom type |

## Tips & tricks

- **Header guards matter.** Every `.h` file should be wrapped in `#ifndef FOO_H` / `#define FOO_H` / `#endif` so it's safe to `#include` it more than once across a project — this becomes essential once projects span multiple files.
- **`typedef` doesn't create a new type from nothing** — it gives an existing type (or struct) a new name. `typedef struct s_point { int x; int y; } t_point;` means `t_point` is now shorthand for that struct.
- **Macros vs. functions**: a `#define`d macro is text substitution done before compilation — it has no type-checking and can behave unexpectedly with side effects (e.g. `ABS(x++)`). A `static inline` function is safer and usually preferred when correctness matters more than raw simplicity — think about which fits `ft_abs` best and why.
- **A header should only contain declarations** (function prototypes, struct/type definitions, macros) — not the actual function bodies (except for genuinely short inline/macro logic). Keep `.c` and `.h` responsibilities separate; it's a habit that saves real pain later when projects grow.

## Resources

- [cppreference — struct declaration](https://en.cppreference.com/w/c/language/struct) — struct syntax reference.
- [Header guards explained](https://en.wikipedia.org/wiki/Include_guard) — why they exist and what breaks without them.
- Search "C macro vs inline function pitfalls" for real examples of macro side-effect bugs — worth seeing once so you recognize the trap.

## Don't

Don't skip thinking about *why* each exercise wants a `.h` file specifically — this module is building the habits (guards, clean declarations, struct design) you'll lean on constantly from C09 onward, where you start building your own small library.
