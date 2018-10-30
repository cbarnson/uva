// Cody Barnson
// 5736 - Contour Tracing
#include <bits/stdc++.h>
using namespace std;

// represents a segment of a contour (x1, y1, x2, y2)
typedef tuple<int, int, int, int> line;

// change in row and column for the dth direction
const int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dj[] = {-1, -1, 0, 1, 1, 1, 0, -1};

// max rows and columns for the current case
int NN, MM;
int cn = 1;

// our "board"
int arr[200][200];
void init() {
  for (int i = 0; i < 200; i++) {
    fill(arr[i], arr[i] + 200, 0);
  }
  cout << "Case " << cn++ << endl;
}

// given line from prev to current, retrieve the starting index for current's
// clockwise search for neighbors
int prevIndex(line l) {
  int dx = get<0>(l) - get<2>(l);
  int dy = get<1>(l) - get<3>(l);
  for (int i = 0; i < 8; i++) {
    if (dx == di[i] && dy == dj[i]) return i;
  }
  assert(0);
  return 0;
}

int contour(int r, int c, map<line, int>& m, int& pix) {
  set<pair<int, int> > per;
  line curr = make_tuple(r - 1, c - 1, r, c);

  pix = 0;
  int len = 0;
  bool done = false;
  while (!done) {
    int nn = prevIndex(curr);
    int nold = nn;
    for (int i = 0; i < 8; i++) {
      nn = (nn + 1) % 8;
      int x = get<2>(curr) + di[nn];
      int y = get<3>(curr) + dj[nn];
      if (arr[x][y]) {
        line l = make_tuple(get<2>(curr), get<3>(curr), x, y);
        auto it = m.find(l);
        if (it != m.end()) {
          // found
          done = true;
          break;
        }
        // update length (plus 1), add segment to map, update current, continue
        len++;
        m.insert(make_pair(l, len));
        per.insert(make_pair(get<0>(l), get<1>(l)));
        curr = l;
        break;
      } else {
        // x y position is a 0 space
        if (i == 7)  // last iteration
          done = true;
      }
    }
  }

  // special case for
  // 010
  // 111
  // 010
  pix = per.size();
  if (pix == 4) {
    if (r + 2 < NN && arr[r][c] && arr[r + 1][c] && arr[r + 1][c - 1] &&
        arr[r + 1][c + 1] && arr[r + 2][c]) {
      // adjust pix, so we can safely filter pix < 5
      pix = 5;
    }
  }

  return len;
}

int neigh(int r, int c) {
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (i == 0 && j == 0) continue;
      if (arr[r + i][c + j]) return arr[r + i][c + j];
    }
  }
  return 0;
}

int main() {
  while (cin >> NN >> MM >> ws) {
    if (NN == 0 || MM == 0) break;
    init();

    int id = 1;
    map<int, bool> seen;
    for (int i = 0; i < NN; i++) {
      for (int j = 0; j < MM; j++) {
        char c;
        cin >> c;
        assert(c != '\n');
        if (c == '1') {
          int nn = neigh(i, j);
          if (nn == 0) {
            seen.insert(make_pair(id, false));
            // seen[id] = false;
            arr[i][j] = id++;
          } else {
            arr[i][j] = nn;
          }
        }
      }
      cin >> ws;
    }

    map<line, int> m;
    vector<int> v;

    for (int i = 0; i < NN; i++) {
      for (int j = 0; j < MM; j++) {
        if (arr[i][j]) {
          if (!seen[arr[i][j]]) {
            int pix = 0;
            int len = contour(i, j, m, pix);
            if (len > 3 && pix >= 5) {
              v.push_back(len);
            }
            seen[arr[i][j]] = true;
          }
        }
      }
    }

    // output
    // If multiple contour lengths were found print ascending order
    if (v.empty())
      cout << "no objects found";
    else {
      sort(begin(v), end(v));
      for (uint i = 0; i < v.size(); i++) {
        if (i) cout << " ";
        cout << v[i];
      }
    }
    cout << endl;
  }

  return 0;
}
