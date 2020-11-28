#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4;

int n;
int inp[mx], tmp;
vector<int> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }

    int idx = n - 1;
    tmp = inp[idx];
    v.push_back(tmp);

    while (--idx > -1)
    {
        // cout << idx << " ";
        if (inp[idx] > tmp)
        {
            tmp = inp[idx];
            v.push_back(tmp);
        }
        else
        {
            break;
        }
        // idx--;
    }
    // cout << "\nresult\n";
    if (idx == -1)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < idx; i++)
    {
        cout << inp[i] << " ";
    }
    int start = n - 1;
    // cout << inp[n - 1];
    for (int i : v)
    {
        // cout << i << " ";
        if (i > inp[idx])
            start = min(start, i);
    }
    v.push_back(inp[idx]);
    sort(v.begin(), v.end());
    // cout << " start " << start << " ";
    cout << start << " ";
    // cout << " vector ";
    for (int i : v)
    {
        // cout << i << " ";
        if (i == start)
            continue;
        cout << i << " ";
    }
}