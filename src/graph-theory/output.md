
## What is the number of edges in a complete graph, K_n?
(n * (n - 1)) / 2

## What is Euler's handshaking lemma?
sum of d(v) for all v in V = 2 * |E|


## Thm: If G1 and G2 are isomorphic graphs, then ...
same number vertices same number edges, and multiset of degrees in G1 is same as in G2

# DEFINITIONS

## Closed (walk)
a closed walk is a sequence of distinct vertices except that the first vertex is same as last
## Trail
a trail is a walk from 1..k where each edge i,i+1 is distinct
## Tour
a tour is a closed trail
## Euler trail
an euler trail is a trail that visits all edges exactly once
## Euler tour
is an euler trail but ends up at starting vertex
## Hamilton cycle
is a cycle that visits all vertices of a graph
## Hamilton path
is a path that visits all vertices of a graph (doesn't have to end up at starting vertex)

# GRAPH QUESTIONS

## How do you tell if simple, connected graph G has an Euler tour?
will have no vertex degrees that are odd, all even
## How do you tell if simple, connected graph G has an Euler trail?
there will be no more than 2 odd valencies
## Give the theorem about if G is a graph with a Hamilton cycle, then _precondition_
for each subset S of G, other than the emptyset and V itself, G \ S must not have more than |S| connected components

# EDGE COLORING


## Define edge-chromatic number and give relation to Delta(G)
edge chrom number is Delta(G) or Delta(G) + 1
## Give Vizing's Theorem
^^ above wrong, thats here , above is <= delta(g)
## Define a bipartite graph
all vertices can be partitioned into two sets v1 and v2 such that no pair of vertices in v1 are adjacent, same for v2
## Define complete bipartite graph K_{m,n}

## Thm: G is bipartite if and only if ...

## Thm: If G is bipartite, then X'(G) = ...
2

# VERTEX COLORING


## Define chromatic number
chromatic number is the lowest n such that we can do a proper coloring of the vertices with n colors
## What is the chromatic number for a complete graph (i.e. K_n)?
n
## What is the chromatic number for a bipartite graph that has at least one edge?
2
## What is the chromatic number for a cycle, C_n?
2 if n is even, 3 otherwise
## Give Brooks' Theorem
X(G) <= delta(G) if G is not complete graph nor is it a cycle graph (odd cycle)

# RAMSEY THEORY



## R(3, 3) = 
6
## R(k, 1) = 
1
## R(k, 2) = 
k
## R(k, l) = 
R(l, k) for all k and l


## R(k, l) <=
R(k -1 , l) + R(k, l - 1)


## R(k, l) <=


# PLANAR GRAPHS




## Give Euler's formula (planar embedding of a connected graph)
|V| - |E| + |F| = 2


## K_5 and K_{3,3} (are / are not) planar?
are not


## If G is a connected, simple, planar graph, then G has a vertex of valency <= ...
5


## Give Kuratowski's Theorem




