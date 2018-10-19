#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vi factor(int n) {
   int f = false; vi ans;
   if (n < 2) return ans;

   while (n % 2 == 0) {
      n /= 2; ans.push_back(2);
      f = true;
   }

   for (ll p = 3; p * p <= n; p += 2) {
      while (n % p == 0) {
	 n /= p; ans.push_back((int)p);
	 f = true;
      }
   }

   if (n > 1)
      ans.push_back(n);

   return ans;
   
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   for (int i = 0; i <= 20; i++) {
      vi ans = factor(i);
      cout << i << " : ";
      for (auto &x : ans) cout << x << " ";
      cout << endl;
   }

}
