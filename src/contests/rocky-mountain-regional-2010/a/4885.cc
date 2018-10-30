#include <bits/stdc++.h>

#define HI 0
#define LO std::numeric_limits<int>::max()

using namespace std;

typedef int Edge;
typedef vector<Edge>::iterator EdgeIter;


struct edge {
   int to, lo, hi;
   edge(int i, int j, int k) : to(i), lo(j), hi(k) { }
   // edge() { to = -1; lo = 0; hi = HI; }
      
};

struct node {
   int lo, hi;
   node(int j, int k) : lo(j), hi(k) { }
   node() { lo = 1; hi = numeric_limits<int>::max(); }
};

struct Graph {
   vector<edge> *nbr;
   int num_nodes;
   Graph(int n) : num_nodes(n) {
      nbr = new vector<edge>[num_nodes];
   }
   ~Graph() {
      delete[] nbr;
   }

   bool exists(int from, int to) {
      for (auto &e : nbr[from]) {
	 if (e.to == to)
	    return true;
      }
      return false;
   }

   void print() {
      for (unsigned int i = 1; i < num_nodes; i++) {
	 for (auto &e : nbr[i]) {
	    cout << i << " --> " << e.to << ", [" << e.lo << "," << e.hi
		 << "]" << endl;
	 }
      }
   }
   
   // does a duplicate check
   void add_edge(int u, int v, int lo, int hi) {
      for (auto &e : nbr[u]) {
	 if (e.to == v) {
	    if (e.lo == LO) e.lo = lo;
	    if (e.hi == HI) e.hi = hi;
	    return;
	 }
      }
      // else, does not exist, create new edge
      nbr[u].push_back(edge(v, lo, hi));
   }
};

bool dfs(int u, Graph& g, vector<bool>& seen, vector<node>& time) {

   seen[u] = true;
   if (g.nbr[u].empty()) return true;
   
   for (auto &e : g.nbr[u]) {

      int j = e.to;
      int lo = time[u].lo + e.lo;
      int hi = time[u].lo + e.hi;
      if (!seen[j]) {	 
	 time[j].lo = lo;
	 time[j].hi = hi;
      } else {
	 time[j].lo = lo;
	 time[j].hi = hi;
      }
      
      // failure condition
      if (time[j].hi - time[j].lo < 0) {
	 return false;
      }

      return dfs(e.to, g, seen, time);
   }
   return true;
}

bool topsort(const Graph& g, vector<int>& order, vector<int>& start) {
   vector<int> deg(g.num_nodes);
   fill(deg.begin(), deg.end(), 0);
   for (int i = 1; i < g.num_nodes; i++) {
      for (auto &e : g.nbr[i]) {
	 deg[e.to]++;
      }
   }

   start.clear();
   queue<int> q;
   for (int i = 1; i < g.num_nodes; i++) {
      if (deg[i] == 0) {
	 q.push(i);
	 start.push_back(i);
      }
   }

   order.clear();
   while (!q.empty()) {
      int x = q.front(); q.pop();
      order.push_back(x);
      for (auto &e : g.nbr[x]) {
	 if (--deg[e.to] == 0)
	    q.push(e.to);
      }
   }

   return order.size() == (g.num_nodes - 1);
}


int getTime(int u, Graph& g, vector<node>& time) {
   for (auto &e : g.nbr[u]) {
      time[u].lo = time[e.to].lo - e.lo;
      time[u].hi = time[e.to].hi - e.lo;
   }
   return time[u].lo;
}

void update(Graph& g, vector<node>& time) {
   for (unsigned int i = 1; i < g.num_nodes; i++) {
      for (auto &e : g.nbr[i]) {
	 time[i].lo = time[e.to].lo - e.lo;
	 time[i].hi = time[e.to].hi - e.lo;
      }
   }
}


// task i starts at least A minutes later than task j
// task i starts within A minutes of the starting time of task j
int main() {

   
   int n, m;
   while (cin >> n && n != 0) {
      cin >> m >> ws;
      Graph g(n+1);

      string s;
      while (m-- && getline(cin, s)) {
	 istringstream iss(s);
	 int i, j, A;
	 iss >> s; iss >> i;
	 iss >> s >> s;
	 if (s == "at") { // at least
	    iss >> s >> A;
	    iss >> s >> s >> s >> s >> j;
	    g.add_edge(j, i, A, HI);
	 } else { // within
	    iss >> A;
	    int x = 7; while (x--) iss >> s;
	    iss >> j;
	    g.add_edge(j, i, LO, A);
	 }
      }

      vector<int> order;
      vector<int> start;
      if (topsort(g, order, start)) {
	 vector<bool> seen(n+1, false);
	 vector<node> time(n+1);
	 
	 for (unsigned int i = 0; i < start.size(); i++) {
	    if (start[i] == 0) continue;
	    if (dfs(start[i], g, seen, time) == false)
	       goto impossible;
	    
	 }

	 update(g, time);
	 for (int i = 1; i < n; i++)
	    cout << time[i].lo << " ";
	 cout << time[n].lo << endl;

	 continue;
      }
     impossible:
      cout << "Impossible." << endl;
   }
   

   return 0;
}

