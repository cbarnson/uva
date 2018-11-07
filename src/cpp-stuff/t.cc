// Problem #    : t
// Created on   : 2018-11-01 07:41:02
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vi a = {1, 2, 3, 4};
  vi b = {6, 2, 3, 4};

  // number of occurrences of a[i] > b[i]
  // output: 0
  int x =
      inner_product(begin(a), end(a), begin(b), 0, plus<int>{}, greater<int>{});

  // count # of a[i] <= b[i]
  // output: 4
  int y = inner_product(begin(a), end(a), begin(b), 0, plus<int>{},
                        less_equal<int>{});
  cout << x << " " << y << endl;

  string s = "ABCabc";
  for (char c : s) {
    cout << setw(3) << c << setw(3) << (char)(c | 0x20) << setw(3)
         << (char)(c & ~0x20) << endl;
  }

  // 'accumulate' to get length of largest string in vector of strings
  vector<string> vs = {"hello", "abc", "!", "", "worlda"};
  auto z = accumulate(begin(vs), end(vs), 0u,
                      [](size_t i, string str) { return max(i, str.size()); });
  cout << z << endl;
}
