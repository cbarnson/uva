// Problem #    : 339a
// Created on   : 2018-09-29 10:42:46
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   vi A;
   char c;

   while (cin >> c) {
      if (isdigit(c))
	 A.push_back(c - '0');
   }

   sort(begin(A), end(A));
   for (int i = 0; i < A.size(); i++)
      cout << (i ? "+" : "") << A[i];
   cout << endl;
   


}
