#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int longestSubsequence(string st, int k)
    {
        int len = st.size();
        int res = 0;
        vector<int> v;
        string s = string(s.rbegin(), s.rend());
        for (int i = 0; i < len; i++)
        {
            int cur = s[i] - '0';
            if (cur == 1)
                v.push_back(1);
            else
                res++;
        }

        int n = 0;
        for (int i = 0; i < len; i++)
        {
            int cur = s[i] - '0';
            if (cur == 1)
            {
                n += (1 << n);
                if (cur > k)
                    break;
                res++;
            }
        }
        return res;
    }
};