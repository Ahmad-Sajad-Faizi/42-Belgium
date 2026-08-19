#!/bin/sh

find . -type f -o -type d | wc -l

# find . lists everything recursively.
# -type f -o -type d matches regular files OR directories.
# wc -l counts lines (each entry one line).
