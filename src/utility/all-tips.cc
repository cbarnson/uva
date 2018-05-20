// Tips and tricks

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

// PREPROCESSOR DIRECTIVES - MACROS
#define bitcount __builtin_popcount
#define GCD __gcd
#define INF (int)1e9
#define EPS 1e-9
#define mp make_pair
#define pb push_back
#define sz(a) ((int)(a.size()))

typedef vector<vector<int>> vec2d;
typedef vector<int> vi;
typedef pair<int, int> ii;

// bitwise - check if a number is odd
bool isOdd(int num) { return (num & 1); }

// bitwise multiply by 2
int multBy2(int num) { return num << 1; }

// bitwise divid-by-2
int divBy2(int num) { return num >> 1; }

// Number of digits of a base-10 number
int numberOfDigits(int num) { return floor(log10(num)) + 1; }

// Greatest common divisor of two numbers
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

// Greatest common divisor of more than two numbers
int gcd(int a, int b, int c) { return gcd(a, gcd(b, c)); }

// Least common multiple of two numbers
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

// for positive integers >= 0
bool isPowerOf2(int x) { return x && (!(x & (x - 1))); };

// print the binary representation of an int
void printBinaryRep(int x) { cout << bitset<32>(x).to_string() << endl; }

// rounds a floating point value to the nearest integer
int roundNearest(double val) {
  int answer = (int)((double)val + 0.5);
  return answer;
}

// VECTOR - 1. initialization of 2D vector
void init2DVec() {
  int ROWS = 3, COLS = 4, DEFAULT_VALUE = 5;
  vector<vector<int>> a(ROWS, vector<int>(COLS));
  vector<vector<int>> b(ROWS, vector<int>(COLS, DEFAULT_VALUE));
  vector<vector<int>> c{{1, 2, 3}, {4, 5, 6}};
}

// VECTOR - 2. initialize and read-in for 2D vector
void initAndRead2DVec() {
  int M = 3, N = 4;
  vector<vector<int>> mat;
  mat.resize(M);
  for (auto &i : mat) {
    i.reserve(N);
    copy_n(istream_iterator<int>(cin), N, back_inserter(i));
  }
  // To reuse across several "cases", remember to resize back to 0 to clear
  mat.resize(0);
}

// VECTOR - 3. Print a 2D vector
void print2DVec() {
  vector<vector<int>> v;
  for (auto &i : v) {
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}

// VECTOR - 4. Read and write 1D vector
void readAndWrite1DVec() {
  int n = 3;
  vector<int> v;

  // reserve 'possibly' allocates memory
  v.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(v));

  copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
  cout << endl;
}

// VECTOR - 5.
void vec() {
  int n;
  cin >> n;

  vector<int> v;
  v.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(v));

  // print a sequence
  copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
  cout << "\n";

  // print a sequence with a separator, but not after last element
  copy(begin(v), end(v) - 1, ostream_iterator<int>(cout, ", "));
  cout << v.back() << endl;

  // find min difference in the sorted vector
  auto mindiff = inner_product(begin(v), end(v) - 1, begin(v) + 1,
                               numeric_limits<int>::max(),
                               [](int l, int r) { return min(l, r); },  // "sum"
                               [](int l, int r) { return r - l; }  // "product"
  );
  cout << mindiff << endl;

  // Note: simplest overload of inner_product returns the result of accumulating
  // a starting value "init" with the inner products of pairs formed by the
  // elements of 2 ranges
  // init += range1[0]*range2[0] + range1[1]*range2[1] + ... +
  // range1[N-1]*range2[N-1] Thus, both + and * can be overloaded for your needs
}

// STRING - 1.
void stringDemo1() {
  // string comparison
  string a = "hello";
  string b = "hell";
  auto areEqual = a.compare(b) == 0;
  // returns positive if a lexicographically > b
  // returns negative if a lexicographically < b
  // 0 if equal

  // check if a string is a prefix of another
  string prefix = b;
  auto isPrefix = a.compare(0, prefix.size(), prefix) == 0;
}

// MATH - 1. Get a list (asc order) of all the distinct divisors of a number
vector<int> getDivisors(int n) {
  vector<int> v;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        v.push_back(i);
      } else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  sort(v.begin(), v.end());
  return v;
}

// MATH - 2. Common constants
const double PI = acos(-1.0);
const double E = exp(1.0);

// SHORTCUTS - Initializer list as argument
template <typename T>
void printInitList(initializer_list<T> l) {
  for (const auto &i : l) cout << i << ' ';
  cout << endl;
}

// variadic function
// int sum() { return 0; }
// template<typename T, typename... Args>
// T sum(T a, Args... args) { return a + sum(args...); }

int main() {
  int n;
  cin >> n;
  cout << n;

  return 0;
}
