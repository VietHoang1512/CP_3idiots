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
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int total = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < (1 << total); i++)
        {
            vector<int> tmp;
            for (int j = 0; j < total; j++)
            {
                if ((i >> j) & 1)
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};