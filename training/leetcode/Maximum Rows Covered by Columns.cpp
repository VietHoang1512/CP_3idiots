#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maximumRows(vector<vector<int>> &mat, int cols)
    {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        for (int i = 1; i <= pow(2, 13) - 1; i++)
        {
            
            if (__builtin_popcount(i) == cols)
            {
                int num = 0;
                for (int j = 0; j < m; j++)
                {
                    int cnt = 1;
                    for (int k = 0; k < n; k++)
                    {
                        if (mat[j][k])
                            if (!((i >> k) & 1))
                                cnt = 0;
                    }
                    num += cnt;
                }
                res = max(res, num);
            }
            
        }
        return res;
    }
};