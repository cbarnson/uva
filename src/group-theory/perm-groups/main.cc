#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

const int width = 4;

void print(vector<int> &V, string s) {
  int n = V.size();
  string pre = s + " = ";
  cout << pre;
  FR(i, n) cout << setw(width) << i+1;
  cout << endl;
  cout << setw(pre.length()) << "";
  FR(i, n) cout << setw(width) << V[i];
  cout << endl << endl;
}

class permutationGroup {
public:
  vi A;
  vector<vi> C;
  int n;
  string name;

  permutationGroup(const vector<int> &V, string name) {
    A = V;
    n = A.size();
    this->name = name;
  }

  permutationGroup operator^(int n) {
    string s = name + to_string(n);
    assert(n > 1);
    auto B = permutationGroup(A, "");
    auto S = permutationGroup(A, s);
    for (int i = 1; i < n; i++) {
      S = S * B;
    }
    return S;
  }
  
  permutationGroup operator*(const permutationGroup &pg) {
    string s = name + pg.name;
    assert(n == pg.n);
    vi C(n);
    FR(i, n) {
      C[i] = A[pg.A[i]-1];
    }
    return permutationGroup(C, s);
  }

  void cycles() {
    computeCycles();
    printCycles();
  }

  void cycles(permutationGroup &B) {

    computeCycles();
    B.computeCycles();

    vi vis(n, 0);
    vector<vi> ans;
    
    while (1) {

      int k = -1;
      for (int i = 0; i < n; i++) {
	if (!vis[i]) {
	  k = i; break;
	}
      }
      if (k == -1) break;
      int s = k;

      // vi V(1, k);
      // while (1) {
      // 	for (int i = B.C.size() - 1; i >= 0; i--) {
      // 	  int m = B.C[i].size();
      // 	  for (int j = 0; j < m; j++) {
      // 	    if (B.C[i][j] == k+1) {
      // 	      k = (B.C[i][(j + 1) % m];
      // 	    }
      // 	  }
      // 	}
      // }
      
    }
    
  }
  
  void computeCycles() {

    // vis[i] == 1 if used in some disjoint cycle
    C.clear();
    vi vis(n, 0);
    while (1) {

      int k = -1;
      for (int i = 0; i < n; i++) {
	if (!vis[i]) {
	  k = i; break;
	}
      }

      if (k == -1) break;

      int s = k;

      vi B(1, k);
      k = A[k] - 1;
      while (k != s) {
      	B.push_back(k);
      	k = A[k] - 1;
      }

      for (auto &x : B) vis[x] = 1, x = A[x];
      C.push_back(B);      
    }

  }

  void printCycles() {
    cout << "cycles(" << name << ") = ";
    for (int i = 0; i < C.size(); i++) {
      for (int j = 0; j < C[i].size(); j++) {
	if (C[i].size() == 1) continue;
	cout << (j == 0 ? "(" : "") << C[i][j] << (j == C[i].size() - 1 ? ")" : "");
      }
    }
    cout << endl << endl;
  }

  void print() {
    string pre = name + " = ";
    cout << setw(width * 2) << pre;
    FR(i, n) cout << setw(width) << i+1;
    cout << endl;
    cout << setw(width*2) << "";
    FR(i, n) cout << setw(width) << A[i];
    cout << endl << endl;
  }
};

int main() {
  
  int t;
  cin >> t;
  while (t--) {


    int m;
    cin >> m;

    vector<int> P(m), Q(m), C(m);

    for (auto &x : P) cin >> x;
    for (auto &x : Q) cin >> x;


    permutationGroup A(P, "a"), B(Q, "B");
    A.print();
    B.print();

    A.cycles();
    B.cycles();

    
    auto BB = B * B; BB.print(); BB.cycles();
    auto BBB = BB * B; BBB.print(); BBB.cycles();
    auto BBBB = BBB * B; BBBB.print(); BBBB.cycles();
    
    auto B2 = B ^ 2; B2.print(); B2.cycles();
    auto B3 = B ^ 3; B3.print(); B3.cycles();
    auto B4 = B ^ 4; B4.print(); B4.cycles();

    auto B99 = B ^ 99; B99.print(); B99.cycles();


    for (int i = 2; i < 20; i++) {
      auto Bi = B ^ i; Bi.cycles();
    }
    
    // auto aB = A * B; aB.print();
    // auto Ba = B * A; Ba.print();
    // auto aa = A * A; aa.print();
    // auto BB = B * B; BB.print();
    // auto aab = A * aB; aab.print();
    
  }

}
