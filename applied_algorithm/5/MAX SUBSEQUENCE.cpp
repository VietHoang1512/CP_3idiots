#include <bits/stdc++.h>

using namespace std;
const int mx = 1e7;
long long n, a[mx], dp[mx];
int main()
{
    cin >> n;
    long long res;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[1] = a[1];
    res = a[1];
    for (long long i = 2; i <= n; i++)
    {
        dp[i] = max(a[i], a[i] + dp[i-1]);
        res = max(res, dp[i]);
    }
    cout << res;
}