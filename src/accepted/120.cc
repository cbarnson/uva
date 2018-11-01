// Problem #    : 120
// Created on   : 2018-10-31 22:41:07
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

vi input() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  vi A;
  int x;
  while (ss >> x) A.push_back(x);
  return A;
}

vi solve(vi &A) {
  int n = A.size();
  vi ans;
  do {
    int j = max_element(begin(A), end(A)) - begin(A);
    if (j != A.size() - 1) {
      if (j) {
        reverse(begin(A), begin(A) + j + 1);
        ans.push_back(n - j);
      }
      reverse(begin(A), end(A));
      ans.push_back(n - (A.size() - 1));
    }
    A.pop_back();
  } while (A.size() > 1);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while (1) {
    vi A = input();
    if (A.empty()) break;
    FR (i, A.size())
      cout << (i ? " " : "") << A[i];
    cout << endl;
    vi ans = solve(A);
    FR (i, ans.size())
      cout << ans[i] << " ";
    cout << 0 << endl;
  }
}
