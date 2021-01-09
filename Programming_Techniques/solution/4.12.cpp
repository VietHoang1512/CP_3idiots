#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *h = new int[n + 1];
    int *k = new int[n + 1];

    long long *d = new long long[n + 1];
    stack<int> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    S.push(1);
    k[1] = 1;
    int a = 1;
    for (int i = 2; i <= n; i++)
    {
        while (!S.empty() && (h[S.top()] >= h[i]))
        {
            a = S.top();
            S.pop();
            d[a] = h[a] * (i - k[a]);
        }
        if (S.empty())
        {
            k[i] = 1;
        }
        else
        {
            k[i] = S.top() + 1;
        }
        S.push(i);
    }

    while (!S.empty())
    {
        a = S.top();
        S.pop();
        d[a] = h[a] * (n - k[a] + 1);
    }

    long long res = d[1];
    for (int i = 2; i <= n; i++)
    {
        res = max(res, d[i]);
    }
    cout << res;
    return 0;
}