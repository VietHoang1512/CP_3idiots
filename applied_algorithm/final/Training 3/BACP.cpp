#include<bits/stdc++.h>
using namespace std;

int n;
int m;
int *credit;
int *x;
int **condition;
int *load;
int max_load;
int result;

int UCV(int k, int i){// Mon hoc thu k co the xep vao ki i hay khong
	for(int j=0; j<k; ++j){
		if(condition[j][k] == 1 && x[j] >= i)
			return 0;
		if(condition[k][j] == 1 && i >= x[j])
			return 0;
	}
	return 1;
}

void Try(int k){
	for(int i=0; i<m; ++i)
		if(UCV(k, i)){
			int old_max_load = max_load;
			x[k] = i;
			load[i] += credit[k];
			if(load[i] > max_load)
				max_load = load[i];
			if(k == n-1){
				if(max_load < result)
					result = max_load;
			}
			else
				Try(k+1);
				
			load[i] -= credit[k];
			max_load = old_max_load;
		}
}

int main(){
	cin >> n >> m;
	
	credit = new int[n];
	
	condition = new int*[n];
	for(int i=0; i<n; ++i)
		condition[i] = new int[n];
		
	x = new int[n];
	load = new int[m];
	result = INT_MAX;
	max_load = 0;
	
	for(int i=0; i<m; ++i)
		load[i] = 0;
	
	for(int i=0; i<n; ++i)
		cin >> credit[i];
		
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> condition[i][j];
	
	Try(0);
	cout << result << endl;
	
	return 0;
}
