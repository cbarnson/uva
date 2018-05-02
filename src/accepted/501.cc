//================================
//UVA problem#: 501
//CPSC 3200,	2017-02-02
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

typedef multiset< pair<int,int> >::iterator msit;

int main() {
   
  int num_cases;
  cin >> num_cases;
  while (num_cases--) {

    // add values
    int A[30000];
      
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }

    // 'timestamp', increments with each insertion, ensures that
    // inserted values equal to the jth min always get placed to the
    // logical 'right' of our iterator
    int ts = 0;
    multiset< pair<int, int> > ms;

    // first element
    ms.insert(make_pair(A[0], ts++));
    msit itr = ms.begin();

    // index of next 'Add' element to insert into our multiset
    int a = 1;

    // read get values one at a time
    for (int j = 0; j < m; j++) {
      int get;
      cin >> get;
      int sz = ms.size();
	 
      if (get > sz) {
        // insert the next 'difference' number of Add elements
        int toAdd = get - sz;
        while (toAdd--) {
          ms.insert(make_pair(A[a], ts++));
          // if the insert value is strictly less than current min, move iter back
          if (A[a++] < (*itr).first) itr--;
        }
      }
	 
      // print jth min
      // exception to rule: the very first case
      if (j == 0) {
        cout << (*itr).first << endl;
      } else {
        ++itr;
        cout << (*itr).first << endl;
      }
    }

    if (num_cases) cout << endl;
  }


  return 0;
}
