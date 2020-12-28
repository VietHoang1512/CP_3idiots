#include <bits/stdc++.h>

using namespace std;
int N, M, K;
int C[40][40], cmin = 1e6, cur_cost;
int assigned[40];
int res = INT_MAX;
int cmin_by_task[40];

void Try(int k)
{
    // cout << "TRY " << k << endl;
    if (((N + 1 - k) * cmin + cur_cost) > res)
        return;
    if (k == N + 1)
    {
        res = min(res, cur_cost);
        // cout << cur_cost << endl;
        return;
    }
    for (int i = 1; i <= M; i++)
    {
        if (assigned[i] < K)
        {
            int tmp = cur_cost;
            assigned[i]++;
            cur_cost += C[i][k];
            Try(k + 1);
            assigned[i]--;
            cur_cost = tmp;
        }
    }
}

int main()
{
    // memset(cmin_by_task, -1, sizeof(cmin_by_task));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        cmin_by_task[i] = INT_MAX;
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> C[i][j];
            cmin = min(cmin, C[i][j]);
        }
    }
    // for (int i = N; i > 0; i--)
    // {
    //     // cout << cmin_by_task[i] << endl;
    //     if (i < N)
    //         cmin_by_task[i] = cmin_by_task[i + 1];
    //     // cout << cmin_by_task[i] << endl;
    //     for (int j = 1; j <= M; j++)
    //     {
    //         cmin_by_task[i] = min(cmin_by_task[i], C[j][i]);
    //     }
    // }
    // for (int j = 1; j <= N; j++)
    // {
    //     cout << cmin_by_task[j] << " ";
    // }

    Try(1);
    cout << res;
}