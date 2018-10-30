// Cody Barnson
// 5738 - Robot Navigation
#include <bits/stdc++.h>
using namespace std;

const int MM = 1000;
const int NN = 1000;

int xt, yt, xs, ys, ds;
int m, n;
uint64_t modfactor;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

// namespace N {
// typedef std::tuple<int, int, int> key_t;
// struct key_hash : public std::unary_function<key_t, std::size_t> {
//   std::size_t operator()(const key_t& k) const {
//     return std::get<0>(k) ^ std::get<1>(k) ^ std::get<2>(k);
//     // ^ std::get<3>(k) ^
//     //       std::get<4>(k) ^ std::get<5>(k);
//   }
// };
// struct key_equal : public std::binary_function<key_t, key_t, bool> {
//   bool operator()(const key_t& v0, const key_t& v1) const {
//     return (std::get<0>(v0) == std::get<0>(v1) &&
//             std::get<1>(v0) == std::get<1>(v1) &&
//             std::get<2>(v0) == std::get<2>(v1));
//     //  &&
//     // std::get<3>(v0) == std::get<3>(v1) &&
//     // std::get<4>(v0) == std::get<4>(v1) &&
//     // std::get<5>(v0) == std::get<5>(v1));
//   }
// };
// struct data {
//   int x, ways;
// };
// typedef std::unordered_map<const key_t, data, key_hash, key_equal> map_t;
// }
// using namespace N;

struct data {
  int x, ways;
};
typedef tuple<int, int, int> tstate;
// unordered_map<tstate, int> seen;
typedef map<tstate, pair<int, int> > map_t;
map_t seen;

struct state {
  int cost, i, j, d;
  state(int row, int col, int dir, int c) : i(row), j(col), d(dir), cost(c) {}
  void print() const {
    cout << "(state: " << i << ", " << j << ", " << d << ", " << cost << ")";
  }
  bool operator<(const state& s) const { return cost > s.cost; }
};

char grid[MM][NN];
// int ways[MM][NN];

void printGrid(int x, int y) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == x && j == y)
        cout << "S";
      else if (i == xt && j == yt)
        cout << "T";
      else
        cout << grid[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void init() {
  for (int i = 0; i < MM; i++) {
    for (int j = 0; j < NN; j++) {
      grid[i][j] = '*';
      // ways[i][j] = 0;
    }
  }
  seen.clear();
}

bool isInBound(const state& s) {
  if (s.i < 0 || s.i >= m || s.j < 0 || s.j >= n) return false;
  if (grid[s.i][s.j] == '*') return false;
  return true;
}

void expand(const state& from, const state& to, queue<state>& q) {
  if (isInBound(to)) {
    auto itf = seen.find(make_tuple(from.i, from.j, from.d));
    assert(itf != seen.end());

    // if exists, and new is higher cost, don't add
    auto entry = make_tuple(to.i, to.j, to.d);
    auto it = seen.find(entry);
    if (it != seen.end()) {  // this state has been seen before

      int prevCost = it->second.first;
      int currCost = to.cost;
      if (to.cost == prevCost) {  // this new state converges with existing
        // update the number of ways we can reach this new state, but do not
        // add the new state, it's already in circulation in our algorithm
        // cout << "state ";
        // from.print();
        // cout << " converges with ";
        // to.print();
        // // it->second.ways += itf->second.ways;

        it->second.second += itf->second.second;

      } else if (to.cost > prevCost) {  // not in the shortest path, don't add

      } else {  // is shorter than existing, should not happen
        assert(0);
      }
    } else {  // this state has NOT been seen before, add new state, update ways
              // to get here
      // cout << itf->second.second << "---\n";
      seen[entry] = make_pair(to.cost, itf->second.second);
      q.push(to);
      // ways should just be equal the number of ways we can get to the from
      // state
    }
  }
}

void expandChildren(const state& from, queue<state>& q) {
  // not at destination, but valid state.  Add outgoing 'edge' states.  Move
  // forward relative to the current position, turn 'right' or forward in
  // direction, and turn 'left' or backward in direction (circularly).
  state s1 =
      state(from.i + di[from.d], from.j + dj[from.d], from.d, from.cost + 1);
  state s2 = state(from.i, from.j, (from.d + 1) % 4, from.cost + 1);
  state s3 = state(from.i, from.j, (from.d + (4 - 1)) % 4, from.cost + 1);
  expand(from, s1, q);
  expand(from, s2, q);
  expand(from, s3, q);
}

uint64_t solve(uint64_t& totalWays) {
  // priority_queue<state> pq;
  queue<state> pq;
  state start = state(xs, ys, ds, 0);
  pq.push(start);

  seen[make_tuple(xs, ys, ds)] = make_pair(0, 1);

  totalWays = 0;
  int64_t shortestPath;
  bool hasPath = false;

  while (!pq.empty()) {
    state ss = pq.front();
    pq.pop();

    // if at target state, we are done.
    if (ss.i == xt && ss.j == yt) {
      auto it = seen.find(make_tuple(ss.i, ss.j, ss.d));
      if (it != seen.end()) {
        // first time?
        if (!hasPath) {
          shortestPath = it->second.first;
          totalWays = it->second.second;
          totalWays = (totalWays % modfactor);
          hasPath = true;
        } else {
          // update condition
          if (it->second.first > shortestPath) {
            return totalWays;
          } else if (it->second.first == shortestPath) {
            totalWays += it->second.second;
            totalWays = (totalWays % modfactor);
          } else {
            shortestPath = it->second.first;
            totalWays = it->second.second;
            totalWays = (totalWays % modfactor);
          }
        }
      }
      continue;
    }

    expandChildren(ss, pq);
  }
  // cout << "outside of loop" << endl;
  return hasPath;
  // return solns;
}

int main() {
  int cn = 1;
  while (cin >> m >> n >> modfactor >> ws) {
    if (m == 0 || n == 0 || modfactor == 0) break;

    init();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
      cin >> ws;
    }

    char dir;
    cin >> xs >> ys >> xt >> yt >> dir >> ws;
    if (dir == 'N')
      ds = 0;
    else if (dir == 'E')
      ds = 1;
    else if (dir == 'S')
      ds = 2;
    else
      ds = 3;

    uint64_t ans = 0;
    cout << "Case " << cn++ << ": " << modfactor << " ";
    if (solve(ans)) {
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}