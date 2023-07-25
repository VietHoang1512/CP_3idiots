#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        map<int, int> m;
        int total = v.size(), res = 1;
        m[v[0]] = 1;
        for (int i = 1; i < total; i++)
        {
            int root = sqrt(v[i]);
            if (root * root == v[i])
            {
                m[v[i]] = m[root] + 1;
            }
            else
                m[v[i]] = 1;
            res = max(res, m[v[i]]);
        }
        if (res == 1)
            return -1;
        return res;
    }
};