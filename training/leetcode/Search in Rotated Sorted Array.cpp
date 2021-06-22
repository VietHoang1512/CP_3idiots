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
    int search(vector<int> &nums, int target)
    {
        int total = nums.size(), pivot;
        int l = 0, r = total - 1;
        if (nums[l] > nums[r])
            while (r > l)
            {
                cout << nums[l] << " " << nums[r] << endl;
                int tmp = l + (r - l) / 2;
                if (nums[l] > nums[(l + 1) % total])
                {
                    r = l;
                    l = (l + 1) % total;
                    break;
                }
                if (nums[r] > nums[(r + 1) % total])
                {

                    l = (r + 1) % total;

                    break;
                }
                if (nums[tmp] > nums[(tmp + 1) % total])
                {
                    r = tmp;
                    l = (tmp + 1) % total;
                    break;
                }
                if (nums[l] > nums[tmp])
                {
                    r = tmp;
                }
                else if (nums[r] < nums[tmp])
                {
                    l = tmp;
                }
                if (r - l == 1)
                {
                    if (nums[l] > nums[(l + 1) % total])
                    {
                        r = l;
                        l = (l + 1) % total;
                        break;
                    }
                    if (nums[r] > nums[(r + 1) % total])
                    {

                        l = (r + 1) % total;
                        break;
                    }
                }
            }
        // cout << nums[l] << " " << nums[r] << "\n\n\n";
        int mod = l;
        l = 0, r = total - 1;
        while (r > l)
        {
            int tmp = l + (r - l) / 2;
            if (nums[(l + mod) % total] == target)
                return (l + mod) % total;
            if (nums[(r + mod) % total] == target)
                return (r + mod) % total;
            if (nums[(tmp + mod) % total] == target)
                return (tmp + mod) % total;
            if (nums[(tmp + mod) % total] > target)
            {
                r = tmp;
            }
            else
            {
                l = tmp;
            }
            if (r - l == 1)
            {
                if (nums[(l + mod) % total] == target)
                    return (l + mod) % total;
                if (nums[(r + mod) % total] == target)
                    return (r + mod) % total;
                return -1;
            }
        }
        if (nums[(l + mod) % total] == target)
            return (l + mod) % total;
        if (nums[(r + mod) % total] == target)
            return (r + mod) % total;
        return -1;
    }
};