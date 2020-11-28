#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4;

int n, m;
int inp[mx], tmp, appear[mx];
vector<int> v;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> inp[i];
        appear[inp[i]] = 1;
    }
    if (n == m)
    {
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
        return 0;
    }

    for (int i = m - 1; i > -1; i--)
    {
        if (inp[i] < n)
        {
            for (int j = inp[i]; j <= n; j++)
            {
                if (!appear[j])
                {
                    inp[i] = j;
                    for (int i = 0; i < m; i++)
                    {
                        cout << inp[i] << " ";
                    }
                    return 0;
                }
            }
        }
    }

    // cout << tmp << "tmp\n";
    // for (int i = m - 1; i > -1; i--)
    // {
    //     if (inp[i] < n)
    //     {
    //         inp[i] = tmp;
    //         break;
    //     }
    // }
    // int idx = m - 1;
    // int tmp = inp[idx];
    // // vector<int> v;
    // v.push_back(tmp);
    // while (--idx)
    // {
    //     if (inp[idx] > tmp)
    //     {
    //         tmp = inp[idx];
    //         v.push_back(tmp);
    //     }
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     cout << inp[i] << " ";
    // }
}