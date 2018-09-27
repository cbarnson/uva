#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   vi A(n);
   for (auto &x : A) cin >> x;
   
   map<int, int> m;
   FR(i, n) {
     m[A[i]] = m[A[i] - 1] + 1;
   }

   int mx = -0x3f3f3f3f, mxi;
   for (auto &kv : m) if (kv.second > mx) mx = kv.second, mxi = kv.first;
   cout << mx << endl;

   vi B;
   for (int j = n - 1; j >= 0; j--) {
     if (A[j] == mxi) B.push_back(j + 1), mxi--;
     if (B.size() == mx) break;
   }

   for (int j = B.size() - 1; j >= 0; j--) {
     cout << B[j];
     if (j) cout << " ";
     else cout << endl;
   }
}


