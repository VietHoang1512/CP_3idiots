#include <bits/stdc++.h>
using namespace std;

int N, M, c[20], A[20][20];
int assigned[20], max_load[20];
int res = INT_MAX, max_tmp = 0;

void Try(int k)
{
    if (k == N + 1)
    {
        res = min(res, max_tmp);
        return;
    }

    for (int i = 1; i <= M; i++)
    {

        int is_conflict = 0;

        for (int j = 1; j < k; j++)
        {
            if ((assigned[j] > i) && (A[j][k]))
            {
                is_conflict = 1;
                break;
            }
            if ((assigned[j] < i) && (A[k][j]))
            {
                is_conflict = 1;
                break;
            }
        }

        if (!is_conflict)
        {
            max_load[i] += c[k];
            int tmp = max_tmp;
            max_tmp = max(max_tmp, max_load[i]);
            assigned[k] = i;
            if (max_tmp < res)
            {
                Try(k + 1);
            }
            max_load[i] -= c[k];
            max_tmp = tmp;
            assigned[k] = 0;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
        }
    }

    Try(1);
    cout << res;
}
