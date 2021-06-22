#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        long long base = 'Z' - 'A' + 1;
        long long total = columnTitle.size(), res = 0, tmp = 1;
        for (long long i = 0; i < total; i++)
        {
            res += (columnTitle[total-i-1]-'A'+1)*tmp;
            tmp*=base;
        }
        return res;
    }
};