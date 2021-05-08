#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int res = INT_MAX;
        for (auto x : nums)
        {
            res = min(res, x);
        }
        return res;
    }
};