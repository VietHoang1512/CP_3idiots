#include <bits/stdc++.h>

using namespace std;

const int mx = 5e5;

int N, M;
int u, v, w, s, t;
vector<pair<int, int>> adj[mx];
int min_res = INT_MAX, res = 0, visited[mx];
int min_w = INT_MAX, cnt;

void dfs(int u)
{
    cnt++;

    if (res > min_res)
    {
        return;
    }
    // cout << "->" << u << " (cost " << res << ") " << endl;
    visited[u] = 1;
    if (u == t)
    {
        visited[u] = 0;
        return;
    }

    for (auto v : adj[u])
    {
        if (!visited[v.first])
        {
            int tmp = res;
            res += v.second;
            if (v.first == t)
            {
                // cout << "Found " << t << " (cost " << res << ") " << endl;
                min_res = min(res, min_res);
            }

            dfs(v.first);
            // cout << "Back to " << u << endl;
            res = tmp;
        }
    }
    cnt--;
    visited[u] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    if (N == 1)
    {
        cout << 0;
        exit(0);
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v >> w;
        min_w = min(w, min_w);
        adj[u].push_back(make_pair(v, w));
    }
    cin >> s >> t;

    dfs(s);

    cout << min_res;
}

// #include <bits/stdc++.h>

// using namespace std;

// const int mx = 1e5;

// int N, M;
// int u, v, w, s, t;
// vector<int> adj[mx];
// int min_res = INT_MAX, res, visited[mx];
// int weight[mx][mx];

// void dfs(int u)
// {
//     // cout << "->" << u << " (cost " << res << ") " << endl;
//     visited[u] = 1;
//     if (u == t){
//         visited[u] = 0;
//         return;
//     }

//     for (auto v : adj[u])
//     {
//         if (!visited[v])
//         {
//             res += weight[u][v];
//             if (v == t)
//             {
//                 // cout << "Found " << t << " (cost " << res << ") " << endl;
//                 min_res = min(res, min_res);
//             }

//             dfs(v);
//             // cout << "Back to " << u << endl;
//             res -= weight[u][v];
//         }
//     }
//     visited[u] = 0;
// }

// int main()
// {
//     cin >> N >> M;

//     for (int i = 1; i <= M; i++)
//     {
//         cin >> u >> v >> w;
//         weight[u][v] = w;
//         // weight[v][u] = w;
//         adj[u].push_back(v);
//         // adj[v].push_back(u);
//         // cout << "From " << u << " to " << v << " cost " << w << endl;
//     }
//     // cout << "********************\n";
//     cin >> s >> t;

//     // for (int i = 1; i <= N; i++)
//     // {
//     //     for (int j = 1; j <= N; j++)
//     //     {
//     //         cout << weight[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // dfs(1);

//     res = 0;
//     dfs(s);

//     cout << min_res;
// }