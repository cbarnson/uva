#include <bits/stdc++.h>
using namespace std;

// house numbers will not exceed 1 mil, main street
// 'block' starts at 0, so high end of bsearch can
// start from 1 mil
const double MAX = 1000000.0;

// want answer to the nearest tenth
const double EPS = 0.01;

// given some distance d (think of as a radius) and
// number of access points n, returns true if first m
// number of elements in h (i.e. houses) can be covered
bool check(int n, int h[100000], int m, double d) {
  int i = 0;
  while (n--) {
    if (i == m) return true;

    double next = (double)h[i] + 2*d;
    while ((double)h[i] <= next) {
      i++;
      if (i == m) return true;
    }
  }
  return false;
}

int main() {

  int t; cin >> t;
  while (t--) {

    // houses, contents are the house numbers
    int h[100000];

    // n access points, m houses
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
      cin >> h[i];

    // ensure house numbers are sorted (ascending)
    sort(h, h+m);
    
    double hi = MAX;
    double lo = 0.0;
    while ((hi-lo) > EPS) {
      double mid = (hi+lo) / 2;
      if (check(n, h, m, mid))
        hi = mid;
      else
        lo = mid;
    }
    // solution, answer to 1 decimal place
    cout << setprecision(1) << fixed << hi << endl;
  }

  return 0;

}
