#include<bits/stdc++.h>
using namespace std;
int n, m, s, t;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
	int len=adj.size();
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    vector <int> dist(len, INT_MAX);
    
    pq.push(make_pair(0, s));
    dist[s] = 0;
    
    while(!pq.empty()){
    	int u=pq.top().second;
    	pq.pop();
    	for(auto itr=adj[u].begin(); itr!=adj[u].end(); ++itr){
    		int v=itr->first;
    		int weight=itr->second;
    		
    		if(dist[v] > dist[u] + weight){
    			dist[v] = dist[u] + weight;
    			pq.push(make_pair(dist[v], v));
			}
		}
	}
    return dist;
}

int main() {
	scanf("%d%d", &n, &m);
	
	int a, b, dis;
	vector <vector <pair <int, int>>> adj(n);
	for(int i=0; i<m; ++i){
		scanf("%d%d%d", &a, &b, &dis);
		adj[a-1].push_back(make_pair(b-1, dis));
	}
		
	scanf("%d%d", &s, &t);
	--s;
	--t;
		
	vector<int> distance = dijkstra(adj);
	if(distance[t] == INT_MAX)
		cout << -1;
	else
		cout << distance[t];
	
	return 0;
}
