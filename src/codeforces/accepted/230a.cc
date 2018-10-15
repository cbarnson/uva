// Problem #    : 230a
// Created on   : 2018-10-14 17:46:30
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int s, n;
   cin >> s >> n;

   multiset<ii> st;
   FR(i, n) {
      int x, y;
      cin >> x >> y;
      st.emplace(x, y);
   }

   
   for (auto &i : st) {
      if (s <= i.first) {
	 cout << "NO" << endl;
	 return 0;
      }
      s += i.second;
   }
   cout << "YES" << endl;
   


}
