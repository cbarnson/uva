// Problem #    : 119
// Created on   : 2018-06-12 22:16:15

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

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, tc = 1;
  while (cin >> n) {
    if (tc > 1) {
      cout << endl;
    }
    tc++;
    vector<int> net(n, 0);
    vector<string> names;
    map<string, int> m;

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s >> ws;
      names.push_back(s);
      m.insert(make_pair(s, i));
    }

    for (int i = 0; i < n; i++) {
      string a, b;
      int amt, num, k;
      cin >> a >> amt >> num;
      k = m[a];

      if (num == 0) {
        continue;
      } else if (amt == 0 || ((amt / num) == 0)) {
        while (num--) cin >> b;
        continue;
      }

      net[k] = net[k] - amt + (amt - ((amt / num) * num));
      for (int j = 0; j < num; j++) {
        cin >> b;
        k = m[b];
        net[k] += (amt / num);
      }
    }

    // answer
    for (int i = 0; i < n; i++) {
      cout << names[i] << " " << net[i] << endl;
    }
  }

  return 0;
}
