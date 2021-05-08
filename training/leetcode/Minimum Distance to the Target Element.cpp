#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int res = INT_MAX, total = nums.size();
        for (int i = 0; i < total; i++)
        {
            if (nums[i] == target)
            {
                res = min(res, abs(start - i));
            }
        }
        return res;
    }
};