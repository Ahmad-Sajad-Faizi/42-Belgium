#!/bin/sh

find . -type f -name '*.sh' -exec basename {} .sh \;

# find . searches recursively from current dir.
# -type f limits to regular files.
# -name "*.sh" filters filenames.
# -exec basename {} .sh \; strips the .sh suffix and prints only the name.
