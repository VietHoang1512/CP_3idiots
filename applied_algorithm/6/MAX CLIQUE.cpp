#include <bits/stdc++.h>

using namespace std;

const int mx = 15;

int N, M;
int u, v;
int adj[mx][mx];
int res = 1, visited[mx];
vector<int> all_vertices;

int is_clique()
{
    int k = all_vertices.size();
    if (k == 1)
        return k;
    for (int i = 0; i < k; i++)
    {
        for (int j = i+1; j < k; j++)
        {
            int u = all_vertices[i], v = all_vertices[j];
            if (!adj[u][v])
                return 0;
        }
    }
    return k;
}

void TRY(int u)
{

    if (u == N + 1)
        return;

    // cout << "Add " << u << " to graph\n";
    all_vertices.push_back(u);
    // cout << "ALL: ";
    // for (int x : all_vertices)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << "Max clique " << is_clique() << endl;
    res = max(res, is_clique());

    TRY(u + 1);

    // cout << "Remove " << u << " out of graph\n";
    all_vertices.pop_back();
    TRY(u + 1);
}

int main()
{
    cin >> N>>M;

    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    TRY(1);
    cout << res;
}