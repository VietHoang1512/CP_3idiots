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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // cout << nums1.size() << " " << nums2.size();
        int l = m - 1, r = n - 1, cur = m + n - 1;
        while (cur >= 0)
        {
            if (r < 0)
            {
                nums1[cur] = nums1[l];
                l--;
            }
            else if (l < 0)
            {
                nums1[cur] = nums2[r];
                r--;
            }
            else if (nums1[l] >= nums2[r])
            {
                nums1[cur] = nums1[l];
                l--;
            }
            else
            {
                nums1[cur] = nums2[r];
                r--;
            }
            cur--;
        }
    }
};