#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 100;
int n, m, X[mx], Y[mx];
int dp[mx][mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> X[i];
    for (int i = 1; i <= m; i++)
        cin >> Y[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // cout << dp[i][j]<<" ";
        }
        // cout << endl;
    }
    cout << dp[n][m];
}