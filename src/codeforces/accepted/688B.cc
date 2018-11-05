// Problem #  : 688B
// Created on : 2018-Nov-03 09:23:33
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  cout << s;
  reverse(begin(s), end(s));
  cout << s << endl;
  
}
