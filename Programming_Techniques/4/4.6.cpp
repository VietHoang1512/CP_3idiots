#include <bits/stdc++.h>
using namespace std;

void bfs(vector<list<int>> adj)
{
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1

    /*****************
    # YOUR CODE HERE #
    *****************/
}

int main()
{
    int n = 7;
    vector<list<int>> adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
}
