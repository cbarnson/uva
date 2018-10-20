#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i) 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string s;
   cin >> s;

   int g = 1;
   for (auto c : s) {
      if (c == 'U')
	 g = min(5, g + 1);
      else
	 g = max(1, g - 1);
   }
   cout << g << endl;
   

   

}
