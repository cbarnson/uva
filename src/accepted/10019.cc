// Problem #    : 10019
// Created on   : 2018-05-30 22:51:12
// Title        : Funny Encryption Method
// Accepted     : Yes

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

  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;

    bitset<32> n(m);
    stringstream ss;
    ss << m;
    auto hx = stol(ss.str(), nullptr, 16);
    bitset<32> bhx(hx);

    cout << (int)n.count() << " " << (int)bhx.count() << endl;
  }

  return 0;
}
