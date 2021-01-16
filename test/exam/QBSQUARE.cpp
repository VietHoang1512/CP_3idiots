#include <bits/stdc++.h>

using namespace std;

const long long mx = 5000;
long long N, M, A[mx][mx];

long long dp[mx][mx], res;

int main()
{
    cin >> M >> N;
    for (long long i = 1; i <= M; i++)
    {
        for (long long j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            
            if(A[i][j])
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            res = max(res, dp[i][j]);
        }
        
    }
    cout << res;
}