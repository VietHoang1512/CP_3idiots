#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // nums.push_back(-INT_MAX);
        int total = nums.size();
        if (total == 2)
            return (nums[1] > nums[0]) ? 1 : 0;
        if (total == 1)
            return 0;
        for (int i = 1; i < total - 1; i++)
        {
            if ((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
                return i;
        }
        if (nums[0] > nums[1])
            return 0;
        return total - 1;
    }
};