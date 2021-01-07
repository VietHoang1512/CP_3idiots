#include <bits/stdc++.h>

using namespace std;

const int mx = 2e4;

int n_test;
int N, M;
int side[mx];
vector<int> adj[mx];
int u, v;
bool is_bipartie = true;

void dfs(int u)
{

    // visited[u] = 1;

    if (!side[u])
        side[u] = -1;
    for (int v : adj[u])
    {

        if (side[u] * side[v] > 0)
        {
            is_bipartie = false;
            // cout << "Revisited " << v << " at odd index " << endl;
        }
        else if (!side[v])

        {
            side[v] = -side[u];
            // cout << "Set side of " << v << " to " << side[v] << endl;
            dfs(v);
        }
        // else
        // {
        //     cout << "NGU\n";
        // }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n_test;
    for (int t = 1; t <= n_test; t++)
    {
        cout << "Scenario #" << t << ":\n";
        is_bipartie = true;
        for (auto &v : adj)
        {
            v.clear();
        }
        memset(side, 0, sizeof(side));

        cin >> N >> M;
        for (int i = 1; i <= M; i++)
        {
            cin >> u >> v;
            // if (u == v)
            //     is_bipartie = false;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= N; i++)
        {
            dfs(i);
        }
        // for (int i = 1; i <= N; i++)
        // {
        //     cout << " -> " << i << " (" << side[i] << ")" << endl;
        // }
        if (is_bipartie)
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
    }
}