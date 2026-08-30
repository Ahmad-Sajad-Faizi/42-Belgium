# C09 — Building Your Own Mini-Library

This module has you package a handful of the functions you've already written into an actual static library, plus write a real `Makefile` for the first time. It's less about new algorithms and more about tooling — this is where "programmer" starts meaning more than "person who writes functions."

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` (ft_putchar/ft_putstr/ft_strcmp/ft_strlen/ft_swap + `libft_creator.sh`) | Gathering your own reusable functions, shell scripting to automate a build |
| `ex01` (Makefile) | Writing a real `Makefile` for a static library |
| `ex02` ft_split | Reimplementing `ft_split` — this time compiled against and using your *own* library |

## Tips & tricks

- **A static library is just an archive of `.o` object files.** The general flow is: compile each `.c` into a `.o` with `gcc -c`, then bundle the `.o` files into a `.a` archive with `ar rc libft.a *.o`, then (optionally) index it with `ranlib libft.a`. Understanding these three steps by hand makes the Makefile version make sense instead of feeling like magic.
- **A Makefile needs at minimum**: a default target that builds everything, a `clean` target (remove `.o` files), a `fclean` target (remove `.o` files *and* the final binary/library), and a `re` target (`fclean` then rebuild). This exact pattern (`all`, `clean`, `fclean`, `re`) is the 42 standard and will be expected in nearly every later project — learn it properly here.
- **`$@`, `$<`, `$^` are your friends** in a Makefile — they refer to the target, the first prerequisite, and all prerequisites respectively, and they're what let you write one rule that works for many files instead of repeating yourself.
- **The shell script (`libft_creator.sh`)** is a good moment to get comfortable with basic shell scripting: variables, loops over files, and calling other commands (`gcc`, `ar`) from within a script.

## Resources

- [Makefile Tutorial (makefiletutorial.com)](https://makefiletutorial.com/) — genuinely one of the best free resources for learning Make from scratch.
- `man ar`, `man ranlib` — the actual tools your Makefile will call.
- [GNU Make manual — Automatic Variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html) — reference for `$@`/`$<`/`$^` and friends.

## Don't

Don't copy a Makefile template from someone else's repo without understanding every line. Every C project from here through the end of the core curriculum needs its own Makefile — this is the one time it's worth going slow and building it up rule by rule so the next twenty times are fast.
