// Cody Barnson
// 384 - Slurpys
#include <bits/stdc++.h>
using namespace std;

bool isF(string& str) {
   string s = str;
   if (s.front() == 'F') {
      s.erase(s.begin());
      while (s.front() == 'F') {
	 s.erase(s.begin());
      }
      str = s;
      return true;
   }
   return false;
}

bool isSlump(string& str) {
   string s = str;
   if (s.front() == 'D' || s.front() == 'E') {
      s.erase(s.begin());
      if (isF(s)) {
	 if (isSlump(s)) {
	    str = s;
	    return true;
	 }
	 if (s.front() == 'G') {
	    s.erase(s.begin());
	    str = s;
	    return true;
	 }
      }
   }
   return false;
}

bool isSlimp(string& str) {

   string s = str;
   if (s.front() == 'A') {
      s.erase(s.begin());
      if (s.front() == 'H') {
	 s.erase(s.begin());
	 str = s;
	 return true;
      } 
      if (s.front() == 'B') {
	 s.erase(s.begin());
	 if (isSlimp(s)) {
	    if (s.front() == 'C') {
	       s.erase(s.begin());
	       str = s;
	       return true;
	    }
	 }
      } else {
	 if (isSlump(s)) {
	    if (s.front() == 'C') {
	       s.erase(s.begin());
	       str = s;
	       return true;
	    }
	 }
      }
   }
   return false;
}

bool isSlurpy(string& str) {
   string s = str;
   if (isSlimp(s)) {
      if (isSlump(s)) {
	 str = s;
	 return true;
      }
   }
   return false;
}

// approach: tokenize the string, use recursive function calls to determine
// the status of the input string
int main() {
   int t;
   cin >> t;
   cout << "SLURPYS OUTPUT" << endl;
   while (t--) {
      string input;
      cin >> input;      
      if (isSlurpy(input) && input.empty()) {
	 cout << "YES" << endl;
      } else {
	 cout << "NO" << endl;
      }
   }
   cout << "END OF OUTPUT" << endl;
   

   return 0;
}
