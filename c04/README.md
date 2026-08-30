# C04 — Parsing & Number/String Conversion

This module is about going back and forth between numbers and their text representation — the foundation for basically every parsing exercise later in the curriculum.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_strlen | Re-implementing `strlen` (again — repetition is deliberate) |
| `ex01` ft_putstr | Re-implementing string printing |
| `ex02` ft_putnbr | Re-implementing number printing |
| `ex03` ft_atoi | Parsing a string into an `int` |
| `ex04` ft_putnbr_base | Printing a number in an arbitrary base |
| `ex05` ft_atoi_base | Parsing a number written in an arbitrary base |

## Tips & tricks

- **`ft_atoi` has a specific, well-defined behaviour you must match**: skip leading whitespace, accept at most one `+`/`-` sign, then read digits until a non-digit appears — anything after that is ignored, not an error.
- **Base conversion is really just repeated division and remainder.** To print a number in base *b*: divide by *b*, the remainder is your next digit (from the *end* backwards), repeat on the quotient until it's zero. This is naturally recursive — it's worth writing it recursively so the digit order comes out right without an extra buffer.
- **`ft_atoi_base` needs to validate the base string itself** (no duplicate characters, etc., depending on your subject's exact rules) before trusting it as your digit alphabet.
- **Negative numbers and non-decimal bases interact awkwardly** — decide early how your function should behave (does base 2 support a `-` sign? what about bases that already contain `+`/`-` as digit characters?) and be consistent.

## Resources

- [cppreference — `strtol`](https://en.cppreference.com/w/c/string/byte/strtol) — read how a real, robust version of this parsing works (for understanding the contract, not for copying).
- Search "number base conversion algorithm explained" for a refresher on the divide-and-remainder method if it's rusty.

## Don't

Don't hardcode base 10 anywhere by accident when writing `ft_putnbr_base` — it's an easy mistake to copy your `ft_putnbr` logic and forget to actually use the passed-in base.
