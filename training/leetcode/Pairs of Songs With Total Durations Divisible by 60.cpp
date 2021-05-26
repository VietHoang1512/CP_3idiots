#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> cnt(60);
        for (auto x : time)
        {
            cnt[x % 60]++;
        }
        int res = 0;
        for (int i = 1; i <= 29; i++)
        {
            res += cnt[i] * cnt[60 - i];
        }
        res += (cnt[0] * (cnt[0] - 1) / 2);
        res += (cnt[30] * (cnt[30] - 1) / 2);
        return res;
    }
};