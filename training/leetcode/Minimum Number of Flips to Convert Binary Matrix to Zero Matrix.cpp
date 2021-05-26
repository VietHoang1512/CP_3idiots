#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int res = INT_MAX;
    int minFlips(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < (1 << m * n); i++)
        {
            if (check(mat, i))
            {
                res = min(res, __builtin_popcount(i));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    bool check(vector<vector<int>> mat, int mask)
    {

        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((mask >> (i * n + j)) & 1)
                {
                    mat[i][j] = 1 - mat[i][j];
                    if (i > 0)
                        mat[i - 1][j] = 1 - mat[i - 1][j];
                    if (j > 0)
                        mat[i][j - 1] = 1 - mat[i][j - 1];
                    if (i < m - 1)
                        mat[i + 1][j] = 1 - mat[i + 1][j];
                    if (j < n - 1)
                        mat[i][j + 1] = 1 - mat[i][j + 1];
                }
            }
        }
        int tmp = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp += mat[i][j];
            }
        }
        return !tmp;
    }
};