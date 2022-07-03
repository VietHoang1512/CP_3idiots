#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int countPaths(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res += dfs(grid, visited, dp, m, n, i, j, res, 0);
                res%=1000000007;
            }
        }
        return res;
    }
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, vector<vector<int>> &dp, int m, int n, int i, int j, int &res, int cur)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return 0;
        if (grid[i][j] <= cur)
            return 0;
        if (dp[i][j] > 0)
            return dp[i][j];
        visited[i][j] = 1;
        int r = 1;
        r += dfs(grid, visited, dp, m, n, i + 1, j, res, grid[i][j]);
        r%=1000000007;
        r += dfs(grid, visited, dp, m, n, i - 1, j, res, grid[i][j]);
        r%=1000000007;
        r += dfs(grid, visited, dp, m, n, i, j + 1, res, grid[i][j]);
        r%=1000000007;
        r += dfs(grid, visited, dp, m, n, i, j - 1, res, grid[i][j]);
        r%=1000000007;
        visited[i][j] = 0;
        dp[i][j] = r;
        return r;
    }
};