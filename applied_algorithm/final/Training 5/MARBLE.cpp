#include<bits/stdc++.h>
using namespace std;

int main(){
	int wide, height;
	scanf("%d%d", &wide, &height);
	
	int n;
	scanf("%d", &n);
	
	int waste[wide+1][height+1];	
	for(int i=0; i<=wide; ++i)
		for(int j=0; j<=height; ++j)
			waste[i][j] = -1;
			
	int w[n], h[n];
	for(int i=0; i<n; ++i){
		scanf("%d%d", &w[i], &h[i]);
		waste[w[i]][h[i]] = 0;
	}

	for(int i=0; i<=height; ++i)
		waste[0][i] = 0;
		
	for(int i=1; i<=wide; ++i){
		for(int j=0; j<=height; ++j){
			waste[i][j] = (waste[i][j] == -1)? i*j: waste[i][j];
			for(int c=1; c<i; ++c)
				waste[i][j] = min(waste[i][j], waste[i-c][j] + waste[c][j]);
			for(int d=1; d<j; ++d)
				waste[i][j] = min(waste[i][j], waste[i][j-d] + waste[i][d]);
		}
	}
	
	cout << waste[wide][height];
	return 0;
}
