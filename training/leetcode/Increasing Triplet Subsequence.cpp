#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (auto x : nums)
        {
            if (x <= c1)
            {
                c1 = x;
            }
            else if (x <= c2)
            {
                c2 = x;
            }
            else if (x > c2 && c2 > c1)
            {
                return true;
            }
        }
        return false;
    }
};