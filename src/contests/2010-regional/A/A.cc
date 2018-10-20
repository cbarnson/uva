#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

struct tok {
   enum Type { VAR, PLUS, LP, RP };
   int pr[4];
   bool la[4];
   Type type;
   char val;

   tok() {
      pr[1] = 1; pr[2] = 0;
      la[1] = true;
   }

   int getpr() {
      return pr[type];
   }

   bool isla() {
      return la[type];      
   }

   bool next(string &expr, int &start, bool &err) {
      cout << "next: " << expr << endl;
      int len = (int)expr.length();
      err = false;
      while (start < len && isspace(expr[start])) {
	 start++;
      }

      if (start >= len) return false;

      switch(expr[start]) {
	 case '(':
	    type = LP;
	    break;
	 case ')':
	    type = RP;
	    break;
	 case '+':
	    type = PLUS;
	    break;
	 default:
	    type = VAR;
      }
      start++;
   }
};

bool apply(stack<char> &ops, tok t) {
   char a, b;
   if (ops.size() < 2) return false;
   if (t.type == tok::PLUS) {
      b = ops.top(); ops.pop();
      a = ops.top(); ops.pop();
      cout << "b: " << b << ", a: " << a << endl;
      ops.push(b); ops.push(a);
   } else {
      return false;
   }
   return true;
}

string evaluate(string expr, bool &err) {
   stack<tok> s;
   stack<char> ops;
   int i;
   tok t;

   err = false;
   i = 0;
   while (t.next(expr, i, err) && !err) {
      switch (t.type) {
	 case tok::VAR:
	    ops.push(t.val);
	    break;
	 case tok::LP:
	    s.push(t);
	    break;
	 case tok::RP:
	    while (!(err = s.empty()) && s.top().type != tok::LP) {
	       if ((err = !apply(ops, s.top()))) {
		  break;
	       }
	       s.pop();	       
	    }
	    if (!err) {
	       s.pop();
	    }
	    break;
	 default:
	    while (!err && !s.empty() &&
		   (t.getpr() < s.top().getpr() || (t.getpr() == s.top().getpr() && t.isla()))) {
	       
	       err = !apply(ops, s.top());
	       s.pop();
	    }
	    if (!err) {
	       s.push(t);
	    }
      }
      if (err)
	 break;
   }
   while (!err && !s.empty()) {
      err = !apply(ops, s.top());
      cout << "popping: " << s.top().val << endl;
      s.pop();
   }
   err |= (ops.size() != 1);
   if (err) return "";


   cout << "output: ";
   string ans = "";
   while (!ops.empty()) {
      cout << ops.top() << " ";
      ans += ops.top();
      ops.pop();
   }
   return ans;
      
   
   // return ops.top();
}

int main() {

   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);

   string expr;
   bool err;
   
   while(getline(cin, expr)) {
      cout << "expr: " << expr << endl;
      string res = evaluate(expr, err);
      if (err) {
	 cout << "invalid" << endl;	 
      } else {
	 cout << res << endl;
      }
   }
}
