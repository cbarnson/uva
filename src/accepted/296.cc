#include <bits/stdc++.h>
using namespace std;

int indexVal(int val, int index) {
  for (int i = 0; i < index; i++)
    val = val / 10;   
  return (val % 10);
}

bool isValid(int x, int g, int cr, int cw) {

  // cr - correct and right position
  bool match[4];
  fill(match, match+4, false);
  for (int i = 0; i < 4; i++) {
    if (indexVal(x, i) == indexVal(g, i))
      match[i] = true;
  }
  int mcount = count(match, match+4, true);
  if (mcount != cr) return false;
   
  // cw - correct and wrong position
  bool used[4];
  copy(match, match+4, used);
  int cwcount = 0;
  for (int i = 0; i < 4; i++) {
    if (!match[i]) {
      for (int j = 0; j < 4; j++) {
        if (i != j && !used[j] && (indexVal(x,j) == indexVal(g,i))) {
          cwcount++;
          used[j] = true;
          break;
        }
      }
    }
  }
  if (cwcount != cw) return false;
  return true;
}

int main() {

  int cases; cin >> cases;
  while (cases--) {
    
    int num_g; cin >> num_g;
    cin.ignore();
    
    int g[10]; // the guesses
    int a[10]; // correct && right place
    int b[10]; // correct && wrong place
    for (int i = 0; i < num_g; i++) {
      string s;
      getline(cin, s);
      replace_if(s.begin(), s.end(),
                 [](char c) { return c == '/'; }, ' ');
      istringstream iss(s);
      string gg, aa, bb;
	 
      iss >> gg >> aa >> bb;
      g[i] = stoi(gg);
      a[i] = stoi(aa);
      b[i] = stoi(bb);
    }

    // contains the possible solutions
    vector<int> v;

    // do a 'consistency' check on every possible solution
    // using the information given in the 'guesses'
    for (int i = 0; i < 10000; i++) { // from 0000 to 9999
      bool good = true;
      for (int j = 0; j < num_g; j++) {
        if (!isValid(i, g[j], a[j], b[j])) {
          good = false;
          break;
        }
      }
      // still good? Is a possible solution
      if (good)
        v.push_back(i);
    }

    // output answer
    if (v.empty())
      cout << "impossible";
    else if (v.size() > 1)
      cout << "indeterminate";
    else
      cout << setw(4) << setfill('0') << v[0];
    cout << endl;      
  }

  return 0;
}
