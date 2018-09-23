#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

   vi A = { 1, 2, 3, 4, 5, 5, 5 };

   priority_queue<int, vi, greater<int> > pq;
   FR(i, A.size()) { pq.push(A[i]); }

   while (!pq.empty()) {
      cout << pq.top() << " ";
      pq.pop();
   }

   cout << endl;
   
  
}
