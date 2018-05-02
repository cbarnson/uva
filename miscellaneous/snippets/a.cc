#include <bits/stdc++.h>
using namespace std;


int main() {

   int n;
   cin >> n;
   // reserve 'possibly' allocates memory
   vector<int> v; v.reserve(n);
   copy_n(istream_iterator<int>(cin), n, back_inserter(v));

   copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
   cout << endl;

   // reading matrix into vector of vectors
   int nn, mm;
   cin >> nn >> mm;
   vector< vector<int> > mat; mat.resize(nn);
   for (auto &i : mat) {
      i.reserve(mm);
      copy_n(istream_iterator<int>(cin), mm, back_inserter(i));
   }

   // discard leading whitespace
   int x;
   string s;
   // cin >> x >> ws; // std::ws
   // getline(cin, s);

   // can also do, (shorter version)
   getline(cin >> x >> ws, s);
   cout << "s: " << s << endl;

   
   // cout << "mat: " << endl;
   // for (int i = 0; i < nn; i++) {
   //    for (int j = 0; j < mm; j++) {
   // 	 cout << mat[i][j] << " ";
   //    }
   //    cout << endl;
   // }
      
   
   

   return 0;
}
