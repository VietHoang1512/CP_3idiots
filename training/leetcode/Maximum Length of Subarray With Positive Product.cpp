#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int total = nums.size();
        vector<int> pos(total, 0);
        vector<int> neg(total, 0);

        if (nums[0] > 0)
            pos[0] = 1;

        if (nums[0] < 0)
            neg[0] = 1;

        for (int i = 1; i < total; i++)
        {
            if (nums[i] > 0)
            {
                pos[i] = pos[i - 1] + 1;
                if (neg[i - 1])
                    neg[i] = neg[i - 1] + 1;
            }
            else if (nums[i] < 0)
            {
                neg[i] = pos[i - 1] + 1;
                if (neg[i - 1])
                    pos[i] = neg[i - 1] + 1;
            }
            else
            {
                pos[i] = neg[i] = 0;
            }
        }
        // for (auto x : pos)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : neg)
        // {
        //     cout << x << " ";
        // }
        // cout << endl
        //      << endl;

        return *max_element(pos.begin(), pos.end());
    }
};