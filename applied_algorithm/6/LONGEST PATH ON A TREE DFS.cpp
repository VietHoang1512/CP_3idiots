#include <bits/stdc++.h>

using namespace std;

const int mx = 5e5;

int N;
int u, v, w;
vector<pair<int, int>> adj[mx];
int max_res = 0, res = 0, visited[mx];
int max_w, cnt;

void dfs(int u)
{
    cnt++;
    if (res + (N - cnt) * max_w < max_res)
    {
        cnt--;
        return;
    }
    // cout << "->" << u << " (cost " << res << ") " << endl;
    visited[u] = 1;

    for (auto v : adj[u])
    {
        if (!visited[v.first])
        {
            int tmp = res;
            res += v.second;
            max_res = max(res, max_res);
            dfs(v.first);
            // cout << "Back to " << u << endl;
            res = tmp;
        }
    }
    cnt--;
    visited[u] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    if (N == 1)
    {
        cout << 0;
        exit(0);
    }
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> u >> v >> w;
        max_w = max(w, max_w);
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         cout << weight[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // dfs(1);

    for (int i = 1; i <= N; i++)
    {

        if (adj[i].size() == 1)
        {
            memset(visited, 0, sizeof(visited));
            res = 0;
            cnt = 0;
            // cout << "Leaf " << i << endl;
            dfs(i);
        }
    }

    cout << max_res;
}