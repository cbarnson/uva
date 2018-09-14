#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int n;
   string s;
   set<string> set;
   
   cin >> n;
   while (n--) {

      cin >> s;
      sort(s.begin(), s.end());
      auto e = unique(s.begin(), s.end());
      string v = string(s.begin(), e);
      set.insert(v);
   }

   cout << set.size() << endl;

}


