#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int total = nums.size();
        vector<int> res(total);
        for (int i = 0; i < total; i++)
        {
            for (auto x : nums)
            {
                res[i] += (x < nums[i]);
            }
        }
        return res;
    }
};