#include <iostream>

using namespace std;

int a[202];
int n, k1, k2, len;

void func(int k)
{
    if (k == (n + 1))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    int old_len = len;
    if (k == 1)
    {
        a[k] = 0;
        len = 0;
        func(k + 1);
        len = old_len;

        a[k] = 1;
        len = len + 1;
        func(k + 1);
        len = old_len;
    }
    else if ((a[k - 1] == 0) && (n - k + 1 < k1))
    {
        return;
    }
    else if (len < k1)
    {
        a[k] = 1;
        len = len + 1;
        func(k + 1);
        len = old_len;
    }
    else if ((len >= k1) && (len < k2))
    {
        a[k] = 0;
        len = 0;
        func(k + 1);
        len = old_len;

        a[k] = 1;
        len = len + 1;
        func(k + 1);
        len = old_len;
    }
    else
    {
        a[k] = 0;
        len = 0;
        func(k + 1);
        len = old_len;
    }
}

int main()
{
    cin >> n >> k1 >> k2;
    len = 0;
    func(1);
    return 0;
}