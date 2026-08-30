# C03 — More String Functions

A short module, but a sharp one — these five functions are where off-by-one buffer bugs like to hide.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_strcmp | Comparing strings byte by byte |
| `ex01` ft_strncmp | Bounded comparison |
| `ex02` ft_strcat | Appending one string to another |
| `ex03` ft_strncat | Bounded appending |
| `ex04` ft_strstr | Substring search |
| `ex05` ft_strlcat | Safe, size-bounded appending that reports total length |

## Tips & tricks

- **Comparisons return the *difference* between the first mismatching characters**, not just `-1`/`0`/`1`. Compare as `unsigned char` to match the real function's behaviour with high-value bytes.
- **`strcat`-family functions assume the destination buffer has enough room** — that's the caller's responsibility, but understanding *why* this function is considered dangerous (in the real C library) will help you get the size-bounded versions right.
- **`ft_strstr`** is just: for every starting position in the haystack, check whether the needle matches from there. You don't need anything cleverer than brute force here — clarity matters more than speed at this stage.
- **`ft_strlcat`** is the trickiest of the five: its return value is the *total length it tried to create* (`strlen(dst) + strlen(src)`), even if truncation happened, and it must never write past `size - 1` characters plus the null terminator. Re-read the real man page slowly — this one trips almost everyone up on the first try.

## Resources

- [OpenBSD `strlcat` man page](https://man.openbsd.org/strlcat.3) — the authoritative description of the size-bounded semantics you're reimplementing.
- `man 3 strcmp` / `man 3 strstr` — for understanding the real contract (return values especially).

## Don't

Don't skip re-reading the subject's exact edge-case rules for `strlcat` (what happens if `size` is 0, or smaller than `strlen(dst)`). This is a "read carefully twice" exercise, not a "code fast" one.
