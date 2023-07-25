#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> row(k, vector<int>(k, 0)), col(k, vector<int>(k, 0));
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<vector<int>> r_order(k), c_order(k), r_to(k), c_to(k);
        for (auto r : rowConditions)
        {
            row[r[0]-1][r[1]-1] = 1;
            r_to[r[0]-1].push_back(r[1]-1);
        }

        

        for (auto c : colConditions)
        {
            col[c[0]-1][c[1]-1] = 1;
            c_to[c[0]-1].push_back(c[1]-1);
        }
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if ((row[i][j] == row[j][i]) || (col[i][j] == col[j][i]))
                {
                    return {};
                }
            }
        }



        return res;

    }
};