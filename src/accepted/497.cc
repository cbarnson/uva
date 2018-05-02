// Cody Barnson
// 497 - strategic defense initiative
#include <bits/stdc++.h>
using namespace std;

void print(int p[100000], int a[100000], int end) {
   if (p[end] == -1)
      return;
   print(p, a, p[end]);
   cout << a[p[end]] << endl;
}

int main() {

   string s;
   getline(cin, s);
   int t = stoi(s);
   getline(cin, s);
   while (t--) {

      int a[100000], lis[100000], prev[100000];
      int n = 0;
      while (getline(cin, s) && !s.empty()) {
	 istringstream iss(s);
	 int val;
	 iss >> val;
	 a[n++] = val;
      }
      int max = 1;
      int end = 0;

      // longest increasing subsequence
      lis[0] = 1;
      prev[0] = -1;
      for (int i = 1; i < n; i++) {
	 lis[i] = 1;
	 prev[i] = -1;
	 for (int j = 0; j < i; j++) {
	    if (lis[j]+1 > lis[i] && (a[j] < a[i])) {
	       lis[i] = lis[j] + 1;
	       prev[i] = j;
	    }
	 }
	 if (lis[i] > max) {
	    end = i;
	    max = lis[i];
	 }
      }

      cout << "Max hits: " << max << endl;

      // recursive print to get order as they arrived
      print(prev, a, end);
      cout << a[end] << endl;
      
      if (t) cout << endl;
      
   } // end while

   return 0;
}
