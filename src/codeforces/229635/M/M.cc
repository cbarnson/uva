#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  ll x = 1;
  for (int i = 0; i < n && x < m; i++)
    x *= 2;
  if (x <= m)
    cout << m % x << endl;
  else
    cout << m << endl;
}
