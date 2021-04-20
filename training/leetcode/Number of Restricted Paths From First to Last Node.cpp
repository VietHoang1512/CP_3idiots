#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 20005;

class Solution
{
public:
    int res = 0;
    vector<pair<int, int>> adj[mx];
    vector<int> new_adj[mx];
    int distance[mx];
    int visited[mx];
    int dp[mx];
    int mod = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        memset(visited, 0, sizeof(visited));
        memset(dp, 0, sizeof(dp));
        for (auto x : edges)
        {
            adj[x[1]].push_back(make_pair(x[0], x[2]));
            adj[x[0]].push_back(make_pair(x[1], x[2]));
        }

        for (int i = 1; i < n; i++)
        {
            distance[i] = INT_MAX;
        }

        distance[n] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

        PQ.push(make_pair(n, 0));
        // PQ.pop();

        while (PQ.size())
        {
            int u = PQ.top().first;
            // int w = PQ.top().first;
            PQ.pop();
            for (auto x : adj[u])
            {
                int v = x.first;
                int w = x.second;
                if (distance[v] > distance[u] + w)
                {
                    // cout << "Update distance to " << v << " from " << distance[v] << " to " << (distance[u] + w) << endl;
                    distance[v] = distance[u] + w;
                    PQ.push(make_pair(v, distance[v]));
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << distance[i] << " ";
        }
        cout << endl;
        visited[n] = 1;
        // TRY(n);
        for (auto x : edges)
        {
            if(distance[x[0]]<distance[x[1]])
                new_adj[x[1]].push_back(x[0]);
            else if (distance[x[0]]>distance[x[1]])
                new_adj[x[0]].push_back(x[1]);
        }
        
        for(int i=1; i<=n; i++){

        }        
        cout << endl;
        return res;
    }
    void TRY(int t)
    {
        if (t == 1)
        {
            res++;
            return;
        }

        for (auto x : adj[t])
        {
            if ((!visited[x.first]) && (distance[t] < distance[x.first]))
            {
                visited[x.first] = 1;
                TRY(x.first);
                visited[x.first] = 0;
            }
        }
    }
};