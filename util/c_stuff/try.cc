// Problem #    : try
// Created on   : 2018-10-22 12:22:55
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
#define fn(c) __fn(__LINE__, #c, !!c)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

void __fn(int line, const char *x, bool y) {
   if (!y) {
      cout << x << " failed." << line << endl;
   }      
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int64_t x = numeric_limits<int64_t>::max();
   ll y = numeric_limits<ll>::max();

   fn(x);

   fn((false) && NULL == "this is a string");
   
   assert(x == y);
   


}
