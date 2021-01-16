#include <bits/stdc++.h>

using namespace std;

const long long mx = 100005;
long long n, m, M;
long long A[mx], cum_sum[mx], s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> M;
    for (long long i = 1; i <= n; i++)
    {

        cin >> A[i];
        s += A[i];
        cum_sum[i] = s;
    }
    s = 0;
    // for (long long i = 1; i <= n; i++)
    // {
    //     cout << cum_sum[i] << " ";
    // }
    // cout << endl;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i; j <= n; j++)
        {
            // cout << i << " " << j <<  " " << cum_sum[j] - cum_sum[i - 1] << endl;
            if (((cum_sum[j] - cum_sum[i - 1]) >= m) && ((cum_sum[j] - cum_sum[i - 1]) <= M))
                s++;
        }
    }
    cout << s;
}