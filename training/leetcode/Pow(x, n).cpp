#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}
class Solution
{
public:
    double myPow(double x, int n)
    {
        float sgn = (n >= 1) ? 1 : -1;
        n = abs(n);
        if (n == 0)
            return 1;
        double tmp = myPow(x, n / 2);
        tmp *= tmp;
        if (n % 2)
        {
            if (sgn > 0)
                return x * tmp;
            return 1 / (x * tmp);
        }
        if (sgn > 0)
            return tmp;
        return 1 / tmp;
    }
};