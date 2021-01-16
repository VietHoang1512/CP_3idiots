#include <bits/stdc++.h>

using namespace std;

const long long mx = 5000;
long long N, M, A[mx][mx];

long long dp[mx][mx], res;

long long getMaxArea(long long hist[], long long n)
{

    stack<long long> s;

    long long max_area = 0;
    long long tp;
    long long area_with_top;

    long long i = 0;
    while (i < n)
    {

        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        else
        {
            tp = s.top();
            s.pop();

            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main()
{
    cin >> M >> N;
    for (long long i = 1; i <= M; i++)
    {
        for (long long j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            if (A[i][j])
                dp[i][j] = dp[i - 1][j] + 1;
        }
        res = max(res, getMaxArea(dp[i], N+1));
    }
    cout << res;
}