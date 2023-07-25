#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        map<int, int> m;
        vector<int> res;
        int cur = 1, i = 1;
        m[1]=1;
        while (1)
        {
            cur += i * k;
            i++;
            if (cur > n)
                cur -= n;

            if (m[cur])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!m[j])
                        res.push_back(j);
                }
                break;
            }
            else
                m[cur] = 1;
        }
        return res;
    }
};