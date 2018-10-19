// Problem #    : 155a
// Created on   : 2018-10-18 17:39:06
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
   set<int> st;

   cin >> n;
   int cnt = 0;
   FR(i, n) {

      int x;
      cin >> x;

      if (!st.empty() && (x < *st.begin() || x > *st.rbegin())) {
	 cnt++;
      }
      st.emplace(x);
   }
   
   cout << cnt << endl;

}
