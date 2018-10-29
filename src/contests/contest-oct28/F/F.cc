#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   int m, n;
   cin >> m >> n;

   vi A(m);
   for (auto &x : A) cin >> x;

   int s = accumulate(begin(A), end(A), 0);
   int x = (s + n - 1) / n;
   cout << x << endl;
   


}
