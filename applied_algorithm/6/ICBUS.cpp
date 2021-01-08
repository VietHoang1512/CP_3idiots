#include <bits/stdc++.h>

using namespace std;

const unsigned int mx = 6000;

unsigned int N, K;
unsigned int C[mx], D[mx];
// vector<unsigned  int> adj[mx];
vector<pair<unsigned int, unsigned int>> weight[mx];

unsigned int u, v, w;
unsigned int distance_[mx][mx], cost = 0;
unsigned int dis[mx];

unsigned int dijkstra(unsigned int s, unsigned int t)
{
    
    for (unsigned int i = 1; i <= N; i++)
    {
        dis[i] = INT_MAX;
    }
    priority_queue<pair<unsigned int, unsigned int>, vector<pair<unsigned int, unsigned int>>, greater<pair<unsigned int, unsigned int>>> Q;
    Q.push(make_pair(0, s));
    dis[s] = 0;
    while (Q.size())
    {
        unsigned int u = Q.top().second;
        Q.pop();
        for (auto i : weight[u])
        {
            unsigned int v = i.first;
            unsigned int w = i.second;
            if (v == s)
                continue;
            if ((dis[v] > dis[u] + w))
            {
                dis[v] = dis[u] + w;
                Q.push(make_pair(dis[v], v));
            }
        }
    }
    return dis[t];
}

void bfs(unsigned int u)
{
    // cout << " -> " << u;
    queue<unsigned int> Q;
    Q.push(u);
    for (unsigned int i = 1; i <= N; i++)
    {
        distance_[u][i] = 0;
    }
    distance_[u][u] = 0;

    while (Q.size())
    {
        unsigned int s = Q.front();
        Q.pop();
        // cout << " pop " << s << " ";
        for (auto x : weight[s])
        {
            unsigned int v = x.first;
            if (u == v)
                continue;
            if (distance_[u][v] == 0)
            {
                distance_[u][v] = distance_[u][s] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    for (unsigned int i = 1; i <= N; i++)
    {
        cin >> C[i] >> D[i];
    }

    for (unsigned int i = 1; i <= K; i++)
    {
        cin >> u >> v;
        weight[u].push_back({v, 0});
        weight[v].push_back({u, 0});
    }

    for (unsigned int i = 1; i <= N; i++)
    {
        
        bfs(i);
        // cout << "\n***********************\n";
    }
    for (auto x : weight)
        x.clear();

    for (unsigned int i = 1; i <= N; i++)
    {
        for (unsigned int j = 1; j <= N; j++)
        {
            cout << distance_[i][j] << " ";
            if (distance_[i][j] <= D[i])
                weight[i].push_back({j, C[i]});
        }
        cout << endl;
    }

    cout << dijkstra(1, N);
    // cout << endl;
    // for (unsigned  int i = 1; i <= N; i++)
    // {
    //     cout << dis[i] << " ";
    // }
}