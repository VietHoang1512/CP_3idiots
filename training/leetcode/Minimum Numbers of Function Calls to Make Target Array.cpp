#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int total = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        if (mx == 0)
            return 0;

        int subtract = 0, divide = 0;
        for (int i = 0; i < total; i++)
        {
            if (nums[i] % 2)
            {
                subtract++;
                nums[i]--;
            }
            if (nums[i])
            {
                divide = 1;
            }
        }
        if (divide)
        {
            for (int i = 0; i < total; i++)
            {
                nums[i] /= 2;
            }
        }

        return subtract + divide + minOperations(nums);
    }
};