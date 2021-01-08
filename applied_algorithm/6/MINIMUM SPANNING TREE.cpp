#include <bits/stdc++.h>

using namespace std;

const long long mx = 2e5;
long long N, M, u, v, w;
vector<pair<long long, pair<long long, long long>>> E;
long long p[mx];

bool cmp(pair<long long, pair<long long, long long>> x, pair<long long, pair<long long, long long>> y)
{
    return x.first < y.first;
}

long long find(long long x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(long long x, long long y)
{
    p[find(x)] = find(y);
}

int main()
{
    cin >> N >> M;

    for (long long i = 1; i <= N; i++)
    {
        p[i] = i;
    }
    for (long long i = 1; i <= M; i++)
    {
        cin >> u >> v >> w;
        E.push_back({w, {u, v}});
        // E.push_back({w, {v, u}});
    }

    sort(E.begin(), E.end(), cmp);
    long long res = 0, n_edge = 0;
    for (auto x : E)
    {
        if (n_edge == N - 1)
            break;
        long long u = x.second.first;
        long long v = x.second.second;
        u = find(u);
        v = find(v);
        if (u == v)
        {
            continue;
        }
        res += x.first;
        n_edge++;
        // cout << "Merged " << max(u, v) << " to " << min(u, v) << " cost " << x.first << endl;
        unite(min(u, v), max(u, v));
    }
    cout << res;
}
