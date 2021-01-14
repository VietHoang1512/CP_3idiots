#include<bits/stdc++.h>
using namespace std;
int n, m;
vector <int> *adj, *bridges;
int *num, *low;
int curnum=0;

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
		if (low[v] > num[u]) {
			bridges[u].push_back(v);
			bridges[v].push_back(u);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	num = new int[n];
	low = new int[n];
	for(int i=0; i<n; ++i){
		num[i] = -1;
	}
	
	int a, b;
	adj = new vector <int>[n];
	bridges = new vector <int>[n];
	for(int i=0; i<m; ++i){
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	for (int u=0; u<n; u++) {
		if (num[u] == -1)
			find_bridges(u, -1);
	}
	
//	for(int i=0; i<n; ++i){
//		for(int j=0; j<bridges[i].size(); ++j)
//			cout << bridges[i][j] << " ";
//		cout << endl;
//	}
	
	int visit[n]={0};
	int length=0; 
	long long result=0;
		
	while(length<n){
		int first; 
		long long len=1;
		++length;
		for(int i=0; i<n; ++i){
			if(!visit[i]){
				first = i;
				break;
			}
		}
		visit[first]=1;
		int num_edge=bridges[first].size();
 
		bool found=false;
		queue <int> q;
		q.push(first);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i: bridges[u]){
				if(!visit[i]){
					++length;
					++len;
					num_edge += bridges[i].size();
					visit[i] = 1;
					for(int j: bridges[i]){
						if((visit[j]) && (j != u)){
							found=true;
							break;
						}
					}
					if(found)
						break;
					q.push(i);
				}
			}
		}
		if(not found){
			//cout << len << " " << num_edge << endl;
			result += (len*(len-1) - num_edge)/2;
		}
	}
	
	cout << result;
	return 0;
}
