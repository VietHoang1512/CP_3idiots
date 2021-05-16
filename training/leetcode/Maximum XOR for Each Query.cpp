#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int total = nums.size();
        vector<int> xr{nums[0]};
        for (int i = 1; i < total; i++)
        {
            xr.push_back(xr.back() ^ nums[i]);
        }
        vector<int> res(total);
        for (int i = 0; i < total; i++)
        {
            int bit = min(maximumBit, (int)ceil(log2(xr[total - 1 - i])));
            int k = (1 << bit) ^ xr[total - 1 - i];
            res[i] = k;
        }
        return res;
    }
};