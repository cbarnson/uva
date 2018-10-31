// Problem #    : 349A
// Created on   : 2018-Oct-30 23:58:37
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int bill[2] = {};
  FR(i, n) {
    int x;
    cin >> x;
    if (x == 25)
      bill[0]++;
    else if (x == 50)
      bill[1]++;

    int y = x - 25;
    while (y >= 50 && bill[1]) bill[1]--, y -= 50;
    while (y >= 25 && bill[0]) bill[0]--, y -= 25;
    if (y > 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
