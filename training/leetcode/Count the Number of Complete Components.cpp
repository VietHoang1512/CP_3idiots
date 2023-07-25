#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        // cout << "\n\n";
        vector<vector<int>> adjacencyList(n);
        map<int, map<int, int>> adjacencyMap;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
            adjacencyMap[u][v] = 1;
            adjacencyMap[v][u] = 1;
        }

        int count = 0;
        vector<int> visited(n, 0);

        for (int v = 0; v < n; ++v)
        {
            if (!visited[v])
            {
                ++count;

                dfs(adjacencyList, visited, v, count);
            }
        }
        map<int, vector<int>> m;
        int res=0;
        for (int i = 0; i < n; i++)
        {
            // cout << i << " "<< visited[i] << endl;
            m[visited[i]].push_back(i);
        }
        for (auto p : m)
        {
            int is_complete = 1;
            for (auto x : p.second)
            {
                for (auto y : p.second)
                {
                    if (x != y)
                        if (!adjacencyMap[x][y]) is_complete=0;
                }
            }
            res+= is_complete;
        }
        return res;
    }
    void dfs(const vector<vector<int>> &adjacencyList, vector<int> &visited, int vertex, int count)
    {
        visited[vertex] = count;

        for (int neighbor : adjacencyList[vertex])
        {
            if (!visited[neighbor])
            {
                dfs(adjacencyList, visited, neighbor, count);
            }
        }
    }
};
