#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   unsigned long long n, m;
   cin >> n;
   m = n + 1;
   if (m & 1)
      cout << (m > 1 ? m : 0) << endl;
   else
      cout << (m >> 1) << endl;

}


