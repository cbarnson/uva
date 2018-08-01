// Problem #    : 10935
// Created on   : 2018-07-31 21:44:58

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

typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints
typedef vector<vii> vvii;  // 2d vector of pairs
typedef vector<bool> vb;   // 1d vector of bools
typedef long long ll;

ostream &operator<<(ostream &os, vi &v) {
  for (auto &i : v)
    os << i << " ";
  os << endl;
}

void f(int n) {
  list<int> d(n);
  iota(d.begin(), d.end(), 1);
  printf("Discarded cards:");
  while (d.size() > 1) {
    if (d.size() > 2) {
      printf(" %d,", d.front());
    } else {
      printf(" %d", d.front());
    }

    d.pop_front();
    d.push_back(d.front());
    d.pop_front();
  }
  printf("\nRemaining card: %d\n", d.front());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (scanf("%d ", &n)) {
    if (n == 0) break;
    f(n);    
  }
  
  return 0;
}
