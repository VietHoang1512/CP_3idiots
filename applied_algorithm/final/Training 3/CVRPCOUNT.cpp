#include<bits/stdc++.h>
using namespace std;

int n;
int l;
int Q;
int *pack;
long long counter;
int *cap;
int *number;

int fact(int n){
	int result = 1;
	for(int i=2; i<=n; ++i)
		result *= i;
	return result;
}

int valid(){
	for(int i=0; i<l; ++i){
		if(number[i] == 0)
			return 0;
	}
		
	return 1;
}

void Try(int k){
	if(k == n){
		if(valid() == 1){
			long long temp = 1;
			for(int i=0; i<l; ++i)
				temp *= fact(number[i]);
			counter += temp;
			
		}
	}
	else{
		for(int i=0; i<l; ++i){ // Possible truck i for k-th delivery
			if(cap[i] >= pack[k]){
				cap[i] -= pack[k];
				number[i]++;
				
				Try(k+1);
				
				cap[i] += pack[k];
				number[i]--;
			}
		}
	}
}

int main(){
	cin >> n >> l >> Q;
	
	pack = new int[n];
	
	for(int i=0; i<n; ++i)
		cin >> pack[i];
		
	counter = 0;
	
	cap = new int[l];
	for(int i=0; i<l; ++i)
		cap[i] = Q;
	
	number = new int[l];
	for(int i=0; i<l; ++i)
		number[i] = 0;
	
	Try(0);
	for(int i=1; i<=l; ++i)
		counter /= i;
		
	cout << (counter % 1000000007) << endl;
}

