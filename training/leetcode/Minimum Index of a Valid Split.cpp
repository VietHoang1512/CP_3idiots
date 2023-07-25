#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int total = nums.size(), mode = 0, mode2 = 0;
        map<int, int> m m2;
        for (auto x : nums)
        {
            m[x]++;
            mode = max(m[x], mode);
        }
        int res = -1;
        for (int i = 0; i < total; i++)
        {
            m2[nums[i]]++;
            mode2 = max(mode2, m2[nums[i]]);

            if (mode2 == m2[nums[i]])
            {
                if (mode2 * mode2 > (i + 1))
                    if ((m[nums[i]] - mode2) * (m[nums[i]] - mode2) > (total - i))
                        return i;
            }
        }
        return -1;
    }
};