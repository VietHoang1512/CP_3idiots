#include <bits/stdc++.h>
using namespace std;

int n, a[100000];

int main()
{
    cin >> n;
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= a[i - 1])
            res++;
    }
    cout << res;
}