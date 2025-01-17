#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n, k;
   cin >> n >> k;

   vector<ll> A(n);
   for (auto &x : A) cin >> x;

   ll s = 0;
   FR(i, n) {
      s += (A[i] + k - 1) / k;
   }

   ll d = (s + 2 - 1) / 2;
   cout << d << endl;
}
