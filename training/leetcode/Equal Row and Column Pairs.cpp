#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int equal = 1;
                for (int k = 0; k < n; k++)
                {
                    if (grid[i][k] != grid[k][j])
                    {
                        equal = 0;
                    }
                }
                res += equal;
            }
        }
        return res;
    }
};