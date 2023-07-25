#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int total = nums.size();
        vector<int> dp(total, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < total; i++)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                if (i + j >= total)
                    break;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        // for (auto x:dp)
        // cout << x << " ";
        return dp[total - 1];
    }
};