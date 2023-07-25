#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> dp(n, 1);
        long long cur = nums[0], res = 0;
        for (int i = 1; i < n; i++)
        {
            if ((cur & nums[i]) == 0)
            {
                dp[i] = dp[i - 1] + 1;
                cur = cur | nums[i];
            }
            else
            {
                if ((nums[i] & nums[i - 1]) == 0)
                {
                    cur = nums[i] | nums[i - 1];
                    dp[i] = 2;
                }
                else
                {
                    cur = nums[i];
                }
            }

            res = max(dp[i], res);
        }

        return res;
    }
};