#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minFlips(string target)
    {
        string s(target.size(), '0');
        int idx = 0, res = 0;
        while (idx < target.size())
        {
            if ((s[idx] - target[idx] - res) % 2)
            {
                res++;
            }
            idx++;
        }
        return res;
    }
};