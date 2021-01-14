#include<bits/stdc++.h>
using namespace std;

int n;
int *used;
int *x;

void Try(int k){
	if(k == n){
		for(int i=0; i<n; ++i)
			cout << x[i] << " ";
		cout << "\n";
	}
	else{
		for(int i=1; i<=n; ++i){
			if(used[i] == 0){
				used[i] = 1;
				x[k] = i;
				Try(k+1);
				used[i] = 0;
			}
		}
	}
}

int main(){
	cin >> n;
	used = new int[n+1];
	for(int i=0; i<n+1; ++i)
		used[i] = 0;
	
	x = new int[n];
		
	Try(0);
}
