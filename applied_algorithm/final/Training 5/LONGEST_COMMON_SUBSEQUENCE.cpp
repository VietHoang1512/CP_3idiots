#include<bits/stdc++.h>
using namespace std;

int a[10005];
int b[10005];
int n, m;

short lcs(){
	short table[n+1][m+1];
	for(int j=0; j<=m; ++j)
		table[0][j] = 0;
	for(int i=0; i<=n; ++i)
		table[i][0] = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			table[i][j] = max(table[i][j-1], table[i-1][j]);
			if(a[i-1] == b[j-1])
				table[i][j] = (table[i][j] > table[i-1][j-1] + 1)? table[i][j]: table[i-1][j-1] + 1;
		}
	}
	return table[n][m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", &a[i]);
	for(int i=0; i<m; ++i)
		scanf("%d", &b[i]);
	
	printf("%d", lcs());
}
