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
    int majorityElement(vector<int> &nums)
    {
        int candidate, cnt = 0;
        for (auto n : nums)
        {
            if (cnt == 0)
            {
                candidate = n;
                cnt++;
                continue;
            }
            if (n == candidate)
            {
                cnt++;
            }
            else
                cnt--;
        }
        return candidate;
    }
};