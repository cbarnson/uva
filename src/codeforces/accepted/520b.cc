// Problem #    : 520b
// Created on   : 2018-10-24 11:17:44
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    


int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   vector<vi> g(2 * 10000 + 1, vi());

   for (int i = 1; i <= 2 * 10000; i++) {
      if (i - 1 >= 1) g[i].push_back(i - 1);
      if (i * 2 <= 2 * 10000) g[i].push_back(i * 2);
   }

   vi D(2 * 10000 + 1, -1);
   queue<int> q;
   q.emplace(n);

   while (!q.empty()) {
      int u = q.front();
      q.pop();
      
      if (u == m) {
	 cout << D[u] + 1 << endl;
	 return 0;
      }
      
      for (auto &v : g[u]) {
	 if (D[v] == -1) {
	    D[v] = D[u] + 1;
	    q.emplace(v);
	 }
      }
   }

}
