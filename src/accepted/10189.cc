//================================
//UVA problem#: 10189
//CPSC 3200,	2017-01-15
//Cody Barnson,	ID#001172313
//================================
#include <bits/stdc++.h>
using namespace std;

// note: "don't really need a map, just a pair, though slower to code"
typedef map<pair<int, int>, int> mmap;


int main() {

  int rows, cols;
  int testcase = 1;
  while (cin >> rows >> cols && rows != 0 && cols != 0) {

    if (testcase > 1) cout << endl;
    cout << "Field #" << testcase++ << ":" << endl;
    
    // store coordinates of mines in map
    mmap m;

    // note: "artificially increase dimensions by 1 in all directions
    // to avoid doing the 'in bound' check"
    int arr[100][100];
    // initialize board all to zeros
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
	arr[i][j] = 0;
      }
    }

    // read in board character by character, insert mine locations into map
    char c;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
	cin >> c;
	if (c == '*') {
	  m[make_pair(i, j)] += 1;
	}
      }
    }

    // for each mine location, increment by 1 all 8 spaces around it
    // note, this includes other mine locations, but doesn't matter as they
    // will be reset
    for (auto it : m) {
      int r = it.first.first, c = it.first.second;
      for (int i = -1; i < 2; i++) {
	for (int j = -1; j < 2; j++) {
	  if (i == 0 && j == 0) continue;
	  // bound check
	  if (r + i >= 0 &&
	      r + i < 100 &&
	      c + j >= 0 &&
	      c + j < 100) {
	    arr[r + i][c + j]++;
	  }	  
	}
      }
    }

    // go back through each mine location, set value in board to -1
    for (auto it : m) {
      arr[it.first.first][it.first.second] = -1;
    }

    // output the result, printing '*' in place of any -1
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
	if (arr[i][j] == -1) cout << '*';
	else cout << arr[i][j];
      }
      cout << endl;
    }
    
  }
  
  

  return 0;
}
