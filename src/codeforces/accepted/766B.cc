// Problem #  : 766B
// Created on : 2018-Nov-09 13:19:53
#include <bits/stdc++.h>
#define FR(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
#if __has_include("default_cf.h")
#include "default_cf.h"
#endif

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

// bool isPossibleTriangle(ll a, ll b, ll c) {}

// Triangle Inequalities
// Note: isPossible true for degenerate triangles; to change,
// make it a + b > c (possible and not degenerate)
bool isDegenerate(ll a, ll b, ll c) { return (a + b == c); }
bool isPossible(ll a, ll b, ll c) { return (a + b > c); }
bool isImpossible(ll a, ll b, ll c) { return (a + b < c); }

// Sort such that a <= b <= c
void sort3(ll &a, ll &b, ll &c) {
  swap(a, (a < min(b, c) ? a : (b < c ? b : c)));
  swap(b, (b < c ? b : c));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  vi A(n);
  FR(i, n) cin >> A[i];

  sort(begin(A), end(A));
  for (ll i = 0; i < n - 2; i++) {
    ll a = A[i], b = A[i + 1], c = A[i + 2];
    if (isPossible(a, b, c)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}
