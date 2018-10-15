// Problem #    : 455a
// Created on   : 2018-10-14 18:41:56
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

   set<int> st;
   FR(i, n) {
      int x;
      cin >> x;
      st.emplace(x);
   }
   
   vi A(n); for (auto &x : A) cin >> x;
   sort(A.rbegin(), A.rend());

   
   


}
