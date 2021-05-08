#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 305;
class Solution
{
public:
    int visited[mx][mx];
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    if (!visited[i][j])
                    {
                        res++;
                        DFS(grid, i, j);
                    }
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if ((i > 0) && (grid[i - 1][j] == '1') && (!visited[i - 1][j]))
        {
            visited[i - 1][j] = 1;
            DFS(grid, i - 1, j);
            // visited[i - 1][j] = 0;
        }

        if ((j > 0) && (grid[i][j - 1] == '1') && (!visited[i][j - 1]))
        {
            visited[i][j - 1] = 1;
            DFS(grid, i, j - 1);
            // visited[i][j - 1] = 0;
        }

        if ((i + 1 < m) && (grid[i + 1][j] == '1') && (!visited[i + 1][j]))
        {
            visited[i + 1][j] = 1;
            DFS(grid, i + 1, j);
            // visited[i + 1][j] = 0;
        }

        if ((j + 1 < n) && (grid[i][j + 1] == '1') && (!visited[i][j + 1]))
        {
            visited[i][j + 1] = 1;
            DFS(grid, i, j + 1);
            // visited[i][j + 1] = 0;
        }
    }

    // int numIslands(vector<vector<char>> &grid)
    // {
    //     int m = grid.size(), n = grid[0].size();
    //     vector<int> parent(m * n, -1);
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (grid[i][j] == '1')
    //             {
    //                 parent[i * n + j] = i * n + j;
    //             }
    //             // cout << parent[i * n + j] << " ";
    //         }
    //         // cout << endl;
    //     }
    //     // cout << endl;
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (grid[i][j] == '1')
    //             {
    //                 if ((i > 0) && (grid[i - 1][j] == '1'))
    //                     Union(grid, parent, i, j, i - 1, j);

    //                 if ((j > 0) && (grid[i][j - 1] == '1'))
    //                     Union(grid, parent, i, j, i, j - 1);

    //                 if ((i + 1 < m) && (grid[i + 1][j] == '1'))
    //                     Union(grid, parent, i, j, i + 1, j);

    //                 if ((j + 1 < n) && (grid[i][j + 1] == '1'))
    //                     Union(grid, parent, i, j, i, j + 1);
    //             }
    //         }
    //     }
    //     set<int> s;
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (grid[i][j] == '1')
    //             {
    //                 Find(grid, parent, i, j);
    //                 s.insert(parent[i * n + j]);
    //             }
    //             cout << parent[i * n + j] << " ";

    //         }
    //         cout << endl;
    //     }
    //     return s.size();
    // }
    int Find(vector<vector<char>> grid, vector<int> &parent, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (parent[i * n + j] == i * n + j)
            return i * n + j;
        return parent[i * n + j] = Find(grid, parent, parent[i * n + j] / n, parent[i * n + j] % n);
    }

    void Union(vector<vector<char>> grid, vector<int> &parent, int i1, int j1, int i2, int j2)
    {
        // cout << "joining " << i1 << "," << j1 << " vs " << i2 << "," << j2 << endl;
        int m = grid.size(), n = grid[0].size();
        int p1 = Find(grid, parent, i1, j1), p2 = Find(grid, parent, i2, j2);
        if (p1 <= p2)
            parent[p2] = p1;
        else
            parent[p1] = p2;
        // cout << p1 << "-" << p2 << "," << parent[p1] << "-" << parent[p2] << endl;
    }
};
