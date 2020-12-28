#include <bits/stdc++.h>

using namespace std;
const int mx = 2e6;
int n, s[mx], t[mx], c[mx], dp[mx];
pair<int, int> input[mx];

bool cmp(pair<int, int> s1, pair<int, int> s2)
{
    return s1.second <= s2.second;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> t[i];
        c[i] = t[i] - s[i];
        dp[t[i]] = max(dp[i], t[i]);
        // input[i] = pair<int, int>(s[i], t[i]);
    }
    // sort(input+1, input+n, cmp);
    // for(int i=1; i<=n; i++){
        // cout << input[i].second << " ";
    // }
    int tmp=0;
    for(int i=1; i<=1e6; i++){
        tmp = max(tmp, dp[i]);
        dp[i] = tmp;
        cout << tmp << " ";

    }

    // for(int )
    int res = -1;
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