#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int numberOfWays(string corridor)
    {
        long long cnt = 0, total = 0, cur = 0;
        long long mod = 1e9 + 7;
        vector<long long> v, v2;
        long long is_start = 1;
        for (auto x : corridor)
        {
            if (x == 'S')
            {
                is_start = 0;
                cnt++;
                total++;
                v.push_back(1);
                if (cnt == 2)
                    cnt = 0;
            }
            else
            {
                if (cnt == 1)
                    continue;
                else if (!is_start)
                    v.push_back(0);
            }
        }

        if (total % 2 || !total)
            return 0;

        while (!v.back())
            v.pop_back();


        for (auto x : v)
        {
            // cout << x << " ";
            if (x == 1)
            {
                v2.push_back(cur);
                cur = 0;
            }
            else
                cur++;
        }
        cout << endl;
        long long res = 1;
        for (auto x : v2)
        {
            // cout << x << " ";
            res = (res * (x + 1)) % mod;
        }

        return res;
    }
};