#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

string name[] = { "Power", "Time", "Space", "Soul", "Reality", "Mind" };
string c[] = { "purple", "green", "blue", "orange", "red", "yellow" };
int a[6];

int main() {
   
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      auto j = find(c, c+6, s) - c;
      a[j] = true;
   }

   cout << 6 - n << endl;
   for (int i = 0; i < 6; i++) {
      if (!a[i]) {
	 cout << name[i] << endl;
      }
   }
   

}


