#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long n, a[250000], b[250000];
long long res = 0;
long long cur_term;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= mod;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    cur_term = a[0];
    for (int i = 0; i < n - 1; i++)
    {
        // cout << "Start " << i + 1 << " RESULT " << res << " CURRENT " << cur_term << endl;
        if (b[i] - 2)
        {
            res += cur_term;
            res %= mod;
            if (b[i] == 1)
                cur_term = a[i + 1];
            else
                cur_term = -a[i + 1];
        }

        else
        {
            cur_term *= a[i + 1];
            cur_term %= mod;
        }
        if (i + 2 == n)
            res += cur_term;
        // cout << "End " << i + 1 << " RESULT " << res << " CURRENT " << cur_term << endl;
    }
    res %= mod;
    cout << res;
}