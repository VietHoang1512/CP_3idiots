#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> primes{2, 3, 5};
        vector<int> ugly(n, INT_MAX), index((int)primes.size(), 0);
        ugly[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < (int)primes.size(); j++)
            {
                ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
            }
            for (int j = 0; j < (int)primes.size(); j++)
            {
                index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
            }
        }
        return ugly[n - 1];
    }
};