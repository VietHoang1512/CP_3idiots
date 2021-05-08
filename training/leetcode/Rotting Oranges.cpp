#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int fresh = 0;
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int prev = fresh, t = 3;
        while ((t == 3) || (prev > fresh))
        {
            prev = fresh;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] < t)
                        BFS(grid, i, j, t);
                }
            }
            t++;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        if (fresh)
            return -1;
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res = max(res, grid[i][j]);
            }
        }
        if (res == 1)
            return -1;
        if (res == 0)
            return 0;
        return res - 2;
    }
    void BFS(vector<vector<int>> &grid, int x, int y, int t)
    {
        int m = grid.size(), n = grid[0].size();

        if (grid[x][y] <= 1)
            return;

        if ((x > 0) && (grid[x - 1][y] <= 1) && grid[x - 1][y])
        {
            grid[x - 1][y] = t;
            fresh--;
        }

        if ((x < m - 1) && (grid[x + 1][y] <= 1) && grid[x + 1][y])
        {
            grid[x + 1][y] = t;
            fresh--;
        }
        if ((y > 0) && (grid[x][y - 1] <= 1) && grid[x][y - 1])
        {
            grid[x][y - 1] = t;
            fresh--;
        }

        if ((y < n - 1) && (grid[x][y + 1] <= 1) && grid[x][y + 1])
        {
            grid[x][y + 1] = t;
            fresh--;
        }
    }
};