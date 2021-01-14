#include<bits/stdc++.h>

int n; // Number of passengers
int cap;
int k; // Number of passengers at most on bus at same time
int **distance;
int *x; // Solution status
int *possible;
int result; // shortest route
int f;
int d_min;


void Try(int l){
	if(l == 2*n+1){// Maximum visit
	// No passengers left
		if(f + distance[x[l-1]][0] < result){
			result = f + distance[x[l-1]][0];
		}
	}
	else{ // Have to take passengers
		int start = 1;
		if(cap == 0) // Have to leave a passenger
			start = n+1;
	
		int end = 2*n+1;
		if(cap == k)
			end = n+1;
			
		for(int i=start; i<end; ++i){ // Can't go back to 0. Next position is i
			if(possible[i-1]){
				if(i <= n)
					possible[i+n-1] = 1;
				
				possible[i-1] = 0;
				int old_cap = cap;
				
				x[l] = i;
				f += distance[x[l-1]][i];
				
				if(i <= n) // Possible passenger i-1. Passenger i-1 weren't on the bus
					cap--;
				
				else // Possible passenger i-n-1. Passenger i-n-1 is on the bus
					cap++;
				
				if(f + (2*n-l+1) * d_min < result)
					Try(l+1);
				
				// Restore value
				cap = old_cap;
				f -= distance[x[l-1]][i];
				
				if(i <=n)
					possible[i+n-1] = 0;
					
				possible[i-1] = 1;
			}
		}	
	}
}


int main(){
	std :: cin >> n >> k;
	
	d_min = INT_MAX;
	
	distance = new int *[2*n+1];
	for(int i=0; i<2*n+1; ++i)
		distance[i] = new int[2*n+1];
		
	x = new int[2*n+1];
	possible = new int[2*n];
	for(int i=0; i<n; ++i){
		possible[i] = 1;
		possible[i+n] = 0;
	}
		
	
	for(int i=0; i<2*n+1; ++i)
		for(int j=0; j<2*n+1; ++j){
			scanf("%d", &distance[i][j]);
			if(distance[i][j] < d_min && distance[i][j] != 0)
				d_min = distance[i][j];
		}
			

	cap = k;
	result = INT_MAX;
	f = 0;
	x[0] = 0;
	
	Try(1);
	std :: cout << result << std :: endl;
}
