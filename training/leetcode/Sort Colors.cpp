#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        vector<int> cnt(3);
        for (auto n : nums)
        {
            cnt[n]++;
        }
        int cur = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = cur; j < cur + cnt[i]; j++)
            {
                nums[j] = i;
            }
            cur += cnt[i];
        }
    }
};