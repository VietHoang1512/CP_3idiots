#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mx = 2000000;

vector<int> neighbors[mx];
bool visited[mx];
// int n_components=0,;
// int root;
int n_cycles = 0;
int deg[mx];
bool IsCycle = false;

int dfs(int src, bool &IsCycle)
{
    // args: non-visited vertice
    // cout << "->" << src;
    visited[src] = true;
    // if (neighbors[src].size()>2){
    //     IsCycle = false;
    //     return 0;
    // }
    // if ((neighbors[src].size())==1&&neighbors[src][0]==root){
    //     IsCycle = true;
    //     return 0;
    // }
    // if ((neighbors[src].size())==1&&neighbors[src][0]!=root){
    //     cout << "Leaf node is" << neighbors[src][0];
    //     IsCycle = false;
    // }
    // int cnt = 0;
    if (neighbors[src].size() != 2)
    {
        IsCycle = false;
    }
    for (int v : neighbors[src])
    {
        if (!visited[v])
        {
            // cnt++;
            dfs(v, IsCycle);
        }
    }
    return 0;
}

int main()
{
    int n, m;
    int src, sink;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> src >> sink;
        neighbors[src].push_back(sink);
        neighbors[sink].push_back(src);
        deg[src]++;
        deg[sink]++;
    }
    for (int v = 1; v <= n; v++)
    {
        // cout << endl;
        // root = v;

        if (!visited[v])
        {
            // cout << "From root " << v << endl;
            //            n_components++;
            IsCycle = true;
            dfs(v, IsCycle);
            if (IsCycle)
            {
                n_cycles++;
                // cout << " this is a satisfied cycle" << endl;
            }
        }
    }
    // cout << endl << n_cycles;
    cout << n_cycles;
}