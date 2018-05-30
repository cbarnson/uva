// Problem #    : 102
// Created on   : 2018-05-29 19:17:09
// Title        : Ecological Bin Packing
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

string z = "BCG"; // lexicographical order
string y = "012";

int moves(int a[][3], int b[])
{
  int ans = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (j == b[i])
      {
        continue;
      }

      ans += a[i][j];
    }
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a[3][3] = {0};

  string s;
  while (getline(cin, s) && s != "")
  {
    stringstream ss(s);

    for (int i = 0; i < 3; i++)
    {
      // adjust our read order to make it work with next_permutation,
      // which wants to start from '012' ==> 'BCG'
      // Read order is Brown, Green, Clear
      ss >> a[i][0] >> a[i][2] >> a[i][1];
    }

    int b[3] = {0, 1, 2};
    int c[3] = {0};
    int minn = pow(2, 31) - 1;
    do
    {
      int ans = moves(a, b);
      if (ans < minn)
      {
        minn = ans;
        copy(b, b + 3, c);
      }
      else if (ans == minn)
      {
        if (lexicographical_compare(b, b + 3, c, c + 3))
        {
          minn = ans;
          copy(b, b + 3, c);
        }
      }
    } while (next_permutation(b, b + 3));

    for_each(c, c + 3, [&](int x) {
      cout << z[x];
    });
    cout << " " << minn << "\n";
  }

  return 0;
}
