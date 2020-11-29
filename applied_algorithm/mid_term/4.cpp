#include <bits/stdc++.h>
using namespace std;
int n, k;

stack<double> s;
double a[100000], cum_sum[100000];
double res = -__DBL_MAX__;
pair<int, double> dp[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    double cum_sum_ = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cum_sum_ += a[i];
        cum_sum[i] = cum_sum_;
    }
    dp[k] = pair<float, double>(k, cum_sum[k]);
    res = cum_sum[k]/k;

    for (int i = k + 1; i <= n; i++)
    {
        double sum_tmp1 = (dp[i - 1].second + a[i]) / (dp[i - 1].first + 1);
        double sum_tmp2 = ((cum_sum[i] - cum_sum[i - k]) / (k));
        if (sum_tmp1 < sum_tmp2)
        {
            dp[i] = pair<double, double>(dp[i - 1].first + 1, (dp[i - 1].second + a[i]));
        }
        else
        {
            dp[i] = pair<double, double>(k, (cum_sum[i] - cum_sum[i - k] ));
        }
        res = max(res, max(sum_tmp1, sum_tmp2));
    }
    // for (int i = 1; i <= n - k; i++)
    // {
    //     for (int j = i + k-1; j <= n; j++)
    //     {
    //         res = max(res, ((cum_sum[j] - cum_sum[i]+a[i]) / (j - i+1)));
    //     }
    // }

    cout << fixed << setprecision(5) << res;
}