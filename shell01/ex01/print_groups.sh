#!/bin/sh

id -Gn $FT_USER | tr ' ' ','

# id -Gn prints all group names for the given user (or current user if no argument).
# tr ' ' ',' replaces spaces with commas.
