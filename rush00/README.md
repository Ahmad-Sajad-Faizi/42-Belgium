# Rush00 — First Team Project

The first group project of the Piscine, done over a weekend with a small team. The core task: given two dimensions (width and length) passed in as arguments, display a rectangle of characters on screen — but the *actual* difficulty is handling every edge case cleanly (invalid input, `0` or negative dimensions, huge dimensions, missing/extra arguments) without the program ever crashing or looping forever.

## What this project is really testing

- **Command-line argument parsing and validation** — this leans directly on C06.
- **Pointer usage** — parameters are conventionally passed to your core function in a specific way (see your subject for the exact signature required); handle them exactly as specified, since defense usually involves your teammates modifying your `main` and checking your function still holds up.
- **Never crashing** — this is graded explicitly. A segfault, an infinite loop, or a crash on bad input is treated far more harshly than a wrong-looking rectangle.
- **Team communication** — you're graded partly on the *worst* explanation among your teammates. Make sure everyone genuinely understands every line, not just the parts they personally wrote.

## Tips & tricks

- **Read the subject as a team before anyone writes code.** Agree on your exact function signatures and file layout up front — merging conflicting approaches later costs more time than 20 minutes of planning does.
- **Handle the boring cases first**: what happens with `0` width? Negative numbers? Non-numeric arguments? Too few or too many arguments? Write these down as a checklist and test every single one before you consider the project "done."
- **Validate before you compute.** Don't let a bad argument reach your drawing logic at all — reject it (per your subject's expected behaviour) at the parsing stage.
- **Use `ft_atoi`-style parsing carefully** — a string like `"12abc"` or `""` should not silently become `12` or `0` without you deciding that's actually correct per the subject.

## Resources

- Revisit your own C01 (pointers) and C06 (argv) notes — this project is built directly on both.
- `man 3 strtol` — a good reference for what "properly validated" integer parsing looks like, even though you're likely writing your own.

## Don't

Don't let one teammate write the whole thing while others watch. The defense format (graded on the worst explanation) exists specifically to prevent that — make sure every member can walk through the full program from `main` to the last `write()` call.
