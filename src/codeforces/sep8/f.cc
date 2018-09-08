#include <bits/stdc++.h>
using namespace std;

int main() {

   int n;
   int a[101];
   while (cin >> n) {
      memset(a, 0, sizeof a);
      for (int i = 0; i < n; i++) {
	 int x;
	 cin >> x;
	 a[x]++;
      }

      int m = *max_element(a, a+101);
      cout << m << endl;
   }
}
