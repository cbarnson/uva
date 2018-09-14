#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   
   int A[3] = {};
   string s;

   cin >> s;
   for (auto &i : s) 
      A[(int)(i - 'a')]++;
   
   string ss = s;
   sort(ss.begin(), ss.end());

   if (ss != s || any_of(A, A+3, [](int x) { return x == 0; }) || (A[2] != A[1] && A[2] != A[0]))
      cout << "NO" << endl;
   else
      cout << "YES" << endl;
   

}


