// Problem #    : 723a
// Created on   : 2018-10-18 18:13:57
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   vi A(3);
   FR(i, 3) cin >> A[i];
   sort(begin(A), end(A));

   cout << A[1] - A[0] + A[2] - A[1] << endl;
   


}
