// Problem #    : 526
// Created on   : 2018-05-30 20:11:09
// Title        : String Distance and Transform Process
// Accepted     : No

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

const int MATCH = 2;
const int MISMATCH = -1;
const int INDEL = -1;

string a, b;
const int NN = 81;

int dp[NN][NN];

vector<ii> v[NN][NN];

int f(int i, int j) {
  if (i == 0 && j == 0) {
    return 0;
  } else if (i == 0) {
    return j * INDEL;
  } else if (j == 0) {
    return i * INDEL;
  }

  int x = dp[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? MATCH : MISMATCH);
  int y = dp[i - 1][j] + INDEL;
  int z = dp[i][j - 1] + INDEL;

  int maxx = max(x, max(y, z));
  if (x == maxx) {
    v[i][j].push_back(make_pair(i - 1, j - 1));
  }
  if (y == maxx) {
    v[i][j].push_back(make_pair(i - 1, j));
  }
  if (z == maxx) {
    v[i][j].push_back(make_pair(i, j - 1));
  }

  return max(x, max(y, z));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (getline(cin, a) && getline(cin, b)) {
    for (int i = 0; i < NN; i++) {
      for (int j = 0; j < NN; j++) {
        v[i][j].clear();
      }
    }

    int ii = (int)a.length();
    int jj = (int)b.length();
    for (int i = 0; i <= ii; i++) {
      for (int j = 0; j <= jj; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = f(i, j);
          if (i > 0) {
            v[i][j].push_back(make_pair(i - 1, j));
          } else if (j > 0) {
            v[i][j].push_back(make_pair(i, j - 1));
          }
        }
      }
    }

    for (int i = 1; i <= ii; i++) {
      for (int j = 1; j <= jj; j++) {
        dp[i][j] = f(i, j);
      }
    }

    // for (int i = 0; i <= ii; i++) {
    //   for (int j = 0; j <= jj; j++) {
    //     cout << setw(3) << dp[i][j];
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    // cout << dp[ii][jj] << endl;

    // cout << "path:" << endl;
    int i = ii, j = jj;
    stack<string> stk;
    while (i >= 0 && j >= 0) {
      // cout << "i, j : " << i << ", " << j << endl;
      if (v[i][j].empty()) {
        // cout << "empty\n";
        break;
      }

      pair<int, int> p = v[i][j][0];

      // diagonal
      string s = "";
      if (abs(p.first - i) == abs(p.second - j)) {
        // if match, do nothing
        // if mismatch, print replace
        if (a[i - 1] != b[j - 1]) {
          s += "Replace " + to_string(i) + "," + b[j - 1];
          // cout << p.first << " Replace " << i << ", j = " << j;
          // cout << ", a[i-1], b[j-1] : " << a[i - 1] << ", " << b[j - 1] <<
          // endl;
        }
      } else if (p.first == i) {
        s += "Insert " + to_string(i) + "," + b[j - 1];
        // cout << p.first << " Insert " << i << endl;
      } else if (p.second == j) {
        s += "Delete " + to_string(i);
        // cout << p.first << " Delete " << i << endl;
      }

      if (s != "") {
        stk.push(s);
      }

      i = p.first;
      j = p.second;
    }

    int cmd_cnt = 1;
    int del = 0;
    int ins = 0;
    cout << (int)stk.size() << endl;
    while (!stk.empty()) {
      stringstream ss(stk.top());
      stk.pop();

      string s;
      int x;
      ss >> s >> x;
      cout << cmd_cnt++ << " ";
      if (s == "Delete") {
        cout << s << " " << x - del + ins;
        del++;
      } else if (s == "Replace") {
        cout << s << " ";
        ss >> s;
        cout << x - del + ins << s;
      } else if (s == "Insert") {
        cout << s << " ";
        ss >> s;
        cout << x - del + ins + 1 << s;
        ins++;
      }
      cout << endl;
    }

    // int i = ii, j = jj;
    // while (i != 0 && j != 0) {
    //   int x = dp[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? MATCH : MISMATCH);
    //   int y = dp[i - 1][j] + INDEL;
    //   int z = dp[i][j - 1] + INDEL;
    // }
  }

  return 0;
}
