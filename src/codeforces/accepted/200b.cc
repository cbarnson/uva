// Problem #    : 200b
// Created on   : 2018-10-14 18:31:33
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

   vector<double> A(n);
   for (auto &x : A) cin >> x;
   double p = accumulate(begin(A), end(A), 0.0);

   cout << setprecision(8) << fixed << p / (double)n << endl;
   


}
