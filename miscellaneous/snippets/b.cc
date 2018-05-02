#include <bits/stdc++.h>
using namespace std;


int main() {

   int n;
   cin >> n;

   vector<int> v; v.reserve(n);
   copy_n(istream_iterator<int>(cin), n, back_inserter(v));

   // print a sequence
   copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
   cout << "\n";

   // print a sequence with a separator, but not after last element
   copy(begin(v), end(v)-1, ostream_iterator<int>(cout, ", "));
   cout << v.back() << endl;


   // find min difference in the sorted vector
   auto mindiff = inner_product(begin(v), end(v)-1, begin(v)+1,
				numeric_limits<int>::max(),
				[] (int l, int r) { return min(l, r); }, // "sum"
				[] (int l, int r) { return r - l; } // "product"
      );
   cout << mindiff << endl;

   // Note: simplest overload of inner_product returns the result of accumulating
   // a starting value "init" with the inner products of pairs formed by the
   // elements of 2 ranges
   // init += range1[0]*range2[0] + range1[1]*range2[1] + ... + range1[N-1]*range2[N-1]
   // Thus, both + and * can be overloaded for your needs



   // string comparison
   string a = "hello";
   string b = "hell";
   auto areEqual = a.compare(b) == 0;
   // returns positive if a lexicographically > b
   // returns negative if a lexicographically < b
   // 0 if equal

   // check if a string is a prefix of another
   string prefix = b;
   auto isPrefix = a.compare(0, prefix.size(), prefix) == 0;

   return 0;
}
