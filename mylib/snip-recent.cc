// Problem #    : snip
// Created on   : 2018-10-21 10:03:54
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

namespace ArticulationPointsBridges {
// doesn't matter the value, just different
const int UNVISITED = -1;

// need these for APB algorithm, initialized in main()
int depth, root, children;
vi lo, num, parent;

// true for index i if i identifies an articulation point
vector<bool> art_points;

// adj list representation of graph
vector<vi> adj_list;

// Find Articulation Points and Bridges
void APB(int u) {
  lo[u] = num[u] = depth++;  // lo[u] <= num[u]
  for (auto &v : adj_list[u]) {
    if (num[v] == UNVISITED) {
      // tree edge
      parent[v] = u;
      if (u == root) children++;

      // Recurse
      APB(v);

      // articulation point
      if (lo[v] >= num[u]) art_points[u] = true;

      // bridge
      if (lo[v] > num[u])
        cout << "Edge " << u << " -> " << v << " is a bridge\n";

      // update lo
      lo[u] = min(lo[u], lo[v]);

    } else if (v != parent[u]) {
      // back edge, not a direct cycle
      lo[u] = min(lo[u], num[v]);
    }
  }
}

void SolveForArticulationPointsAndBridges() {
  // setup adjlist
  int V;
  V = 10;

  // find articulation points and bridges
  depth = 0;
  num.assign(V, UNVISITED);
  lo.assign(V, 0);
  parent.assign(V, -1);
  art_points.assign(V, false);

  // first find bridges
  cout << "Bridges:\n";
  FR(i, V) {
    if (num[i] == UNVISITED) {
      root = i, children = 0;
      APB(i);
      art_points[root] = (children > 1);
    }
  }

  // points
  cout << "Points:\n";
  FR(i, V) {
    if (art_points[i]) cout << "Vertex " << i << endl;
  }
}
}  // namespace ArticulationPointsBridges

// Bellman-Ford
// Complexity: O(VE)
// Notes: SSSP; supports negative edge weights, commonly use to
// detect presence of negative cycle.
namespace BellmanFord {
const int INF = ~(1 << 31);
vvii G;  // Graph, G[u][j] = (w, v), edge u -> v weight w
vi D;    // Distance
int n;   // nodes

// Returns: true if there is a negative cycle, false otherwise
bool bellmanFord(int s) {
  D.assign(n, INF);
  D[s] = 0;
  FR(i, n - 1) FR(u, n) for (const auto &p : G[u]) {
    int v, w;
    tie(w, v) = p;
    D[v] = min(D[v], D[u] + w);
  }
  bool ncycle = false;
  FR(u, n) for (const auto &p : G[u]) {
    int v, w;
    tie(w, v) = p;
    if (D[v] > D[u] + w) ncycle = true;
  }
  return ncycle;
}
}  // namespace BellmanFord

// Binomial Coefficient (sequence of products)
// Complexity: O(k)
// Notes:
// C(n, k) == C(n, n - k);
// C(n, 0) = C(n, n) = 1;
// C(n, k) = C(n - 1, k - 1) + C(n - 1, k);
ll BinomialCoefficient(int n, int k) {
  if (k == 0 || k == n) return 1;
  k = min(k, n - k);
  ll ans = 1;
  for (ll i = 1; i <= k; i++) {
    ans *= (n - k + i) / i;
  }
  return ans;
}

// BFS
// Complexity: O(V + E)
namespace BFS {
vvi G;
vi D;
int n;
void bfs(int s) {
  D.assign(n, -1);
  D[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : G[u]) {
      if (D[v] == -1) {
        D[v] = D[u] + 1;
        q.push(v);
      }
    }
  }
}

// Bipartite (check)
// Complexity: O(V + E)
bool isBipartite(int s) {
  vi color(n, -1);
  color[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : G[u]) {
      if (u == v) return false;
      if (color[v] == -1)
        color[v] = !color[u], q.push(v);
      else if (color[v] == color[u])
        return false;
    }
  }
  return true;
}
}  // namespace BFS

// Enumerate combinations
namespace EnumerateCombinations {
vi A;
int countCombinations(int n, int k) {
  vi B(k, 1);
  B.resize(n, 0);
  reverse(begin(B), end(B));  // equivalently, sort ascending
  int cnt = 0;
  do {
    // For each item, i, if ith item included, do 'something'
    FR(i, n) if (B[i]) { cout << A[i] << " "; }
  } while (next_permutation(begin(B), end(B)));
  return cnt;
}
}  // namespace EnumerateCombinations

// Count # of digits
int countDigits(long long n) { return n > 0 ? (int)log10((double)n) + 1 : 1; }

// Custom sorting condition
// Notes: 'customSortAscDesc' sorts 'A' by ascending p.first, descending
// p.second
namespace CustomSortPair {
void customSortAscDesc(vii &A) {
  sort(begin(A), end(A), [](const ii &x, const ii &y) {
    return (x.second > y.second || (x.second == y.second && x.first < y.first));
  });
}
}  // namespace CustomSortPair

// DFS
// Complexity: O(V + E)
namespace DFS {
vvi G;
void dfs(int s, vi &vis) {
  vis[s] = true;
  for (auto &v : G[s]) {
    if (!vis[v]) dfs(v, vis);
  }
}
}  // namespace DFS

// Dijkstra
// Complexity: O(E + V*log(V))
// Notes: SSSP, weighted graph, directed or undirected
namespace Dijkstra {
vvii G;       // u -> (w, v)
vi D;         // distance
int n, dest;  // = G.size(), usually; dest optional

void dijkstra(int s) {
  D.assign(n, -1);
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.emplace(0, s);
  while (!pq.empty()) {
    int u, d;
    tie(d, u) = pq.top();
    pq.pop();
    if (D[u] != -1) continue;
    D[u] = d;
    for (auto &i : G[u]) {
      int v, w;
      tie(w, v) = i;
      pq.emplace(d + w, v);
    }
  }
  // return D[dest];
}

// DP - find # of optimal paths (to dest) after running dijkstra
// WARNING: this not verified, is this correct?
const int MAX_N = 1000;
vi dp(MAX_N, -1);
int numberOfWays(int u) {
  if (u == dest) return 1;
  int &x = dp[u];
  if (x != -1) return x;
  for (auto &j : G[u]) {
    int v, w;
    tie(w, v) = j;
    // if D[u] + w == D[v], then u -> v is part of some optimal path
    if (D[u] + w == D[v]) x += numberOfWays(v);
  }
  return x;
}
}  // namespace Dijkstra

// Factorization (primes)
// Complexity: O(log(n))
// Notes: for n >= 0, does not include 0, 1 in the result array;
// remember to change 'vi f' to 'vector<ll> f' if necessary
namespace Factorization {
vi factor(ll n) {
  vi f;
  if (n < 2) return vi();  // vi(1, n), if want 'n' for n < 2
  while (~n & 1) n /= 2, f.push_back(2);
  for (ll p = 3; p * p <= n; p += 2)
    while (n % p == 0) n /= p, f.push_back((int)p);
  if (n > 1) f.push_back(n);
  return f;
}
}  // namespace Factorization

// Fibonacci (DP & matrix exponentiation)
// Complexity: O(log(n))
// Notes: computes nth Fibonacci number, fib(0) = 0, fib(1) = 1;
// fib(>= 47) will overflow a 32-bit signed integer
namespace Fibonacci {
int f[1000];
int fib(int n) {
  if (n < 2) return n;
  if (f[n]) return f[n];
  int k = (n + 1) / 2;
  f[n] = (n & 1) ? fib(k) * fib(k) + fib(k - 1) * fib(k - 1)
                 : (2 * fib(k - 1) + fib(k)) * fib(k);
  return f[n];
}
}  // namespace Fibonacci

// Floyd-Warshall
// Complexity: O(V^3)
// Notes: Computes all-pairs shortest path; Graph must be represented as
// adjacency matrix.  Use for # of nodes up to 400.
namespace FloydWarshall {
const int INF = ~(1 << 31);
const int MAX_N = 400;
int G[MAX_N][MAX_N];  // G[u][v] => weight of edge u -> v (INF if no edge)
int n;                // # of nodes
void AllPairsShortestPath() {
  FR(k, n) FR(i, n) FR(j, n) { G[i][j] = min(G[i][j], G[i][k] + G[k][j]); }
}
void FloydWarshall_Usage() {
  FR(i, n)
  FR(j, n)
  G[i][j] = (i == j ? 0 : INF);  // distance to self 0, else INF
  int m;                         // # of edges
  cin >> m;
  FR(i, m) {
    int u, v, w;  // u -> v, weight w
    cin >> u >> v >> w;
    G[u][v] = w;
    G[v][u] = w;  // if undirected
  }
  AllPairsShortestPath();
}
}  // namespace FloydWarshall

// KMP (Knuth-Morris-Pratt)
// Complexity: O(k + n), where k, n are pattern length, search length,
// respectively
// Notes: Given pattern string 'p', and search string 's', finds all occurrences
// of 'p' in 's'.
namespace KMP {
string p, s;  // pattern, search

// Complexity: O(k), k = p.length()
vi KMP_Init() {
  int n = p.size();
  vi V(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    int j = V[i - 1];
    while (j != -1 && p[j] != p[i - 1]) j = V[j];
    V[i] = j + 1;
  }
  return V;
}

// Complexity: O(n), n = s.length()
vi KMP_Find(const vi &V) {
  vi res;
  int i = 0, j = 0, sl = s.size(), pl = p.size();
  while (i < sl) {
    while (j != -1 && (j == pl || p[j] != s[i])) j = V[j];
    i++, j++;
    if (j == pl) res.push_back(i - pl), j = V[j];
  }
  return res;
}

// Complexity: O(k + n)
void KMP_Usage() {
  cin >> p >> s;         // pattern, search
  vi V = KMP_Init();     // must call before KMP_Find
  vi res = KMP_Find(V);  // s[ans[i]] is first character of a match for all i
}
}  // namespace KMP

// Least Common Multiple - O(log n), where n = max(a, b) (as in gcd)
int LCM(int a, int b) { return a * (b / __gcd(a, b)); }

// LCS (Longest Common Subsequence)
// Complexity: O(n^2)
// Notes: Bottom-up DP implementation, returns the length of the LCS, and stores
// (one of) the optimal sequences in 'ans' (may be >1 optimal solutions, may
// need to modify tiebreaker condition). 'A' and 'B' need not be equal length,
// but both sizes must be less than MAX_N.
namespace LCS {
const int MAX_N = 1000;
int LCS(const vi &A, const vi &B, int ans[MAX_N]) {
  int a = A.size(), b = B.size();
  assert(a <= MAX_N && b <= MAX_N);
  int L[MAX_N + 1][MAX_N + 1];
  for (int i = a; i >= 0; i--)
    for (int j = b; j >= 0; j--)
      if (i == a || j == b)
        L[i][j] = 0;
      else if (A[i] == B[j])
        L[i][j] = 1 + L[i + 1][j + 1];
      else
        L[i][j] = max(L[i + 1][j], L[i][j + 1]);

  // return L[0][0]; // End here if only care about length
  int i = 0, j = 0, k = 0;
  while (i < a && j < b) {
    if (A[i] == B[j])
      ans[k++] = A[i], i++, j++;
    else if (L[i + 1][j] > L[i][j + 1])
      i++;
    else if (L[i + 1][j] < L[i][j + 1])
      j++;
    else
      j++;  // tiebreaker
  }
  return L[0][0];
}
}  // namespace LCS

// LIS (Longest Increasing Subsequence)
// Complexity: O(n log(n)) and O(n^2)
namespace LIS {

// LIS
// Complexity: O(n log(n))
// Notes: Returns the sequence itself stored in a vector<int>
vi LIS_nlogn(vi &A) {
  int n = A.size(), len = 1;
  // For descending, reverse(begin(A), end(A));
  vi last(n + 1), pos(n + 1), pred(n);
  if (n == 0) return vi();
  last[1] = A[pos[1] = 0];
  for (int i = 1; i < n; i++) {
    // Use lower_bound for strictly ascending/descending
    int j = upper_bound(begin(last) + 1, begin(last) + len + 1, A[i]) -
            last.begin();
    pred[i] = (j - 1 > 0) ? pos[j - 1] : -1;
    last[j] = A[pos[j] = i];
    len = max(len, j);
  }
  // Recovers the sequence, store in 'S'
  int start = pos[len];
  vi S(len);
  for (int i = len - 1; i >= 0; i--) {
    S[i] = A[start];
    start = pred[start];
  }
  return S;
}

// Complexity: O(n^2)
int LIS_asc(int n, const vi &A) {
  vi asc(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    asc[i] = 1;
    for (int j = i + 1; j < n; j++)
      if (A[i] < A[j]) asc[i] = max(asc[i], asc[j] + 1);
  }
  return asc[0];
}

// Complexity: O(n^2)
int LIS_desc(int n, const vi &A) {
  vi desc(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    desc[i] = 1;
    for (int j = i + 1; j < n; j++)
      if (A[i] > A[j]) desc[i] = max(desc[i], desc[j] + 1);
  }
  return desc[0];
}
}  // namespace LIS

// Max Flow - Edmonds Karp
// Complexity: O(V^3  * E)
namespace MaxFlowEdmondsKarp {
const int INF = ~(1 << 31);
// mf: max flow (our solution, eventually)
// f : min f at the time
// s : source
// t : sink
int mf, f, s, t;

// parent, for BFS
vi p;

// max # of vertices we could have
const int MV = 1000;
int res[MV][MV];

void augment(int v, int lo) {
  if (v == s) {
    // base case: we reach source, and resolve 'f' to the minimum edge
    f = lo;
    return;
  } else if (p[v] != -1) {
    // wonder... is this check redundant? ==> no. It is needed because not
    // necessarily have v -> u (back) for all u -> v

    // recursive call
    augment(p[v], min(lo, res[p[v]][v]));

    // NOTE: changing with 'f', not 'lo'... why?
    // because we're doing recursive calls, updating 'f' once we arrive at
    // 's', at which point the global 'f' is updated, 'augment' returns up the
    // stack, and these values need to be updated with that 'f', not just what
    // 'lo' was at the time
    //
    // update forward res edges u -> v (i.e. p[v] -> v) with -f
    // update backwrd res edges v -> u (i.e. v -> p[v]) with +f
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
}

void usage() {
  // for each case, setup res, s, t
  cin >> s >> t;

  // init to 0, need to do this cause using adj matrix
  FR(i, MV)
  FR(j, MV) res[i][j] = 0;

  // of the form:
  // node_u node_v uv_capacity
  int u, v, c;
  while (cin >> u >> v >> c) {
    cin >> u >> v >> c;
    res[u][v] = c;
  }

  // max flow, initially 0
  mf = 0;
  for (;;) {
    // don't forget this.  'f' needs to be reset each time
    // or does it?... don't see why
    // ==> YES: it is needed,
    // ==> See below: <f needs to be 0>
    f = 0;

    // here, dist is the 'hop-count' from s to t
    // but the actual 'weights' (i.e. capacities) of the edges are
    // handled in 'res', initially equal to original values, but
    // change over the course of the algorithm
    vi dist(MV, INF);
    dist[s] = 0;

    // don't forget this part
    p.assign(MV, -1);

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      if (u == t) break;  // Exit condition: reach the sink

      FR(v, MV) {
        // Interpretation
        // 1: res[u][v] > 0
        // ==> v reachable from u
        // 2: dist[v] == INF
        // ==> unvisited
        if (res[u][v] > 0 && dist[v] == INF)
          dist[v] = dist[u] + 1, q.push(u), p[v] = u;
      }
    }
    // BFS path has been created and stored by 'p', now augment.
    // When this completes, we will know the minimum flow 'f' in this path ***IF
    // ANY*** why IF ANY?  ==> because when 'f' == 0, we cannot send any more
    // flow, so we are DONE
    // ==> See above: <f needs to be 0>
    augment(t, INF);
    if (f == 0) break;

    // we increase 'mf' maxflow solution for this case, by 'f' -> the flow that
    // we still have the capacity to send.
    mf += f;
  }

  // print 'mf' the maximum flow.
  cout << mf << endl;
}

}  // namespace MaxFlowEdmondsKarp

// Maximal Matching (Hopcroft-Karp)
// https://en.wikipedia.org/wiki/Hopcroft–Karp_algorithm
// time complexity: O(E * sqrt(V))
class MaxMatching {
 public:
  static tuple<int, vi> max_matching(const vector<vi> &g) {
    int m = 0, n = g.size();

    for (auto &gg : g)
      for (int u : gg) m = max(m, u + 1);
    vi A(m, -1), D(n), used(n);

    for (int i = 0, f = 0;; i += f, f = 0) {
      vi vis(n);
      bfs(g, used, A, D);
      FR(u, n) if (!used[u] && dfs(g, vis, used, A, D, u)) f++;
      if (!f) return make_tuple(i, A);
    }
  }

  static void bfs(const vector<vi> &g, vi &used, vi &A, vi &D) {
    int n = g.size(), q = 0;
    fill(begin(D), end(D), -1);
    vi Q(n);
    FR(u, n) if (!used[u]) Q[q++] = u, D[u] = 0;
    FR(i, q) {
      int u = Q[i];
      for (int v : g[u]) {
        int w = A[v];
        if (w >= 0 && D[w] < 0) D[w] = D[u] + 1, Q[q++] = w;
      }
    }
  }

  static bool dfs(const vector<vi> &g, vi &vis, vi &used, vi &match, vi &D,
                  int u) {
    vis[u] = 1;
    for (int v : g[u]) {
      int w = match[v];
      if (w < 0 ||
          (!vis[w] && D[w] == D[u] + 1 && dfs(g, vis, used, match, D, w))) {
        match[v] = u;
        used[u] = true;
        return true;
      }
    }
    return false;
  }
};

// Modular Exponentiation
// Compute x^n mod m
int modexp(int x, int n, int m) {
  if (n == 0) return 1;
  if (n & 1) return ((x % m) * modexp(x, n - 1, m)) % m;
  int y = modexp(x, n / 2, m);
  return (y * y) % m;
}

// Palindrome
// Check if a string is a palindrome
bool palindrome(string s) {
  return equal(s.begin(), next(s.begin(), s.size() / 2), s.rbegin());
}

// Range Minimum Query
// Complexity: < O(n log(n)), O(1) >
namespace RangeMinimumQuery {
class RMQ {
 public:
  vi A;
  vector<vi> M;
  RMQ(const vi &B) {
    A = B;
    int n = A.size();
    int m = 31 - __builtin_clz(n) + 1;
    M.assign(m, vi(n));
    FR(j, n) M[0][j] = j;
    for (int i = 1; (1 << i) <= n; i++) {
      for (int j = 0; (j + (1 << i)) <= n; j++) {
        M[i][j] = (A[M[i - 1][j]] <= A[M[i - 1][j + (1 << (i - 1))]])
                      ? M[i - 1][j]
                      : M[i - 1][j + (1 << (i - 1))];
      }
    }
  }
  int query(int L, int R) {
    int k = 31 - __builtin_clz(R - L + 1);
    return (A[M[k][L]] <= A[M[k][R - (1 << k) + 1]]) ? M[k][L]
                                                     : M[k][R - (1 << k) + 1];
  }
};
}  // namespace RangeMinimumQuery

namespace StronglyConnectedComponents {

const int UNVISITED = -1;

int depth, num_scc;
vi num, lo, stk, vis;
vvi g;
// Tarjan's algorithm to find SCC's of directed graph; O(V+E).
// --> commonly used for pre-processing to contract digraph to DAG
void scc(int u) {
  lo[u] = num[u] = depth++;  // lo[u] <= num[u]

  // push 'u' onto stack, and track explored vertices with 'vis'
  stk.push_back(u);
  vis[u] = 1;
  for (auto &v : g[u]) {
    if (num[v] == UNVISITED) scc(v);  // this part is amortized O(V)

    // Condition to update:
    if (vis[v]) lo[u] = min(lo[u], lo[v]);
  }

  // if root, i.e. start of an SCC
  // Since only visited vertices may update lo[u], and initally we set lo[u] =
  // num[u], then if lo[u] == num[u], we know 'u' is the root of this SCC.  To
  // access the members of this SCC, pop from our "stack" (i.e. 'stk', as
  // vector), up to (and including) root 'u'.
  if (lo[u] == num[u]) {
    cout << "SCC #" << ++num_scc << ":";
    for (;;) {
      int v = stk.back();
      stk.pop_back();
      vis[v] = 0;
      cout << " \n"[u == v] << v;
      if (u == v) break;
    }
  }
}

void sccUsage() {
  // Number of vertices
  int V;
  V = 10;

  // Build adjacency list
  g.assign(V, vi());
  // ...

  depth = num_scc = 0;
  num.assign(V, UNVISITED);
  lo.assign(V, 0);
  vis.assign(V, 0);
  FR(i, V) {
    if (num[i] == UNVISITED) {
      scc(i);
    }
  }
}
}  // namespace StronglyConnectedComponents

// Sieve + optimized prime testing
ll sz;
bitset<10000010> p;
vi primes;
void sieve(ll m) {
  sz = m + 1;
  p.set();
  p[0] = p[1] = 0;
  for (ll i = 2; i <= sz; i++)
    if (p[i]) {
      for (ll j = i * i; j <= sz; j += i) p[j] = 0;
      primes.push_back((int)i);
    }
}
bool isPrime(ll x) {
  if (x <= sz) return p[x];
  for (int i = 0; i < (int)primes.size(); i++)
    if (x % primes[i] == 0) return false;
  return true;
}

// Topological Sort - Print all top sorts
namespace TopologicalSortPrintAll {
void printAllTS(vi &res, vii &vind, vvi &g) {
  bool d = true;
  for (int i = 0; i < g.size(); i++) {
    if (vind[i] == ii(0, 0)) {
      for (auto &j : g[i]) vind[j].second--;
      vind[i] = ii(1, 0);
      res.push_back(i);
      printAllTS(res, vind, g);
      for (auto &j : g[i]) vind[j].second++;
      vind[i] = ii(0, 0);
      res.pop_back();
      d = false;
    }
  }
  if (d) {
    for (auto &i : res) cout << i << " ";
    cout << endl;
  }
}

void allTS(vvi &g) {
  vii vind(g.size(), ii(0, 0));  // 2nd is pair (visible, indegree)
  for (int i = 0; i < g.size(); i++)
    for (auto &v : g[i]) vind[v].second++;
  vi res;
  printAllTS(res, vind, g);
}
}  // namespace TopologicalSortPrintAll

// Find Tree Diameter
namespace TreeDiameter {
// graph representation of our tree, as an adjacency list
vvi g;

// Returns a pair<int, int>, first is the greatest depth found
// from 's', second is the node ID where that depth was found.
ii dfs(int s, int e) {
  ii b = ii(0, s);
  for (auto &u : g[s]) {
    // only recurse on children (i.e. below 'u')
    if (u != e) {
      ii x = dfs(u, s);
      x.first++;

      // update, if greatest depth seen so far
      if (x.first > b.first) b = x;
    }
  }
  return b;
}

void tree_diameter() {
  ii b = dfs(0, 0);
  ii c = dfs(b.second, b.second);
  cout << "diameter is " << c.first << ", found between nodes " << b.second
       << " and " << c.second << endl;
}
}  // namespace TreeDiameter

// Union Find (Disjoint Set)
namespace UnionFind {
class UF {
 public:
  vi p, r;
  UF(int n) {
    p.assign(n, 0);
    iota(begin(p), end(p), 0);
    r.assign(n, 0);
  }
  int find(int i) { return (p[i] == i ? i : (p[i] = find(p[i]))); }
  bool same(int i, int j) { return find(i) == find(j); }
  void merge(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (r[x] > r[y])
        p[y] = x;
      else {
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
      }
    }
  }
};
}  // namespace UnionFind

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << numeric_limits<int>::max() << endl;
  cout << ~(1 << 31) << endl;
}
