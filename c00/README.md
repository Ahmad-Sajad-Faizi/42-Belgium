# C00 — First Steps in C

The very first exercise set of the Piscine. Everything here uses `write()` instead of `printf()` — the goal isn't to print things, it's to make you understand exactly how output works at a low level, and to get comfortable with loops, conditions, and basic recursion before pointers get involved.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_putchar | Calling `write()` correctly, function basics |
| `ex01` ft_print_alphabet | `for`/`while` loops, ASCII character ranges |
| `ex02` ft_print_reverse_alphabet | Looping backwards |
| `ex03` ft_print_numbers | Printing digits without `printf`/`itoa` |
| `ex04` ft_is_negative | Conditionals, `void` functions with output via `write` |
| `ex05` ft_print_comb | Nested loops, generating ordered combinations |
| `ex06` ft_print_comb2 | Nested loops with a stricter output format |
| `ex07` ft_putnbr | Printing an `int` (incl. negative numbers and `INT_MIN`) manually |
| `ex08` ft_print_combn_recursive | Your first recursive function |

## Tips & tricks

- **`write()` only takes `char`, not numbers.** To print the digit `7`, convert it to the *character* `'7'`, which is `'0' + 7` thanks to how ASCII is laid out. Get comfortable with this trick early — it comes back constantly.
- **Know your ASCII table.** `'a'` to `'z'` and `'A'` to `'Z'` are contiguous ranges, so `for (char c = 'a'; c <= 'z'; c++)` works directly.
- **`INT_MIN` is the classic trap in `ft_putnbr`.** `-INT_MIN` overflows because the positive equivalent doesn't fit in an `int`. Think about how you'd print it as a special case, or work with a wider type.
- **For the combination exercises**, work out the exact output format on paper first (comma placement, digit ranges) before writing any code — most people fail these on formatting, not logic.
- **For the recursive exercise**, write down your base case before your recursive case. Ask: "what's the smallest version of this problem, and what do I return for it directly?"

## Resources

- [ASCII Table](https://www.asciitable.com/) — keep this open in a tab for this whole module.
- `man 2 write` — read it, understand the return value and arguments.
- [learn-c.org — Loops](https://www.learn-c.org/en/Loops) — quick refresher if `for`/`while` syntax feels shaky.
- Search "recursion explained visually" if the idea of a function calling itself hasn't clicked yet — a short animated walkthrough helps more than any text explanation.

## Don't

Don't guess-and-check against the checker until it passes. Trace your loop bounds by hand with pen and paper for a small case (e.g. n=3) — it saves far more time than trial and error, and it's the habit that gets you through the harder modules later.
