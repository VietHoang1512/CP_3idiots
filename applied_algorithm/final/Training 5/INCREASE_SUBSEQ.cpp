#include<bits/stdc++.h>
using namespace std;

int arr[10005];
int n;

int lis(){
	int result=1;
	int table[n] = {1};
	for(int i=1; i<n; ++i){
		table[i] = 1;
		for(int j=0; j<i; ++j)
			if(arr[j] < arr[i])
				table[i] = max(table[j] + 1, table[i]);
		result = max(result, table[i]);
	}
	return result;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	
	printf("%d", lis());
}
