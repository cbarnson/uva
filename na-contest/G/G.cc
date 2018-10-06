#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n; string s;

   cin >> n >> s;
   vi A(n);
   iota(begin(A), end(A), 1);
   s = (s[0] == 'L' ? string("R") : string("L")) + s;
   // cout << s << endl;

   for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'R' && s[i+1] == 'L') {
	 int j = i + 1;
	 for (j; j < n; j++) {
	    if (s[j] == 'L') continue;
	    // cout << "break " << j << ", len " << (int)s.length() << endl;
	    break;
	 }

	 reverse(A.begin() + i, A.begin() + j);
	 i = j - 1;
      }
   }
   for (auto &x : A) {
      cout << x << endl;
   }
   

}
