#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    float res = 0;
    int encountered = 0;
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        // cout << "\n\n";
        target--;
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for (auto e : edges)
        {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }

        visited[0] = 1;
        DFS(0, adj, visited, target, t, 1.0, -1);
        if (encountered)
            return res;
        return 0.0;
    }
    void DFS(int root, vector<vector<int>> &adj, vector<int> &visited, int target, int t, float prob, int step)
    {
        step++;
        if (step > t)
            return;
        // cout << "Step " << step << " on vertice " << root << " prob " << prob << endl;
        if ((step == t) && (root == target))
        {
            res = prob;
            encountered = 1;
            return;
        }

        int cnt = 0;
        for (auto x : adj[root])
        {
            if (!visited[x])
            {
                cnt++;
            }
        }
        if ((cnt == 0) && (root == target))
        {
            res = prob;
            encountered = 1;
            return;
        }
        prob *= (1.0 / cnt);
        for (auto x : adj[root])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                DFS(x, adj, visited, target, t, prob, step);
                visited[x] = 0;
            }
        }
    }
};