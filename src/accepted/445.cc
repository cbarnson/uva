// Problem #    : 445
// Created on   : 2018-05-25 00:25:42
// Title        : Marvelous Mazes
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

const int NN = 140;

char g[NN][NN];
int i, j;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  while (cin.get(c))
  {
    if (c == '!' || c == '\n')
    {
      cout << '\n';
      continue;
    }

    int x = 0;
    while (c <= '9' && c >= '0')
    {
      x += (int)(c - '0');
      cin.get(c);
    }

    if (c == 'b')
    {
      for (int i = 0; i < x; i++)
      {
        cout << ' ';
      }
    }
    else
    {
      for (int i = 0; i < x; i++)
      {
        cout << c;
      }
    }
  }

  return 0;
}
