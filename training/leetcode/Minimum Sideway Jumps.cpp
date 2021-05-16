#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minSideJumps(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(n + 1, vector<int>(4, -2));
        dp[0][1] = dp[0][3] = 1, dp[0][2] = 0;
        for (int i = 1; i <= n; i++)
        {
            int prev = obstacles[i - 1], cur = obstacles[i];
            dp[i - 1][prev] = -1;
            dp[i][cur] = -1;
            for (int j = 1; j <= 3; j++)
            {
                if (j != prev)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j == cur)
                {
                    dp[i][j] = -1;
                }
                dp[i][prev] = INT_MAX - 5;
                for (int j = 1; j <= 3; j++)
                {
                    if (dp[i][j] >= 0)
                        dp[i][prev] = min(dp[i][prev], dp[i][j] + 1);
                }
            }
        }
        // for (int i = 0; i <= 3; i++)
        // {
        //     for (int j = 0; j <= n; j++)
        //     {
        //         cout << dp[j][i] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        int res = INT_MAX;
        for (int j = 1; j <= 3; j++)
        {
            if (dp[n][j] >= 0)
                res = min(res, dp[n][j]);
        }
        return res;
    }
};