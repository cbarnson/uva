
## What is the number of edges in a complete graph, K_n?
SOLN n choose 2 = (n * (n - 1)) / 2

## What is Euler's handshaking lemma?
SOLN If G is any graph, then the sum of all d_G(v), for all v in V, is equal to (2 * |E(G)|)

Give the 3 facts resulting from the following theorem:

## Thm: If G1 and G2 are isomorphic graphs, then ...
SOLN 1. |V(G1)| = |V(G2)|, 2. |E(G1)| = |E(G2)|, 3. the multiset of valencies of every vertex of G1 is the same as the multiset of valencies of every vertex of G2

# DEFINITIONS

## A walk is `closed` if ...
SOLN A walk is closed if it begins and ends with the same vertex
## Trail
SOLN A trail is a walk in which no two vertices appear consecutively (in either order) more than once (i.e. no edge is used more than once)
## Tour
SOLN A tour is a closed trail
## Euler trail
SOLN An Euler trail is a trail in which every pair of adjacent vertices appear consecutively (every edge is used exactly once)
## Euler tour
SOLN An Euler tour is a closed Euler trail
## Hamilton cycle
SOLN a cycle that visits every vertex of the graph
## Hamilton path
SOLN a path that visits every vertex of the graph

# GRAPH QUESTIONS

## How do you tell if simple, connected graph G has an Euler tour?
SOLN It has an Euler tour if and only if every vertex in the graph has even valency
## How do you tell if simple, connected graph G has an Euler trail?
SOLN It has an Euler trail if and only if at most two of its vertices have odd valency
## Give the theorem about if G is a graph with a Hamilton cycle, then _precondition_
SOLN If G is a graph with a Hamilton cycle, then for every S subset V with S != emptyset and S != V itself, the graph G \ S has at most |S| connected components

# EDGE COLORING

* coloring of edges of graph is proper if two edges that meet at an endvertex never have the same color
* Delta = Delta(G) is maximum valency of G

## Define edge-chromatic number and give relation to Delta(G)
SOLN is smallest number of colors that can be used in a proper edge-coloring of G, denoted X'(G).  X'(G) >= Delta(G) for every graph G
## Give Vizing's Theorem
SOLN X'(G) == Delta(G) or Delta(G) + 1, for every graph G
## Define a bipartite graph
SOLN G is bipartite if V can be partitioned into V1 and V2 such that every edge of G has one endvertex in V1 and the other in V2 (sets V1 and V2 for a bipartition of G)
## Define complete bipartite graph K_{m,n}
SOLN is the bipartie graph on m + n vertices with maximum # of edges such that has bipartition into sets of cardinality m and n (it has every edge between the two sets of the biparition)
## Thm: G is bipartite if and only if ...
SOLN it has no cycles of odd length
## Thm: If G is bipartite, then X'(G) = ...
SOLN Delta(G)

# VERTEX COLORING

* coloring of vertices of a graph is proper if no two adjacent vertices have same color

## Define chromatic number
SOLN is smallest number of colors that can be used in a proper coloring of vertices of G, denoted X(G). X(G) <= Delta(G) + 1 for every graph G
## What is the chromatic number for a complete graph (i.e. K_n)?
SOLN X(K_n) = n
## What is the chromatic number for a bipartite graph that has at least one edge?
SOLN X(G) = 2
## What is the chromatic number for a cycle, C_n?
SOLN X(C_n) = (n is even) ? 2 : 3
## Give Brooks' Theorem
SOLN X(G) <= Delta(G) if G is connected, and G is neither a complete graph nor a cycle of odd length

# RAMSEY THEORY

* let k, l in set of natural numbers, and each edge of K_n is colored red or blue
* there is red copy of K_k if exists k vertices 1..k s.t. edge ki -> kj is red for all i != j
* there is blue copy of K_l if exists l vertices 1..l s.t. edge li -> lj is red for all i != j
* Ramsey number R(k, l) is smallest n s.t. whenever each edge of K_n is colored red or blue, there is always either a red copy of K_k, or a blue copy of K_l

Answer the following:

## R(3, 3) = 
SOLN 6
## R(k, 1) = 
SOLN 1 for all k
## R(k, 2) = 
SOLN k for all k
## R(k, l) = 
SOLN R(l, k) for all k and l

Complete the proposition:

## R(k, l) <=
SOLN R(k - 1, l) + R(k, l - 1) for all k, l >= 2

Complete the corollary:

## R(k, l) <=
SOLN 2^{k + l} for all k and l

# PLANAR GRAPHS

* K_5 and K_{3,3} are not planar
* planar embedding of G divides plane into faces, F(G) 
* an edge is incident with a face of a planar embedding, if it lies on boundary or inside the face

For a planar embedding of G, dual graph, G* defined by V(G*) = F(G), and fi ~ fj if and only if there is an edge of G that is incident with both fi and fj.  Note, G* may have loops or multiple edges, even if G does not

* dual graph of planar embedding has natural planar embedding, so is a planar graph.  Also, (G*)* = G, if G is connected

## Give Euler's formula (planar embedding of a connected graph)
SOLN If G is a planar embedding of a connected graph then |V| - |E| + |F| = 2

* if G is a connected graph, then all planar embeddings of G have the same number of faces
* if G is a connected, simple, planar graph and |V| >= 3, then |E| <= (3 * |V| - 6).  Also, if G has no cycles of length 3, then |E| <= (2 * |V| - 4)

## K_5 and K_{3,3} (are / are not) planar?
SOLN are not

* Give the value for this corollary:

## If G is a connected, simple, planar graph, then G has a vertex of valency <= ...
SOLN 5

* an edge uv can be subdivided by placing a vertex somewhere along its length (i.e. taking uv, replacing with new vertex w, and edges uw and wv)
* a subdivision of a graph is a graph that is obtained by subdividing some of the edges of the graph

## Give Kuratowski's Theorem
SOLN graph G is planar if and only if no subgraph of G is a subdivision of K_5 or K_{3,3}



