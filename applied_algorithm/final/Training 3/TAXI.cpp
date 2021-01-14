#include<bits/stdc++.h>

int n; // Number of passengers
int k; // Number of passengers at most on bus at same time
int **distance;
int *x; // Solution status
int *visit;
int result; // shortest route
int f;
int d_min;


void Try(int l){
	if(l == n+1){// Maximum visit
		if(f + distance[x[2*l-2]][0] < result){
			result = f + distance[x[2*l-2]][0];
		}
	}
	else{ // Have to take passengers
		for(int i=0; i<n; ++i){ // Can't go back to 0. Next position is i
			if(visit[i] == 0){
				x[2*l-1] = i+1;
				x[2*l] = i+n+1;
				f += distance[x[2*l-2]][x[2*l-1]] + distance[x[2*l-1]][x[2*l]];
				visit[i] = 1;
				
				if(f + d_min * (2*n-2*l+1) < result)
					Try(l+1);
				
				// Restore value
				visit[i] = 0;
				f -= distance[x[2*l-2]][x[2*l-1]] + distance[x[2*l-1]][x[2*l]];
			}
		}	
	}
}


int main(){
	std :: cin >> n;
	
	d_min = INT_MAX;
	distance = new int *[2*n+1];
	for(int i=0; i<2*n+1; ++i)
		distance[i] = new int[2*n+1];
		
	visit = new int[n];
	for(int i=0; i<n; ++i)
		visit[i] = 0;
		
	x = new int[2*n+1];
	
	for(int i=0; i<2*n+1; ++i)
		for(int j=0; j<2*n+1; ++j){
			scanf("%d", &distance[i][j]);
			if(distance[i][j] < d_min && distance[i][j] != 0)
				d_min = distance[i][j];
		}
					
	result = INT_MAX;
	f = 0;
	x[0] = 0;
	
	Try(1);
	std :: cout << result << std :: endl;
}
