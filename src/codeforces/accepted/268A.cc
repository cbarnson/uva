// Problem #    : 268A
// Created on   : 2018-10-14 15:54:57
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
   vi B;
   vi H(101, 0), A(101, 0);
   FR(i, n) {
      int h, a;
      cin >> h >> a;
      B.push_back(h);
      H[h]++, A[a]++;
   }

   int cnt = 0;
   for (auto &x : B) {
      cnt += A[x];
   }
   cout << cnt << endl;
   
   


}
