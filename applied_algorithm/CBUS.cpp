#include <bits/stdc++.h>
using namespace std;
const int mx = 500;

int n, k;
int cost[mx][mx], visited[mx];
int n_psg = 0, cur_cost = 0, min_cost = 1e6, n_trans, res = 1e6;

void Try(int cur_pos)
{
    cout << "On position " << cur_pos << endl;
    if (n_trans == 1)
    {
        res = min(res, cur_cost + cost[cur_pos][0]);
        cout << "Enough with " << cur_cost + cost[cur_pos][0] << endl;
        return;
    }

    if (n_psg < k)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cout << "Got " << i << endl;
                visited[i] = 1;
                n_psg++;
                n_trans--;
                cur_cost += cost[cur_pos][i];

                // cur_pos = i;
                if (cur_cost + n_trans * min_cost < res)
                    Try(i);

                cout << "Back 1 " << endl;
                visited[i] = 0;
                n_psg--;
                n_trans++;
                cur_cost -= cost[cur_pos][i];
            }
        }
    }

    // if (n_psg > 0)
    // {
    for (int i = n + 1; i <= 2 * n; i++)
    {

        if ((!visited[i]) && (visited[i - n]))
        {
            cout << "Released " << i - n << " on " << i << endl;
            visited[i] = 1;
            n_psg--;
            n_trans--;
            cur_cost += cost[cur_pos][i];

            // cur_pos = i;
            if (cur_cost + n_trans * min_cost < res)
                Try(i);

            cout << "Back 2 " << endl;
            visited[i] = 0;
            n_psg++;
            n_trans++;
            cur_cost -= cost[cur_pos][i];
        }
        // }
    }
}

int main()

{
    memset(visited, 0, sizeof(visited));

    cin >> n >> k;
    n_trans = 2 * n;

    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cin >> cost[i][j];
            min_cost = min(min_cost, cost[i][j]);
        }
    }
    Try(0);
    cout << res;
    cout << "\nDONE";
}