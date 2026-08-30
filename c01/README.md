# C01 — Pointers

This is the module that makes or breaks people's Piscine. Everything from here on assumes you're comfortable with pointers, so take the extra time now.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_ft | Modifying a value through a single pointer |
| `ex01` ft_ultimate_ft | Pointer-to-pointer-to-pointer-to-pointer, chained dereferencing |
| `ex02` ft_swap | Swapping two values through pointers (no return value) |
| `ex03` ft_div_mod | Returning two results via pointer "output parameters" |
| `ex04` ft_ultimate_div_mod | Same, but without using `/` or `%` |
| `ex05` ft_putstr | Looping over a string, `write()` per character |
| `ex06` ft_strlen | Reimplementing `strlen` |
| `ex07` ft_rev_int_tab | Reversing an array in place |
| `ex08` ft_sort_int_tab | Sorting an array in place |

## Tips & tricks

- **A pointer is just an address, and `*` has two different jobs.** In a declaration (`int *p`), `*` means "this variable holds an address." Everywhere else, `*p` means "go to that address and give me the value there." Confusing these two is the #1 source of pointer bugs.
- **Draw it.** Literally sketch boxes and arrows: a box for each variable, an arrow from the pointer to the box it points at. Do this for `ft_ultimate_ft` especially — four levels of `**` is confusing until you've drawn it once.
- **"Output parameters"**: a function can only truly `return` one value. To hand back two results (like a quotient and remainder), you pass in *pointers* to where the answers should be written, and the function writes through them.
- **In-place vs. new array**: for `ft_rev_int_tab` and `ft_sort_int_tab`, you're modifying the caller's original array through the pointer you were given — you're not allowed to return a new array.
- **Sorting**: you don't need a fancy algorithm here. A simple, correct bubble/selection sort you fully understand beats a clever algorithm you copied and can't explain.

## Resources

- [Beej's Guide to C — Pointers chapter](https://beej.us/guide/bgc/html/split/pointers.html) — the best free explanation of pointers there is.
- Draw pointer diagrams — search "C pointers diagram tutorial" and pick any visual walkthrough; seeing arrows-between-boxes is what makes this click for most people.
- `man 3 qsort` (just to read, not to use) — good example of how C functions use pointers to modify caller data.

## Don't

Don't move on until `ft_ultimate_ft` makes sense to *you*, not just to the compiler. Nearly every later project (linked lists in C12, binary trees in C13, argument parsing everywhere) leans on the pointer intuition you build here.
