#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   ll n, k, A, B;
   cin >> n >> k >> A >> B;

   ll x = n;
   ll c = 0;
   while (x > 1) {

     if (x % k == 0) {
       ll y = x / k;
       ll z = (x - y) * A;
       if (B < z) {
	 x /= k; c += B;
	 continue;
       } else {
	 c += (x - 1) * A;
	 break;	 
       }
     }

     int m = (x % k) - (x / k < 1 ? 1 : 0);     
     x -= m;
     c += A * m;     
   }

   cout << c << endl;
  
   
}


