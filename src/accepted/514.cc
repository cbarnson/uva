// Problem #    : 514
// Created on   : 2018-06-03 00:01:38

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// e.g. int varX = 376; what_is(varX); prints "varX is 376"
// e.g. what_is(varX * 2 + 1); prints "varX * 2 + 1 is 753"
#define what_is(x) cerr << #x << " is " << x << endl;

// e.g. rep(i, 1, 10) is 1, 2, ..., 8, 9 and rep(i, 10, 1) is 9, 8, ..., 2, 1
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
bool isPalidrome(string s) {
  return equal(s.begin(), next(s.begin(), s.size() / 2), s.rbegin());
}

bool onFront(queue<int>& q, int x) {
  if (q.empty()) {
    return false;
  } else if (q.front() != x) {
    return false;
  }
  return true;
}

bool onTop(stack<int>& s, int x) {
  if (s.empty())
    return false;
  else if (s.top() != x)
    return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  while (n != 0) {
    int x;
    cin >> x;
    if (x == 0) {
      cin >> n;
      cout << endl;
      continue;
    }
    queue<int> q;
    vector<int> v(n);
    v[0] = x - 1;
    for (int i = 1; i < n; i++) {
      cin >> x;
      v[i] = x - 1;
    }

    stack<int> s;

    for (int i = 0; i < n; i++) {
      q.push(i);
    }

    int i;
    for (i = 0; i < n; i++) {
      if (!onTop(s, v[i])) {
        while (!onFront(q, v[i]) && !q.empty()) {
          int tmp = q.front();
          q.pop();
          s.push(tmp);
        }

        if (onFront(q, v[i])) {
          q.pop();
          continue;
        } else {
          break;
        }
      } else {
        s.pop();
      }
    }

    if (i < n) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }

  return 0;
}
