// Problem #    : 362
// Created on   : 2018-08-10 18:23:19

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; // pair of ints
typedef vector<int> vi;    // 1d vector of ints
typedef vector<ii> vii;    // 1d vector of pairs
typedef vector<vi> vvi;    // 2d vector of ints

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int b, t, x, tc = 1;
  while (cin >> b && (b)) {
    cout << "Output for data set " << tc++ << ", " << b << " bytes:\n";
    list<int> l;
    t = 0;
    while (b > 0) {
      cin >> x;
      b -= x, l.push_front(x), t++;
      if (l.size() > 5)
        l.pop_back();

      if (t % 5 == 0) {
        cout << "   Time remaining: ";
        double avg = 0;
        for (auto &i : l)
          avg += (double)i;
        if (avg > 0)
          // Note: make sure we multiply the 5 by the quotient, rather than
          // divide avg by 5, then divide b by avg.  Otherwise we get "Wrong
          // Answer" from online judge, likely edge case around rounding.  Just
          // be careful.
          cout << setprecision(0) << fixed << ceil(5.0 * ((double)b / avg))
               << " seconds\n";
        else
          cout << "stalled\n";
      }
    }
    cout << "Total time: " << t << " seconds\n\n";
  }

  return 0;
}
