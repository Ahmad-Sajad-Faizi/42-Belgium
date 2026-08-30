# C02 — String Basics

Reimplementing a chunk of `<string.h>` and `<ctype.h>` yourself, exercise by exercise. The point isn't the specific functions — it's building the habit of thinking carefully about string boundaries and character classification.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_strcpy | Copying a string including the terminating `\0` |
| `ex01` ft_strncpy | Copying with a length limit, and the (annoying) padding behaviour of real `strncpy` |
| `ex02` ft_str_is_alpha | Character classification |
| `ex03` ft_str_is_numeric | Character classification |
| `ex04` ft_str_is_lowercase | Character classification |
| `ex05` ft_str_is_uppercase | Character classification |
| `ex06` ft_str_is_printable | Character classification (printable ASCII range) |
| `ex07` ft_strupcase | In-place transformation of a string |
| `ex08` ft_strlowcase | In-place transformation of a string |
| `ex09` ft_strcapitalize | Word-boundary detection while transforming a string |
| `ex10` ft_strlcpy | Safe copying with a destination-size limit, returning source length |
| `ex11` ft_putstr_non_printable | Printing non-printable bytes as escape sequences |
| `ex12` ft_print_memory | Dumping raw memory as hex + printable chars |

## Tips & tricks

- **Every C string ends in `'\0'`.** Any function that "reads a string" should be a loop that stops at that byte — don't hardcode a length anywhere; find the end yourself.
- **`is_alpha`, `is_numeric`, etc. are one-character-at-a-time checks looped over the whole string.** Write the single-character check first, then loop it.
- **For `ft_strcapitalize`**, think about what counts as a "word boundary" — usually anything that isn't a letter or digit. The character right after a boundary gets uppercased; everything else lowercased.
- **`ft_strlcpy` real behaviour**: it copies up to `size - 1` characters and *always* null-terminates (unlike `strncpy`), and its return value is the length of the *source* string, not the destination — that return value matters for how it's meant to be used (truncation detection).
- **`ft_print_memory`**: cast your pointer to `unsigned char *` before reading it byte by byte — reading raw memory through any other pointer type risks reading the wrong number of bytes or garbage due to sign extension.

## Resources

- [cppreference — `<ctype.h>`](https://en.cppreference.com/w/c/string/byte) — the exact behaviour of `isalpha`, `isdigit`, etc. (for understanding, not for calling — you're reimplementing these).
- `man ascii` — printable range is 32–126.
- [OpenBSD's real `strlcpy`/`strlcat` man page](https://man.openbsd.org/strlcpy.3) — read this to understand the real function's contract before writing your version.

## Don't

Don't assume "printable" means "not a control character" — check the actual printable ASCII range (32 to 126 inclusive) rather than guessing.
