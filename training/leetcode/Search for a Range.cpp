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
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int found = 0, l = 0, total = nums.size(), r = total - 1;
        if (total == 0)
            return {-1, -1};
        if (total == 1)
            if (nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};

        while (r > l)
        {
            int tmp = l + (r - l) / 2;
            if (nums[tmp] == target || nums[l] == target || nums[r] == target)
                found = 1;
            if (nums[tmp] <= target)
            {
                l = tmp;
            }
            else
                r = tmp;
            if (r == l + 1)
            {
                if (nums[l] >= target && nums[r] > target)
                    r = l;
                break;
            }
        }
        int right = r;
        l = 0, r = total - 1;

        while (r > l)
        {
            int tmp = l + (r - l) / 2;
            if (nums[tmp] == target || nums[l] == target || nums[r] == target)
                found = 1;
            if (nums[tmp] >= target)
            {

                r = tmp;
            }
            else
                l = tmp;
            if (r == l + 1)
            {
                if (nums[r] <= target && nums[l] < target)
                    l = r;
                break;
            }
        }
        int left = l;
        cout << left << " " << right << endl;
        if (found)
            return {left, right};
        return {-1, -1};
    }
};