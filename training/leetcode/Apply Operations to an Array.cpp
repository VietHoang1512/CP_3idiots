#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int total = nums.size();
        for (int i = 0; i < total - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> res;
        for (auto x : nums)
        {
            if (x)
                res.push_back(x);
        }
        for (auto x : nums)
        {
            if (!x)
                res.push_back(x);
        }
        return res;
    }
};