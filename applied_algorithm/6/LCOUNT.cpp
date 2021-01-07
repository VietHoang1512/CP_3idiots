#include <bits/stdc++.h>

using namespace std;

const int mx = 1e6 ;

int N;
int u, v;
vector<int> adj[mx];
int cnt = 0, visited[mx];

void dfs(int u)
{
    if (adj[u].size() == 1)
    {
        cnt++;
    }

    visited[u] = 1;

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

    for (int i = 1; i <= N-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs(1);
    for (int i = 2; i <= N; i++)
    {
        if (adj[i].size() == 1)
        {
            // cout << "Leaf " << i << endl;
            cnt++;
        }
    }

    cout << cnt;
}