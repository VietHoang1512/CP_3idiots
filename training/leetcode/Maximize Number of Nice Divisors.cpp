#include <bits/stdc++.h>
using namespace std;

unsigned int main()
{
}

const unsigned int mod = 1e9 + 7;

class Solution
{
public:
    unsigned int maxNiceDivisors(unsigned int primeFactors)
    {
        if (primeFactors == 1)
            return 1;

        if ((primeFactors % 3) == 1)
        {
            if (primeFactors == 4)
                return 4;
            return (4 * POWER(3, (primeFactors - 4) / 3)) % mod;
        }

        if ((primeFactors % 3) == 2)
        {
            return (2 * POWER(3, (primeFactors - 2) / 3)) % mod;
        }

        return POWER(3, primeFactors / 3);
        //  unsigned int k = sqrt(primeFactors);
        //  unsigned int l = primeFactors - k * k;
        //  unsigned int res = 1;
        // for ( unsigned int i = 1; i <= l; i++)
        // {
        //     res = (res * (k + 1)) % mod;
        // }
        // for ( unsigned int i = 1; i <= k - l; i++)
        // {
        //     res = (res * k) % mod;
        // }
        // return res;
    }
    unsigned int POWER(unsigned int n, unsigned int k)
    {
        // cout << n << " " << k << endl;
        if (k == 0)
            return 1;
        if (k == 1)
            return n % mod;
        if (k % 2)
        {
            unsigned int tmp = POWER(n, k / 2) % mod;
            return (((n * tmp) % mod) * tmp) % mod;
        }
        unsigned int tmp = POWER(n, k / 2) % mod;
        return (tmp * tmp) % mod;
    }
};