#include <bits/stdc++.h>

using namespace std;
const int mx = 1e7;
int n, l1, l2, a[mx];
int dp[mx], res = 0;

int main()
{
    // cin >> n >> l1 >> l2;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> a[i];
    //     // cout << a[i];
    // }
    // // cout << n;
    // for (int i = 1; i <= l1; i++)
    // {
    //     dp[i] = a[i];
    //     // cout << dp[i] << " ";
    //     res = max(res, dp[i]);
    // }

    // for (int i = l1 + 1; i <= n; i++)
    // {
    //     int tmp = 0;
    //     for (int j = l1; j <= l2; j++)
    //     {   if((i-j)<1) continue;
    //         tmp = max(tmp, dp[i - j]);
    //     }
    //     dp[i] = tmp + a[i];
    //     // cout << dp[i] << " ";
    //     res = max(res, dp[i]);
    // }
    cout << res;
}