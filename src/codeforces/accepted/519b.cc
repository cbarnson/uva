// Problem #    : 519b
// Created on   : 2018-10-21 14:11:52
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
   vi A(n), B(n - 1), C(n - 2);
   for (auto &x : A) cin >> x;
   for (auto &x : B) cin >> x;
   for (auto &x : C) cin >> x;
   sort(begin(A), end(A));
   sort(begin(B), end(B));
   sort(begin(C), end(C));
   
   vi D(1);
   auto i = set_difference(begin(A), end(A), begin(B), end(B), begin(D));
   cout << *begin(D) << endl;   
   auto j = set_difference(begin(B), end(B), begin(C), end(C), begin(D));
   cout << *begin(D) << endl;


}
