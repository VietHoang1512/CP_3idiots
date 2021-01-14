#include<bits/stdc++.h>
using namespace std;

long long gold_mining(int n, int low, int high, int *arr){
	long long res=0;
	long long result[n];
	for(int i=0; i<low; ++i)
		result[i] = arr[i];
	for(int i=low; i<n; ++i){
		long long temp=0;
		for(int j=max(0, i-high); j<= i-low; ++j)
			temp = max(temp, result[j] + arr[i]);
		result[i] = temp;
		res = max(result[i], res);
	}
	return res;
}

int main(){
	int n, low, high, *arr;
	cin >> n >> low >> high;
	arr = new int[n];
	
	for(int i=0; i<n; ++i)
		cin >> arr[i];
		
	cout << gold_mining(n, low, high, arr);
	return 0;
}
