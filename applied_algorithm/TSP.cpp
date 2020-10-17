#include <bits/stdc++.h>
using namespace std;

const int mx = 21;
int n, m, u, v;

int cost[mx][mx];
int visited[mx], vertices[mx];
int res = 1e8, cmin = 1e8;
int cur_cost = 0, c;

void Try(int k)
{
    if (res <= cur_cost + cmin * (n - k + 1))
        return;
    for (int i = 2; i <= n; i++)
    {
        if ((!visited[i]) && (cost[vertices[k - 1]][i] > 0))
        {
            vertices[k] = i;
            visited[vertices[k]] = 1;
            cur_cost += cost[vertices[k - 1]][i];
            
            if ((k == n) && (cost[vertices[k]][1] >= 0))
            {
                res = min(res, cur_cost + cost[vertices[k]][1]);
            }
            else
                Try(k + 1);

            visited[vertices[k]] = 0;
            cur_cost -= cost[vertices[k - 1]][i];
        }
    }
}

int main()
{
    memset(cost, -1, sizeof(cost));
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;

    while (m--)
    {
        cin >> u >> v >> c;
        cost[u][v] = c;
        cmin = min(cmin, c);
    }

    visited[1] = 1;
    vertices[1] = 1;
    Try(2);
    cout << res;
}

// int E[20][20];
// int m, n, i, j, c;
// int vertices[20], n_vertices = 0, distances[20];
// bool isVertices[20];
// // int res = int_MAX;

// bool isCandidate(int k, int c)
// {
//     return ((!isVertices[c]) && (E[k][vertices[n_vertices - 1]] > -1));
// }

// void Try(int k, int res)
// {
//     if (k >= n)
//     {
//         res = min(res, distances[n - 1]);
//     }
//     else
//     {
//         for (int l = 0; l < n; l++)
//         {
//             if ((!isCandidate(l))&&(distances[n_vertices]<res))
//             {
//                 vertices[n_vertices] = l;
//                 distances[n_vertices] = distances[n_vertices - 1] + E[vertices[n_vertices - 1]][l];
//                 n_vertices++;
//                 k++;
//                 Try(k, res);
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     memset(E, -1, sizeof(E));

//     for (int t = 0; t < m; t++)
//     {
//         cin >> i >> j >> E[i][j];
//         E[j][i] = E[i][j];
//     }

//     cout << "\nDONE";
// }
