
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, res = 0, cur = 1, total = nums.size();
        for (int r = 0; r < total; r++)
        {
            while (nums[r] - k > nums[l] + k)
            {
                l++;
                cur--;
            }
            cur = r-l;
            res = max(res, cur);

        }
        return res;
    }
};