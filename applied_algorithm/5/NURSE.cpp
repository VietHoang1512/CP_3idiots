#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long dp[1000];
long long N, K1, K2;

int main()
{
    cin >> N >> K1 >> K2;
    // if(N<K1)

    // if (N < K2 + 2)
    // {
    //     cout << 1;
    //     return 0;
    // }

    // for (int idx=2; idx <= K1; idx++)
    // {
    //     dp[idx] = 0;
    // }
    dp[1] = 1;
    dp[K1 + 1] = 1;

    // for (long long i = K1 + 2; i <= K2 + 1; i++)
    // {
    //     dp[i] = 1;
    // }

    for (long long i = K1 + 2; i <= N+1; i++)
    {
        for (long long j = K1; j <= K2; j++)
        {
            if (i - j - 1 > 0)
            {
                dp[i] += (dp[i - j - 1] % mod);
                dp[i] = dp[i] % mod;
            }
        }
        // dp[i] = dp[i] % mod;
    }
    for (long long i = 1; i <= N+1; i++)
    {
        cout << dp[i] << " ";
    }
    // cout << "\nresult:\n";
    cout << (dp[N] + dp[N + 1]) % mod;
}