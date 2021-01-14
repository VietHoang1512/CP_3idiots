#include<bits/stdc++.h>
using namespace std;

int n, m;
vector <pair <int, int>> *edge;

long long mst(){
	priority_queue<pair <int, int>, vector <pair <int, int>> , greater<pair <int, int>> > pq; 
  
    int src = 0;
    long long res=0;
    vector<int> key(n, INT_MAX); 
    vector<bool> visit(n, false); 
  
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    while (!pq.empty()) { 
        int u = pq.top().second;
        pq.pop(); 
        visit[u] = true; 
        
        for (auto i=edge[u].begin(); i!=edge[u].end(); ++i) { 
            int v=i->first; 
            int weight=i->second; 
  
            if (visit[v] == false && key[v] > weight) { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
            } 
		} 
    }
    
    for(int i=1; i<n; ++i)
    	res = res + key[i];
	return res; 
}

int main(){
	scanf("%d%d", &n, &m);
	
	int a, b, cost;
	edge = new vector <pair <int, int>>[n];
	for(int i=0; i<m; ++i){
		scanf("%d%d%d", &a, &b, &cost);
		edge[a-1].push_back(make_pair(b-1, cost));
		edge[b-1].push_back(make_pair(a-1, cost));
	}
	
	cout << mst();
	return 0;
}

