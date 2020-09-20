#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long T, n, mn, tmp;
    long long a[30000], b[30000], c[30000], cnt;
    cin >> T;
    while (T--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        mn = a[0];
        cnt = 0;

        for (int i = 0; i < n; i++)
        {
            tmp = max((long long)0, a[(i + 1) % n] - b[i]);
            mn = min(mn, a[(i + 1) % n] - tmp);
            cnt += tmp;
        }

        cout << cnt + mn << endl;
    }
}
