#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int f[40];
int fib(int n) {
  if (n < 2) return n;
  if (f[n]) return f[n];

  int k = (n + 1) / 2;
  f[n] = (n & 1) 
    ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
    : (2 * fib(k - 1) + fib(k)) * fib(k);
  return f[n];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   set<int> s;
   FR(i, 20) s.insert(fib(i));

   int n;
   cin >> n;

   for (int i = 1; i <= n; i++)
     if (s.find(i) == s.end())
       cout << "o";
     else
       cout << "O";
   cout << endl;
   
}


