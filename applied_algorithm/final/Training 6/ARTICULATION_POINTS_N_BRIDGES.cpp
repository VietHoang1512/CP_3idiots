#include<bits/stdc++.h>
using namespace std;

int n, m;
vector <int> *adj;
int *num, *low, *art;
int curnum=0;
int res_bri=0, res_art=0;

void find_bridges (int u, int p){
	low [u] = num [u] = curnum ++;
	for(int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(v == p)
			continue ;
		if(num[v] == -1){
			find_bridges (v, u);
			low[u] = min(low[u], low[v]);
		}		 
		else {
			low[u] = min(low[u], num[v]);
		}
		if(low[v] > num[u]){
			++res_bri;
		}
	}
}

int dfsAP(int u, int p) {
  int children = 0;
  low[u] = num[u] = curnum++;
  for (int& v : adj[u]) {
    if (v == p) continue;
    if (num[v] == -1) { 
      children++;
      dfsAP(v, u); 
      if (num[u] <= low[v]) // condition #1
        art[u] = 1;
      low[u] = min(low[u], low[v]); 
    } else 
      low[u] = min(low[u], num[v]); 
  }
  return children;
}

int main(){
	scanf("%d%d", &n, &m);
	num = new int[n];
	low = new int[n];
	art = new int[n];
	for(int i=0; i<n; ++i){
		num[i] = -1;
		art[i] = 0;
	}
	
	int a, b;
	adj = new vector <int>[n];
	for(int i=0; i<m; ++i){
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	for (int u=0; u<n; u++) {
		if (num[u] == -1)
			find_bridges(u, -1);
	}
	// Done finding bridges and low and num
	curnum = 0;
	for(int i=0; i<n; ++i){
		num[i] = -1;
	}
	
	for(int i=0; i<n; ++i){
		if(num[i] == -1)
			art[i] = dfsAP(i, -1) > 1;
	}	
	
	for(int i=0; i<n; ++i){
		if(art[i])
			++res_art;
	}
	cout << res_art << " " << res_bri;
	return 0;
}
