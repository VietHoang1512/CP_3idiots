# include <bits/stdc++.h>

using namespace std;

const int mx = 1005;
// const int mx = 12;
int N, T, D;
int a[mx], t[mx], dp[mx][mx], res = 0;

int main()
{
    cin >> N >> T >> D;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    for (int i = 1; i <= N; i++)
        cin >> t[i];

    for (int i = 1; i <= N; i++)
    {
        if (t[i]<T)
            {
                dp[i][t[i]] = a[i];
                res = max(res, a[i]);
            }

        int tmp = 0;
        for (int j = i - D; j <= i - 1; j++)
        {
            if (j > 0)
            {
                for (int t_ = 0; t_ <= T - t[i]; t_++)
                {
                    dp[i][t_ + t[i]] = max(dp[i][t_ + t[i]], dp[j][t_] + a[i]);
                    res = max(res, dp[i][t_ + t[i]]);
                }
            }
        }
    }
    // for (int i = 0; i <= N; i++)
    // {
    //     for (int j = 1; j <= T; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << res;
}