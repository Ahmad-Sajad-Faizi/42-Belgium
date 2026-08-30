# C11 — Function Pointers

Functions that take *other functions* as arguments. This is the concept that unlocks generic, reusable code — and it's directly used again in C12 (`foreach`) and C13 (tree traversal with a callback).

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_foreach | Applying a `void`-returning function to every array element |
| `ex01` ft_map | Applying a function to every element and collecting the results into a new array |
| `ex02` ft_any | Checking if a predicate is true for *any* element |
| `ex03` ft_count_if | Counting elements matching a predicate |
| `ex04` ft_is_sort | Checking array order using a comparator function |
| `ex05` do_op (+ Makefile) | Dispatching behaviour based on a function pointer selected at runtime (e.g. from CLI arguments) |
| `ex06` ft_sort_string_tab | Sorting an array of strings |
| `ex07` ft_advanced_sort_string_tab | Sorting with a caller-provided comparator function |

## Tips & tricks

- **Function pointer syntax is genuinely just weird to read at first** — `int (*f)(int)` declares `f` as "a pointer to a function that takes an `int` and returns an `int`." Practice reading a few of these out loud until the pattern sticks; it won't get easier by avoiding it.
- **`foreach` vs `map` is a meaningful distinction**: `foreach` just *does something* with each element (no return value expected — think side effects like printing), while `map` *transforms* each element and produces a brand-new array of results. Keep that distinction clear in how you design your functions.
- **A "predicate" function** is just a function that returns true/false (or 1/0) about a single element — `ft_any` and `ft_count_if` are both built around calling one per element and reacting to the result.
- **Comparator functions (as in `ft_advanced_sort_string_tab`)** conventionally return negative/zero/positive to mean "less than / equal / greater than" — this matches how the real `qsort`'s comparator works, which is worth reading about even though you're not using `qsort` here.

## Resources

- [cdecl.org](https://cdecl.org/) — paste any confusing C declaration (like a function pointer type) and it translates it to plain English. Extremely useful for this whole module.
- `man 3 qsort` — the real standard library function built entirely around a comparator function pointer; a great real-world reference point.
- Search "C function pointers explained" for a short tutorial if the syntax still feels unnatural after `cdecl.org`.

## Don't

Don't try to memorize function pointer syntax by staring at it — write out a few small throwaway examples of your own (a function pointer to a function that squares a number, for instance) until typing the syntax feels automatic.
