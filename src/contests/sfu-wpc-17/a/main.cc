#include <bits/stdc++.h>
using namespace std;

void print(queue<string>& q) {
   if (q.empty()) return;
   // assert(!q.empty());
   string s = q.front();
   if (s == "pair") {
      cout << s << "<";
      q.pop();
      print(q);
      cout << ",";
      print(q);
      cout << ">";
   } else {
      cout << s;
      q.pop();
   }
   return;
}

int main() {


   int t, n;
   cin >> t;
   while (t--) {

      cin >> n >> ws;
      multimap<int, string> mm;

      // priority_queue<string> pq;
      int hi = 0;
      
      for (int i = 0; i < n; i++) {

	 string s;
	 getline(cin, s);
	 istringstream iss(s);

	 string str = "";
	 while (getline(iss, s, '.')) {
	    if (s == "f" || s == "s") {
	       str += s;
	    }
	 }
	 int len = str.length();
	 hi = max(hi, len);
	 // cout << "'" << str << "'" << "\t";	    
	 // cout << endl;

	 mm.insert(make_pair(str.length(), str));
	 
      }

      queue<string> q;
      q.push("pair");
      
      for (int i = 1; i <= hi; i++) {
	 // cout << "len: " << i << " ";
	 int c = mm.count(i);
	 // cout << "count " << c << endl;
	 if (c == 0) {
	    q.push("pair");
	    q.push("pair");
	 } else if (c == 1) {
	    // auto it = mm[i];
	    auto r = mm.equal_range(i);
	    string val = r.first->second;
	    val = val.back();
	    // cout << "val: " << val << endl;
	    if (val == "f") {
	       q.push("int");
	       q.push("pair");
	    } else {
	       q.push("pair");
	       q.push("int");
	    }
	    // for (auto it = r.first; it != r.second; ++it) {
	    //    cout << it->second << " ";
	    // }
	 } else {
	    while (c--) q.push("int");
	 }
	 // } else if (c == 2) { // c == 2
	 //    q.push("int");
	 //    q.push("int");
	 // }
	 // auto r = mm.equal_range(i);
	 // for (auto it = r.first; it != r.second; ++it) {
	 //    cout << it->second << " ";
	 // }
	 // cout << endl;
      }

      print(q); 
      cout << q.size() << endl;
      
      // cout << "queue: ";
      // while (!q.empty()) {
      // 	 cout << q.front() << " ";
      // 	 q.pop();	 
      // }
      cout << endl;

      // for (auto &it : mm) {
      // 	 cout << it.second << " ";
      // }
      // cout << endl;


   }
   

   return 0;
}



