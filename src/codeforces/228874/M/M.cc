#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, d;
   cin >> n >> d;

   vi A(n);
   for (auto &x : A) cin >> x;

   sort(begin(A), end(A));

   auto it = A.begin();
   int m = 0x3f3f3f3f;
   while (it != A.end()) {

     int i = it - begin(A);
     int j = upper_bound(it, end(A), *it + d) - begin(A);
     m = min(m, n - j + i);

     it = upper_bound(it, end(A), *it);
   }

   cout << m << endl;

}


