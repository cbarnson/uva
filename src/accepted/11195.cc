#include <bits/stdc++.h>
using namespace std;

// true if a queen may not occupy this space
bool ban[15][15];

// d represents our 'depth' in the recursion, i.e. the row index
int ways(int n, vector<int> b, int d, bool col[15], bool di[29],
	 bool rdi[29]) {
  // if we get here, we have a correct solution
  if (d == n) return 1;

  // for each column index, if its column, diagonal, and reverse
  // diagonal is clear, and the space is not banned, set those
  // locations to true, recurse, then unset them.
  int total = 0;
  for (int i = 0; i < n; i++) {    
    int r = d, c = i;            
    if (col[c] || di[r+c] || rdi[(n-r-1)+c] || ban[r][c]) continue;
    // set
    col[c] = true;
    di[r+c] = true;
    rdi[(n-r-1)+c] = true;            
    // call
    b[r] = c;
    total += ways(n, b, d+1, col, di, rdi);      
    // unset
    col[c] = false;
    di[r+c] = false;
    rdi[(n-r-1)+c] = false;      
  }
  return total;
}



int main() {

  string s;
  getline(cin, s);
  int n = stoi(s);
  int cases = 1;
  while (n != 0) {
    
    for (int i = 0; i < n; i++) {
      getline(cin, s);
      for (int j = 0; j < n; j++) 
        if (s[j] == '*') {
          ban[i][j] = true;
        } else {
          ban[i][j] = false;
        }	 
    }

    // will be passed recursively to each ways call
    bool col[15];
    bool di[29];
    bool rdi[29];
    fill(col, col+15, false);
    fill(di, di+29, false);
    fill(rdi, rdi+29, false);

    // the 'board', represented by an array of ints, each
    // integer in the ith position represents the location of
    // a queen in the jth column (represented by the integer)
    vector<int> b(n);
    fill(b.begin(), b.end(), 0);
    int result = ways(n, b, 0, col, di, rdi);

    // number of solutions
    cout << "Case " << cases++ << ": " << result << endl;
    getline(cin, s);
    n = stoi(s);
  }

  return 0;

}
