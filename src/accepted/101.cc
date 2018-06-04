// Problem #    : 101
// Created on   : 2018-06-03 18:18:52

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
#define what_is(x) cout << #x << " is " << x << endl;

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

const int NN = 25;
list<int> al[NN];
int pos[NN];

bool isLegal(int a, int b) {
  if (a == b || pos[a] == pos[b]) {
    return false;
  }
  return true;
}

void toInitial(int a) {
  auto i = find(al[pos[a]].begin(), al[pos[a]].end(), a);
  if (i == al[pos[a]].end()) {
    return;
  }
  ++i;
  if (i == al[pos[a]].end()) {
    return;
  }
  for_each(i, al[pos[a]].end(), [](int x) {
    al[x].push_back(x);
    pos[x] = x;
  });
  auto d = distance(i, al[pos[a]].end());
  for (int j = 0; j < d; j++) {
    al[pos[a]].pop_back();
  }
}

int n;
void print(int n) {
  for (int i = 0; i < n; i++) {
    cout << i << ":";
    for (auto& j : al[i]) {
      cout << " " << j;
    }
    cout << endl;
  }
}

void moveOnto(int a, int b) {
  al[pos[b]].push_back(a);
  al[pos[a]].pop_back();
  pos[a] = pos[b];
}

void spliceOnto(int a, int b) {
  auto i = find(al[pos[a]].begin(), al[pos[a]].end(), a);
  al[pos[b]].splice(al[pos[b]].end(), al[pos[a]], i, al[pos[a]].end());
  auto j = find(al[pos[b]].begin(), al[pos[b]].end(), a);
  for_each(j, al[pos[b]].end(), [&](int x) { pos[x] = pos[b]; });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  string s1, s2;
  cin >> n;
  iota(pos, pos + n, 0);
  for (int i = 0; i < n; i++) {
    al[i].push_back(i);
  }

  int db = 1;

  while (cin >> s1) {
    if (s1 == "quit") {
      print(n);
      break;
    }

    cin >> a >> s2 >> b;

    if (!isLegal(a, b)) {
      continue;
    }

    if (s1 == "move" && s2 == "onto") {
      toInitial(a);
      toInitial(b);
      moveOnto(a, b);
    } else if (s1 == "move" && s2 == "over") {
      toInitial(a);
      moveOnto(a, b);
    } else if (s1 == "pile" && s2 == "onto") {
      toInitial(b);
      spliceOnto(a, b);
    } else if (s1 == "pile" && s2 == "over") {
      spliceOnto(a, b);
    }
  }

  return 0;
}
