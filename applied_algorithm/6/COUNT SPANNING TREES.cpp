#include <bits/stdc++.h>

using namespace std;

const int mx = 100;

int N, M;

int res = 0;
vector<pair<int, int>> all_edges;
vector<pair<int, int>> cur_edges;

int appear[mx];

int is_spaning()
{
    int len = cur_edges.size();
    if (len != N - 1)
        return 0;

    memset(appear, 0, sizeof(appear));
    for (auto x : cur_edges)
    {
        int u = x.first, v = x.second;
        appear[u] = appear[v] = 1;
    }
    int tmp = 1;
    for (int i = 1; i <= N; i++)
        tmp *= appear[i];
    return tmp;
}

void TRY(int k)
{
    // cout << "Trying on " << k << endl;
    if (k == M)
        return;
    int len = cur_edges.size();

    // if (len < N - 1)
    // {
    // cout << "Add edge no " << k << " to graph\n";

    cur_edges.push_back(all_edges[k]);
    res += is_spaning();
    TRY(k + 1);
    // cout << "Remove edge no " << k << " out of graph\n";
    cur_edges.pop_back();
    TRY(k + 1);

    // }
}

int main()
{

    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        all_edges.push_back({u, v});
    }

    TRY(0);
    cout << res;
}