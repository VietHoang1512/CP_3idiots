#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	int arr[m];
	for(int i=0; i<m; ++i)
		cin >> arr[i];
	
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
	
	for(int j=0; j<m; ++j)
		cout << arr[j] << " ";
}
