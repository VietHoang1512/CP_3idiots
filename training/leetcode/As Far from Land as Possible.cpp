#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int shift = 5;
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int n_water = 0, n_land = 0;
        vector<pair<int, int>> waters;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                n_water += (grid[i][j] == 0);
                n_land += (grid[i][j] == 1);
                if (!grid[i][j])
                    waters.push_back({i, j});
            }
        }
        if (!(n_water * n_land))
            return -1;
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 1)
                {

                    res = max(res, nearestLand(grid, i, j, visited));
                    // cout << i << " " << j << " " << nearestLand(grid, i, j, visited) << endl;
                }
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return res - shift;
    }

    int nearestLand(vector<vector<int>> &grid, int i, int j, vector<vector<int>> visited)
    {
        // cout << i << " " << j << endl;
        int m = grid.size(), n = grid[0].size();
        if (grid[i][j] == 1)
            return shift;
        if (grid[i][j] >= shift)
            return grid[i][j];
        visited[i][j] = 1;
        vector<int> dist;
        if (i > 0)
        {
            if (grid[i - 1][j] >= shift)
            {
                dist.push_back(grid[i - 1][j]);
            }
            else if (!visited[i - 1][j])
            {
                int tmp = nearestLand(grid, i - 1, j, visited);
                // grid[i - 1][j] = tmp;
                dist.push_back(tmp);
            }
        }
        if (i < m - 1)
        {
            if (grid[i + 1][j] >= shift)
            {
                dist.push_back(grid[i + 1][j]);
            }
            else if (!visited[i + 1][j])
            {
                int tmp = nearestLand(grid, i + 1, j, visited);
                grid[i + 1][j] = tmp;
                dist.push_back(tmp);
            }
        }
        if (j > 0)
        {
            if (grid[i][j - 1] >= shift)
            {
                dist.push_back(grid[i][j - 1]);
            }
            else if (!visited[i][j - 1])
            {
                int tmp = nearestLand(grid, i, j - 1, visited);
                grid[i][j - 1] = tmp;
                dist.push_back(tmp);
            }
        }
        if (j < n - 1)
        {
            if (grid[i][j + 1] >= shift)
            {
                dist.push_back(grid[i][j + 1]);
            }
            else if (!visited[i][j + 1])
            {
                int tmp = nearestLand(grid, i, j + 1, visited);
                grid[i][j + 1] = tmp;
                dist.push_back(tmp);
            }
        }
        if (dist.empty())
        {
            grid[i][j] = INT_MAX / 2;
            return INT_MAX / 2;
        }
        grid[i][j] = 1 + *min_element(dist.begin(), dist.end());

        return 1 + *min_element(dist.begin(), dist.end());
    }
};