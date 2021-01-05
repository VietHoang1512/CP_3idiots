#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    printf("Done input\n");
    vector<int> f(n);
    for (int i = 0; i < f.size(); ++i)
    {
        int &ans = f[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i])
                ans = max(ans, f[j] + 1);
        }
        printf("i=%d, a=%d, f=%d\n", i, a[i], f[i]);
    }
    cout << *max_element(f.begin(), f.end());
}