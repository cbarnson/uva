#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;



int main() {
   
   unsigned int n, k;
   cin >> n >> k;

   while (k--) {

      if (n % 10 == 0)
	 n /= 10;
      else
	 n--;
      
   }
   cout << n << endl;


}


