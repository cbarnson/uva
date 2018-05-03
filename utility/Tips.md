# C++ Competitive Programming Cheat Sheet

# Common algorithms

## Graph algorithms

### Minimum spanning tree

A [minimum spanning tree (MST)](https://en.wikipedia.org/wiki/Minimum_spanning_tree) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight. That is, it is a spanning tree whose sum of edge weights is as small as possible. More generally, any edge-weighted undirected graph (not necessarily connected) has a minimum spanning forest, which is a union of the minimum spanning trees for its [connected components](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)).

## Dynamic programming

### Longest common subsequence

[LCS](http://www.geeksforgeeks.org/longest-common-subsequence/) Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.

It is a classic computer science problem, the basis of [diff](https://en.wikipedia.org/wiki/Diff_utility) (a file comparison program that outputs the differences between two files), and has applications in bioinformatics.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem.

1) Optimal Substructure: 
Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y.

If last characters of both sequences match (or X[m-1] == Y[n-1]) then
**L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])**

If last characters of both sequences do NOT match (or X[m-1] != Y[n-1]) then
**L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2])**

So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.

2) Overlapping Subproblems:
Following is simple recursive implementation of the LCS problem. The implementation simply follows the recursive structure mentioned above.

	/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
	int lcs( char *X, char *Y, int m, int n )
	{
	   if (m == 0 || n == 0)
	     return 0;
	   if (X[m-1] == Y[n-1])
	     return 1 + lcs(X, Y, m-1, n-1);
	   else
	     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
	}

**Time complexity of the above naive recursive approach is O(2^n)** in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0.

So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation. Following is a tabulated implementation for the LCS problem.

	/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
	int lcs( char *X, char *Y, int m, int n )
	{
	   int L[m+1][n+1];
	   int i, j;
	  
	   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
	      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	   for (i=0; i<=m; i++)
	   {
	     for (j=0; j<=n; j++)
	     {
	       if (i == 0 || j == 0)
	         L[i][j] = 0;
	  
	       else if (X[i-1] == Y[j-1])
	         L[i][j] = L[i-1][j-1] + 1;
	  
	       else
	         L[i][j] = max(L[i-1][j], L[i][j-1]);
	     }
	   }
	    
	   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	   return L[m][n];
	}

**Time Complexity of the above implementation is O(mn)** which is much better than the worst case time complexity of Naive Recursive implementation.


# Definitions

## Connected graph

A graph is [connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph) when there is a path between every pair of vertices. In a connected graph, there are no unreachable vertices. A graph that is not connected is disconnected. A graph G is said to be disconnected if there exist two nodes in G such that no path in G has those nodes as endpoints. A graph with just one vertex is connected. An edgeless graph with two or more vertices is disconnected.

## Spanning tree

In the mathematical field of graph theory, a spanning tree T of an [undirected](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)#Undirected_graph) graph G is a subgraph that is a tree which includes all of the vertices of G, with minimum possible number of edges. In general, a graph may have several spanning trees, but a graph that is not connected will not contain a spanning tree (but see [Spanning forests](https://en.wikipedia.org/wiki/Spanning_tree#Spanning_forests)). If all of the edges of G are also edges of a spanning tree T of G, then G is a tree and is identical to T (that is, a tree has a unique spanning tree and it is itself).







