#include<bits/stdc++.h>
using namespace std;

int n, k;
int *visit;
int counter=0;
int **edge;
int pre;

void Try(int l){
	if(l == k+1){
		counter++;
	}
	else{
		for(int i=0; i<n; ++i){
			if(visit[i] == 0 && edge[pre][i] == 1){
				int old_pre = pre;
				visit[i] = 1;
				pre = i;
				
				Try(l+1);
				
				visit[i] = 0;
				pre = old_pre;	
			}
		}
	}
}

int main(){
	int T;
	cin >> n >> k >> T;
	
	edge = new int*[n];
	for(int i=0; i<n; ++i){
		edge[i] = new int[n];
		for(int j=0; j<n; ++j)
			edge[i][j] = 0;
	}
	
	visit = new int[n];
	for(int i=0; i<n; ++i)
		visit[i] = 0;
		
	for(int i=0; i<T; ++i){
		int a, b;
		cin >> a >> b;
		edge[a-1][b-1] = 1;
		edge[b-1][a-1] = 1;
	}
	for(int i=0; i<n; ++i){
		visit[i] = 1;
		pre = i;
		Try(1);
		visit[i] = 0;
	}
	
	cout << counter/2 << endl;
	return 0;
}
