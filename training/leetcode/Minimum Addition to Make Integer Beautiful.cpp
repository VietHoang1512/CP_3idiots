#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        vector<long long> v;
        long long m = n, n_digit = 0;
        while (m)
        {
            v.push_back(m % 10);
            m /= 10;
            n_digit++;
        }
        reverse(v.begin(), v.end());
        int break_id = INT_MAX, tmp;
        int trigger = 0 for (int i = 0; i < n_digit; i++)
        {
            tmp += v[i];
            if (tmp > target)
            {
                if (v[i] == 1)
                    trigger = 1;
                break_id = i;
                break;
            }
        }
        if (break_id == INT_MAX)
            return 0;
        int t = break_id - 1;
        while (1)
        {
            if (break_id < 0)
            {
                return pow(10, n_digit) - n;
            }
            v[break_id] += 1;
            if (v[break_id] <= 9)
                break break_id--;
        }
        long long res = 0;
        for (int i = 0; i < n_digit; i++)
        {
            if (i <= t)
                res += v[i] * pow(10, n_digit - i - 1);
        }
        return res;
    }
};