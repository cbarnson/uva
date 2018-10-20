#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int k;
   cin >> k;

   for (int i = 0; i <= (31 - __builtin_clz(k)); i++) {
      if (k & (1 << i)) {
	 cout << "Go" << endl;
      }
      if (i < (31 - __builtin_clz(k)))
	 cout << "AddRockets" << endl;      
   }

   

   
   // cout << k << ", leading zeros : " << 31 - __builtin_clz(k) << endl;
   
   

   

}
