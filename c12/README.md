# C12 — Linked Lists

Your first real data structure. Eighteen exercises building up a full singly-linked list toolkit, one operation at a time. Take it slow — this module's habits carry directly into C13 and into `get_next_line`/`push_swap` later in the core curriculum.

## Exercises

| Ex | Concept it's testing |
|---|---|
| `ex00` ft_create_elem + `ft_list.h` | Defining the node struct, allocating a single node |
| `ex01` ft_list_push_front | Inserting at the head |
| `ex02` ft_list_size | Traversal + counting |
| `ex03` ft_list_last | Traversal to the end |
| `ex04` ft_list_push_back | Inserting at the tail |
| `ex05` ft_list_push_strs | Building a list from an array of strings |
| `ex06` ft_list_clear | Freeing every node (and not leaking) |
| `ex07` ft_list_at | Traversal to the nth element |
| `ex08` ft_list_reverse | Reversing the list *in place*, no new allocation |
| `ex09` ft_list_foreach | Applying a function to every element (function pointers again) |
| `ex10` ft_list_foreach_if | Same, but conditional on a predicate |
| `ex11` ft_list_find | Searching for a value |
| `ex12` ft_list_remove_if | Deleting nodes matching a condition |
| `ex13` ft_list_merge | Combining two lists into one |
| `ex14` ft_list_sort | Sorting the list |
| `ex15` ft_list_reverse_fun | Reversing again, functional/recursive style |
| `ex16` ft_sorted_list_insert | Inserting into a list while keeping it sorted |
| `ex17` ft_sorted_list_merge | Merging two already-sorted lists while preserving order |

## Tips & tricks

- **A linked list is just nodes pointing to the next node** — each node holds data and a pointer to the next node (or `NULL` if it's the last one). The list itself is usually represented by just a pointer to the first node ("head").
- **To modify the head from inside a function, you need a pointer to the pointer** (`t_list **list`). If you only receive `t_list *list`, changing it inside the function only changes your local copy — the caller's head pointer is untouched. This trips up almost everyone on `push_front` the first time.
- **When freeing a node, save `next` first.** `free(node)` destroys your only way to reach the rest of the list — grab `t_list *next = node->next;` *before* freeing, then move to `next`.
- **In-place reverse (`ft_list_reverse`) needs three pointers in flight** at any moment: the node you're working on, the one before it, and the one after it — before you break a link, make sure you've already saved what you need on the other side of it.
- **`ft_list_sort` and the merge exercises** are a good moment to think about which sorting approach actually fits a linked list well (insertion into a sorted list, or merge-based approaches) rather than trying to force an array-style algorithm onto a structure that doesn't support random access efficiently.

## Resources

- [VisuAlgo — Linked List](https://visualgo.net/en/list) — step through insert/delete/reverse operations visually; extremely useful for this module specifically.
- [Beej's Guide — structs and linked data](https://beej.us/guide/bgc/html/split/structs.html) — struct fundamentals if C08 feels like a while ago.
- Search "singly linked list reverse in place explained" for a walkthrough of the three-pointer technique if `ft_list_reverse` isn't clicking.

## Don't

Don't write `ft_list_clear` carelessly — a linked list is the classic place to introduce a memory leak (forgetting to free node data) or a use-after-free (freeing a node, then still reading `->next` from the freed memory). Run this module's tests under Valgrind; it will catch these instantly.
