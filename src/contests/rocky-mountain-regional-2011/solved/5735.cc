// Cody Barnson
// 5735 - Stock prices
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {

   // want k1 lowest price days, and k2 highest price days
   int n, k1, k2;
   int cn = 1;
   while (cin >> n >> k1 >> k2) {
      if (n == 0 && k1 == 0 && k2 == 0) break;


      // NOTE: Howard's comment
      // (1) it is slightly faster to put things into a vector and call sort,
      // than to use a multiset
      // (2) instead of sorting the whole thing and then picking up the largest
      // and smallest values, could use 2 priority queues, one for largest
      // and one for smallest, that way you don't store more than k1 + k2
      // things in the two queues
      
      multiset<ii> ms; // elements are pair< price, day >
      for (int i = 1; i <= n; i++) {
	 int p;
	 cin >> p;
	 ms.insert(ii(p, i));
      }
      int low[100];
      int high[100];
      
      // copy low end of our multiset (days element) into low
      auto it = ms.begin();
      advance(it, k1);
      transform(ms.begin(), it, low, [] (const ii &x) { return x.second; });      
      
      // copy high end of our multiset (days element) into high
      auto itr = ms.rbegin();
      advance(itr, k2);
      transform(ms.rbegin(), itr, high, [] (const ii &x) { return x.second; });

      // sort low to ascending order, sort high to descending order
      sort(low, low+k1);
      sort(high, high+k2, [] (int a, int b) { return a > b; });

      // print results (assumes k1, k2 > 0)
      cout << "Case " << cn++ << endl;
      copy(low, low+(k1-1), ostream_iterator<int>(cout, " "));
      cout << low[k1-1] << endl;
      copy(high, high+(k2-1), ostream_iterator<int>(cout, " "));
      cout << high[k2-1] << endl;
   }


   return 0;
}
