#include <bits/stdc++.h>
using namespace std;

int main() {
   string str;
   bool backdash = true;
   while (getline(cin, str, '\n')) {

      int c = count(str.begin(), str.end(), '\"');

      while (c--) {
	 auto it = find(str.begin(), str.end(), '\"');
	 if (it != str.end()) {
	    if (backdash) {
	       *it = '`';
	       str.insert(it, '`');
	    } else {
	       *it = '\'';
	       str.insert(it, '\'');
	    }
	 }
	 backdash = !backdash;
      }
      cout << str << endl;
      
   }

}
