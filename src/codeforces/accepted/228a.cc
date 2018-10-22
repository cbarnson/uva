// Problem #    : 228a
// Created on   : 2018-10-22 08:16:02
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   set<int> st;
   FR(i, 4) {
      int x; cin >> x; st.insert(x);
   }

   cout << 4 - st.size() << endl;
   


}
