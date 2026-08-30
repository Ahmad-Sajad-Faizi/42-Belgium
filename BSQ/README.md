# BSQ — Biggest Square

The Piscine's final individual algorithmic challenge: given a map made of empty cells, obstacle cells, and (in some variants) already-filled cells, find the largest possible square made entirely of empty cells, and output the map with that square filled in.

## What this project is really testing

- **Reading/parsing structured input files** — the map format typically starts with a size line and a set of character definitions (which character means "empty," which means "obstacle," which fills the found square), and a file can contain several maps in sequence that all need to be processed independently.
- **Dynamic programming** — this is the real heart of the project. Brute-force checking every possible square at every position is far too slow for large maps; you need an approach that reuses work you've already done.
- **Robust error handling** — malformed input (wrong size line, invalid characters, inconsistent row lengths) needs to be detected and reported cleanly, not crash your program.

## Tips & tricks

- **The classic approach ("maximal square in a binary grid")**: build a second grid the same size as your map, where each cell holds "the size of the largest all-empty square that has *this* cell as its bottom-right corner." For an empty cell, that value is `1 + the minimum of the three neighbouring values above, to the left, and diagonally above-left` (if any of those neighbours is out of bounds or an obstacle, treat it as 0). For an obstacle cell, the value is always `0`. The overall answer is just the largest value anywhere in that second grid, and its position tells you exactly where to draw the square.
- **Work through this by hand on a small 4x4 or 5x5 grid on paper before coding it** — this DP recurrence is a well-known pattern but it won't feel intuitive until you've traced it manually at least once.
- **Process one map at a time and reset your state between them** — a file with multiple maps is really just "run the whole algorithm independently, several times," not one combined problem.
- **Validate the map shape as you read it** — every row should be the same length as declared, and only the three allowed characters (empty/obstacle/other-defined characters) should appear; catch and report violations instead of letting bad data flow into your DP grid.
- **Free everything you allocate for one map before moving to the next**, especially if you're processing many maps from one file — leaks here add up fast and are easy to catch early with Valgrind.

## Resources

- Search "maximal square dynamic programming explained" — this is a well-known, widely explained problem (sometimes called "Maximal Square"); there are many good walkthroughs and visualizations of the DP recurrence described above.
- [Introduction to Dynamic Programming (freeCodeCamp or similar)](https://www.freecodecamp.org/news/tag/dynamic-programming/) — if DP as a general technique is new to you, a short intro will make the specific recurrence above click faster.
- Revisit C07 for allocation patterns (you'll likely need a 2D dynamically-allocated grid) and Valgrind for leak-checking multi-map runs.

## Don't

Don't attempt this by brute-force-checking every possible square size at every position unless you're specifically doing it as a first "get something working" pass — it will time out or feel unbearably slow on larger maps, and the whole educational point of BSQ is learning to replace that brute force with the DP approach above.
