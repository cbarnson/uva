// Problem #    : t2
// Created on   : 2018-11-01 08:18:07
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  stringstream ss("1 2 3 4 5 -1");
  vi a;
  copy_n(istream_iterator<int>(ss), 4, back_inserter(a));

  copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
}
