#include <bits/stdc++.h>
using namespace std;

const int mx = 6e3;
long long mod = 1e9 + 7;
int dp[mx][mx];

int main()
{
    int n, i, j;
    int sum;
    char c;
    cin >> n;
    getchar();
    dp[1][0] = 1;
    for (i = 1; i <= n; i++)
    {
        cin >> c;
        if (c == 'f')
        {
            for (j = 0; j < n; j++)
            {
                dp[i + 1][j + 1] = dp[i][j];
            }
        }
        else
        {
            sum = 0;
            for (j = n - 1; j >= 0; j--)
            {
                sum = (sum + dp[i][j]) % mod;
                dp[i + 1][j] = sum;
            }
        }
    }
    sum = 0;
    for (j = 0; j < n; j++)
        sum = (sum + dp[n][j]) % mod;
    cout << sum << endl;
}