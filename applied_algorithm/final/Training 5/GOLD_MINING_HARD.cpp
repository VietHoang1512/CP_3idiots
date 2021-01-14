#include<bits/stdc++.h>
using namespace std;

int n, low, high, k;
int arr[1000005];

int gold_mine(){
	priority_queue <int, vector <int>> pq;
	int result[n];
	int res=0;
	for(int i=0; i<low; ++i){
		result[i] = arr[i];
		res = max(res, result[i]);
	}
	pq.push(result[0]);
	
	for(int i=low; i<=high; ++i){
		int largest = pq.top();
		result[i] = largest + arr[i];
		res = max(res, result[i]);
		pq.push(result[i-low+1]);
	}
	pq.push(result[high-low+1]);
	
	for(int i=high+1; i<n; ++i){
		int largest = pq.top();
		result[i] = largest + arr[i];
		pq.push(result[i-low+1]);
		res = max(res, result[i]);
	}
	/*
	for(int i=0; i<n; ++i)
		cout << result[i] << " ";
	cout << endl;
	*/
	return res;
}

int main(){
	scanf("%d%d%d", &n, &low, &high);
	k = high-low+1;
	
	for(int i=0; i<n; ++i)
		scanf("%d", arr+i);
		
	cout << gold_mine();
	return 0;
}


