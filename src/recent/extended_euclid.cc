// Problem #    : extended_euclid
// Created on   : 2018-08-04 22:14:02

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
#define L first
#define R second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;  // pair of ints
typedef vector<int> vi;     // 1d vector of ints
typedef vector<ii> vii;     // 1d vector of pairs

// Greatest common divisor
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

// Least common multiple
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

// ax + by = c
//
// a, b are integers, with d = gcd(a, b)
// ax + by = c, has no solution if d % c != 0, otherwise infinitely many
// integral solutions.  To find the first solution (x0, y0), use the following:
int x, y, d;
void extended_euclid(int a, int b) {
  if (b == 0) {
    x = 1, y = 0, d = a;
    return;
  }
  extended_euclid(b, a % b);
  int tmp = y;
  y = x - (a / b) * y;
  x = tmp;

  // once you have the first solution (x0, y0), you can derive the others from
  // xi = x0 + (b / d) * i
  // yi = y0 + (a / d) * i
}

int main() {
  // Uncomment to use c++ IO (cout/cin) faster,
  // but don't use scanf/printf if you do.
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  extended_euclid(25, 18);
  cout << x << ", " << y << ", " << d << endl;

  return 0;
}
