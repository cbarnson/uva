#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  if ((int)s.length() & 1) {
    cout << -1 << endl;
    return 0;
  }

  map<char, int> mp;
  for (auto c : string("LRUD")) {
    mp[c] = count(begin(s), end(s), c);
  }

  cout << (abs(mp['L'] - mp['R']) + abs(mp['U'] - mp['D'])) / 2 << endl;
}
