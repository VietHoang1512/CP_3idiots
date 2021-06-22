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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int total = nums.size();
        vector<int> res(total);
        int tmp = 1;
        for (int i = 0; i < total; i++)
        {
            tmp *= nums[i];
            res[i] = tmp;
        }
        tmp = 1;
        for (int i = total - 1; i >= 1; i--)
        {
            res[i] = res[i - 1] * tmp;
            tmp *= nums[i];
        }
        res[0] = tmp;
        return res;
    }
};