#include<bits/stdc++.h>
using namespace std;

int n;
vector <pair <int, int>> *adj;

vector <int> bfs(int root){
	int visit[n]={0};
	vector <int> res(n, 0);
	queue <int> q;
	q.push(root);
	visit[root] = 1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(pair <int, int> e: adj[u]){
			int v=e.first, cost=e.second;
			if(!visit[v]){
				q.push(v);
				res[v] = res[u]+cost;
				visit[v] = 1;
			}
		}
	}
	
	return res;
}

int main(){
	scanf("%d", &n);
	
	int a, b, w;
	adj = new vector <pair <int, int>>[n];
	for(int i=0; i<n-1; ++i){
		scanf("%d%d%d", &a, &b, &w);
		adj[a-1].push_back(make_pair(b-1, w));
		adj[b-1].push_back(make_pair(a-1, w));
	}
	
	vector <int> beacon = bfs(0);
	int m=0, index;
	for(int i=0; i<n; ++i){
		if(beacon[i] > m){
			m = beacon[i];
			index = i;
		}
	}
	m = 0;
	
	vector <int> result = bfs(index);
	for(int i=0; i<n; ++i){
		if(result[i] > m)
			m = result[i];
	}
	
	cout << m << endl;
	return 0;

}
