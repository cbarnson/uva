// Problem #    : 490a
// Created on   : 2018-10-21 14:03:59
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;
   vi A(n);

   queue<int> q[3];
   
   FR(i, n) {
      cin >> A[i];
      q[A[i] - 1].push(i + 1);
   }

   int w = 0;
   vi B;
   while (!any_of(q, q+3, [](queue<int> &qu) { return qu.empty(); })) {
      B.push_back(q[0].front());
      B.push_back(q[1].front());
      B.push_back(q[2].front());
      q[0].pop();
      q[1].pop();
      q[2].pop();
      w++;
   }

   cout << w << endl;
   for (int i = 0; i < w * 3; i += 3) {
      cout << B[i] << " " << B[i + 1] << " " << B[i + 2] << endl;
   }
   


}
