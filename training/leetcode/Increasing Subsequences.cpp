#include <bits/stdc++.h>
using namespace std;

int main()
{
}
const int mx = 20;
class Solution
{
public:
    vector<vector<int>> dp[mx];
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int total = nums.size();
        for (int i = 0; i < total; i++)
            dp[i].push_back({nums[i]});
        for (int i = 1; i < total; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    for (auto x : dp[j])
                    {
                        vector<int> tmp = x;
                        tmp.push_back(nums[i]);
                        dp[i].push_back(tmp);
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (int i = 1; i < total; i++)
        {
            for (auto x : dp[i])
            {
                if ((int)x.size() > 1)
                    res.push_back(x);
            }
        }
        return res;
    }
};