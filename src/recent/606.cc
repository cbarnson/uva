// Problem #    : 606
// Created on   : 2018-08-01 21:05:22

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

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vvi g(26, vi());
    vector<vector<char>> gc(26, vector<char>());

    REP(i, n) {
      char c, cc;
      cin >> ws >> c >> cc >> ws;
      if (cin.peek() == 'z') {
        char a, b;
        string s;
        cin >> s >> a >> b;
        gc[c - 'A'].push_back(a);
        gc[c - 'A'].push_back(b);
        continue;
      }

      int x;
      while (!isalpha(cin.peek())) {
        cin >> x >> ws;
        g[c - 'A'].push_back(x);
      }

      cin >> cc;
      gc[c - 'A'].push_back(cc);
    }

    for (int i = 0; i < 26; i++) {
      cout << (char)(i + 'A') << " =";
      for (auto &j : g[i]) {
        cout << " " << j;
      }
      for (auto &j : gc[i]) {
        cout << " " << j;
      }
      cout << endl;
    }

    REP(i, m) {
      char c;
      int s, e;
      cin >> ws >> c >> s >> e;
      int d = e - s;

      queue<int> ans;
      queue<char> q;
      q.push(c);
      int ii = 0;

      while (ii < e) {
        char f = q.front();
        q.pop();

        for (auto &j : g[f - 'A']) {
          ans.push(j);
          ii++;
          if (ans.size() > d) {
            ans.pop();
          }
        }
        for (auto &j : gc[f - 'A']) {
          q.push(j);
        }
      }

      cout << "done, ans.size = " << ans.size() << endl;
      while (!ans.empty()) {
        cout << ans.front();
        ans.pop();
        if (!ans.empty()) {
          cout << " ";
        }
      }
    }
  }

  return 0;
}
