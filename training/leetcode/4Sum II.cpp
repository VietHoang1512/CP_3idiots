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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int total = nums1.size();
        map<int, int> m1, m2;

        int res = 0;
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                m1[nums1[i] + nums2[j]]++;
                m2[nums2[i] + nums3[j]]++;
            }
        }
        // for (auto p : m1)
        // {
        //     cout << p.first << " " << p.second << endl;
        // }
        // cout << "\n";
        // for (auto p : m2)
        // {
        //     cout << p.first << " " << p.second << endl;
        // }
        for (auto p : m1)
        {
            res += p.second * m2[-p.first];
        }
        // cout << "\n\n\n";
        return res;
    }
};