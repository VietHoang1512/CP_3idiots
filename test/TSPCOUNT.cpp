#include <bits/stdc++.h>
using namespace std;

long long M, N, C[20][20], cmin = 1e5, visited[20], res = 0, cur_cost = 0, cur_pos = 1;

int Try(int k)
{
    if (((N + 2 - k) * cmin + cur_cost) > M)
        return 0;
    if (k == N + 1)
    {
        res += (!((cur_cost + C[cur_pos][1]) > M));
        return 0;
    }

    for (int i = 1; i <= N; i++)
    {
        if ((!visited[i]) && (i - cur_pos))
        {
            long long tmp_cost = cur_cost;
            long long tmp_pos = cur_pos;
            cur_cost += C[cur_pos][i];
            cur_pos = i;
            visited[i] = 1;
            Try(k + 1);
            visited[i] = 0;
            cur_cost = tmp_cost;
            cur_pos = tmp_pos;
        }
    }
    return 0;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> C[i][j];
            if (i - j)
                cmin = min(cmin, C[i][j]);
        }
    }
    visited[1] = 1;
    cur_pos = 1;
    Try(2);
    cout << res;
}
