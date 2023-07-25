#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int total = nums.size();
        vector<int> dp(total, -1);
        dp[0] = 1;
        for (int i = 1; i < total; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(nums[j] - nums[i]) <= target){
                    dp[i] = max(dp[i], dp[j]+1)
                }
            }
        }
        return dp[total - 1];
    }

};