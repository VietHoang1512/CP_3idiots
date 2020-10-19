#include <bits/stdc++.h>

using namespace std;
// const int
int A[15], C[35];
int m, n, k;
int Assign[15][35], Assigned[15][35], conflict[35][35];
// vector<pair<int, int>> conflict;
int mx[15], res = -1;

int x, y;
bool is_conflict, has_teacher;
void Try(int k)
{
    cout << "Try " << k << " result " << res << endl;
    if (k == n)
    {
        for (int i = 1; i <= m; i++)
        {
            res = max(res, mx[i]);
        }
        cout << "DONE" << endl;
        return;
    }
    // has_teacher = false;
    for (int i = 1; i <= m; i++)
    {
        cout << "Checking teacher " << i << endl;
        if (Assign[i][k] && (!Assigned[i][k]))
        {
            is_conflict = false;
            for (int j = 1; j <= n; j++)
            {
                if (Assigned[i][j] && conflict[j][k])
                    is_conflict = true;
            }
            if (!is_conflict)
            {
                has_teacher = true;
                Assigned[i][k] = 1;
                cout << "Assigned " << k << " to " << i << endl;
                mx[i]++;
                Try(k + 1);
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
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << Assign[i][j] << " ";
        }
        cout << endl;
    }
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        conflict[x][y] = 1;
        conflict[y][x] = 1;
    }
    Try(1);
    cout << res;
    // cout << "\nDONE";
}