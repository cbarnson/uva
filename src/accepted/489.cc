// Problem #    : 489
// Created on   : 2018-06-12 21:55:18

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

  int r;
  string soln, guess;
  while (cin >> r) {
    // cout << "---" << endl;
    if (r == -1) {
      break;
    }
    cout << "Round " << r << endl;
    cin >> soln >> guess;

    // cout << "--" << soln << ", " << guess << endl;

    map<char, int> m;
    int total = (int)soln.length();
    for_each(soln.begin(), soln.end(), [&](char c) {
      if (m.count(c) > 0) {
        m[c] += 1;
      } else {
        m.insert(make_pair(c, 1));
      }
    });

    set<char> tried;
    int wrong = 0;
    for (int i = 0; i < (int)guess.length(); i++) {
      if (tried.count(guess[i]) > 0) {
        continue;
      }

      if (m.count(guess[i]) > 0) {
        total -= m[guess[i]];
      } else {
        wrong += 1;
      }

      if (wrong == 7 || total <= 0) {
        break;
      }

      tried.insert(guess[i]);
    }

    // answer
    if (wrong >= 7) {
      cout << "You lose." << endl;
    } else if (total <= 0) {
      cout << "You win." << endl;
    } else {
      cout << "You chickened out." << endl;
    }
  }

  return 0;
}
