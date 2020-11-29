#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000], dp[1000][1000];
// int main()
// {

//     cin >> n >> k;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         a[i] %= k;
//     }
//     dp[0] = a[0];
//     for (int i = 1; i < n; i++)
//     {
//         dp[i] += (!(a[i]%k));
//         for (int j = 0; j < i; j++)
//         {
//             dp[i] += (a[i] + dp[j]);
//         }
//     }
//     int res = 0;
//     for (int i = 0; i < n; i++)
//     {
//         res = max(res, dp[i]);
//     }
//     cout << res;
// }

// int chuanHoa(long k, long x)
// {
//     long tmp = x % k;
//     if (tmp < 0)
//         return tmp + k;
//     return tmp;
// }

int main()
{

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= k;
    }
    // for (int i = 0; i < k; i++)
    // {
    //     dp[0][i] = -1;
    // }
    memset(dp, -1, sizeof(dp));

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == 1)
                dp[i][j] = ((a[i] % k) == j);
            else
            {
                dp[i][j] = max((int)((a[i] % k) == j), (dp[i - 1][(j + k - a[i])%k]>0)*(dp[i - 1][(j + k - a[i]) % k] + 1) );
            }

            cout << dp[i][j] << " ";
        }
        cout << endl;
        res = max(res, dp[i][0]);
    }
    cout << res;

    // for (int j = 1; j < n; j++)
    // {
    //     for (int i = 0; i < k; i++)
    //     {
    //         M[i][j] = max(M[i][j - 1], M[chuanHoa(k, i - a[j])][j - 1] + 1);
    //     }
    // }

    // cout << M[0][n - 1];
}