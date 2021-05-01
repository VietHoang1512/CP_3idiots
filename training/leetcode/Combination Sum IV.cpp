#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const unsigned long long int mx = 1005;

class Solution
{
public:
    unsigned long long int dp[mx][mx];
    int combinationSum4(vector<int> &nums, int target)
    {
        unsigned long long int total = nums.size();
        sort(nums.begin(), nums.end());
        for (auto x : nums)
            dp[x][1] = 1;
        unsigned long long int res = dp[target][1];

        for (unsigned long long int i = 2; i <= target; i++)
        {
            for (unsigned long long int j = 0; j <= target; j++)
            {
                for (unsigned long long int k = 0; k < total; k++)
                {
                    if (j < nums[k])
                        break;
                    dp[j][i] += dp[j - nums[k]][i - 1];
                }
            }
            res += dp[target][i];
        }
        return res;
    }
};