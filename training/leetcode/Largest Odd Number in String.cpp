#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int meet = -1, total = num.size();
        for (int i = total - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2)
            {
                meet = i;
                break;
            }
        }
        if (meet == -1)

            return "";

        return num.substr(0, meet + 1);
    }
};