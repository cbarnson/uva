#include <bits/stdc++.h>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

map<char, int> A;

void setc(char c, int &n)
{
   if (A.find(c) == A.end()) {
      A[c] = n;
      n++;
   }
}

int eval(int vals[], string expr, int &i, int &n)
{
   char c, c2;
   c = expr[i++];
   char op;
   int x, y;

   if (c == '(') {
      x = eval(vals, expr, i, n);
   }
   else {
      setc(c, n);
      x = vals[A[c]];
   }
   op = expr[i++];
   c2 = expr[i++];
   if (c2 == '(') {
      y = eval(vals, expr, i, n);
   }
   else {
      setc(c2, n);
      y = vals[A[c2]];
   }
   i++;
   if (op == '-') {
      return x - y;
   }
   else if (op == '+') {
      return x + y;
   }
   else if (op == '*') {
      return x * y;
   }
   else {
      assert(false);
      return 0;
   }
}


int main()
{

   while (true) {
      int n;
      cin >> n;
      if (n == 0) break;
      
      int vals[5];
      for (int i = 0; i < n; i++) {
	 cin >> vals[i];
      }
      sort(vals, vals + n);
   
      int r;
      cin >> r;
      string expr;
      cin >> expr;


      bool good = false;
      do {
	 A.clear();
	 int i = 1, n = 0;
	 int t;
	 if (expr.size() == 1) {
	    setc(expr[0], n);
	    t = vals[A[expr[0]]];
	 }
	 else {
	    t = eval(vals, expr, i, n);
	 }
	 if (t == r) {
	    good = true;
	    break;
	 }
      } while(next_permutation(vals, vals + n));
      
      if (!good) {
	 cout << "NO" << endl;
      }
      else {
	 cout << "YES" << endl;
      }

   }
}
