#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int res = 0;
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] >= 0)
                adj[manager[i]].push_back(i);
        }
        DFS(headID, adj, informTime, 0);
        return res;
    }
    void DFS(int headID, vector<vector<int>> &adj, vector<int> &informTime, int cur_time)
    {
        cur_time += informTime[headID];
        if (adj[headID].empty())
        {
            res = max(res, cur_time);
        }
        for (auto x : adj[headID])
        {
            DFS(x, adj, informTime, cur_time);
        }
    }
};