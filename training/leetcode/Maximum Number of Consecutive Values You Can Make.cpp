#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 4 * 1e4 + 5;
class Solution
{
public:
    int cnt[mx];
    int getMaximumConsecutive(vector<int> &coins)
    {
        int total = coins.size();
        int max_e = 0;
        // sort(coins.begin(), coins.end());
        set<int> s;
        for (auto x : coins)
        {
            cnt[x]++;
            max_e = max(max_e, x);
            if (x > 1)
                s.insert(x);
        }

        if (!cnt[1])
            return 1;

        int tmp = cnt[1];

        for (auto x : s)
        {
            if (x <= tmp + 1)
            {
                tmp = cnt[x] * x + tmp;
            }
            else
            {
                break;
            }
        }
        return tmp + 1;
    }
};