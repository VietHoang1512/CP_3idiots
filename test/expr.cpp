#include <bits/stdc++.h>

using namespace std;

int n, b, a[40], amax = 0;

int res, cur;

void Try(int k)
{
    if (((cur + (n + 1 - k) * amax) < b) || ((cur - (n + 1 - k) * amax) > b))
        return;
    if (k == n + 1)
    {
        // cout << "hi";
        res += (cur == b);
        return;
    }
    
    int tmp = cur;
    cur += a[k];
    Try(k + 1);
    cur = tmp;

    cur -= a[k];
    Try(k + 1);
    cur = tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        amax = max(amax, abs(a[i]));
    }
    cur = a[1];
    Try(2);
    cout << res;
}