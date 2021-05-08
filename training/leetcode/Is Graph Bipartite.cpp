#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 105;

class Solution
{
public:
    vector<int> adj[mx];
    int color[mx];
    bool res = true;
    bool isBipartite(vector<vector<int>> &graph)
    {
        cout << endl;
        memset(color, 0, sizeof(color));
        int n = graph.size();
        // for (int i = 0; i < n; i++)
        // {
        //     for (auto x : graph[i])
        //     {
        //         adj[i].push_back(x);
        //     }
        // }
        for (int i = 0; i < n; i++)
        {

            cout << "->";
            DFS(graph, i);
        }
        return res;
    }
    void DFS(vector<vector<int>> &graph, int v)
    {
        cout << "On vertice " << v << endl;
        if (!color[v])
            color[v] = 1;
        // else
        //     return;

        for (auto x : graph[v])
        {
            if (!color[x])
            {
                color[x] = -color[v];
                DFS(graph, x);
            }

            else if (color[x] == color[v])
            {
                res = false;
                cout << x << "-" << v << " ";
                return;
            }
        }
    }
};