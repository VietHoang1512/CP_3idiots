#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        int total = nums1.size(), res = 1;
        vector<int> dp1(total, 1), dp2(total, 1);
        dp1[0] = 1;
        dp2[0] = 1;
        for (int i = 1; i < total; i++)
        {
            if (nums1[i] >= nums1[i - 1])
                dp1[i] = max(dp1[i - 1] + 1, dp1[i]);
            if (nums1[i] >= nums2[i - 1])
                dp1[i] = max(dp2[i - 1] + 1, dp1[i]);
            if (nums2[i] >= nums2[i - 1])
                dp2[i] = max(dp2[i - 1] + 1, dp2[i]);
            if (nums2[i] >= nums1[i - 1])
                dp2[i] = max(dp1[i - 1] + 1, dp2[i]);
            res = max(res, dp1[i]);
            res = max(res, dp2[i]);
        }
        return res;
    }
};