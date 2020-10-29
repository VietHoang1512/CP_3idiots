#include <bits/stdc++.h>

using namespace std;
// const int
int A[12], C[32];
int m, n, k;
int Assign[12][32], Assigned[12][32];
vector<int> conflict[32];
int mx[12], res = INT_MAX, mx_tmp = 0;

int x, y;
bool is_conflict;
void Try(int k)
{
    // cout << "Try " << k << " result " << res << endl;
    if (k == n + 1)
    {
        // int tmp = 0;
        // for (int i = 1; i <= m; i++)
        // {
        //     tmp = max(tmp, mx[i]);
        // }
        res = min(res, mx_tmp);
        // cout << "DONE" << endl;
        return;
    }
    // has_teacher = false;
    for (int i = 1; i <= m; i++)
    {

        // cout << "Checking teacher " << i << endl;
        if (Assign[i][k] && (!Assigned[i][k]))
        {
            is_conflict = false;

            for (int j : conflict[k])
            {
                // if (j > k)
                // {
                //     break;
                // }
                if (Assigned[i][j])
                {
                    is_conflict = true;
                    break;
                }
            }

            // for (int j = 1; j <= k-1; j++)
            // {
            //     if (Assigned[i][j] && conflict[j][k])
            //     {
            //         is_conflict = true;
            //         break;
            //     }
            // }

            if (!is_conflict)
            {
                // has_teacher = true;
                Assigned[i][k] = 1;
                // cout << "Assigned " << k << " to " << i << endl;
                mx[i]++;
                int tmp = mx_tmp;
                mx_tmp = max(mx_tmp, mx[i]);
                if (mx_tmp < res)
                    Try(k + 1);
                mx_tmp = tmp;
                mx[i]--;

                Assigned[i][k] = 0;
            }
        }
    }
    // if (!has_teacher)
    //     return;
}

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> x;
            Assign[i][x] = 1;
        }
    }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << Assign[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        conflict[x].push_back(y);
        conflict[y].push_back(x);
    }
    Try(1);
    // if (res == 1e6)
    // {
    //     res = -1;
    // }
    cout << res;
    // cout << "\nDONE";
}