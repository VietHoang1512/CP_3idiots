#include<bits/stdc++.h>
using namespace std;

int n, m;
int counter=0;
pair <int, int> *edge;
int *x;

void Try(int k){
	if(k == n-1){
		int cnt[n]={0};
		int adj[n][n];
		for(int i=0; i<k; ++i){
			pair <int, int> e=edge[x[i]];
			int u=e.first, v=e.second;
			adj[u][cnt[u]++] = v;
			adj[v][cnt[v]++] = u;
		}
		queue <int> q;
		int visit[n]={0}, number=1;
		q.push(0);
		visit[0] = 1;
		while(!q.empty()){
			int nt=q.front();
			q.pop();
				
			for(int j=0; j<cnt[nt]; ++j){
				int u=adj[nt][j];
				if(!visit[u]){
					visit[u] = 1;
					q.push(u);
					++number;
				}
			}
		}
			
		if(number == n)
			++counter;
//			for(int i=0; i<n-1; ++i){
//			pair <int, int> e=edge[x[i]];
//			int u=e.first, v=e.second;
//			cout << u << " " << v << endl;
//			}
//			cout << "*******" << endl;
	}
	else{
		for(int i=x[k-1]+1; i<m-n+2+k; ++i){
			x[k] = i;
			Try(k+1);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	x = new int[n-1];
	edge = new pair <int, int>[m];
	
	int a, b;
	for(int i=0; i<m; ++i){
		scanf("%d%d", &a, &b);
		edge[i] = make_pair(a-1, b-1);
	}
	
	for(int i=0; i<m-n+2; ++i){
		x[0] = i;
		Try(1);
	}
	
	cout << counter;
	return 0;
}

