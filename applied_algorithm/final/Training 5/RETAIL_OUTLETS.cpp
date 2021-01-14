#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	
	int a[n];
	for(int i=0; i<n; ++i)
		scanf("%d", &a[i]);
	
	long long result[m+1][n];
	for(int amount=0; amount<=m; ++amount)
		for(int i=0; i<n; ++i)
			result[amount][i] = 0;
	
	for(int amount=1; amount<=m; ++amount){
		if((amount % a[0]) == 0)
			result[amount][0] = 1;
		for(int i=1; i<n; ++i){
			int bound = amount / a[i];
			for(int j=1; j<=bound; ++j)
				result[amount][i] = (result[amount][i] + result[amount-j*a[i]][i-1]) % M;
		}
	}
	
	cout << result[m][n-1] ;
	return 0;
}
