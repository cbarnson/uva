#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   map<string, string> map;
   string nam, ip;
   FR(i, n) {
     cin >> nam >> ip;
     map.emplace(ip, nam);
   }

   FR(i, m) {
     string cmd;
     cin >> cmd >> ws;
     getline(cin, ip, ';');
     cout << cmd << " " << ip << "; #" << map[ip] << endl;
   }
   
}


