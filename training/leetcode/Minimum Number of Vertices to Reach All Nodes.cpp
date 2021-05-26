#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> adj(n);
        for (auto e : edges)
        {
            adj[e[1]]++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (!adj[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};