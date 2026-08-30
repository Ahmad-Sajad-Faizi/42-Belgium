# C05 — Recursion & Algorithms

This is where you start writing genuine small algorithms instead of just string/loop utilities. Take your time on the last exercise — it's a real backtracking problem, not a warm-up.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_iterative_factorial | Basic loop, overflow handling |
| `ex01` ft_recursive_factorial | Same problem, recursive form |
| `ex02` ft_iterative_power | Loop-based exponentiation |
| `ex03` ft_recursive_power | Recursive exponentiation |
| `ex04` ft_fibonacci | Recursion with two base cases |
| `ex05` ft_sqrt | Integer square root without `math.h` |
| `ex06` ft_is_prime | Primality testing |
| `ex07` ft_find_next_prime | Searching forward using your primality test |
| `ex08` ft_ten_queens_puzzle | Classic N-Queens backtracking, N=10 |

## Tips & tricks

- **Factorial/power/fibonacci**: for negative input or overflow, the subject usually wants you to return `0` — decide this up front rather than after the checker fails.
- **`ft_sqrt`**: you don't need floating point tricks. A simple approach is to test integers `i = 1, 2, 3...` and check when `i*i == n`; return `0` if no exact integer root exists (watch your subject for whether non-perfect squares should return 0 or something else).
- **`ft_is_prime`**: you only ever need to test divisors up to `sqrt(n)`, not all the way to `n` — this is the single biggest performance/style improvement you can make here, and it directly sets up `ft_find_next_prime`.
- **N-Queens (`ft_ten_queens_puzzle`)** is genuinely a different kind of problem: you place queens column by column, and every time you place one, you check it doesn't attack any queen already placed (same row, or same diagonal). If it doesn't fit anywhere in a column, you backtrack — undo the last placement and try the next option. Work through N=4 on paper by hand before touching code; once you can solve 4-queens with pencil and paper, coding N=10 is just formalizing what you already did.

## Resources

- [Sieve of Eratosthenes — visual explanation](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) — not what you're implementing, but useful background for why the `sqrt(n)` bound works for primality.
- [N-Queens backtracking — visualized](https://www.google.com/search?q=n+queens+backtracking+visualization) — search for a visualization; watching the algorithm backtrack on a small board makes the recursive structure click far faster than reading pseudocode.
- [Newton's method for integer square roots](https://en.wikipedia.org/wiki/Integer_square_root) — optional, if you want a faster `ft_sqrt` than linear search.

## Don't

Don't start coding N-Queens before you can explain, out loud, what "backtracking" means and why it's different from plain recursion. This exercise is a good gut-check for whether you actually understand recursion or have just been pattern-matching so far.
