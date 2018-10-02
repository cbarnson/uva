#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   multiset<int> ms;
   cin >> n;
   FR(i, n) {
     int x; cin >> x;
     ms.emplace(x);
   }
   
   int x = *ms.rbegin();
   if (ms.count(x) % 2 == 0) {
     auto i = ms.equal_range(x);
     if (i.first == ms.begin()) {
       cout << "Agasa" << endl;
       return 0;
     }
   }

   cout << "Conan" << endl;
}


