#include <bits/stdc++.h>
using namespace std;

const int NN = 150000;


// note: this won't work....
int main() {

   int n, k;
   while (cin >> n >> k) {

      int degree[NN+1];
      int worth[NN+1];
      worth[0] = -1;
      fill(degree, degree+n+1, 0);
      
      for (int i = 1; i < n+1; i++) {
	 int parent;
	 cin >> parent >> worth[i];
	 degree[parent]++;
      }

      priority_queue<int, vector<int>, greater<int> > pq;
      for (int i = 1; i < n+1; i++) {
	 if (degree[i] == 0) {
	    pq.push(worth[i]);
	 }
      }

      if (pq.size() < k) {
	 cout << "impossible" << endl;
      } else {
	 int total = 0;
	 while (k--) {
	    total += pq.top();
	    pq.pop();
	 }
	 cout << total << endl;
      } 
   }


   return 0;
}
