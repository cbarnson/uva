// 11906 - Knight in War Grid
// Unfinished

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi dr = {1, 1, -1, -1};
vi dc = {1, -1, 1, -1};

int R, C, M, N;

vector<vector<bool>> water;
vector<vector<int>> evenorodd;

int row(int r, int i, int mn)
{
    return mn * dr[i] + r;
}

int col(int c, int i, int mn)
{
    return mn * dc[i] + c;
}

bool inbound(int r, int c)
{
    if (r < 0 || r >= R || c < 0 || c >= C)
    {
        return false;
    }
    return true;
}

bool iswater(int r, int c)
{
    if (water[r][c])
    {
        return true;
    }
    return false;
}

void dfsUtil(ii s, vector<vector<bool>> &vis)
{
    // printf("dfsUtil(%d, %d)\n", s.first, s.second);
    vis[s.first][s.second] = true;
    int even_odd = 0;
    for (size_t i = 0; i < 4; i++)
    {
        int dx = row(s.first, i, M);
        int dy = col(s.second, i, N);

        if (inbound(dx, dy) && !iswater(dx, dy))
        {
            even_odd = 1 - even_odd;
            if (!vis[dx][dy])
            {
                // printf("!vis[%d][%d]\n", dx, dy);
                dfsUtil(make_pair(dx, dy), vis);
            }
        }

        dx = row(s.first, i, N);
        dy = col(s.second, i, M);

        if (inbound(dx, dy) && !iswater(dx, dy))
        {
            even_odd = 1 - even_odd;
            if (!vis[dx][dy])
            {
                // printf("!vis[%d][%d]\n", dx, dy);
                dfsUtil(make_pair(dx, dy), vis);
            }
        }
    }
    if (evenorodd[s.first][s.second] == -1)
    {
        evenorodd[s.first][s.second] = even_odd;
    }
}

void dfs(ii s)
{
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    dfsUtil(s, vis);
}

void printGrid(vector<vector<int>> &v)
{
    for (auto &i : v)
    {
        copy(begin(i), end(i), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

int main()
{
    int t, tc = 1;
    cin >> t;
    while (t--)
    {
        int w;
        cin >> R >> C >> M >> N >> w;

        // resize appropriately
        water.resize(R, vector<bool>(C, false));
        evenorodd.resize(R, vector<int>(C, -1));

        while (w--)
        {
            int x, y;
            cin >> x >> y;
            water[x][y] = true;
        }
        dfs(make_pair(0, 0));

        // printGrid(evenorodd);
        int c = 0;
        for (auto &i : evenorodd)
        {
            c += count_if(i.begin(), i.end(), [](int x) {
                return x == 0;
            });
        }
        // printf("even count: %d\n", c);

        int o = 0;
        for (auto &i : evenorodd)
        {
            o += count_if(i.begin(), i.end(), [](int x) {
                return x == 1;
            });
        }
        // printf("odd count: %d\n", o);

        printf("Case %d: %d %d\n", tc++, c, o);

        // reset
        water.resize(0);
        evenorodd.resize(0);
    }

    return 0;
}
