// Problem #    : t1
// Created on   : 2018-11-01 08:02:01
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vi a = {1, 2, 3};
  copy_if(begin(a), end(a), ostream_iterator<int>(cout, " "),
          [](int x) { return x < 4; });

  cout << endl;

  cout << to_string(3.14) << endl;
  cout << to_string(12LL) << endl;

  const string number = "001234";
  auto toUInt = accumulate(
      begin(number), end(number), 0u,
      [](unsigned curr, char nxt) { return curr * 10u + nxt - '0'; });
  cout << toUInt << endl;

  // convert to int32
  auto mult = number[0] == '-' ? -1 : 1;
  auto realBegin = mult > 0 ? begin(number) : next(begin(number));
  auto toInt =
      mult * accumulate(realBegin, end(number), 0, [](int curr, char nxt) {
        return curr * 10 + nxt - '0';
      });
  cout << toInt << endl;

  auto i = stoi("10");
  auto dbl = stod("10.123");

  cout << i << endl << dbl << endl;

  // cout << accumulate(next(istream_iterator<int>(cin)),
  // istream_iterator<int>(),
  //                    0)
  //      << endl;
}
