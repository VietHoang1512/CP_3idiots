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
        if (total == 1)
            return 1;
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        return LCS(nums, sorted_nums, total, total);
        // vector<int> dp(total, 1);
        // int res = dp[0] = 1;
        // for (int i = 1; i < total; i++)
        // {
        //     for (int j = 0; j < i; j++)
        //         dp[i] = max(dp[i], (nums[i] > nums[j]) ? dp[j] + 1 : 1);
        //     res = max(res, dp[i]);
        // }
        // return res;
    }
    int LCS(vector<int> &A, vector<int> &B, int m, int n)
    {
        if (!(m * n))
            return 0;
        if (A[m - 1] == B[n - 1])
            return 1 + LCS(A, B, m - 1, n - 1);
        return max(LCS(A, B, m - 1, n), LCS(A, B, m, n - 1));
    }
};
