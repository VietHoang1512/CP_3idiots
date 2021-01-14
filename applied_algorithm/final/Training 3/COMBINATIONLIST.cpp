#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	int arr[m];
	for(int i=0; i<m; ++i)
		arr[i] = i+1;
	
	for(int _=0; _<k-1; ++_){
		bool found = false;
		int i;
		for(i=m-1; i>=0; --i){
			if(arr[i] != n-m+i+1){
				found = true;
				break;
			}
		}
	
		if(!found){
			cout << "-1";
			return 0;
		}
	
		arr[i]++;
		for(int j=i+1; j<m; ++j)
			arr[j] = arr[j-1]+1;
	}
	
	for(int j=0; j<m; ++j)
		cout << arr[j] << " ";
}
