#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	++k;
	
	int c[n], a[n];
	for(int i=0; i<n; ++i)
		scanf("%d", &c[i]);
	for(int i=0; i<n; ++i)
		scanf("%d", &a[i]);
	
	int edge[n][n];
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			edge[i][j] = 0;
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<=min(n-1, i+a[i]); ++j)
			edge[j][i] = 1; // i vertice can traverse to j
	
	long long table[k][n]; // table i, j represent j is the i-th vertice
	for(int i=0; i<n; ++i)
		for(int v=0; v<k; ++v)
			table[v][i] = 0;
	table[0][0] = c[0];
	
	for(int v=1; v<k; ++v){ // v-th vertice
		for(int i=1; i<n; ++i){
			for(int j=0; j<i; ++j){
				if((edge[i][j] == 1) && (table[v-1][j] > 0)){ // Can traverse from j to i
					table[v][i] = max(table[v-1][j] + c[i], table[v][i]);
				}
			}
		}
	}
	
	long long result=0;
	for(int v=0; v<k; ++v)
		result = max(result, table[v][n-1]);
		
	cout << result;
	return 0;
}
