#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int total = nums.size();
        for (int i = 0; i < total; i++)
        {
            while (nums[i] > 0 && nums[i] <= total && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < total; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return total + 1;
    }
};