#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	
	int i;
	bool found = false;
	for(i=n-2; i>=0; i--){
		if(arr[i] < arr[i+1]){
			found = true;
			break;
		}
	}
	
	if(!found){
		cout << "-1";
		return 0;
	}
	else{
		int temp = i+1;
		for(int j=i+2; j<n; ++j){
			if(arr[j] > arr[i] && arr[j] < arr[temp])
				temp = j;
		}
		
		int buff = arr[temp];
		arr[temp] = arr[i];
		arr[i] = buff;
		
		reverse(arr+i+1, arr+n);
	
		for(int i=0; i<n; ++i)
			cout << arr[i] << " ";
	}
}
