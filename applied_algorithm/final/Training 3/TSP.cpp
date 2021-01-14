#include<bits/stdc++.h>
using namespace std;

int **cost;
int n;
int m;
int *visit;
int *x;
long long f;
long long result;
int c_min;

void Try(int k){
	for(int i=0; i<n; ++i){
		if((visit[i] == 0) && (cost[x[k-1]][i] > -1)){
			long long old = f;
			x[k] = i;
			visit[i] = 1;
			f += cost[x[k-1]][x[k]];
			
			if(k == n-1){
				if(cost[x[k]][x[0]] >-1)
					if(f + cost[x[k]][x[0]] < result)
						result = f + cost[x[k]][x[0]];
			}
				
			else{
				if(f + (n-k) * c_min < result)
					Try(k+1);
			} 
			f = old;
			visit[i] = 0;
		}
	}
}


int main(){
	cin >> n >> m;
	
	cost = new int *[n];
	for(int i=0; i<n; ++i){
		cost[i] = new int[n];
		for(int j=0; j<n; ++j)
			cost[i][j] = -1;
	}
		
	visit = new int[n];
	for(int i=0; i<n; ++i)
		visit[i] = 0;
		
	x = new int[n];
	result = INT_MAX;
	c_min = INT_MAX;
	f = 0;
	
	int first, second;
	int c;
	
	for(int i=0; i<m; ++i){
		cin >> first >> second >> c;
		cost[first-1][second-1] = c;
		if(c < c_min)
			c_min = c;
	}
	
	x[0] = 0;
	visit[0] = 1;
	Try(1);
	if(result == INT_MAX)
		cout << -1 << endl;
	else
		cout << result << endl;
	return 0;
}
