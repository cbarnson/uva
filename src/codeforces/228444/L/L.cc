#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   string s;
   cin >> s;

   int p = 0, l = 0;
   for (auto &i : s) {      
      if (i == '-')
	 l++;
      else
	 p++;
   }

   if (!p || l % p == 0)
      cout << "YES" << endl;
   else
      cout << "NO" << endl;

}


