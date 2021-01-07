#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5;
int N, M, cnt = 0;
int u, v;
vector<int> adj[mx];
int visited[mx];

void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}