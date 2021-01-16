#include <bits/stdc++.h>

using namespace std;

const long long mx = 5005;


const int N = 5002;
 
int n, m;
vector<vector<pair<int, long long>>> adj(N);
vector<long long> dist(N, LLONG_MAX), path(N, 0ll);
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int k, x, y;
    long long z;
    for (int i = 1; i <= m; i++)
    {
        cin >> k >> x >> y >> z;
        if (k == 1)
        {
            adj[x].push_back(make_pair(y, z));
        }
        else if (k == 2)
        {
            adj[x].push_back(make_pair(y, z));
            adj[y].push_back(make_pair(x, z));
        }
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    dist[1] = 0;
    path[1] = 1;
    PQ.push(make_pair(0ll, 1));
    int u, v;
    long long w;
    while (!PQ.empty())
    {
        u = PQ.top().second;
        z = PQ.top().first;
        PQ.pop();
        if (dist[u] < z)
        {
            continue;
        }
        for (auto e : adj[u])
        {
            v = e.first;
            w = e.second;
            if (dist[v] > (dist[u] + w))
            {
                path[v] = path[u];
                dist[v] = dist[u] + w;
                PQ.push(make_pair(dist[v], v));
            }
            else if (dist[v] == (dist[u] + w))
            {
                path[v] += path[u];
            }
        }
    }
 
    cout << dist[n] << " " << path[n];
    return 0;
}



// long long N, M;
// long long K, U, V, L;
// long long adj[mx][mx];
// long long dis[mx];
// long long visited[mx];
// long long cnt[mx];
// long long cur_cost, best_cost, res_cnt;

// long long dijkstra(long long s, long long t)
// {
//     for (long long i = 1; i <= N; i++)
//     {
//         dis[i] = LONG_LONG_MAX;
//     }
//     priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> Q;
//     Q.push(make_pair(0, s));
//     dis[s] = 0;
//     while (Q.size())
//     {
//         long long u = Q.top().second;
//         long long w = Q.top().first;
//         Q.pop();
//         if (dis[u] < w)
//         {
//             continue;
//         }
//         for (int v = 1; v <= N; v++)
//         {
//             long long w = adj[u][v];
//             if (w && (u - v))
//             {
//                 if (dis[v] > dis[u] + w)
//                 {
//                     cnt[v] = cnt[u];
//                     dis[v] = dis[u] + w;
//                     Q.push(make_pair(dis[v], v));
//                 }
//                 else if (dis[v] == (dis[u] + w))
//                 {
//                     cnt[v] += cnt[u];
//                 }
//             }
//         }
//     }
//     return dis[t];
// }

// void TRY(long long u, long long t)
// {
//     // cout << "\nVisit " << u;
//     if (u == t)
//     {
//         if (cur_cost == best_cost)
//         {
//             res_cnt++;
//         }
//         return;
//     }
//     visited[u] = 1;
//     // cout << "\nNeighbors:\n";
//     for (int v = 1; v <= N; v++)
//     {
//         long long w = adj[u][v];
//         if (w && (!visited[v]))
//         {
//             visited[v] = 1;
//             cur_cost += w;
//             TRY(v, t);
//             cur_cost -= w;
//             visited[v] = 0;
//             // cout << "\nBack to " << u;
//         }
//     }
// }

// int main()
// {
//     cin >> N >> M;
//     for (long long i = 1; i <= M; i++)
//     {
//         cin >> K >> U >> V >> L;
//         adj[U][V] = L;
//         if (K - 1)
//             adj[V][U] = L;
//     }

//     cnt[1] = 1;
//     best_cost = dijkstra(1, N);
//     cout << best_cost << " " << cnt[N];

//     // memset(dis, 0, sizeof(dis));
//     // TRY(1, N);
//     // cout << best_cost << " " << res_cnt;
//     // cnt[1] = 1;
//     // for (int i = 1; i <= N; i++)
//     // {
//     //     cout << cnt[i] << " ";
//     // }
//     // cout << endl;
//     // cout << best_cost << " " << cnt[N];
// }