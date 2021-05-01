#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 105;
class Solution
{
public:
    int left[mx][mx], right[mx][mx], up[mx][mx], down[mx][mx];
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int res = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            int cum_left = 0, cum_right = 0;
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                    cum_left = 0;
                left[i][j] = cum_left;
                cum_left += grid[i][j];
                if (!grid[i][n - 1 - j])
                    cum_right = 0;
                right[i][n - 1 - j] = cum_right;
                cum_right += grid[i][n - 1 - j];

                res = max(res, grid[i][j]);
            }
        }
        if (min(m, n) == 1)
            return res;
        for (int i = 0; i < n; i++)
        {
            int cum_up = 0, cum_down = 0;
            for (int j = 0; j < m; j++)
            {
                if (!grid[j][i])
                    cum_up = 0;

                up[j][i] = cum_up;
                cum_up += grid[j][i];
                if (!grid[m - 1 - j][i])
                    cum_down = 0;

                down[m - 1 - j][i] = cum_down;
                cum_down += grid[m - 1 - j][i];
            }
        }

        for (int i = 0; i < m - 1; i++)
        {

            for (int j = 0; j < n - 1; j++)
            {
                // cout << "(" << left[i][j] << "," << right[i][j] << "," << up[i][j] << "," << down[i][j] << ")";

                for (int k = 1; k <= min(m - i, n - j); k++)
                {
                    if ((down[i][j] >= k) && (right[i][j] >= k) && (left[i + k][j + k] >= k) && (up[i + k][j + k] >= k) && grid[i][j] && grid[i + k][j + k])
                    {
                        res = max(res, (k + 1) * (k + 1));
                        cout << i << " " << j << " " << k << endl;
                    }
                }
            }
            // cout << endl;
        }
        cout << down[2][0];
        return res;
    }
};

// [[1,1,1],[1,0,1],[1,1,1]]
// [[1,1,0,0]]
// [[0,0],[0,0]]
// [[0,1],[1,0]]
// [[1,1,0],[1,1,1],[1,1,1],[0,1,0],[1,1,1],[0,1,1],[1,1,1]]

// [[1,1,1],[1,0,1],[1,1,1]]
// [[1,1,0,0]]
// [[0,0],[0,0]]
// [[0,1],[1,0]]
// [[1,1,0],[1,1,1],[1,1,1],[0,1,0],[1,1,1],[0,1,1],[1,1,1]]
// [[1,1,1],[1,1,0],[1,1,1],[0,1,1],[1,1,1]]