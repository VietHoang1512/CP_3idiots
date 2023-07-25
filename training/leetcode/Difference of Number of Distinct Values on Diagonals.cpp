#include <bits/stdc++.h>
using namespace std;






class Solution
{
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                set<int> tl, br;
                int x1 = i, y1 = j, x2 = i, y2 = j;
                while (x1 - 1 >= 0 && y1 - 1 >= 0)
                {
                    tl.insert(grid[x1 - 1][y1 - 1]);
                    x1--;
                    y1--;
                }
                while (x2 + 1 <m && y2 + 1 <n)
                {
                    br.insert(grid[x2 + 1][y2 + 1]);
                    x2++;
                    y2++;
                }
                int tls=tl.size(), brs=br.size();
                res[i][j] = abs(tls-brs);
            }

        }
        return res;
    }
    
};