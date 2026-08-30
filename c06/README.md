# C06 — Command-Line Arguments

Short module, but it's your first real contact with `argc`/`argv` — something every program you write from now on will use.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_print_program_name | Reading `argv[0]` |
| `ex01` ft_print_params | Looping over `argv`, handling the "no arguments" case |
| `ex02` ft_rev_params | Iterating `argv` in reverse |
| `ex03` ft_sort_params | Sorting the arguments alphabetically |

## Tips & tricks

- **`argc` counts `argv[0]` too.** If your program is run with two extra arguments, `argc` is `3`, and the *extra* arguments are `argv[1]` and `argv[2]` — `argv[0]` is always the program name itself. Off-by-one mistakes here are extremely common.
- **`argv` is always terminated by a `NULL` pointer** at `argv[argc]` — you can loop either by counting to `argc` or by checking for `NULL`, both are valid, just be consistent.
- **For sorting**, you're sorting an array of `char *` — your comparison function compares the *strings* they point to (with something like `strcmp`), but what actually gets swapped/reordered is the pointers, not the characters themselves.
- **"No arguments" is a real case you have to handle deliberately** — decide what your program prints (often nothing, or a specific message per the subject) and test it explicitly, since it's easy to forget when you've been testing with arguments the whole time.

## Resources

- [cppreference — `main` function and argc/argv](https://en.cppreference.com/w/c/language/main_function) — the actual C standard's guarantees about how these are structured.

## Don't

Don't forget to test with zero extra arguments, one argument, and several — each is a genuinely different code path here, not just "more of the same."
