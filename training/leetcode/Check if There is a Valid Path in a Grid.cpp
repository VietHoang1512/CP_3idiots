#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool res = false;
    map<int, int> up[7], down[7], right[7], left[7];
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        right[1][3] = 1;
        right[1][5] = 1;
        
    }
    void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<int>> visited)
    {
    }
};