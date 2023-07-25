#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &nums, int x)
    {
        int total = nums.size();
        long long res = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<long long>> dp(total, vector<long long>(total));
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                if (i == 0)
                    dp[i][j] = nums[j];
                else
                {
                    dp[i][j] = min(dp[i - 1][j], (long long)nums[(j - i + total) % total]);
                }
            }
            long long tmp = accumulate(dp[i].begin(), dp[i].end(), 0);
            tmp += ((long long) i) * x;
            res = min(res, tmp);
        }
        return res;
    }
};