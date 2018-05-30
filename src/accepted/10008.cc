// Problem #    : 10008
// Created on   : 2018-05-29 20:25:25
// Title        : What's Cryptanalysis?
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

bool isChar(char c)
{
  return (c >= 'A' && c <= 'Z');
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n)
  {
    cin.ignore();
    string s = "", line;
    for (int i = 0; i < n; i++)
    {
      getline(cin, line);
      s += line;
    }

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    map<char, int> m;
    for (int i = 0; i < (int)s.length(); i++)
    {
      if (isChar(s[i]))
      {

        if (m.count(s[i]) > 0)
        {
          m[s[i]] += 1;
        }
        else
        {
          m.insert(make_pair(s[i], 1));
        }
      }
    }

    vector<pair<int, char>> v;
    for (auto &i : m)
    {
      v.push_back(make_pair(i.second, i.first));
    }

    sort(v.begin(), v.end(), [](const pair<int, char> &l, const pair<int, char> &r) {
      return (l.first > r.first || (l.first == r.first && l.second < r.second));
    });
    for (auto &i : v)
    {
      cout << i.second << " " << i.first << "\n";
    }
  }

  return 0;
}
