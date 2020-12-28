#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int mx = 1e5;

int main()
{

    int test, n, k;
    int A[mx], dp[mx];
    cin >> test;
    // cout << "Num test case " << test << endl;

    for (int t = 0; t < test; t++)
    {
        int cnt = 0;
        memset(dp, 0, sizeof(dp));
        // cout << "On test " << t << "\n";
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        for (int i = 0; i < n; i++)
        {
            if (A[i] == k / 2)
                cnt++;
            for (int j = i; j < n; j++)
            {

                if (A[j] == k - A[i])
                {
                    dp[j] = 1;
                }
            }
        }
        cnt /= 2;
        if (!(k % 2))
        {
            for (int i = 0; i < n; i++)
            {
                if ((A[i] == k / 2))
                {
                    if (cnt)
                    {
                        dp[i] = 1;
                        cnt--;
                    }
                    else
                    {
                        dp[i] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
}
