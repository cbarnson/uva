// Problem #    : g
// Created on   : 2018-10-20 14:23:55
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s;
   cin >> s;

   int n = s.length();
   vi A(n);

   FR(i, n) {
      if (s[i] == 'B')
	 A[i] = -1;
      else
	 A[i] = 1;
   }

   vi B(n + 1, 0);
   partial_sum(begin(A), end(A), begin(B) + 1);

   int mx = max_element(begin(B), end(B)) - begin(B);
   int mi = min_element(begin(B), end(B)) - begin(B);

   // if (mx > mi && A[mi] == -1) mi++;

   if (mi > mx) swap(mi, mx);
   cout << mi + 1 << " " << mx << endl;


}
