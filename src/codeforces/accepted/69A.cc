// Problem #    : 69A
// Created on   : 2018-10-14 10:40:46
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, x;
   vi A = { 0, 0, 0 };

   cin >> n;
   FR(i, n) {
      FR(j, 3) {
	 cin >> x;
	 A[j] += x;
      }    
   }

   if (all_of(begin(A), end(A), [](int y) { return y == 0; })) {
      cout << "YES" << endl;
   } else
      cout << "NO" << endl;
   


}
