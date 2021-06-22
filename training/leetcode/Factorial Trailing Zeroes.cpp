#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int p = 5, res = 0;
        while (p <= n)
        {
            res += (n / p);
            p *= 5;
        }
        return res;
    }
};