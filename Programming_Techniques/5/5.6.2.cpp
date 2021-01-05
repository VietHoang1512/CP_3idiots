//sol1 và sol 2
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    freopen("LIS.inp", "r", stdin);
    freopen("sol1.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        int pre = -2e9, L = 0;
        for (int j = i; j < a.size(); ++j)
        {
            if (a[j] > pre)
            {
                ++L;
                pre = a[j];
            }
        }
        ans = max(ans, L);
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    freopen("LIS.inp", "r", stdin);
    freopen("sol2.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> f(n);
    for (int i = 0; i < f.size(); ++i)
    {
        int &ans = f[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i])
                ans = max(ans, f[j] + 1);
        }
    }
    cout << *max_element(f.begin(), f.end());
}