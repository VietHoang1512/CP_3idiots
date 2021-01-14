#include<bits/stdc++.h>
using namespace std;

int n, k;
int *cost, *dest;
vector <int> *edge;

vector <pair <int, int>> bfs(int i, int dest, int cost){
	int counter=0;
	vector <pair <int, int>> result;
	vector <int> current_set;
	current_set.push_back(i);
	int visit[n] = {0};
	int length=1;
	visit[i] = 1;
	
	while((length != 0) && (counter < dest)){
		++counter;
		vector <int> new_set;
		length = 0;
		for(int i: current_set){
			for(int v: edge[i]){
				if(!visit[v]){
					visit[v] = 1;
					new_set.push_back(v);
					result.push_back(make_pair(v, cost));
					++length;
				}
			}
		}
		current_set = new_set;
	}
	return result;
}

int main(){
	scanf("%d%d", &n, &k);
	
	cost = new int[n];
	dest = new int[n];
	for(int i=0; i<n; ++i)
		scanf("%d%d", &cost[i], &dest[i]);
	
	edge = new vector <int>[n];
	int a, b;
	for(int i=0; i<k; ++i){
		scanf("%d%d", &a, &b);
		edge[a-1].push_back(b-1);
		edge[b-1].push_back(a-1);
	}
	
	vector <pair <int, int>> adj[n];
	for(int i=0; i<n; ++i){
		adj[i] = bfs(i, dest[i], cost[i]);
	}
	
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
	vector <int> dist(n, INT_MAX);
	
	pq.push(make_pair(0, 0));
	dist[0] = 0;
	
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
	cout << dist[n-1];
	return 0;
}
