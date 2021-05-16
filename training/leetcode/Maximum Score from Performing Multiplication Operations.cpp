#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        cout << "\n\n";
        int res = 0;
        int m = nums.size(), n = multipliers.size();

        sort(nums.begin(), nums.end());
        sort(multipliers.begin(), multipliers.end());
        cout << "nums: ";
        for (auto x : nums)
        {
            cout << x << " ";
        }
        cout << "\nmultipliers: ";
        for (auto x : multipliers)
        {
            cout << x << " ";
        }
        cout << endl;
        int l = 0, r = 1;
        for (int i = 0; i < n; i++)
        {
            int left = nums[l] * multipliers[l];
            int right = nums[m - r] * multipliers[n - r];
            if (left > right)
            {
                cout << nums[l] << " vs " << multipliers[l] << endl;
                res += left;
                l++;
            }
            else
            {
                cout << nums[m - r] << " vs " << multipliers[n - r] << endl;
                res += right;
                r++;
            }
        }
        return res;
    }
};