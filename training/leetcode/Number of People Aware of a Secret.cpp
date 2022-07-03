#include <bits/stdc++.h>
using namespace std;

long long main()
{
}

class Solution
{
public:
    long long peopleAwareOfSecret(long long n, long long delay, long long forget)
    {
        vector<long long> days(forget + 2, 0);
        long long mod = 1000000007;

        days[forget] = 1;
        long long d = 1;
        n--;
        while (n--)
        {
            for (long long i = 1; i <= forget; i++)
            {
                days[i] = days[i + 1];
                if (forget - i >= delay)
                {
                    days[forget + 1] += days[i];
                    days[forget + 1] %= mod;
                }
            }
            days[forget + 1] = 0;
            // cout << "\nDAY " << ++d << ": ";
                
            long long res = 0;
            for (long long i = 0; i <= forget; i++)
            {
                // cout << " (" << i <<": " << days[i] << ") ";
                res += days[i];
                res %= mod;
                
            }
            // cout << " TOTAL: " << res ;
        }
        long long res = 0;
        for (long long i = 0; i <= forget; i++)
        {
            res += days[i];
            res %= mod;
        }
        // cout << "\n*****\n";
        return res;
    }
};