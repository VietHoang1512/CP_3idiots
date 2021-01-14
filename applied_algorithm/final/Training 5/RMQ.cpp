#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int table[1000005][23]; // table[i][j] represents minimum number in range(i, i+2^j-1)
int n, m;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", &a[i]);
	// Preprocessing
	for(int i=0; i<n; ++i)
		table[i][0] = a[i];
	for(int k=1; (1<<k) <= n; ++k){
		for(int i=0; i-1+(1<<k)<n; ++i){
			table[i][k] = min(table[i][k-1], table[i + (1<<(k-1))][k-1]);
			// Dynamic formulation, it is easy to verify
		}
	}
	
	int u, v, result=0;
	scanf("%d", &m);
	for(int _=0; _<m; ++_){
		scanf("%d%d", &u, &v);
		int k = log2(v-u+1);
		result += min(table[u][k], table[v+1 - (1<<k)][k]);
	}
	
	cout << result;
	return 0;
}
