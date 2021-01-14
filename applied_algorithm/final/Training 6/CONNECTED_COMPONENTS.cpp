#include<bits/stdc++.h>
using namespace std;

int n, m;
vector <int> *adj;

int main(){
	scanf("%d%d", &n, &m);
	
	adj = new vector <int>[n];
	int a, b;
	
	for(int i=0; i<m; ++i){
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	
	int visit[n]={0};
	int length=0; 
	int result=0;
	int counter=0;
		
	while(length<n){
		int first; 
		++length;
		++result;
		for(int i=counter; i<n; ++i){
			if(!visit[i]){
				first = i;
				visit[i] = 1;
				break;
			}
		}
		counter=first+1;
 
		queue <int> q;
		q.push(first);
		while(!q.empty()){
			int u=q.front();
			//cout << u << " ";
			q.pop();
			for(int i: adj[u]){
				if(!visit[i]){
					++length;
					visit[i] = 1;
					q.push(i);
				}
			}
		}
		//cout << endl;
	}
	
	cout << result;
	return 0;
}
