#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int sumBase(int n, int k)
    {
        int res = 0;
        while (n)
        {
            res += n % k;
            n /= k;
        }
        return res;
    }
};