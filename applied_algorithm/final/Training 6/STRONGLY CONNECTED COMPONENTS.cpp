#include<bits/stdc++.h>
using namespace std;

int n;
vector <int> adj[1000005];
vector <int> low(1000005), num(1000005 , -1);
vector <bool> connect(1000005, false);
int curnum=0;
stack <int > comp;
int counter=0;

void scc(int u){
	comp.push(u);
	connect[u] = true;
	low[u] = num[u] = curnum++;
	for(int i=0; i<adj[u].size(); ++i){
		int v=adj[u][i];
		if (num[v] == -1){
			scc(v);
			low[u] = min(low[u], low[v]);
		}
		else if(connect[v]){
			low[u] = min(low[u], num[v]);
		}
	}
	if(num[u] == low[u]) {
		while(true) {
			int cur=comp.top ();
			comp.pop ();
			connect[cur] = false ;
			if(cur == u) 
				break ;
		}
		++counter;
	}
}

int main(){
	int m;
	scanf("%d%d", &n, &m);
	
	int a, b;
	for(int i=0; i<m; ++i){
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
	}
	for (int i=0; i<n; ++i) {
		if (num[i] == -1) {
			scc(i);
		}
	}
	
	cout << counter;
	return 0;
}
