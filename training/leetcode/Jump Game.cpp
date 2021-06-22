#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int total = nums.size();
        vector<int> dp(total);
        dp[total - 1] = total - 1;
        for (int i = total - 2; i >= 0; i--)
        {
            for (int k = 1; k <= nums[i]; k++)
            {
                if (i + k >= total)
                    break;

                dp[i] = max(dp[i], dp[i + k]);
                if (dp[i] == total - 1)
                    break;
            }
            // if (dp[i] != total - 1)
            //     break;
        }
        return dp[0] == (total - 1);
    }
};