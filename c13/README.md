# C13 — Binary Trees

The last and hardest of the "C" modules for most people. It reuses everything from C11 (function pointers) and C12 (linked structures, recursive thinking) and applies it to a branching structure instead of a linear one.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` btree_create_node + `ft_btree.h` | Defining the node struct (data + left + right), allocating a node |
| `ex01` btree_apply_prefix | Pre-order traversal (visit node, then left, then right) |
| `ex02` btree_apply_infix | In-order traversal (visit left, then node, then right) |
| `ex03` btree_apply_suffix | Post-order traversal (visit left, then right, then node) |
| `ex04` btree_insert_data | Inserting into a binary *search* tree, using a comparator function |
| `ex05` btree_search_item | Searching a BST using the same comparator |
| `ex06` btree_level_count | Computing tree height/depth |
| `ex07` btree_apply_by_level | Level-order (breadth-first) traversal |

## Tips & tricks

- **A binary tree node has data plus (up to) two children**, conventionally called `left` and `right`, either of which can be `NULL`. Almost every operation on a tree is naturally recursive: do something with the current node, then recurse on `left`, then recurse on `right` (in whatever order the traversal type demands).
- **The three "depth-first" traversals (`prefix`/`infix`/`suffix`) only differ in *when* you visit the current node** relative to recursing into its children — write the recursive skeleton once, then just move one line to get from pre-order to post-order. Understanding this relationship is more valuable than memorizing three separate implementations.
- **`btree_insert_data` needs a comparator function** (same idea as C11's function pointers) to decide whether new data goes left or right at each node — this is what makes it a *search* tree rather than an arbitrary tree, and it's why `btree_search_item` can skip whole branches instead of checking every node.
- **`btree_level_count`** (tree height) is `1 + max(height(left), height(right))`, with an empty tree having height `0` — a clean two-line recursive function once you see the pattern.
- **`btree_apply_by_level` is the odd one out**: breadth-first traversal (level by level, left to right) isn't naturally recursive the way the others are — you generally need an explicit queue (which you can build from what you learned in C12) to track "which nodes to visit next," rather than the call stack doing it for you implicitly.

## Resources

- [VisuAlgo — Binary Search Trees](https://visualgo.net/en/bst) — step through insertion, search, and traversals visually; the single best resource for building intuition here.
- Search "binary tree traversal preorder inorder postorder explained" for a side-by-side comparison if the three depth-first orders are blurring together.
- Search "breadth first search using a queue explained" for why BFS needs an explicit queue instead of relying on recursion, if `btree_apply_by_level` isn't clicking.

## Don't

Don't try to write `btree_apply_by_level` recursively by adapting your other traversal functions — it genuinely needs a different approach (a queue), and forcing recursion onto it is where a lot of people get stuck for hours. Recognizing "this needs a different tool" is itself the skill this exercise is testing.
