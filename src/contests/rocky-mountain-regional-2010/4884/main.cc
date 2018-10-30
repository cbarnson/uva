#include <bits/stdc++.h>
using namespace std;

int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
   string line;
   while (getline(cin, line)) {
      unordered_map<int, pair<int, int> > mm;

      istringstream iss(line);
      char ch;
      int r = 0, c = 0;
      vector<int> vr;
      vector<int> vc;

      // vr.push_back(r);
      // vc.push_back(c);
      mm.insert(make_pair(r, make_pair(c, c)));
      while (iss >> ch) {
	 int x = ch - '0';
	 r += di[x];
	 c += dj[x];

	 // vr.push_back(r);
	 // vc.push_back(c);
	 auto it = mm.find(r);
	 if (it != mm.end()) {
	    it->second.first = min(it->second.first, c);
	    it->second.second = max(it->second.second, c);
	 } else {
	    mm.insert(make_pair(r, make_pair(c, c)));
	 }
      }

      // for (auto &it : vr) {
      // 	 cout << setw(3) << it << " ";
      // }
      // cout << endl;
      // for (auto &it : vc) {
      // 	 cout << setw(3) << it << " ";
      // }
      // cout << endl << endl;

      int total = 0;
      for (auto &it : mm) {
      	 total += abs(it.second.first - it.second.second) + 1;
      }
      cout << total << endl;
   }

   return 0;
}
