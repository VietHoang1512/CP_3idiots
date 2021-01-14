#include<bits/stdc++.h>
using namespace std;

int n;
int low;
int high;
int *x;
int consecutive = 0;
long long counter=0;

void Try(int k){
	if(k == n){
		if(((consecutive >= low) && (consecutive <= high)) || (consecutive == 0)){
			/*
			for(int i=0; i<n; ++i)
				cout << x[i];
			cout << endl;
			*/
			counter++;
		}
	}
	else{
		int old_con = consecutive;		
		if(consecutive == 0){
			x[k] = 1;
			consecutive = 1;
			Try(k+1);
			consecutive = 0;
		}
		else{
			if(consecutive < low){
				x[k] = 1;
				consecutive++;
				Try(k+1);
				consecutive--;
			}
			else if(consecutive >= high){
				x[k] = 0;
				consecutive = 0;
				Try(k+1);
				consecutive = old_con;
			}
			else{
				x[k] = 0;
				consecutive = 0;
				Try(k+1);
				consecutive = old_con;
				
				x[k] = 1;
				consecutive++;
				Try(k+1);
				consecutive--;
			}
		}
	}
}

int main(){
	cin >> n >> low >> high;
	x = new int[n];
	
	x[0] = 0;
	Try(1);
	
	consecutive = 0;
	Try(0);
	cout << counter << endl;
	
	return 0;
}
