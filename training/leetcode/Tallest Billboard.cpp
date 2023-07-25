#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(sum + 1, -1);
        dp[0] = 0;
        for (auto rod : rods)
        {
            vector<int> dp_tmp(dp);
            for (int i = 0; i <= sum-rod; i++)
            {
                if (dp_tmp[i] < 0)
                    continue;
                dp[i + rod] = max(dp[i + rod], dp_tmp[i]);
                if (i >= rod)
                    dp[i - rod] = max(dp[i - rod], dp_tmp[i] + rod);
                else
                    dp[rod - i] = max(dp[rod - i], dp_tmp[i] + i);
            }
        }
        return dp[0];
    }
};