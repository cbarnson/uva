#include <bits/stdc++.h>
using namespace std;

int main() {

   int n, k;
   int l[27];
   while (cin >> n >> k) {

      string s;
      cin >> s;
      fill(l, l+27, 0);

      for (int i = 0; i < (int)s.size(); i++) {
	 l[(int)(s[i] - 'A')]++;
      }

      int i = *min_element(l, l+k);
      cout << i * k << endl;
   }

}
