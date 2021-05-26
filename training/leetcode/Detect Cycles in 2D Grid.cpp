#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool res = false;
    bool containsCycle(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    visited[i][j] = 1;
                    DFS(grid, grid[i][j], i, j, -1, -1, visited);
                }
            }
        }
        return res;
    }

    void DFS(vector<vector<char>> &grid, char c, int i, int j, int prev_i, int prev_j, vector<vector<int>> &visited)
    {
        int m = grid.size(), n = grid[0].size();

        if ((i > 0) && (grid[i - 1][j] == c) && ((i - 1 != prev_i) || (j != prev_j)))
        {
            if (visited[i - 1][j])
                res = true;
            else
            {
                visited[i - 1][j] = 1;
                DFS(grid, c, i - 1, j, i, j, visited);
            }
        }
        if ((i < m - 1) && (grid[i + 1][j] == c) && ((i + 1 != prev_i) || (j != prev_j)))
        {
            if (visited[i + 1][j])
                res = true;
            else
            {
                visited[i + 1][j] = 1;
                DFS(grid, c, i + 1, j, i, j, visited);
            }
        }
        if ((j > 0) && (grid[i][j - 1] == c) && ((i != prev_i) || (j - 1 != prev_j)))
        {
            if (visited[i][j - 1])
                res = true;
            else
            {
                visited[i][j - 1] = 1;
                DFS(grid, c, i, j - 1, i, j, visited);
            }
        }
        if ((j < n - 1) && (grid[i][j + 1] == c) && ((i != prev_i) || (j + 1 != prev_j)))
        {
            if (visited[i][j + 1])
                res = true;
            else
            {
                visited[i][j + 1] = 1;
                DFS(grid, c, i, j + 1, i, j, visited);
            }
        }
    }
};