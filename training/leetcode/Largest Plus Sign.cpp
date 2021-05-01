#include <bits/stdc++.h>
using namespace std;

int main()
{
}


const int mx = 505;
class Solution
{
public:
    int left[mx][mx], right[mx][mx], up[mx][mx], down[mx][mx], grid[mx][mx];
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
    {
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                grid[i][j] = 1;
            }
        }

        for (auto x : mines)
        {
            grid[x[0]][x[1]] = 0;
        }

        for (int i = 0; i < N; i++)
        {
            int l = 0, r = 0, u = 0, d = 0;
            for (int j = 0; j < N; j++)
            {
                if (!grid[i][j])
                    l = 0;
                if (!grid[i][N - 1 - j])
                    r = 0;
                if (!grid[j][i])
                    u = 0;
                if (!grid[N - 1 - j][i])
                    d = 0;

                l += grid[i][j];
                left[i][j] = l;

                r += grid[i][N - 1 - j];
                right[i][N - 1 - j] = r;

                u += grid[j][i];
                up[j][i] = u;

                d += grid[N - 1 - j][i];
                down[N - 1 - j][i] = d;

                res = max(res, grid[i][j]);
            }
        }
//         cout << "GRID\n";
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << grid[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << "LEFT\n";
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << left[i][j] << " ";
//             }
//             cout << endl;
//         }

//         cout << "RIGHT\n";
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << right[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << "UP\n";
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << up[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << "DOWN\n";
//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << down[i][j] << " ";
//             }
//             cout << endl;
//         }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int k = min(right[i][j], min(up[i][j], min(down[i][j], left[i][j])));
                // cout << k << " ";
                if (grid[i][j])
                    res = max(res, k);
            }
        }
        return res;
    }
};