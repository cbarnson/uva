
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define mt make_tuple
#define eb emplace_back

// First of all, you don't need to name the type you want to use. Second of all
// it goes forwards and backwards based on (begin > end) condition. e.g. rep(i,
// 1, 10) is 1, 2, ..., 8, 9 and rep(i, 10, 1) is 9, 8, ..., 2, 1
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef tuple<int, int, int> State; // operator< defined

// #define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
// #define rep(i, n)                forab (i, 0, (n) - 1)
// #define For(i, n)                forab (i, 1, n)
// #define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
// #define per(i, n)                rofba (i, 0, (n) - 1)
// #define rof(i, n)                rofba (i, 1, n)
// #define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i !=
// (s).end (); ++i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c;
  tie(a, b, c) = mt(1, 2, 3); // assign
  tie(a, b) = mt(b, a);       // swap(a,b)

  vector<pair<int, int>> v;
  v.eb(a, b); // shorter and faster than pb(mp(a,b))

  // Dijkstra
  priority_queue<tuple<int, int, int>> q;
  int src = 0;
  q.emplace(0, src, -1);
  while (q.size()) {
    int dist, node, prev;
    tie(dist, node, prev) = q.top();
    q.pop();
    dist = -dist;
    // ~~ find next state ~~
    int new_dist, new_node;
    q.emplace(-new_dist, new_node, node);
  }

  // use ignore in tie to ignore it
  tuple<int, int, int, char> t(3, 4, 5, 'g');
  int a, b;
  tie(b, ignore, a, ignore) = t;
  cout << a << ' ' << b << '\n';

  // -------------
  auto f = [](int a, int b) -> int { return a + b; };
  cout << f(1, 2); // prints "3"

  // -----------------
  // copy and copy_n skips the separators (by default: spaces and carriage
  // returns).
  int N = 10;
  copy_n(istream_iterator<int>(cin), N, begin(v));

  // Another improvement consists in not reading the input at all. We can
  // actually just use accumulate on istream iterators
  accumulate(istream_iterator<int>(cin), istream_iterator<int>(), 0);

  // However, we should skip the first number, that is the size of the vector
  // that will be passed. A simple way to do that consists in using std::next
  cout << accumulate(next(istream_iterator<int>(cin)), istream_iterator<int>(),
                     0);
}
