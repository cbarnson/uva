// Problem #    : next_bracket_sequence_lexicographical
// Created on   : 2018-11-01 21:53:58
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
#define PR(a, n)                             \
  {                                          \
    cout << #a << " = ";                     \
    FR(i, n) cout << (i ? " " : "") << a[i]; \
    cout << endl;                            \
  }
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // Given a bracket sequence (that is correct), find next correct bracket
  // sequence (next lexicographical order), or "No solution" if none exists.
  // Sample:
  // ()     -> No solution
  // (())   -> ()()
  // ()()   -> No solution
  // ((())) -> (()())
  // (()()) -> (())()
  // (())() -> ()(())
  string s;
  cin >> s;
  int n = (int)s.length();
  string ans = "No solution";
  for (int i = n - 1, depth = 0; i >= 0; --i) {
    if (s[i] == '(')
      --depth;
    else
      ++depth;
    if (s[i] == '(' && depth > 0) {
      --depth;
      int open = (n - i - 1 - depth) / 2;
      int close = n - i - 1 - open;
      ans = s.substr(0, i) + ')' + string(open, '(') + string(close, ')');
      break;
    }
  }
  cout << ans;
}
