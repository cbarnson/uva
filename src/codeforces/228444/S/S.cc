#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int n, x, t = 0, y = 0;
   vi A;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> x; A.push_back(x); t += x;
   }

   if (t & 1) t++;

   for (int i = 0; i < n; i++) {
      y += A[i];
      if (y >= (t >> 1)) {
	 cout << i + 1 << endl;
	 return 0;
      }	 
   }

}


