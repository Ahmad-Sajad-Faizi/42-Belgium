# C07 — Dynamic Memory (malloc)

This is where you stop working only with memory the caller gave you, and start allocating your own. It's also where memory leaks start being possible — get into good habits now, they'll matter a lot more once projects get bigger.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_strdup | Allocating a copy of a string |
| `ex01` ft_range | Allocating and filling an array of integers |
| `ex02` ft_ultimate_range | Same idea, but returning the array through a pointer parameter and the length as the return value |
| `ex03` ft_strjoin | Allocating a new string from two others |
| `ex04` ft_convert_base / ft_convert_base2 | Allocating a string representation of a number in an arbitrary base |
| `ex05` ft_split | Splitting a string into an allocated array of allocated strings |

## Tips & tricks

- **`malloc` can fail.** It returns `NULL` if it can't allocate memory — always check for that before using the pointer, even though it rarely happens in practice. The checkers *will* test this.
- **Whatever you allocate, something has to free eventually** — but in most of these exercises, *you* are handing ownership to the caller, so you should *not* free it yourself before returning. Be clear in your own head about who owns each allocation and when.
- **Count first, allocate second.** For `ft_split` especially: do one pass to figure out how many "words" there are (and how long the result array needs to be), *then* allocate, *then* fill. Trying to allocate and grow dynamically as you go is much more error-prone in C.
- **Arrays of strings need a `NULL` terminator** at the end (like `argv`) so the caller can loop over the result without needing to know the count separately — this is the conventional way `ft_split`-style functions signal "end of array."
- **Watch multiple/leading/trailing separators in `ft_split`** — decide explicitly whether consecutive separators should produce empty strings or be collapsed, and test both an empty input and a string that's all separators.

## Resources

- `man 3 malloc`, `man 3 free` — read the actual guarantees (and what happens on `malloc(0)`).
- [Valgrind](https://valgrind.org/) (`valgrind --leak-check=full ./your_program`) — install and run it on your own binaries; catching a leak yourself teaches you more than any explanation of leaks does.
- [Learn-C — Dynamic memory](https://www.learn-c.org/en/Dynamic_allocation) — quick refresher on `malloc`/`free` mechanics if needed.

## Don't

Don't wait until later projects to start using Valgrind. Get in the habit here, on small exercises, where a leak is easy to spot and fix — it's a much harder skill to pick up for the first time on a big project under deadline pressure.
