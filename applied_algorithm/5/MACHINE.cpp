#include <bits/stdc++.h>

using namespace std;
const int mx = 2e6 + 10;
int n, si, ti, c[mx], d[mx], dp[mx];
pair<int, int> input[mx];

// bool cmp(pair<int, int> s1, pair<int, int> s2)
// {
//     return s1.second <= s2.second;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> si >> ti;
        c[ti] = max(c[si], ti - si);
        d[si] = max(d[si], ti - si);
        // dp[t[i]] = max(dp[i], t[i]);
        // input[i] = pair<int, int>(s[i], t[i]);
    }
    int tmp = -1;
    for (int i = 1; i < mx; i++)
    {
        dp[i] = max(dp[i - 1], c[i - 1]);
        // cout << dp[i] << "\n";
        if (d[i] && dp[i])
        {
            // cout << "i " << i << endl;
            // cout << "dp[i] " << dp[i] << endl;
            // cout << "d[i] " << d[i] << endl;
            tmp = max(tmp, dp[i] + d[i]);
        }
    }
    // cout << "\n\n\n\n";
    cout << tmp;

    // sort(input+1, input+n, cmp);
    // for(int i=1; i<=n; i++){
    // cout << input[i].second << " ";
    // }
    // int tmp=0;
    // for(int i=1; i<=1e6; i++){
    //     tmp = max(tmp, dp[i]);
    //     dp[i] = tmp;
    //     cout << tmp << " ";

    // }

    // for(int )
    // int res = -1;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if ((s[i] > t[j]) || (s[j] > t[i]))
    //             res = max(res, c[i] + c[j]);
    //     }
    // }
    // cout << res;
}