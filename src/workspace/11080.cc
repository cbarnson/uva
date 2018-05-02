// 11080 - Place the Guards
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

bool isBipartite(queue<int> &q, vector<vector<int>> &adj, vector<int> &color)
{
    bool good = true;
    while (!q.empty() && good)
    {

        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {

            int v = adj[u][i];

            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
            {
                good = false;
                break;
            }
        }
    }

    return good;
}

int uncolored(int &s, vector<int> &color)
{
    for (int i = 0; i < color.size(); i++)
    {
        if (color[i] == -1)
        {
            s = i;
            return i;
        }
    }
    s = -1;
    return -1;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);
        int s = 0;
        bool good = true;
        while (uncolored(s, color) != -1)
        {
            color[s] = 0;
            queue<int> q;
            q.push(s);

            good = isBipartite(q, adj, color);
            if (!good)
            {
                break;
            }
        }

        if (good)
        {
            int ans = count_if(begin(color), end(color),
                               [](int x) { return x == 0; });

            printf("ans = %d, for V = %d\n", ans, V);

            ans = min(ans, V - ans);
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
