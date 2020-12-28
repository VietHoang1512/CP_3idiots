#include <bits/stdc++.h>

using namespace std;

const int mx = 200;

int t, n;
int grid[mx][mx];
string s;
int x_1, x_2, y_1, y_2;
vector<pair<int, int>> v;
int main()
{
    cin >> t;
    while (t--)
    {
        // cout << "test " << t << endl;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            if (i == 1)
            {

                for (int j = 2; j <= n; j++)
                {
                    grid[1][j] = s[j - 1] - '0';
                }
            }
            if (i == n)
            {
                for (int j = 1; j <= n - 1; j++)
                {
                    grid[n][j] = s[j - 1] - '0';
                }
            }
            else
            {
                for (int j = 1; j <= n; j++)
                {
                    grid[i][j] = s[j - 1] - '0';
                }
            }
        }
        // grid[1][1] = -1;
        // grid[n][n] = -1;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        x_1 = grid[1][2];
        x_2 = grid[2][1];
        y_1 = grid[n - 1][n];
        y_2 = grid[n][n - 1];
        v.clear();

        if (x_1 == x_2)
        {
            if (y_1 != y_2)
            {
                if (y_1 == x_1)
                {
                    v.push_back(pair<int, int>(n - 1, n));
                }
                else
                {
                    v.push_back(pair<int, int>(n, n - 1));
                }
            }
            else
            {
                if (y_1 == x_1)
                {
                    v.push_back(pair<int, int>(n - 1, n));
                    v.push_back(pair<int, int>(n, n - 1));
                }
            }
        }
        else
        {
            if (y_1 == y_2)
            {
                if (x_1 == y_1)
                {

                    v.push_back(pair<int, int>(1, 2));
                }
                else
                {
                    v.push_back(pair<int, int>(2, 1));
                }
            }
            else
            {
                v.push_back(pair<int, int>(1, 2));

                if (y_1 == x_2)
                {
                    v.push_back(pair<int, int>(n - 1, n));
                }
                else
                {
                    v.push_back(pair<int, int>(n, n - 1));
                }
            }
        }
        cout << v.size() << endl;
        if(v.size())
            {
                for (auto x : v)
                {
                    cout << x.first << " " << x.second << endl;
                }
            }
    }
}