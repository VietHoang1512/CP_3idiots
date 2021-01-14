#include#include<bits/stdc++.h>
using namespace std;

bool is_enough(int n, long long m, int *h, int cut){
	long long counter=0;
	for(int i=0; i<n; ++i)
		counter += (h[i] > cut)? h[i] - cut: 0;
	return counter >= m;
}

int main(){
	int n;
	long long m;
	cin >> n >> m;

	int height[n];
	for(int i=0; i<n; ++i)
		scanf("%d", &height[i]);
		
	sort(height, height+n);
	int high = height[n-1];
	int low = 0;
	int mid;
	
	while(low < high){
		mid = (low + high)/2;
		if(is_enough(n, m, height, mid))
			low = mid;
		else
			high = mid-1;
		if(low == high-1){
			if(not is_enough(n, m, height, high))
				break;
			low = high;
		}
	}
	
	cout << low << endl;
}
