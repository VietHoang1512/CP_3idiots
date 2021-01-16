#include <bits/stdc++.h>

using namespace std;
const int mx = 100;
int n, Q;
int A[mx], D[mx][mx], visited[mx];
int cur, cur_cost, best_cost = INT_MAX, cur_pos, min_dis = INT_MAX;
int route[mx], best_num;
int best_route[mx];

void TRY(int num, int k)
{
    // cout << "NUM: " << num << ", K: " << k << endl;
    // cout << "CURRENT COST: " << cur_cost << endl;
    route[num] = k;
    if (cur >= Q)
    {
        if (best_cost > cur_cost + D[cur_pos][0])
        {

            best_cost = cur_cost + D[cur_pos][0];
            best_num = num;
            // cout << "BEST COST: " << best_cost << endl
            //  << "ROUTE\n";
            for (int i = 0; i <= num; i++)
            {
                best_route[i] = route[i];
                // cout << best_route[i] << " ";
            }
            // cout << endl;
            cout << best_cost << endl;
            cout << best_num << endl;
            for (int i = 1; i <= best_num; i++)
            {
                cout << best_route[i] << " ";
            }
            exit(0);
        }

        return;
    }
    if (cur_cost + min_dis > best_cost)
        return;
    cur_pos = k;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int tmp = D[cur_pos][i];
            cur_cost += tmp;
            visited[i] = 1;
            cur += A[i];
            cur_pos = i;
            TRY(num + 1, i);
            cur -= A[i];
            cur_cost -= tmp;
            visited[i] = 0;
            cur_pos = k;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("D:/VH/CP_3idiots/final_exam/4/cpp/input/input_5.txt", "r", stdin);
    freopen("D:/VH/CP_3idiots/final_exam/4/cpp/submission/output_5.txt", "w", stdout);
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> D[i][j];
            if (i != j)
            {
                min_dis = min(min_dis, D[i][j]);
            }
        }
    }
    visited[0] = 1;
    TRY(0, 0);

    // cout << "MIN " << min_dis;
}
