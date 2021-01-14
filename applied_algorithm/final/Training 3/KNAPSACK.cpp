#include<bits/stdc++.h>
using namespace std;

int n;
int b;
int *value;
int *weight;
int current;
int *x;
int f;
int result;

void Try(int k){
	for(int i=x[k]+1; i<n; ++i)
		if(current + weight[i] <= b){// Do i chua duoc dem va co the dem duoc
			x[k+1] = i;
			current += weight[i];
			f += value[i];
			if(f > result)
				result = f;
			Try(k+1);
			current -= weight[i];
			f -= value[i];
		}
}

int main(){
	cin >> n >> b;
	
	value = new int[n];
	weight = new int[n];
	x = new int[n+1];
	x[0] = -1;
	
	for(int i=0; i<n ;++i)
		cin >> weight[i] >> value[i];
		
	current = 0;
	f = 0;
	result = 0;
	
	Try(0);
	
	cout << result << endl;
}
