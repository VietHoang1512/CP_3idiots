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
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int visited = 0, total = nums.size();
        int cum_sum = accumulate(nums.begin(), nums.end(), 0);
        if (cum_sum % k)
            return false;
        int target = cum_sum / k;

        for (int i = 1; i < (1 << total); i++)
        {
            if (__builtin_popcount(i & visited))
                continue;
            int sum = 0;
            for (int j = 0; j < total; j++)
            {
                sum += ((i >> j) & 1) * nums[j];
            }
            if (sum == target)
            {
                visited |= i;
                cout << bitset<16>(i) << endl;
            }
        }

        cout << endl
             << bitset<16>(visited) << endl;
        return visited + 1 == (1 << total);
    }
};