#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 2505;
class Solution
{
public:
    // int dp[mx];
    int lengthOfLIS(vector<int> &nums)
    {
        int total = nums.size();
        vector<int> dp(total, 1);
        int res = dp[0] = 1;
        for (int i = 1; i < total; i++)
        {
            for (int j = 0; j < i; j++)
                dp[i] = max(dp[i], (nums[i] > nums[j]) ? dp[j] + 1 : 1);
            res = max(res, dp[i]);
        }
        return res;
    }
};
