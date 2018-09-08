// Problem #    : c
// Created on   : 2018-09-08 11:43:47

#include <bits/stdc++.h>

#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {
  int n, a;
  while (cin >> n) {

     for (int i = 0; i < n; i++) {
	cin >> a;
	cout << (a & 1 ? a : a - 1) << " \n"[i == n-1];
     }
     
  }
  
  return 0;
}
