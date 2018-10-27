// Problem #    : 499b
// Created on   : 2018-10-26 20:06:29
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   map<string, string> A;
   FR(i, m) {
      string a, b; cin >> a >> b;
      A[a] = b;
   }

   FR(i, n) {
      string a; cin >> a;
      cout << (i ? " " : "");
      if (a.size() <= A[a].size())
	 cout << a;
      else
	 cout << A[a];
   }
   cout << endl;
   


}
