#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll lcm(ll a, ll b) {
   return a * (b / __gcd(a, b));
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll a, b, t;
   cin >> a >> b >> t;

   if (lcm(a, b) <= t) {
      cout << "yes" << endl;
   } else
      cout << "no" << endl;
   
   

}
