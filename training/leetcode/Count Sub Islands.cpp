#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size(), n = grid1[0].size(), res = 0;
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] && (!visited[i][j]))
                {
                    res += isSub(grid1, grid2, visited, i, j);
                }
            }
        }
        return res;
    }
    int isSub(vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &visited, int i, int j)
    {
        int res = grid1[i][j];
        visited[i][j] = 1;
        int m = grid1.size(), n = grid1[0].size();

        if (i > 0 && (!visited[i - 1][j]) && grid2[i - 1][j])
        {
            res = min(res, isSub(grid1, grid2, visited, i - 1, j));
        }
        if (j > 0 && (!visited[i][j - 1]) && grid2[i][j - 1])
        {
            res = min(res, isSub(grid1, grid2, visited, i, j - 1));
        }
        if (i < m - 1 && (!visited[i + 1][j]) && grid2[i + 1][j])
        {
            res = min(res, isSub(grid1, grid2, visited, i + 1, j));
        }
        if (j < n - 1 && (!visited[i][j + 1]) && grid2[i][j + 1])
        {
            res = min(res, isSub(grid1, grid2, visited, i, j + 1));
        }
        return res;
    }
};