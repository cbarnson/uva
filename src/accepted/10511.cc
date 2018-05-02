// Cody Barnson
// 10511 - Councilling

#include <bits/stdc++.h>

using namespace std;

struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
   int to;
   int cap;
   int flow;
   bool is_real;
   EdgeIter partner;
  
   Edge(int t, int c, bool real = true)
      : to(t), cap(c), flow(0), is_real(real)
   {};

   int residual() const
   {
      return cap - flow;
   }
};

struct Graph {
   list<Edge> *nbr;
   int num_nodes;
   Graph(int n)
      : num_nodes(n)
   {
      nbr = new list<Edge>[num_nodes];
   }

   ~Graph()
   {
      delete[] nbr;
   }

   void add_edge(int u, int v, int cap)
   {
      nbr[u].push_front(Edge(v, cap));
      nbr[v].push_front(Edge(u, 0, false));
      nbr[v].begin()->partner = nbr[u].begin();
      nbr[u].begin()->partner = nbr[v].begin();
   }
};

void push_path(Graph &G, int s, int t, const vector<EdgeIter> &path, int flow)
{
   for (int i = 0; s != t; i++) {
      if (path[i]->is_real) {
	 path[i]->flow += flow;
	 path[i]->partner->cap += flow;
      } else {
	 path[i]->cap -= flow;
	 path[i]->partner->flow -= flow;
      }
      s = path[i]->to;
   }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
int augmenting_path(const Graph &G, int s, int t, vector<EdgeIter> &path,
		    vector<bool> &visited, int step = 0)
{
   if (s == t) {
      return -1;
   }
   for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
      int v = it->to;
      if (it->residual() > 0 && !visited[v]) {
	 path[step] = it;
	 visited[v] = true;
	 int flow = augmenting_path(G, v, t, path, visited, step+1);
	 if (flow == -1) {
	    return it->residual();
	 } else if (flow > 0) {
	    return min(flow, it->residual());
	 }
      }
   }
   return 0;
}

// note that the graph is modified
int network_flow(Graph &G, int s, int t)
{
   vector<bool> visited(G.num_nodes);
   vector<EdgeIter> path(G.num_nodes);
   int flow = 0, f;

   do {
      fill(visited.begin(), visited.end(), false);
      if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
	 push_path(G, s, t, path, f);
	 flow += f;
      }
   } while (f > 0);  
   return flow;
}

int main() {

   // representation of node for source and sink
   int source = 3000, sink = 3001;
   
   // read number of cases
   int n;
   cin >> n >> ws;

   while (n--) {
      map<string, int> party;
      map<string, int> club;
      map<int, string> iparty;
      map<int, string> iclub;
      int ip = 1000, ic = 2000;

      vector< pair< string, vector<int> > > input;
      
      string line;
      while (getline(cin, line) && line != "") {

	 string resident, str;
	 vector<int> info;
	 istringstream iss(line);
	 iss >> resident;
	 
	 // party, insert map entries if necessary, otherwise use
	 // integer value for corresponding party name string
	 iss >> str;
	 int id;
	 auto it = party.find(str);
	 if (it == party.end()) {
	    id = ip++;
	    party.insert(make_pair(str, id));
	    iparty.insert(make_pair(id, str));
	 } else
	    id = party[str];
	 info.push_back(id);

	 // clubs, insert map entries if necessary, otherwise use
	 // integer value for corresponding club name strings
	 // (kept in separate maps from parties)
	 while (iss >> str) {
	    auto it = club.find(str);
	    if (it == club.end()) {
	       id = ic++;
	       club.insert(make_pair(str, id));
	       iclub.insert(make_pair(id, str));
	    } else 
	       id = club[str];	    
	    info.push_back(id);
	 }
	 input.push_back(make_pair(resident, info));
      }

      // Network flow graph, extra two nodes for source and sink
      Graph g(3002);
      int sz = club.size();
      if (sz < 3) {
	 cout << "Impossible." << endl;
	 if (n) cout << endl;
	 continue;
      }

      // weight of each edge from source to party
      int sflow = (sz - 1) / 2;
      for (unsigned int i = 0; i < input.size(); i++) {
	 // connect party to person
	 g.add_edge(input[i].second[0], i, 1);
	 // connect person to club
	 for (unsigned int j = 1; j < input[i].second.size(); j++)
	    g.add_edge(i, input[i].second[j], 1);
      }

      // Add edge from source to party for each unique party
      for (auto &it : party)
	 g.add_edge(source, it.second, sflow);
      // Add edge from club to sink for each unique club
      for (auto &it : club) 
	 g.add_edge(it.second, sink, 1);

      int flow = network_flow(g, source, sink);
      if (flow < sz) {
	 cout << "Impossible." << endl;
	 if (n) cout << endl;
	 continue;
      }

      for (unsigned int i = 0; i < input.size(); i++) {
	 for (auto &j : g.nbr[i])
	    if (j.flow > 0 && j.is_real)
	       cout << input[i].first << " " << iclub[j.to] << endl;	 
      }
      if (n) cout << endl;
   }

  
   return 0;
}


