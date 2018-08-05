// Problem #    : 571
// Created on   : 2018-08-02 02:37:12

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

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

template <typename T> void printList(initializer_list<T> l) {
  for (const auto &i : l)
    cout << i << ' ';
  cout << endl;
}

// variadic function
int sum() { return 0; }
template <typename T, typename... Args> T sum(T a, Args... args) {
  return a + sum(args...);
}

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools

#define MM 1005

int max_A, max_B;
int seen[MM][MM] = {0};

bool isValid(int a, int b) {
  if (a < 0 || a > max_A || b < 0 || b > max_B || seen[a][b])
    return false;
  return true;
}

ii next(int a, int b, int k) {
  ii D[] = {ii(max_A, b), ii(a, max_B), ii(0, b), ii(a, 0)};
  if (k < 4) {
    return D[k];
  } else if (k == 4) {
    while (a > 0 && b < max_B) {
      a--;
      b++;
    }
    return ii(a, b);
  } else {
    while (b > 0 && a < max_A) {
      b--;
      a++;
    }
    return ii(a, b);
  }
}

int N;
string s[] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};
list<string> best;
void backtrack(int a, int b, list<string> &cmds) {

  if (b == N) {
    if (best.empty() || (int)best.size() > (int)cmds.size()) {
      best.assign(cmds.begin(), cmds.end());
    }
    return;
  }

  REP(i, 6) {
    ii delta = next(a, b, i);
    if (isValid(delta.first, delta.second)) {

      seen[delta.first][delta.second] = 1;
      cmds.push_back(s[i]);

      backtrack(delta.first, delta.second, cmds);
      seen[delta.first][delta.second] = 0;
      cmds.pop_back();
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> max_A >> max_B >> N) {
    REP(i, MM) {
      REP(j, MM) { seen[i][j] = 0; }
    }
    best.clear();

    list<string> cmds;
    seen[0][0] = 1;
    backtrack(0, 0, cmds);

    FOR(i, best) { cout << *i << endl; }
    cout << "success" << endl;
  }

  return 0;
}
