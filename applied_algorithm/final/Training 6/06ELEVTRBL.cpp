#include<bits/stdc++.h>
using namespace std;

int main(){
	int f, s, g, u, d;
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	
	vector <int> adj[f+1];
	for(int i=1; i<=f; ++i){
		if(i-d > 0)
			adj[i].push_back(i-d);
		if(i+u <= f)
			adj[i].push_back(i+u);
	}
	
	vector <int> q;
	int visit[f+1]={0};
	q.push_back(s);
	visit[s] = 1;
	int counter=0, length=1;
	
	while(length != 0){
		length = 0;
		vector <int> new_q;
		++counter;
		for(int i: q){
			for(int v: adj[i]){
				if(v == g){
					cout << counter;
					return 0;
				}
				if(!visit[v]){
					++length;
					visit[v] = 1;
					new_q.push_back(v);
				}	
			}
		}
		q = new_q;
	}
	cout << "use the stairs";
	return 0;
}
