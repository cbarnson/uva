// Problem #    : 432a
// Created on   : 2018-10-21 11:30:52
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k;
   cin >> n >> k;   
   vi A(n); for (auto &x : A) cin >> x;
   
   int cnt = count_if(begin(A), end(A), [&] (int x) { return 5 - x >= k; });
   cout << cnt / 3 << endl;
   


}
