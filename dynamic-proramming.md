## Dynamic Programming
#### Feb 12, 2014

### Definition

Useful for problems with **overlapping subproblems**.

Basic idea: as **subproblems** are solved, retain their solutions so they never
need to be recalculated.

### Technique

1. Define subproblems with some sort of ordering
2. Solve subproblems "bottom up" in necessary order
3. Keep solutions to each sub-problem stored in some table
4. Start filling table with "obvious" base cases

We are trading space for time - like pokémon!

### Example

Problem: Longest Increasing Subsequence

* Regard each problem as a DAG
    * each number is a node
    * edge between number i and number j if i < j

Solution: Longest path through the DAG

    Len(j) = 1 + max { Len(i); there is an edge i -> j }
