#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1,
            r = *max_element(nums.begin(), nums.end()) + 1;

        while (r > l)
        {
            int tmp = (r + l) / 2;
            if (dividable(nums, threshold, tmp))
            {
                r = tmp;
            }
            else
            {
                l = tmp;
            }
            if (r == l + 1)
            {
                if (dividable(nums, threshold, l))
                    return l;
                break;
            }
        }
        return r;
    }
    bool dividable(vector<int> nums, int threshold, float d)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = ceil(nums[i] / d);
        }
        return accumulate(nums.begin(), nums.end(), 0) <= threshold;
    }
};