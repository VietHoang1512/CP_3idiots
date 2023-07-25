#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidSubstring(string word, vector<string> &forbidden)
    {
        int total = word.size(), res=0;
        map<string, int> m;
        for (auto x : forbidden)
            m[x] = 1;
        // for (int len = 1; len <= 10; len++)
        // {
        //     if (total < len)
        //         break;
        //     for (int i = 0; i < total - len; i++)
        //     {
        //         str tmp = s.substr(i, len);
        //         if(m[tmp])
        //     }
        // }
        vector<int> dp(total);
        string tmp = word[0];
        dp[0] = 1 - m[tmp];
        for (int i = 1; i < total; i++)
        {
            bool ok = true;
            for (int len = 1; len <= min(10, i + 1); len++)
            {
                str tmp2 = word.substr(i - len, len);
                if (m[tmp2])
                    ok = false;
            }
            if (ok)
                dp[i] = dp[i - 1] + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};