// Problem #    : H
// Created on   : 2018-10-01 13:02:18
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k, x;
   cin >> n >> k >> x;

   vector<vi> A(2, vi(1030, 0));
   FR(i, n) {
      int x;
      cin >> x;
      A[0][x]++;
   }

   FR(i, k) {
      
      int l = 1;
      int cur = (i & 1);
      int nxt = !cur;
      
      for (int j = 0; j <= 1025; j++) {
	 while (A[cur][j] > 0) {
	    if (l & 1) {
	       A[nxt][(int)(j ^ x)]++;
	    } else
	       A[nxt][j]++;

	    A[cur][j]--;	    
	    l++;
	 }
      }

      if (i == k - 1) {
	for (int j = 1025; j >= 0; j--) {
	  if (A[nxt][j] > 0) {
	    cout << j << " "; break;
	  }
	}
	for (int j = 0; j <= 1025; j++) {
	  if (A[nxt][j] > 0) {
	    cout << j << endl; break;
	  }
	}

      }

   }
   


}
