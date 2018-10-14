// Problem #    : 469A
// Created on   : 2018-10-14 13:34:28
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m, x;
   cin >> n;

   vi A(n), B;
   iota(begin(A), end(A), 1);

   cin >> m;
   FR(i, m) { cin >> x; B.push_back(x); } 
   cin >> m;
   FR(i, m) { cin >> x; B.push_back(x); } 

   sort(begin(B), end(B));
   auto i = unique(begin(B), end(B));
   B.resize(i - begin(B));

   if (B == A) {
      cout << "I become the guy." << endl;
   } else
      cout << "Oh, my keyboard!" << endl;
   

}
