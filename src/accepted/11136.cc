//================================
//UVA problem#: 11136
//CPSC 3200,	2017-02-02
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

int main() {

  int n; // 1 <= n <= 5000
  while (cin >> n && n != 0) {

    int64_t total = 0;
    multiset<int> myset;
    for (int i = 0; i < n; i++) {

      // k is number of bills
      int k; cin >> k; // 0 <= k <= 10^5
	 
      while (k--) {
        int val; cin >> val; // val <= 10^6
        myset.insert(val);
      }
      auto min = myset.begin();
      auto max = myset.end(); --max;

      // add the difference to total
      total += (*max)-(*min);

      // remove these elements from the set
      // guaranteed there will always be at least 2 elements, no need
      // for extra checks
      myset.erase(max);	 
      myset.erase(min);
	 
    }
    // print total amount paid to clients from the promo
    cout << total << endl;
      
  }
  return 0;
}
