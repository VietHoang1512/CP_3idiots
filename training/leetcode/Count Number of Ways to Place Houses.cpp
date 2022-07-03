#include <bits/stdc++.h>
using namespace std;

long long main()
{
}

class Solution
{
public:
    long long countHousePlacements(long long n)
    {
        long long mod = 1000000007;
        vector<long long> a(n, 0), b(n, 0), c(n, 0), d(n, 0), e(n, 0);
        if (n == 1)
            return 4;
        if (n == 2)
            return 9;
        a[0] = 1;
        b[0] = 1;
        c[0] = 1;
        d[0] = 1;
        e[0] = 4;

        a[1] = 2;
        b[1] = 2;
        c[1] = 1;
        d[1] = 4;
        e[1] = 9;
        for (long long i = 2; i < n; i++)
        {
            a[i] = (b[i - 1] + d[i - 1])%mod;
            b[i] = (a[i - 1] + d[i - 1])%mod;
            c[i] = e[i - 2];
            d[i] = e[i - 1];
            e[i] = (a[i] + b[i] + c[i] + d[i])%mod;
        }
        return e[n - 1];
    }
};