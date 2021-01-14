#include<bits/stdc++.h>
using namespace std;

string bug_life(int k, vector <int> *adj){
	int color[k] = {0};
	queue <int> current_set;
	current_set.push(0);
	color[0] = 1;
	
	int temp;
	while(!current_set.empty()){
		temp = current_set.front();
		current_set.pop();
		for(int i: adj[temp]){
			if(color[i] == 0){
				color[i] = -color[temp];
				current_set.push(i);
			}
			else{
				if(color[i] == color[temp])
					return "Suspicious bugs found!";
			}
		}
	}
	return "No suspicious bugs found!";
}

int main(){
	int n;
	scanf("%d", &n);
	
	int k, m;
	int a, b;
	for(int i=0; i<n; ++i){
		scanf("%d%d", &k, &m);
		vector <int> adj[k];
		for(int j=0; j<m; ++j){
			scanf("%d%d", &a, &b);
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1); 
		}
		printf("Scenario #%d:\n", i+1);
		cout << bug_life(k, adj) << endl;
	}
	
	return 0;
}
