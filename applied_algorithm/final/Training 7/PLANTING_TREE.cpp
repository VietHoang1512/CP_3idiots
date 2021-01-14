#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	int growth[n];
	for(int i=0; i<n; ++i)
		scanf("%d", growth+i);
		
	sort(growth, growth+n, [](int a, int b){
		return a > b;
	});
	
	int result=0;
	for(int i=0; i<n; ++i){
		growth[i] += i+2;
		result = max(result, growth[i]);
	}
	
	cout << result;
	return 0;
}
