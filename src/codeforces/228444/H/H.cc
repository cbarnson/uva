#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int n;
   string s;
   cin >> n >> s;


   int len = s.length();
   if (len < 3) {
      cout <<  (count(s.begin(), s.end(), '1') == 1 ? "Yes" : "No") << endl;
      return 0;
   }

   if (s.find("11") == string::npos && s.find("00") != 0 && s.rfind("00") != len - 2 && s.find("000") == string::npos) {
      cout << "Yes" << endl;
   } else {
      cout << "No" << endl;
   }


}


