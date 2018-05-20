// Problem #    : 977-D
// Title        : D. Divide by three, multiply by two
// Accepted     : Yes
// Date         : 20180519

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

typedef long long ll;

// get the ll value of the nth digit of x
// e.g. 12345
// digitAt(12345, 0) = 5
// digitAt(12345, 1) = 4
// digitAt(12345, 2) = 3
// digitAt(12345, 3) = 2
// digitAt(12345, 4) = 1
// digitAt(12345, 5) = 0
// Wayyyy faster --> 1.912 seconds to execute compared to 17.25 for digitAtUsingString
ll digitAt(ll x, ll n)
{
  return (ll)(x / pow(10, n)) % 10;
}

bool isDivisibleBy3(ll x)
{

  string s = to_string(x);
  ll sum = 0;
  for (ll i = 0; i < (ll)s.length(); i++)
  {
    sum += (ll)(s[i] - '0');
  }
  return sum % 3 == 0;
}

ll digitAtUsingString(ll x, ll n)
{
  string s = to_string(x);
  return s[n] - '0';
}

ll countDigit(long long n)
{
  return n > 0 ? (ll)log10((double)n) + 1 : 1;
}

int main()
{
  ll n;
  while (cin >> n)
  {
    // Adjacency list
    vector<vector<ll>> a(n, vector<ll>(1));
    // vector<vector<ll>> r(n, vector<ll>(1));
    // key    --> value in sequence,
    // value  --> index
    map<ll, ll> m;

    for (ll i = 0; i < n; i++)
    {
      ll x;
      cin >> x;
      a[i][0] = x;
      // r[i][0] = x;

      // cin >> a[i];
      m[a[i][0]] = i;
    }

    vector<ll> indeg(n, 0);

    // for each element b[i], where i = 0 to i = n - 1, a directed edge exists from
    // the ith element in 'a', to the m[b[i]]-th element in 'a'
    for (ll i = 0; i < n; i++)
    {
      ll ansMult2 = a[i][0] * 2;
      if (m.count(ansMult2) > 0)
      {
        a[i].push_back(ansMult2);
        indeg[m[ansMult2]]++;
        // r[m[ansMult2]].push_back(a[i][0]);
      }
      if (isDivisibleBy3(a[i][0]))
      {
        ll ansDiv3 = a[i][0] / 3;
        if (m.count(ansDiv3) > 0)
        {
          // a[m[ansDiv3]].push_back(a[i][0]);
          a[i].push_back(ansDiv3);
          indeg[m[ansDiv3]]++;
        }
      }
    }

    // prll
    // for (ll i = 0; i < n; i++)
    // {
    //   for (ll j = 0; j < a[i].size(); j++)
    //   {
    //     cout << m[a[i][j]] << " ";
    //   }
    //   cout << endl;
    // }

    // prll indeg
    // for (ll i = 0; i < n; i++)
    // {
    //   cout << "indeg[" << i << "]: " << indeg[i] << endl;
    // }

    // find src, with indegree 0
    ll src = -1;
    for (ll i = 0; i < n; i++)
    {
      if (indeg[i] == 0)
      {
        src = i;
        break;
      }
    }

    // cout << "src: " << src << endl;

    cout << a[src][0];
    while (a[src].size() > 1)
    {
      cout << " " << a[src][1];
      src = m[a[src][1]];
    }
    cout << endl;
  }

  return 0;
}

// for (ll i = 0; i < 100; i++)
// {
//   cout << i << " : ";
//   if (isDivisibleBy3(i))
//   {
//     cout << "yes";
//   }
//   else
//   {
//     cout << "no";
//   }
//   cout << endl;
// }