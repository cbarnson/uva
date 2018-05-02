#include <bits/stdc++.h>
using namespace std;


int main() {

  int n, p, cn = 1;
  while (cin >> n >> p && !(n == 0 && p == 0)) {
    if (cn > 1)
      cout << endl;
    cout << "RFP #" << cn++ << endl;
    
    string s, best = "";
    int best_req = 0;
    double best_price = numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
      getline(cin >> ws, s);
    }

    for (int i = 0; i < p; i++) {
      getline(cin >> ws, s);
      double pr;
      int rm;
      cin >> pr >> rm;
      for (int j = 0; j < rm; j++) {
        string ss;
        getline(cin >> ws, ss);
      }
      if (rm > best_req || (rm == best_req && pr < best_price)) {
        best = s;
        best_req = rm;
        best_price = pr;        
      }
    }

    cout << best << endl;
    

  }

  return 0;
}
