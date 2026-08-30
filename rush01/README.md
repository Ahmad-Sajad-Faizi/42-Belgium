# Rush01 — Grid Visibility Puzzle

The second team project. You're given a grid (commonly 4x4) and, around its borders, a set of "visibility" clues — numbers telling you how many boxes of increasing height would be visible from that edge, looking across the row or column. Your program has to fill in the grid with values that satisfy every clue simultaneously, or correctly report that no solution exists.

This is essentially a constraint-satisfaction puzzle, closely related to a Skyscraper puzzle.

## What this project is really testing

- **Backtracking search** — you place a value, check it doesn't violate any constraint so far, and if it eventually leads to a dead end, undo it and try the next possibility. This is the same core idea as `ft_ten_queens_puzzle` from C05, applied to a 2D grid with visibility rules instead of attack rules.
- **Careful grid/array representation** — how you store the grid, its rows, columns, and the border clues will make the constraint checks either simple or painful. Design this before writing your solver.
- **Correct input parsing** — the grid comes with a specific input format (including, in many variants, some cells given as fixed/pre-filled or as wildcards). Get the parser airtight before touching the solver.

## Tips & tricks

- **The "visibility" rule**: looking along a row (or column) from one end, you count a box as "visible" if it's taller than every box before it in that direction. A clue of `3` on one edge means exactly 3 boxes are visible from that direction along that line.
- **Each row and each column must contain every value exactly once** (like a Latin square / mini-Sudoku constraint) — this alone eliminates a lot of the search space and should be one of your very first checks before you even think about the visibility clues.
- **Prune early.** Don't fill the entire grid and then check all constraints at the end — check each new placement against the relevant row/column/clue constraints *as you place it*, so you can backtrack the moment something's violated instead of wasting time filling in the rest of an already-invalid grid.
- **Work a small example by hand on paper first.** Before writing any backtracking code, manually solve one small grid with its clues so you deeply understand what "checking a placement" actually means — coding a backtracking search you don't understand rarely goes well.

## Resources

- Search "Skyscraper puzzle rules explained" for the classic version of this puzzle with worked examples — very close to what you're solving here.
- Revisit C05's N-Queens tips — the backtracking pattern (place → check → recurse → undo if stuck) transfers almost directly.
- Search "backtracking algorithm explained with examples" for a general refresher if the concept still feels abstract.

## Don't

Don't try to solve this with pure brute force (trying every possible grid) — the search space is too large even for a small grid. The whole point of the exercise is learning to prune the search as early as possible using the constraints you already know.
