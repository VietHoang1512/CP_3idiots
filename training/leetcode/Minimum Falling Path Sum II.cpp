#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &arr)
    {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX / 2));
        dp[0] = arr[0];
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k != j)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + arr[i][j]);
                }
            }
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};