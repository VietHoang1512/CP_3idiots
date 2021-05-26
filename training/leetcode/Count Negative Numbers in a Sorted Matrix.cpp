#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int res = 0;
        for (auto x : grid)
        {
            for (auto y : x)
            {
                res += (y < 0);
            }
        }
        return res;
    }
};