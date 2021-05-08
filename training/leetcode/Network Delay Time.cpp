#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // cout << endl;
        vector<int> distance(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);
        distance[k] = 0;
        for (auto x : times)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        PQ.push({0, k});
        while (PQ.size())
        {
            // int w = PQ.top().first;

            int v = PQ.top().second;
            cout << v << endl;
            PQ.pop();
            for (auto x : adj[v])
            {
                if (distance[x.first] > distance[v] + x.second)
                {
                    distance[x.first] = distance[v] + x.second;
                    PQ.push({distance[x.first], x.first});
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = max(res, distance[i]);
            // cout << distance[i] << " ";
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }
};