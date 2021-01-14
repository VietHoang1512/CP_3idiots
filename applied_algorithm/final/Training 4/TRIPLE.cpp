#include<bits/stdc++.h>
using namespace std;

int bi_search(int low, int high, int *arr, int key){
	if(low>high)
		return -1;
	int mid=(low+high)/2;
	if(arr[mid] == key)
		return mid;
	if(arr[mid] < key)
		return bi_search(mid+1, high, arr, key);
	return bi_search(low, mid-1, arr, key);
}

long long Count(int low, int high, int *arr, int key){
	long long res=0;
	int pos = bi_search(low, high, arr, key);
	
	for(int i=pos; i>= low; --i){
		if(arr[i] != key)
			break;
		res++;
	}
	
	for(int i=pos+1; i<= high; ++i){
		if(arr[i] != key)
			break;
		res++;
	}
	
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	
	int arr[n], temp;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	
	long long counter=0;
	sort(arr, arr+n);
	for(int i=0; i<n-2; ++i){
		for(int j=i+1; j<n-1; ++j){
			temp = k - arr[i] - arr[j];
			if(temp >= arr[j]){
				if(bi_search(j+1, n-1, arr, temp) != -1){
					counter += Count(j+1, n-1, arr, temp);
				}	
			}
		}
	}
	
	cout << counter << endl;
	return 0;
}
