#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 5005;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // cout << "\n**************\n";
        int total = prices.size();
        vector<int> buy(total, 0), sell(total, -INT_MAX/2);

        if (total == 2)
            return max(0, prices[1] - prices[0]);
        else if (total == 1)
            return 0;

        buy[0] = -prices[0];
        buy[1] = -prices[1];
        sell[1] = prices[1] - prices[0];
        int res = max(sell[0], sell[1]);

        for (int i = 2; i < total; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                sell[i] = max(sell[i], buy[j]);
                if (i - j >= 2)
                    buy[i] = max(buy[i], sell[j]);
            }
            buy[i] -= prices[i];
            sell[i] += prices[i];
            res = max(res, sell[i]);
            // for (int i = 0; i < total; i++)
            // {
            //     cout << buy[i] << "_" << sell[i] << " ";
            // }
        }
        return max(res,0);
        // dp[0] = -prices[0];
        // dp[1] = -prices[1];
        // // dp[2] = -prices[2] + max(prices[1] - prices[0], 0);
        // int res = 0;
        // for (int i = 2; i < total; i++)
        // {
        //     for(int j=0; j<i-1; j++){
        //         dp[i] = max(dp[i], dp[j])
        //     }

        //     + max(price[i]-prices[i-1], max(prices[i - 1] + dp[i - 2], 0));
        //     if (i < total - 1)
        //         res = max(res, dp[i] + prices[i + 1]);
        // }
        // for (int i = 0; i < total; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // return res;
    }
};
// [1,2,3,0,2]
// [1]
// [1,2,4]