# Shell00 — Unix & Shell Fundamentals

A set of short, practical exercises covering the everyday Unix skills you'll be using constantly for the rest of the Piscine: navigating the filesystem, permissions, symlinks, SSH keys, and basic Git usage.

## What this module covers

Based on this repo's exercise files, the topics in this module include:
- Navigating and manipulating files/directories from the shell
- Working with compressed archives (`tar`)
- Generating and understanding SSH key pairs
- Listing/filtering files (`ls` and its many flags)
- Making your first Git commits
- Writing a `.gitignore`
- File permissions and executable bits
- Cleaning up a directory / working with hidden files
- Identifying file types (magic numbers)

## Tips & tricks

- **Learn to actually read `man` pages** — for basically every command in this module (`ls`, `tar`, `ssh-keygen`, `chmod`, `git`), the man page has the exact flag you need. Get comfortable with `man <command>` and `command --help` as your first move, not a search engine.
- **`ls -la` is your default lens on a directory** — it shows hidden files (dotfiles), permissions, ownership, and sizes all at once. Most "where did my file go" confusion in this module is solved by remembering hidden files start with `.` and don't show in a plain `ls`.
- **Permissions**: `chmod` uses either symbolic (`u+x`, `g-w`) or numeric (`755`, `644`) notation — learn to read `rwxr-xr-x` as three groups of three (owner/group/other), each meaning read/write/execute.
- **SSH keys come in pairs**: a private key (never share this) and a public key (`.pub`, safe to share — this is what gets added to servers/Git hosts to authenticate you).
- **Git basics for this module**: `git init`, `git add`, `git commit -m "message"`, and a `.gitignore` file (one pattern per line, e.g. `*.o` to ignore all object files) are the core moves. Get the habit of small, frequent commits with clear messages now — it matters a lot more once you're collaborating on group projects.
- **`file <filename>`** tells you a file's actual type by inspecting its content (its "magic number"), not just trusting its extension — useful for understanding what a mystery file actually is.

## Resources

- [explainshell.com](https://explainshell.com/) — paste any shell command and it breaks down every flag in plain English. Extremely useful for this whole module.
- [Git — the simple guide](https://rogerdudler.github.io/git-guide/) — a short, practical intro if Git commands still feel unfamiliar.
- `man ssh-keygen`, `man chmod`, `man tar`, `man git-commit` — read them directly; they're shorter than they look.

## Don't

Don't just copy shell commands from a forum answer without reading what each flag does — `explainshell.com` takes 10 seconds and turns copy-pasting into actually learning the tool.
