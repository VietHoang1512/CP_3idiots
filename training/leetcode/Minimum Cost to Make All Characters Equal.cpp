#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string s)
    {
        vector<long long> v;
        for (auto c : s)
        {
            if (c == '0')
                v.push_back(0);
            else
                v.push_back(1);
        }
        long long total = v.size();
        vector<long long> R = {0, 0};

        long long l = total / 2 - 1, r = total / 2;
        for (long long target = 0; target <= 1; target++)
        {
            long long res = 0;
            long long flip_l = 0, flip_r = 0;

            for (long long i = l; i >= 0; i--)
            {
                if ((flip_l + v[i] - target) % 2)
                {
                    flip_l++;
                    res += (i + 1);
                }
            }
            for (long long i = r; i < total; i++)
            {
                if ((flip_r + v[i] - target) % 2)
                {
                    flip_r++;
                    res += (total - i);
                }
            }
            R[target] = res;
        }

        return min(R[0], R[1]);
    }
};