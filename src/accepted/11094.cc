// 11094 - Continents
// Accepted solution
#include <bits/stdc++.h>
using namespace std;

int M, N;
int X, Y;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

// our "grid"
vector<vector<char>> mat;

int floodfill(int r, int c, char c1, char c2)
{
    // special case, wrapping
    c = (c < 0) ? N - 1 : c;
    c = (c >= N) ? 0 : c;

    // bound check
    if (r < 0 || r >= M)
        return 0;

    // takes care of ignoring the water regions
    if (mat[r][c] != c1)
        return 0;

    int ans = 1;
    mat[r][c] = c2;
    for (int i = 0; i < 4; i++)
    {
        ans += floodfill(r + dr[i], c + dc[i], c1, c2);
    }
    return ans;
}

// Not used, but example of how we would output the contents of our
// matrix when we use this approach to create and fill it.
void print2dMatrix()
{
    for (auto &i : mat)
    {
        copy(begin(i), end(i), ostream_iterator<char>(cout, " "));
        cout << endl;
    }
}

int main()
{

    // M rows, N columns
    while (cin >> M >> N)
    {

        // Trick to read in and initialize a 2d matrix
        mat.resize(M);
        for (auto &i : mat)
        {
            i.reserve(N);
            copy_n(istream_iterator<char>(cin), N, back_inserter(i));
        }

        // This is our originating position
        cin >> X >> Y;

        // Our current location must be the "land" character, so we store this
        char land = mat[X][Y];
        int curr_sz = floodfill(X, Y, land, '0');

        // find largest other region
        int maxx = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mat[i][j] == land)
                {
                    int sz = floodfill(i, j, land, '0');
                    maxx = max(maxx, sz);
                }
            }
        }

        cout << maxx << endl;

        // Necessary to reset our 2D matrix for the next case
        mat.resize(0);
    }

    return 0;
}
