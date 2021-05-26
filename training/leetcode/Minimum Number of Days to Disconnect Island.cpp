#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minDays(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<int> component;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((!visited[i][j]) && grid[i][j])
                {
                    int cnt = DFS(i, j, grid, visited);
                    component.push_back(cnt);
                    // cout << i << "-" << j << ":"<< cnt<< endl;
                }
            }
        }
        if(component.size()!=1) return 0;

        cout << endl;
        // sort(component.begin(), component.end());
        return 0;
    }
    int DFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = 1;
        int cnt = 1;
        if (i > 0)
        {
            if ((!visited[i - 1][j]) && grid[i - 1][j])
            {
                cnt += DFS(i - 1, j, grid, visited);
            }
        }
        if (j > 0)
        {
            if ((!visited[i][j - 1]) && grid[i][j - 1])
            {
                cnt += DFS(i, j - 1, grid, visited);
            }
        }
        if (i < m - 1)
        {
            if ((!visited[i + 1][j]) && grid[i + 1][j])
            {
                cnt += DFS(i + 1, j, grid, visited);
            }
        }
        if (j < n - 1)
        {
            if ((!visited[i][j + 1]) && grid[i][j + 1])
            {
                cnt += DFS(i, j + 1, grid, visited);
            }
        }
        return cnt;
    }
};