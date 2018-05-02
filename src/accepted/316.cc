#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef pair<int, int> pos;
typedef map<pos, int> smap;

struct Constel {
   vector<pos> verts;
   string name;
   Constel() {
      name = "";
   }
   Constel(vector<pos> v, string n) {
      verts = v;
      name = n;
   }
};

// all stars arranged into map
smap alls;
// all coordinates of stars in map
pos coord[1000];

// put star x, y, b into main starmap, store position in coord
void getStar(int index) {
   int x, y, b; cin >> x >> y >> b;
   alls[make_pair(x, y)] = b;
   coord[index] = make_pair(x, y);
}

Constel getConstel() {
   int num_v; cin >> num_v;
   string name; cin >> name;
   vector<pos> v;

   for (int i = 0; i < num_v; i++) {
      int x, y; cin >> x >> y;
      v.push_back(make_pair(x, y));
   }

   Constel temp(v, name);
   return temp;
}

void process(Constel& c, int total_stars) {
   // order matters (must check both A then B, and B then A)
   for (int i = 0; i < total_stars; i++) {
      for (int j = i + 1; j < total_stars; j++) {
	 // set origin
	 pos xo = coord[i];
	 pos yo = coord[j];
      }
   }
}

int main() {

   int N; cin >> N;
   int num = 1;
   while (N) {

      printf("Map #%i\n\n", num++);
      // read in N stars
      for (int i = 0; i < N; i++) {
	 getStar(i);
      }
      int num_constel; cin >> num_constel;
      for (int i = 0; i < num_constel; i++) {
	 // read in constellations
	 Constel c = getConstel();
	 
	 // process each constellation
	 process(c, N);
      }
      


      cin >> N;
   }


}
