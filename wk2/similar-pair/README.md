## Similar Pair

You are given a tree where each node is labeled from 1, 2, …, n. How many similar pairs(S) are there in this tree?

A pair (A,B) is a similar pair iff

* node A is the ancestor of node B
* abs(A - B) <= T.

#### Input format:
The first line of the input contains two integers n and T. This is followed by n-1 lines each containing two integers si and ei where node si is a parent to node ei.

#### Output format:
Output a single integer which denotes the number of similar pairs in the tree

#### Constraints:

* 1 <= n <= 100000
* 0 <= T <= n
* 1 <= si, ei <= n.

#### Sample Input:

    5 2
    3 2
    3 1
    1 4
    1 5

#### Sample Output:

    4

#### Explanation:

The similar pairs are: (3, 2) (3, 1) (3, 4) (3, 5)
