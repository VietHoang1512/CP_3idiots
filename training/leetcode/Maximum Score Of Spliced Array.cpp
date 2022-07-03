#include <bits/stdc++.h>
using namespace std;

long long main()
{
}

class Solution
{
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int s1 = accumulate(nums1.begin(), nums1.end(), 0), s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int res = max(s1, s2);
        if (n == 1)
            return res;
        vector<int> dp1(n, 0), dp2(n, 0);
        if (nums1[0] >= nums2[0])
        {
            dp1[0] = 0;
            dp2[0] = nums1[0] - nums2[0];
            res = max(res, s2 + dp2[0]);
        }
        else
        {
            dp2[0] = 0;
            dp1[0] = nums2[0] - nums1[0];
            res = max(res, s1 + dp1[0]);
        }
        for (int i = 1; i < n; i++)
        {
            if (nums1[i] > nums2[i])
            {
                dp1[i] = max(0, dp1[i - 1] - nums1[i] + nums2[i]);
                dp2[i] = dp2[i - 1] + nums1[i] - nums2[i];
            }
            else if (nums2[i] > nums1[i])
            {
                dp2[i] = max(0, dp2[i - 1] - nums2[i] + nums1[i]);
                dp1[i] = dp1[i - 1] + nums2[i] - nums1[i];
            }
            else
            {
                dp1[i] = dp1[i - 1];
                dp2[i] = dp2[i - 1];
            }
            res = max(res, s1 + dp1[i]);
            res = max(res, s2 + dp2[i]);
        }
        return res;
    }
};