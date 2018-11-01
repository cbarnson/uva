#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

// time intersect
double ti(double a0, double b0, double va, double vb) {
  return ((a0 - b0) / (va - vb));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << fixed << setprecision(10);

  // --- (0) ----------------- < ===== a0 ===== >
  //                           < ===== b0 ===== >

  double ax, ay, va, ri, rf, bx, by, vb;
  cin >> ax >> ay >> va >> ri >> rf >> bx >> by >> vb;

  double b0 = hypot(bx - ax, by - ay), a0 = ri;
  double tb = (b0 - rf) / vb;

  double dmg = 0.0;
  if (b0 < a0 && va > vb) {
    double i = ti(a0, b0, va, vb);
    if (i < tb) dmg = (tb - i);
  } else if ((b0 == a0 && va > vb) || (b0 > a0 && va >= vb)) {
    dmg = tb;
  } else if (b0 > a0 && va < vb) {
    double i = ti(a0, b0, va, vb);
    dmg = (i < tb) ? i : tb;
  }
  cout << dmg << endl;
}
