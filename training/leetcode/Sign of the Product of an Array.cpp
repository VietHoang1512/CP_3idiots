#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int res = 1;
        for (auto x : nums)
        {
            if (x == 0)
                return 0;
            res *= (x / abs(x));
        }
        return res;
    }
};