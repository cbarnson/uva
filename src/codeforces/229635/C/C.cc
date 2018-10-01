#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;
   vector<ll> A(n), B(m);
   for (auto &x : A) cin >> x;
   for (auto &x : B) cin >> x;

   vector<ll> C;

   FR(i, n) { // best for i, ... 2nd best
      ll x = -1;
      FR(j, m) {
	 x = (x == -1 ? A[i] * B[j] : max(x, A[i] * B[j]));
      }
      C.push_back(x);
   }

   sort(begin(C), end(C));
   cout << C[(int)C.size() - 2] << endl;
}


