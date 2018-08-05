// Problem #    : 259
// Created on   : 2018-08-04 18:21:03

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define REP2(i, j, n) REP(i, n) REP(j, n)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
#define L first
#define R second

using namespace std;

template <typename T>
void printList(initializer_list<T> l) {
  for (const auto &i : l) cout << i << ' ';
  cout << endl;
}

// variadic function
int sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) {
  return a + sum(args...);
}

typedef long long ll;
typedef pair<int, int> ii;  // pair of ints
typedef vector<bool> vb;    // 1d vector of bools
typedef vector<int> vi;     // 1d vector of ints
typedef vector<ii> vii;     // 1d vector of pairs
typedef vector<vi> vvi;     // 2d vector of ints
typedef vector<vii> vvii;   // 2d vector of pairs

#define MV 38
#define INF 0x3f3f3f3f

int res[MV][MV], mf, f, s, t;
vi p;
vector<vi> g;

void augment(int v, int lo) {
  if (v == s) {
    f = lo;
    return;
  } else if (p[v] != -1) {
    augment(p[v], min(lo, res[p[v]][v]));  // recursive
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
}

int main() {
  // process each case
  while (1) {
    // 'res' must be initialized to 0
    memset(res, 0, sizeof res);

    // note: two extra nodes for source and sink => 1 + 26 + 10 + 1 = 38
    s = 0, t = MV - 1;

    // 'cnt' is the total count of 'app' to 'computer' mappings for each 'app'
    int cnt = 0;
    string l;
    while (getline(cin, l) && l != "") {
      stringstream ss(l);
      int u, v, w;
      u = l[0] - 'A' + 1, w = l[1] - '0';
      res[0][u] = w;
      cnt += w;

      // last character in 'l' is ';', ignore that one
      for (int i = 3; i < l.length() - 1; i++) {
        v = l[i] - '0' + 27;
        res[u][v] = INF;
      }
    }

    // exit condition, no case to process
    if (cnt == 0) break;

    // comp to sink
    for (int i = 27; i < MV; i++) {
      res[i][t] = 1;
    }

    // begin our max-flow algorithm
    mf = 0;
    while (1) {
      // 'f' is the min edge weight for this BFS iteration
      f = 0;

      // must reset all the parent identifiers, and initialize visited array
      p.assign(MV, -1);
      vi vis(MV, 0);
      vis[s] = true;

      // BFS
      queue<int> q;
      q.push(s);
      while (!q.empty()) {
        int u = q.front();
        q.pop();

        // reach the sink 't', must stop
        if (u == t) break;
        REP(v, MV) {
          if (res[u][v] > 0 && !vis[v]) {
            vis[v] = true, q.push(v), p[v] = u;
          }
        }
      }
      augment(t, INF);
      if (f == 0) break;
      mf += f;
    }

    if (mf == cnt) {
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++) {
          if (res[i + 27][j + 1] == 1) {
            cout << (char)(j + 'A');
            goto next;
          }
        }
        cout << '_';
      next:;
      }
      cout << "\n";
    } else {
      cout << "!\n";
    }
  }

  return 0;
}