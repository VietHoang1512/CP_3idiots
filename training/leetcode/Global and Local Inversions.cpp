#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int global = 0, local = 0, total = nums.size();
        for (int i = 0; i + 1 < total; i++)
        {
            if (nums[i] > i)
            {
                if ((nums[i + 1] != i) || (nums[i] != (i + 1)))
                    return false;
            }
            // if (nums[i] > nums[i + 1])
            //     local++;
            // for (int j = i + 1; j < total; j++)
            // {
            //     global += (nums[i] > nums[j]);
            // }
        }
        return true;
        // return (global == local);
    }
};