#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5 + 10;

int N;
int u, v;
vector<int> adj[mx];
int parent[mx], visited[mx];

void dfs(int u)
{
    visited[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
        }
    }

    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << " ";
    }
}