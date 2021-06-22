#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define __builtin_popcount __builtin_popcountll
// #define SCD(t) scanf("%d", &t)
// #define SCLD(t) scanf("%ld", &t)
// #define SCLLD(t) scanf("%lld", &t)
// #define SCC(t) scanf("%c", &t)
// #define SCS(t) scanf("%s", t)
// #define SCF(t) scanf("%f", &t)
// #define SCLF(t) scanf("%lf", &t)
// #define read(type) readInt<type>()
// #define IN(A, B, C) assert(B <= A && A <= C)

int main()
{
}
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int total = nums.size();
        if (total <= 2)
            return *max_element(nums.begin(), nums.end());
        vector<int> dp(total);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];

        for (int i = 3; i < total; i++)
        {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        }
        return *max_element(dp.begin(), dp.end());
        // int res1 = 0, res2 = 0;
        // for (int i = 0; i < nums.size(); i += 2)
        // {
        //     res1 += nums[i];
        //     if (i + 1 < nums.size())
        //         res2 += nums[i + 1];
        // }
        // return max(res1, res2);
    }
};