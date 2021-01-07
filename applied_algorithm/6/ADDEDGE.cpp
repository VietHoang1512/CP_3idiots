#include <bits/stdc++.h>

using namespace std;

const int mx = 2e5;
int n, m;
int u, v;
vector<int> adj[mx];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << 
}