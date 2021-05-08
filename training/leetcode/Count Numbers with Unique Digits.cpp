#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        // if (n == 2)
        //     return 91;
        int res = 10;
        for (int i = 2; i <= n; i++)
        {
            int tmp = 9;
            for (int k = 2; k <= i; k++)
            {
                tmp *= (11 - k);
            }

            res += tmp;
        }
        return res;
    }
};