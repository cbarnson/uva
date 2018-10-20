#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, h, m;
   cin >> n >> h >> m;


   int d = 0, lo = 0, hi = 0;
   FR(i, m) {
      int x;
      cin >> x;
      d += x;
      lo = min(lo, d);
      hi = max(hi, d);      
   }

   d += h;
   lo += h;
   hi += h;


   for (int i = 1; i <= n; i++) {
      if (i == d)
	 cout << "B";
      else if (i < lo || i > hi)
	 cout << ".";
      else
	 cout << "Z";
   }
   cout << endl;
   
   

}
