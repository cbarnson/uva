//================================
//UVA problem#: 10415
//CPSC 3200,	2017-01-13
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

string key = "cdefgabCDEFGAB";
// note: "this value array makes the problem more complicated
// than it needs to be..." better way
string value[14] = {
  "1236789",
  "123678",
  "12367",
  "1236",
  "123",
  "12",
  "1",
  "2",
  "0123678",
  "012367",
  "01236",
  "0123",
  "012",
  "01"
};

int charToInt(int key, int i) {
  char c = value[key][i];
  return (c - '0');
}

// Use a 2D array of bools[note][finger], where the element i,j is true if
// the ith note requires the jth finger.  Then go back through the array,
// iterating row-wise, and increment a running total for that column based
// on the following conditions:
// 1) if TRUE and in the first row, +1; else
// 2) if TRUE and the previous is FALSE, +1
int main() {

  int n;
  cin >> n;
  cin.ignore();
  while (n--) {


    // note: "no need to store every key press in a large array, only need
    // to keep track of previous note pressed when looking at a note"
    bool arr[200][10];
    string s;
    getline(cin, s);

    // empty string case
    if (s.empty()) {
      //cout << "empty case" << endl;
      for (uint i = 0; i < 10; i++) {
	cout << 0;
	if (i != 9) cout << " ";
      }
      cout << endl;
      continue;
    }

    // init arr
    for (uint i = 0; i < s.size(); i++) {
      for (uint j = 0; j < 10; j++) {
	arr[i][j] = false;
      }
    }

    for (uint i = 0; i < s.size(); i++) {
      char c = s[i];
      size_t sz = key.find(c);
      if (sz != string::npos) {
	for (uint j = 0; j < value[sz].size(); j++) {
	  int k = charToInt(sz, j);
	  arr[i][k] = true;
	}
      }
    }

    // arr is now filled
    int finger[10];
    fill(finger, finger+10, 0);

    for (uint i = 0; i < 10; i++) {
      if (arr[0][i]) {
	finger[i]++;
      }
      for (uint j = 1; j < s.size(); j++) {
	if (arr[j][i] && !arr[j-1][i]) {
	  finger[i]++;
	}
      }
    }

    // done, results are stored in finger
    for (int i = 0; i < 10; i++) {
      cout << finger[i];
      if (i != 9) cout << " ";
    }
    cout << endl;
    
  }

  return 0;
}
