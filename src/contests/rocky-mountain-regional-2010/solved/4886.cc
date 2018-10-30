// Cody Barnson
// 4886 - page count
#include <bits/stdc++.h>
using namespace std;

bool p[1001];
int n;

// HOWARDS FEEBACK
// I would tokenize things in a different ways.  If you are going to use
// stringstream anyway, I would first replace all the "," by " " so your
// first loop is easier.  I also probably wouldn't use a queue and just
// use something else, but that's not a huge deal.
int main() {

   while (cin >> n >> ws && n != 0) {
      fill(p, p+n+1, false);
      string s;
      getline(cin, s);
      istringstream iss(s);

      // tokenize string into positive and negative integers, a negative
      // integer implies it is part of a range with the previous integer
      int val;
      queue<int> q;
      while (iss >> val) {  
	 q.push(val);
	 if (iss.peek() == ',') iss.get();
      }

      // process tokenized page ranges
      while (!q.empty()) {
	 int a = q.front();	 
	 q.pop();
	 
	 if (!q.empty() && q.front() < 0) { // check if page range
	    int b = q.front() * -1;
	    q.pop();
	    if (a > b)
	       continue;	    
	    else if (a == b && a <= n)	       
	       p[a] = true;
	    else if (a != b && a <= n)
	       fill(p+a, p+b+1, true);
	 } else {
	    if (a <= n)
	       p[a] = true;	    
	 }
      }

      cout << count(p, p+n+1, true) << endl;
   }

   return 0;
}
