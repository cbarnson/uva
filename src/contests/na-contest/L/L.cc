#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool a[101][101]={0}, b[101][101]={0};
bool done = 0;
int ans[101][101];
int n;

void chk(int i, int j) {
   if (i == n-1 && j == n-1) {
      done = 1;
      return;
   }
   if (j == n-1) {
      i++;
      j = 0;
   } else {
      j++;
   }
   for (int z = 1; z <= n; z++) {
      if (a[i][z] == 0 && b[j][z] == 0) {
	 a[i][z] = 1;
	 b[j][z] = 1;
	 ans[i][j] = z;
	 chk(i, j);
	 a[i][z] = 0;
	 b[j][z] = 0;
	 if (done) {
	    return;
	 }
      }
   }
   ans[i][j] = 0;
   return;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int k; cin >> n >> k;
   for (int x = 0; x < k; x++) {
      for (int y = 0; y < n; y++) {
	 cin >> ans[x][y];
      }
   }
   FR(x, k) {
      FR(y, n) {
	 if (a[x][ans[x][y]] == 1 || b[y][ans[x][y]] == 1) {
	    cout << "no" << endl;
	    return 0;
	 } else {
	    a[x][ans[x][y]] = 1;
	    b[y][ans[x][y]] = 1;
	 }
      }
   }
   /*  for(int x=0;x<n;x++){
      for(int y=0;y<n;y++){
	 cout <<a[x][y+1]<< " ";
      }
      cout << endl;
      }
      cout<<endl;*/
   if(k==n){
      cout<<"yes"<<endl;
      for(int x=0;x<n;x++){
	 for(int y=0;y<n;y++){
	    cout <<ans[x][y]<< " ";
	 }
	 cout << endl;
      }
      return 0;
   }
   chk(k-1, n-1);
   if (done) {
      cout<<"yes"<<endl;
      for(int x=0;x<n;x++){
	 for(int y=0;y<n;y++){
	    cout <<ans[x][y]<< " ";
	 }
	 cout << endl;
      }
      return 0;
   } else {
      cout<<"no"<<endl;
   }
   return 0;
}
