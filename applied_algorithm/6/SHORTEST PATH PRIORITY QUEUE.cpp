#include <bits/stdc++.h>

using namespace std;

const int mx = 5e5;

int N, M;
int u, v, w, s, t;
vector<pair<int, int>> adj[mx];
int res = 0, dis[mx];

int dijkstra(int s, int t)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, s));
    dis[s] = 0;
    while (Q.size())
    {
        int u = Q.top().second;
        Q.pop();
        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                Q.push(make_pair(dis[v], v));
            }
        }
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << dis[i] << " ";
    // }
    cout << endl;
    return dis[t];
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
        adj[u].push_back(make_pair(v, w));
    }
    cin >> s >> t;
    // memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= N; i++)
    {
        dis[i] = INT_MAX;
    }
    cout << dijkstra(s, t);
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