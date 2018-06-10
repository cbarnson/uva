// Problem #    : 10260
// Created on   : 2018-06-10 00:51:18

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

string key = "BFPVCGJKQSXZDTLMNRAEIOUHWY";
string val = "11112222222233455600000000";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (getline(cin, s) && s != "") {
    string ans = "";

    for_each(s.begin(), s.end(), [&](char c) {
      auto j = key.find(c);
      if (j != string::npos) {
        ans += val[j];
      }
    });

    auto i = unique(ans.begin(), ans.end());
    ans.erase(i, ans.end());

    auto j = remove_if(ans.begin(), i, [](char c) { return c == '0'; });
    ans.erase(j, ans.end());

    cout << ans << endl;
  }

  return 0;
}
