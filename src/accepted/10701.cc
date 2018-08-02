// Problem #    : 10701
// Created on   : 2018-08-01 22:06:10

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

string in;
queue<char> pre;
int j = 0;

void post(int l, int r, queue<char> &pre) {
  if (l >= r) {
    return;
  }

  if (r - l == 1) {
    cout << in[l];
    if (pre.front() == in[l]) {
      pre.pop();
    }
    return;
  }

  int i = find(in.begin(), in.end(), pre.front()) - in.begin();
  pre.pop();

  post(l, i, pre);
  post(i + 1, r, pre);
  cout << in[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int len;
    j = 0;
    string pp;
    cin >> len >> pp >> in;

    queue<char> pre;
    for (auto &i : pp) {
      pre.push(i);
    }

    post(0, len, pre);
    cout << endl;
  }

  return 0;
}
