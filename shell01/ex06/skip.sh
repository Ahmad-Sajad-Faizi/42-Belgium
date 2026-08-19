#!/bin/sh

ls -l | awk 'NR%2==1'

# ls -l gives the listing.
# awk 'NR%2==1' prints lines whose record number is odd (1st, 3rd, 5th…).
# Alternatively: ls -l | sed -n '1~2p' (GNU sed) but awk is more portable.
