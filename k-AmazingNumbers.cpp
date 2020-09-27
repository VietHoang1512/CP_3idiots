#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int mx = 3e5;
int A[mx], dp[mx];
int test, n;
int main()
{

    cin >> test;
    // cout << "Num test case " << test << endl;

    for (int t = 0; t < test; t++)
    {

        cin >> n;

        for (int k = 0; k < n; k++)
        {
            cin >> A[k];
        }

        for (int k = 0; k < n; k++)
        {
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < n; i++)
            {
                if (i - dp[A[i]] <= k)
                {
                    dp[A[i]] = i;
                }
            }
            int res = n;
            for (int i = 0; i < mx; i++)
            {
                if (dp[A[i]] > n - 1 - k)
                    res = min(res, A[i]);
            }

            if (res == n)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << res << " ";
            }
        }
        cout << endl;
    }

    cout << "DONE";
    return 0;
}
