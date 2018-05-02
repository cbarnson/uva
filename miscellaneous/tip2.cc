// Problem:
// Status :
#include <bits/stdc++.h>
using namespace std;

// 1 + least significant 1-bit of x, 0 if x == 0
// __builtin_ffs(x); // int
// __builtin_ffsl(x); // long
// __builtin_ffsll(x); // long long

// number of leading 0-bits of x starting from most significant bit position,
// undefined if x == 0
// __builtin_clz(x); // unsigned int
// __builtin_clzl(x); // unsigned long
// __builtin_clzll(x); // unsigned long long

// number of trailing 0-bits of x starting from least significant bit position,
// undefined if x == 0
// __builtin_ctz(x); // unsigned int
// __builtin_ctzl(x); // unsigned long
// __builtin_ctzll(x); // unsigned long long

// number of 1-bits of x, undefined if x == 0
// __builtin_popcount(x); // unsigned int
// __builtin_popcountl(x); // unsigned long
// __builtin_popcountll(x); // unsigned long long

typedef pair<int, int> pii;
typedef vector<pii> vii;

bool isOdd(int num) { return (num & 1); }
int multBy2(int num) { return num << 1; }
int divBy2(int num) { return num >> 1; }
int builtInGCD(int x, int y) { return __gcd(x, y); }
int numberOfDigits(int num) { return floor(log10(num)) + 1; }
bool isPowerOf2(int x) { return x && (!(x & (x - 1))); }; // for positive integers

void printBinaryRep(int x) {
   cout << bitset<32>(x).to_string() << endl;
}

// variadic function
// int sum() { return 0; }
// template<typename T, typename... Args>
// T sum(T a, Args... args) { return a + sum(args...); }


int main() {

   //cout << sum(5,7,2,2) + sum(3.14,4.89) << endl;

   
   printBinaryRep(10);
   printBinaryRep(INT_MAX);
   printBinaryRep(INT_MIN);
   return 0;


   
   int n = 5, m = 3, c = 15;
   int i, j;
   int a[n+1][m+1];
   for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
	 a[i][j] = c++;

   for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++)
	 cout << setw(6) << a[i][j] << ' ';
      cout << endl;
   }
   cout << "--------------" << endl;   
   // equivalent
   for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
	 cout << setw(6) << a[i][j] << " \n"[j == m];

   
   // for (unsigned int i = 0; i < 10; i++) {
   //    cout << i << ' ' << __builtin_clz(i) << endl;
   // }
   // return 0;
   
   // for (long long i = 0; i < 10; i++) {
   //    cout << i << " : " << __builtin_ffsll(i) << endl;
   // }
   // return 0;


   
   // vii vec;
   // vec.push_back({3, 4});

   // for (const auto &i : vec) {
   //    cout << i.first << ' ' << i.second << endl;
   // }

   
   
   return 0;
}
