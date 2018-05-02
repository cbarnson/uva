//================================
//UVA problem#: 793
//CPSC 3200,	2017-02-02
//Cody Barnson,	ID#001172313
//================================

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
  struct UF { int p; int rank; };

public:
  UnionFind(int n) {          // constructor
    howMany = n;
    uf = new UF[howMany];
    for (int i = 0; i < howMany; i++) {
      uf[i].p = i;
      uf[i].rank = 0;
    }
  }

  ~UnionFind() {
    delete[] uf;
  }

  int find(int x) { return find(uf,x); }        // for client use
      
  bool merge(int x, int y) {
    int res1, res2;
    res1 = find(uf, x);
    res2 = find(uf, y);
    if (res1 != res2) {
      if (uf[res1].rank > uf[res2].rank) {
        uf[res2].p = res1;
      }
      else {
        uf[res1].p = res2;
        if (uf[res1].rank == uf[res2].rank) {
          uf[res2].rank++;
        }
      }
      return true;
    }
    return false;
  }
      
private:
  int howMany;
  UF* uf;

  int find(UF uf[], int x) {     // recursive funcion for internal use
    if (uf[x].p != x) {
      uf[x].p = find(uf, uf[x].p);
    }
    return uf[x].p;
  }
};


// use Howards UnionFind class to determine if two elements are in the same set
// i.e. 'connected' in the network
int main() {
   
  int num_cases = 0;
  cin >> num_cases;
  while (num_cases--) {
      
    int n;
    cin >> n;
    cin.ignore();

    int good = 0, bad = 0;

    UnionFind uf(n);
    string s = "";
    getline(cin, s);
    while (s != "") {
      istringstream iss(s);
      char c;
      int i, j;
      iss >> c >> i >> j;	 
      i--; j--; // adjustment to 0-based
      if (c == 'c') {
        uf.merge(i, j);
      } else { // c == 'q'
        if (uf.find(i) != uf.find(j)) {
          bad++;
        } else {
          good++;
        }
      }

      s = "";
      getline(cin, s);
    }

    cout << good << "," << bad << endl;

    // newline only between consecutive cases
    if (num_cases) cout << endl;
  }
   
  return 0;
}
