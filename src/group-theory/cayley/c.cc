#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


int main() {

   vi A;
   int x;
   while (cin >> x) {
      A.push_back(x);
   }

   for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < A.size(); j++) {
	 cout << setw(4) << A[i] + A[j] - ((A[i] + A[j]) / 5);
      }
      cout << endl;
   }
   cout << endl;

}
