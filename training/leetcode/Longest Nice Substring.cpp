#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        string res;
        int tmp = 0;
        int total = s.size();
        for (int i = 0; i < total - 1; i++)
        {
            for (int j = 0; j < total - i; j++)
            {
                string candidate = s.substr(i, j);
                if (CHECK(candidate) && (j > tmp))
                {
                    res = candidate;
                    tmp = j;
                }
            }
        }
        return res;
    }
    bool CHECK(string s)
    {
        unordered_map<char, int> m;
        for (auto x : s)
        {
            m[x]++;
        }
        for (auto x : s)
        {
            if ((x - 'A' >= 0) && ('Z' - x >= 0))
            {
                if (!m.count(x - 'A' + 'a'))
                    return false;
            }
            else
            {
                if (!m.count(x - 'a' + 'A'))
                    return false;
            }
        }
        return true;
    }
};