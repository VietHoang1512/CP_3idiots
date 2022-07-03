#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == j) && (grid[i][j] == 0))
                    return false;
                else if (((i + j) == (n - 1)) && (grid[i][j] == 0))
                    return false;
                else if ((i != j) && ((i + j) != (n - 1)) && (grid[i][j]))
                    return false;
            }
        }
        return true;
    }
};