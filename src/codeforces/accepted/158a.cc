// Problem #    : 158a
// Created on   : 2018-09-27 21:45:40
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

   vi A(n);
   for (auto &x : A) cin >> x;

   cout << partition(begin(A), end(A), [=](int x) { return x > 0 && x >= A[k-1]; }) - begin(A) << endl;
}
