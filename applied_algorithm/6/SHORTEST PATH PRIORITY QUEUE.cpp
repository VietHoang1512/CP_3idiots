#include <bits/stdc++.h>

using namespace std;

const long long mx = 5e5;

long long N, M;
long long u, v, w, s, t;

vector<pair<long long, long long>> adj[mx];
queue<long long> Q;
long long distance_[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (long long i = 1; i <= M; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    cin >> s >> t;

    Q.push(s);
    memset(distance_, -1, sizeof(distance_));
    distance_[s] = 0;
    while (!Q.empty())
    {
        long long u = Q.front();
        // cout << " -> " << u << endl;
        Q.pop();
        for (auto v : adj[u])
        {
            long long tmp = distance_[u] + v.second;
            if (distance_[v.first] == -1)
            {
                Q.push(v.first);
                distance_[v.first] = tmp;
            }
            else
            {
                distance_[v.first] = min(tmp, distance_[v.first]);
            }
        }
    }
    // for (long long i = 1; i <= N; i++)
    // {
    //     cout << distance_[i] << " ";
    // }
    cout << distance_[t];
}