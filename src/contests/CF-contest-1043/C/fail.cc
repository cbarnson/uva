// Problem #    : t
// Created on   : 2018-10-28 09:37:39
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

   int n = s.size();
   
   vector<string> A;
   for (int i = 1; i <= n; i++) {
      string a = s;
      reverse(begin(a), begin(a) + i);
      A.push_back(a);
   }

   string ans = A.front();
   int j = 0;
   for (int i = 1; i < (int)A.size(); i++) {
      if (A[i] < ans) {
	 ans = A[i];
	 j = i;
      }
   }

   FR(i, n) {
      cout << (i ? " " : "") << (i == j ? 1 : 0);
   }
   cout << endl;


}
