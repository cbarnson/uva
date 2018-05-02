// Problem    : UVa 230 - Borrowers
// Time limit : 3.000 seconds
// Difficulty : 3
// Author     : Cody Barnson
// Date       : Jan. 13, 2018
#include <bits/stdc++.h>
using namespace std;

map<string, string> ta;
map<string, string> b;
map<string, string> r;
const string sep = "\" by ";
int sep_sz = sep.length();

void print(string put_x, string after_y) {
   cout << "Put " << put_x;
   if (!after_y.empty()) {
      cout << "\" after " << after_y << endl;
   } else {
      cout << "\" first" << endl;
   }   
}

int main() {
   
   string l;
   while (getline(cin, l)) {

      cout << "l: " << l << endl;
      
      if (l == "END") {
	 // cout << "break" << endl;
	 break;
      } else {
	 cout << "l not equal to END" << endl;
      }

      size_t f = l.find(sep);
      if (f != string::npos) {
	 int len = l.length();
	 string t = l.substr(0, f);
	 string a = l.substr(f + sep_sz, len - (f + sep_sz));
	 
	 ta[t] = a;
	 // // map::insert
	 // auto ret = ta.insert(make_pair(t, a));
	 // if (ret.second == false) {
	 //    // already existed
	 //    exit(1);
	 // } else {
	 //    // successfully inserted
	 // }
	 
      } else {
	 exit(2);
      }
      
   }



   string cmd;
   
   while (cin >> cmd) {

      if (cmd == "END")
	 break;
      
      if (cmd == "BORROW") {
	 
	 // find in ta, put in b, erase in ta
	 string t;
	 cin >> t;
	 t = string(t, 0, t.length() - 1);
	 auto it = ta.find(t);
	 if (it != ta.end()) {
	    b[t] = it->second;
	    ta.erase(it);
	 } else {
	    exit(3);
	 }
	 
      } else if (cmd == "RETURN") {

	 // find in b, put in r, erase in b
	 string t;
	 cin >> t;
	 t = string(t, 0, t.length() - 1);
	 auto it = b.find(t);
	 if (it != b.end()) {
	    r[t] = it->second;
	    b.erase(it);
	 } else {
	    exit(4);
	 }

      } else if (cmd == "SHELVE") {

	 map<string, string> ta_ord;
	 for (auto i = ta.begin(); i != ta.end(); ++i) {
	    ta_ord[i->second] = i->first;
	 }

	 map<string, string> r_ord;
	 for (auto i = r.begin(); i != r.end(); ++i) {
	    r_ord[i->second] = i->first;
	    // insert into ta, fixes it up
	    ta[i->first] = i->second;	    
	 }

	 // empty return pile
	 r.clear();

	 for (auto &i : r_ord) {

	    auto ret = ta_ord.insert(make_pair(i.first, i.second));
	    assert(ret.second);
	    if (ret.first == ta_ord.begin()) {
	       print(i.second, "");
	    } else {
	       map<string, string>::iterator it = ret.first;
	       --it;
	       print(i.second, it->second);
	    }
	    
	 }
	 cout << "END" << endl;
	 
	 

      } else {
	 assert(cmd == "END");
	 break;
      }
   }

   // done
   
  
   

   return 0;
}
