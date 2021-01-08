#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>> &adj)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(adj.size(), INT_MAX);


    pq.push(make_pair(0, 0));
    dist[0] = 0;

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

        for (auto i :adj[u])
        {

            int v = i.first;
            int weight = i.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main()
{
    int n = 9;
    vector<vector<pair<int, int>>> adj(n);
    auto add_edge = [&adj](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i)
    {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}