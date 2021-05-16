#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0), l(n, 1), r(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    l[i] = max(l[i], l[j] + 1);
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] > nums[j])
                {
                    r[i] = max(r[i], r[j] + 1);
                }
            }
        }
        int res = INT_MAX;
        for (int i = 1; i < n - 1; i++)
        {
            int tmp = n - l[i] - r[i] + 1;
            if (!((l[i] - 1)*(r[i] - 1)))
                continue;
            res = min(res, tmp);
        }
        return res;
    }
};