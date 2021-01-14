// #include <iostream>
// #include <list>
// #include <vector>
// #include <stack>

// using namespace std;

void dfs(vector<list<int>> adj)
{
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1

    /*****************
    # YOUR CODE HERE #
    *****************/
    while (!S.empty())
    {
        int cur = S.top();
        S.pop();
        while (!adj[cur].empty())
        {
            int x = adj[cur].back();
            if (!visited[x])
            {
                S.push(x);
            }
            adj[cur].pop_back();
        }
        if (!visited[cur])
        {
            visited[cur] = true;
            cout << cur << endl;
        }
    }
    return;
}

// int main()
// {
//     int n = 7;
//     vector<list<int>> adj;
//     adj.resize(n + 1);
//     adj[1].push_back(2);
//     adj[2].push_back(4);
//     adj[1].push_back(3);
//     adj[3].push_back(4);
//     adj[3].push_back(5);
//     adj[5].push_back(2);
//     adj[2].push_back(7);
//     adj[6].push_back(7);
//     dfs(adj);
//     return 0;
// }