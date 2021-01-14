#include<bits/stdc++.h>
using namespace std;

bool is_assigned(int n, int c, int *x, int dis){
	int start = x[0];
	int temp;
	for(int i=0; i<c-1; ++i){
		temp = lower_bound(x, x+n, start+dis) - x;
		if(temp == n)
			return false;
		start = x[temp];
	}
	return true;
}

int agg_cow(int n, int c, int *x){
	int low = 1;
	int high = x[n-1];
	int mid;
	
	while(low < high){
		mid = (low + high)/2;
		if(is_assigned(n, c, x, mid))
			low = mid;
		else
			high = mid-1;
		if(low == high-1){
			if(not is_assigned(n, c, x, high))
				break;
			low = high;
		}
	}
	return low;
}

int main(){
	int T;
	cin >> T;
	vector <int> result;
	
	int n, c, *x;
	
	for(int i=0; i<T; ++i){
		cin >> n >> c;
		x = new int[n];
		
		for(int j=0; j<n; ++j)
			scanf("%d", &x[j]);
		sort(x, x+n);
		
		result.push_back(agg_cow(n, c, x));
	}
	
	for(int i=0; i<T; ++i)
		cout << result[i] << endl;
}
