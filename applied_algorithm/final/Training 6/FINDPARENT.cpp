#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	int a, b;
	vector <int> edge[n+1];
	for(int i=0; i<n-1; ++i){
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	int visit[n+1] = {0};
	queue <int> q;
	q.push(1);
	visit[1] = 1;
	vector <int> res(n+1);
	
	while(!q.empty()){
		int next=q.front();
		q.pop();
		for(int i: edge[next]){
			if(!visit[i]){
				visit[i] = 1;
				res[i] = next;
				q.push(i);
			}
		}
	}
	
	for(int i=2; i<=n; ++i)
		cout << res[i] << " ";
	return 0;
}
