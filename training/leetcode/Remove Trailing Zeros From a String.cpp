#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        int total = num.size();
        int cur = total - 1;
        while (num[cur] == '0')
        {
            cur--;
        }
        return num.substr(0, cur);
    }
};