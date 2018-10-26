// Problem #    : 456a
// Created on   : 2018-10-25 11:25:03
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   vector<ii> A(n);
   for (auto &x : A) cin >> x.first >> x.second;
   sort(begin(A), end(A), [](ii a, ii b) {
	 return a.first > b.first || (a.first == b.first && a.second < b.second);
      });

   for (int i = 1; i < n; i++) {
      if (A[i].second > A[i-1].second) {
	 cout << "Happy Alex" << endl;
	 return 0;
      }
   }

   cout << "Poor Alex" << endl;

}
