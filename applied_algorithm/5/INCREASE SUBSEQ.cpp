#include <bits/stdc++.h>

using namespace std;
long long n, a[100000], dp[100000];
int main()
{
    cin >> n;
    long long res = 1;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        long long tmp = 0;
        for (long long j = 1; j < i; j++)
        {
            if (a[i] > a[j])
                tmp = max(tmp, dp[j]);
        }
        dp[i] = tmp + 1;
        res = max(res, dp[i]);
    }
    cout << res;
}