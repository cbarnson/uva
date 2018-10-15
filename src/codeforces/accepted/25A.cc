// Problem #    : 25A
// Created on   : 2018-10-14 15:06:40
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, e = 0, o = 0;
   cin >> n;
   vi A(n);
   for (auto &x : A) {
      cin >> x;
      x %= 2;
      if (x) o++;
      else e++;
   }

   FR(i, n) {
      if ((o == 1 && A[i] == 1) || (e == 1 && A[i] == 0)) {
	 cout << i + 1 << endl;
	 return 0;
      }
   }

   
   


}
