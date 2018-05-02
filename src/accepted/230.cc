// Problem    : UVa 230 - Borrowers
// Time limit : 3.000 seconds
// Difficulty : 3
// Author     : Cody Barnson
// Date       : Jan. 13, 2018
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

map<string, string> ta;
const string sep = "\" by ";
const int sep_sz = sep.length();

void print(string put_x, string after_y) {
   cout << "Put " << put_x;
   if (!after_y.empty()) {
      cout << "\" after " << after_y << '\"'<< endl;
   } else {
      cout << "\" first" << endl;
   }   
}

int main() {
   
   // title, author, state = (0: off shelf, 1: on shelf, 2: return)
   vector<string> ti, au;
   vector<int> st; 

   string l;
   set< pair<string, string> > order;
   while (getline(cin, l)) {

      if (l == "END") 
	 break;

      // string::find, returns the index of the first character of the target
      // sequence that occurs in the search string.  Note the check compares
      // with std::string::npos.
      size_t f = l.find(sep);
      if (f != string::npos) {
	 int len = l.length();
	 string t = l.substr(0, f);
	 string a = l.substr(f + sep_sz, len - (f + sep_sz));
	 order.insert(make_pair(a, t));
      }
   }

   // initialize; order is a set of (author, title) pairs, sorted using the
   // ASCII collating sequence
   for (auto &i : order) {
      ti.pb(i.second);
      au.pb(i.first);
      st.pb(1);
   }

   string cmd;   
   while (cin >> cmd) {
      
      if (cmd == "END")
	 break;
      
      if (cmd == "BORROW" || cmd == "RETURN") {
	 string t;
	 getline(cin >> std::ws, t);
	 t = string(t, 0, t.length() - 1);
	 auto it = find(ti.begin(), ti.end(), t);
	 int i = it - ti.begin();

	 // update the state for the ith element
	 st[i] = (cmd == "BORROW") ? 0 : 2;
	 
      } else {

	 // Output the list of instructions for the librarian, according
	 // to the problem specifications	 
	 int len = st.size();
	 for (int i = 0; i < len; i++) {
	    if (st[i] ==  2) {
	       if (!i) {
		  print(ti[i], "");
	       } else {
		  int j = i-1;
		  while (j >= 0 && st[j] != 1) {
		     j--;
		  }
		  if (j < 0) {
		     print(ti[i], "");
		  } else {
		     print(ti[i], ti[j]);
		  }
	       }
	       // state is now 1, the shelved state
	       st[i] = 1;
	    }
	 }
	 // remember this after every SHELVE
	 cout << "END" << endl;
      }
   }

   return 0;
}
