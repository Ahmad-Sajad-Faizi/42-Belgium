# Rush02 — Number-to-Words Converter

The third team project. The task: take a positive integer and convert it into its written-word form (e.g. "one hundred and twenty-three"), by parsing a dictionary file that defines the words for that specific language rather than hardcoding English (that's why this repo's `rush02` folder has separate French, Spanish, and numbers dictionaries — the same program needs to work regardless of which dictionary it's fed).

## What this project is really testing

- **File parsing** — reading and correctly interpreting the structure of a dictionary file (this repo's `.dict`/`.txt` files map numeric values to words, likely with some scale markers for hundred/thousand/etc.).
- **Recursive, rule-based construction** — building "one thousand two hundred thirty-four" isn't a lookup, it's a recursive breakdown: split the number into thousands/hundreds/tens/units groups, convert each group, and stitch the words together according to the target language's grammar rules.
- **Dynamic memory** — you're building strings piece by piece and joining them, so this leans heavily on C07's allocation/`strjoin` habits.
- **Correct memory cleanup** — the subject explicitly calls out freeing all allocated memory; treat this as a real requirement, not a nice-to-have.

## Tips & tricks

- **Break the number into groups before worrying about words.** Most numbering systems build up from a "0-99" building block repeated with scale words (hundred, thousand, million...) — get the pure numeric decomposition right first, independent of any language.
- **The dictionary file defines the vocabulary, not your logic.** Your program's *structure* (how you combine "hundred" and "twenty" and "three") should be generic; only the actual words come from the dictionary. If you hardcode English grammar assumptions into your control flow, it'll break the moment you switch to the Spanish or French dictionary.
- **Test with the smallest and largest numbers you're required to support first** — zero, one, and the upper bound your subject specifies are exactly where grouping-logic bugs hide.
- **Different languages combine number words differently** (e.g. some languages need a connector word between tens and units, some don't) — read your dictionary file's format carefully, since it likely encodes exactly this kind of rule, not just a flat word list.

## Resources

- Revisit C07 (`ft_strjoin`, `ft_split`, dynamic allocation) — this project is built almost entirely on those habits, just applied to a bigger problem.
- Search "number to words algorithm" for general approaches to the grouping/decomposition logic across languages — useful for the *shape* of the algorithm, not the specific vocabulary.

## Don't

Don't hardcode assumptions from one language's grammar (like English's "and" placement) into your core logic — if your program only works correctly for one of the three dictionaries in this repo, that's a sign your parsing and generation logic aren't actually separated the way the project wants.
