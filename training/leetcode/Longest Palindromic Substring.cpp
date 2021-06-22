#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int cnt = 1, total = s.size();
        string res;
        res += s[0];
        for (int i = 0; i < total; i++)
        {
            int mx = min(i, total - 1 - i);
            for (int k = 1; k <= mx; k++)
            {
                if (s[i - k] != s[i + k])
                {
                    if (cnt < 2 * k - 1)
                    {
                        res = s.substr(i - k + 1, 2 * k - 1);
                        cnt = 2 * k - 1;
                    }
                    break;
                }
                if (k == mx)
                {
                    if (cnt < 2 * k + 1)
                    {
                        res = s.substr(i - k, 2 * k + 1);
                        cnt = 2 * k + 1;
                    }
                }
            }
        }
        // cout << res << endl;
        for (int i = 0; i < total - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                if (cnt < 2)
                {
                    cnt = 2;
                    res = s.substr(i, 2);
                }

                int mx = min(i, total - 2 - i);
                for (int k = 1; k <= mx; k++)
                {
                    if (s[i - k] != s[i + 1 + k])
                    {
                        if (cnt < 2 * k)
                        {
                            res = s.substr(i - k + 1, 2 * k);
                            cnt = 2 * k;
                        }
                        break;
                    }
                    if (k == mx)
                    {
                        if (cnt < 2 * k + 2)
                        {
                            res = s.substr(i - k, 2 * k + 2);
                            cnt = 2 * k + 2;
                        }
                    }
                }
            }
        }
        // cout << res << endl
        //      << endl;
        return res;
    }
};