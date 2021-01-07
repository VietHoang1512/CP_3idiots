#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5;
int N, M;
int u, v;
vector<int> adj[mx];
int side[mx];
// int visited[mx];
// int id, order[mx];

// void dfs(int u)
// {
//     id++;

//     order[u] = id;
//     visited[u] = 1;
//     // cout << " -> " << u << " (" << id << ") ";
//     for (int v : adj[u])
//     {
//         if (visited[v] && (!((id - order[v]) % 2)))
//         {
//             // cout << " -> " << v << " (" << id + 1 << ")";
//             // cout << "\nVisited " << v << " at " << order[v] << endl;
//             cout << 0;
//             exit(0);
//         }
//     }
//     for (int v : adj[u])
//     {
//         if (!visited[v])
//         {
//             dfs(v);
//         }
//     }
// }

void dfs(int u)
{

    // visited[u] = 1;
    if (!side[u])
        side[u] = -1;
    for (int v : adj[u])
    {
        if (side[u] * side[v] > 0)
        {
            cout << 0;
            exit(0);
        }
        else if (!side[v])

        {
            side[v] = -side[u];
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

        dfs(i);
    }

    // cout << endl;
    cout << 1;
}