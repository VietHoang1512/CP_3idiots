#include<bits/stdc++.h>
using namespace std;

int n, k;
int result;
int checker[15][15];
int x[15];
int check_row[15];
int left_dial[30];
int right_dial[30];

void Try(int i){
	//Position for i-th row queen
	if(i == n)
		++result;
	else{
		for(int pos=0; pos<n; ++pos){
			if(!checker[i][pos]){
				if(!check_row[pos]){
					if((!left_dial[i+pos])){
						if(!right_dial[i-pos+n-1]){
							x[i] = pos;
							++check_row[pos];
							++left_dial[i+pos];
							++right_dial[i-pos+n-1];
							Try(i+1);
							--check_row[pos];
							--left_dial[i+pos];
							--right_dial[i-pos+n-1];
						}
					}
				}
			}	
		}
	}
	
}

int holey(){
	result = 0;
	for(int i=0; i<n; ++i){
		check_row[i] = 0;
	}
	
	for(int i=0; i<2*n-1; ++i){
		left_dial[i] = 0;
		right_dial[i] = 0;
	}
		
	for(int i=0; i<n; ++i){
		if(!checker[0][i]){
			x[0] = i;
			++check_row[i];
			++left_dial[i];
			++right_dial[n-i-1];
			Try(1);
			--check_row[i];
			--left_dial[i];
			--right_dial[n-i-1];
		}
	}
	
	return result;
}

int main(){
	int a, b;
	while(true){
		scanf("%d%d", &n, &k);
		// Break the loop
		if(n == 0)
			break;
			
		// Init checker
		for(int i=0; i<15; ++i)
			for(int j=0; j<15; ++j)
				checker[i][j] = 0;
		
		for(int i=0; i<k; ++i){
			scanf("%d%d", &a, &b);
			checker[a-1][b-1] = 1;
		}
		cout << holey() << endl;
	}
	return 0;
}
