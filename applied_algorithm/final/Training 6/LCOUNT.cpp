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
	
	int counter=0;
	int visit[n+1]={0};
	queue <int> q;
	visit[1] = 1;
	q.push(1);
	
	while(!q.empty()){
		int next=q.front();
		q.pop();
		bool found=false;
		for(int i: edge[next]){
			if(!visit[i]){
				visit[i] = 1;
				q.push(i);
				found = true;
			}
		}
		if(!found)
			++counter;
	}
	
	cout << counter;
	return 0;
}
