# Shell01 — Shell Scripting

A step up from Shell00: real `.sh` scripts that combine multiple Unix tools together to solve a task, instead of one-off commands. This is where you start thinking in pipelines.

## What this module covers

Based on this repo's exercise files, the scripts in this module involve:
- Listing and formatting system/user groups
- Searching the filesystem for specific files (`find`)
- Counting files matching criteria
- Working with network/MAC address information
- Filtering or skipping specific input
- String reversal / text manipulation
- Conditionally adding content based on a pattern

## Tips & tricks

- **A shell script is just a sequence of commands a human would type, saved to a file.** Start every script with `#!/bin/bash` (or `#!/bin/sh` if you need strict POSIX behaviour — check what your subject requires) on the first line, and make it executable with `chmod +x script.sh`.
- **Learn these tools well — they cover almost everything in this module**: `find` (search the filesystem by name/type/permissions/etc.), `grep` (search text by pattern), `awk` (extract/process columns of text), `sed` (find-and-replace / stream editing), `cut` (extract columns by delimiter), `wc` (count lines/words/bytes), `xargs` (turn a list of results into arguments for another command).
- **Pipe commands together (`|`) instead of writing one giant command.** Build a pipeline incrementally: run the first command alone, check the output looks right, *then* pipe it into the next stage. Debugging a 5-stage pipeline all at once is much harder than building it up one stage at a time.
- **`$1`, `$2`, etc. are your script's arguments**, `$#` is the argument count, and `$@` is all arguments — the shell-scripting equivalent of `argv`/`argc` from C06.
- **Test edge cases explicitly**: an empty input, a directory with no matches, a file with no matching lines. Shell scripts fail silently or in confusing ways far more often than compiled programs do.
- **Use [shellcheck](https://www.shellcheck.net/)** to catch quoting mistakes and common scripting bugs — shell quoting (`"$var"` vs `$var`) is a genuinely common source of bugs even for experienced people, not just beginners.

## Resources

- [explainshell.com](https://explainshell.com/) — again, invaluable for decoding any command with flags you don't recognize.
- [ShellCheck](https://www.shellcheck.net/) — paste your script in, or install it locally, and it will point out real bugs (unquoted variables, wrong test operators, etc.).
- [The Art of Command Line](https://github.com/jlevy/the-art-of-command-line) — a well-organized reference covering most of the tools this module touches.
- `man find`, `man awk`, `man sed`, `man grep` — the core reference material; each has far more capability than this module alone will require, and it's worth skimming each once.

## Don't

Don't write a whole script blind and then debug it all at once. Run each command in your pipeline by hand in the terminal first, check the output at each stage, and only then assemble it into a script — it's much faster than it sounds.
