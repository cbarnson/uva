// Problem #    : 313a
// Created on   : 2018-10-20 20:31:41
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int a;
   cin >> a;
   int b = a / 10;   
   int c = (a % 10) + (a / 100) * 10;

   cout << max(a, max(b, c)) << endl;
}
