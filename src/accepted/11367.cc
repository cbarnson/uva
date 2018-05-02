// Cody Barnson
// 11367
#include <bits/stdc++.h>
using namespace std;

const int NN = 1000;
const int CC = 100;

// index: city number
// fuel : remaining fuel at a given edge state
// cost : the 'cost', in fuel units, to cross an edge; (also) an
// accumulating quantity representing the cost so far
struct edge {
   int index, fuel, cost;
   edge(int i, int f, int c) : index(i), fuel(f), cost(c) { }
   bool operator<(const edge& e) const { return cost > e.cost; }
};

// n cities, m edges (roads)
int n, m;
int cost[NN][CC+1];
int price[NN];
vector<edge> g[NN];

int dijk(int cap, int start, int end) {
   // initialize
   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= cap; j++) {
	 cost[i][j] = INT_MAX;
      }
   }

   // uses overloaded < to function as greater than
   priority_queue<edge> pq;
   
   // source
   cost[start][0] = 0;
   pq.push(edge(start, 0, 0));

   // main loop
   while (!pq.empty()) {
      // current
      edge c = pq.top();
      pq.pop();

      // are we done?
      if (c.index == end)
	 return c.cost;

      // have we seen this state before and a better route exists
      if (cost[c.index][c.fuel] < c.cost) continue;

      // if not at full capacity AND the resulting state from adding fuel is less
      // than the best so far, add 1 unit of fuel at current city
      if (c.fuel < cap &&
	  c.cost + price[c.index] < cost[c.index][c.fuel+1]) {
	 cost[c.index][c.fuel+1] = c.cost + price[c.index];
	 pq.push(edge(c.index, c.fuel+1, c.cost + price[c.index]));
      }

      // for each outgoing edge, for which we have enough fuel to reach
      // the destination city, add the resulting state to our priority queue
      int sz = g[c.index].size();
      for (int i = 0; i < sz; i++) {
	 int dist = g[c.index][i].cost;
	 int dest = g[c.index][i].index;
	 if (c.fuel >= dist) {
	    int left = c.fuel - dist;
	    if (c.cost < cost[dest][left]) {
	       // since we can get to 'dest' without paying for any more fuel
	       // than we already have, add the new edge state.
	       // Note that the new state has the same 'cost', only a different
	       // 'fuel' quantity
	       cost[dest][left] = c.cost;
	       pq.push(edge(dest, left, c.cost));
	    }
	 }
      }
   } // end of while
   return INT_MAX;
}

int main() {

   
   // initialize g and read prices for each city
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      cin >> price[i];
      g[i].clear();
   }

   // read edges
   for (int i = 0; i < m; i++) {
      int u, v, d;
      cin >> u >> v >> d;
      g[u].push_back(edge(v, 0, d));
      g[v].push_back(edge(u, 0, d));
   }

   // queries
   int q;
   cin >> q;
   while (q--) {
      int c, s, e;
      cin >> c >> s >> e;
      int min = dijk(c, s, e);
      if (min == INT_MAX) {
	 cout << "impossible" << endl;
      } else {
	 cout << min << endl;
      }
   }

   return 0;
}
