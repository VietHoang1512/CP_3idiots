#include<bits/stdc++.h>
using namespace std;

int n, m;
int *x;

void Try(int k){
	if(k == m){
		for(int i=0; i<m; ++i)
			cout << x[i] << " ";
		cout << "\n";
	}
	else{
		for(int i=x[k-1]+1; i<= n-m+k+1; ++i){
			x[k] = i;
			Try(k+1);
		}
	}
}

int main(){
	cin >> n >> m;
	x = new int[m];
	
	for(int i=1; i<=n-m+1; ++i){
		x[0] = i;
		Try(1);
	}
}
