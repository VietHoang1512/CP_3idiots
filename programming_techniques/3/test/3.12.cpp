#include <iostream>
#include <vector>

using namespace std;

int n, k, m, cur_pos, res;
vector<int> adj[31];
vector<bool> visited(31, false);

void func(int j)
{
    if (j == (k + 2))
    {
        res = res + 1;
        return;
    }
    int pre_pos = cur_pos;
    for (auto x: adj[cur_pos])
    {
        if (!visited[x])
        {
            visited[x] = true;
            cur_pos = x;
            func(j + 1);
            visited[x] = false;
            cur_pos = pre_pos;
        }
    }
}

int main()
{
    res = 0;
    cin >> n >> k;
    cin >> m;
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        adj[0].push_back(i);
    }
    visited[0] = true;
    cur_pos = 0;
    func(1);
    cout << res/2;
    return 0;
}