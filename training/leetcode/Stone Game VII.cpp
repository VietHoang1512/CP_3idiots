#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 1005;
class Solution
{
public:
    int dp[mx][mx];
    int stoneGameVII(vector<int> &stones)
    {
        int total = stones.size();
        vector<int> cum_sum(total, 0);
        int cum_sum_;
        for (int i = 0; i < total; i++)
        {
            cum_sum_ += stones[i];
            cum_sum[i] = cum_sum_;
        }
        for (int k = 1; k <= total - 1; k++)
        {
            for (int i = 0; i < total - k; i++)
            {
                int j = i + k;
                int turn = (total + i + j + 1) % 2;
                // if ((j - i) == 1)
                // {
                //     dp[i][j] = turn ? abs(stones[i] - stones[j]) : -abs(stones[i] - stones[j]);
                //     continue;
                // }
                // if (i == 0)
                //     if (j == 2)
                //     {
                //         cout << turn << " " << max(dp[i + 1][j] + (cum_sum[j] - cum_sum[i]), dp[i][j - 1] + (cum_sum[j] - stones[j] - cum_sum[i] + stones[i])) << "\n"
                //              << dp[i + 1][j] << " " << cum_sum[j] - cum_sum[i] << " " << dp[i][j - 1] << " " << cum_sum[j] - stones[j] - cum_sum[i] + stones[i] << endl;
                //     }
                if (turn)
                    dp[i][j] = min(dp[i + 1][j] - (cum_sum[j] - cum_sum[i]), dp[i][j - 1] - (cum_sum[j] - stones[j] - cum_sum[i] + stones[i]));
                else
                    dp[i][j] = max(dp[i + 1][j] + (cum_sum[j] - cum_sum[i]), dp[i][j - 1] + (cum_sum[j] - stones[j] - cum_sum[i] + stones[i]));
            }
        }
        int i = 0, j = 2;
        int turn = (total + i + j + 1) % 2;
        // cout << turn << max(dp[i + 1][j] + (cum_sum[j] - cum_sum[i]), dp[i][j - 1] + (cum_sum[j] - stones[j] - cum_sum[i] + stones[i])) << dp[i + 1][j] << cum_sum[j] - cum_sum[i] << dp[i][j - 1] << cum_sum[j] - stones[j] - cum_sum[i] + stones[i] << endl;
        // for (int i = 0; i < total; i++)
        // {
        //     for (int j = 0; j < total; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[0][total - 1];
    }
};