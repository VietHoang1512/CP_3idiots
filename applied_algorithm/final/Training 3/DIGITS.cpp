#include<bits/stdc++.h>
using namespace std;

int *x;// I, C, T, U, S, K
int counter=0;
int H;
int N;
int digit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int check(){
	int result = (x[0] - x[5]) * 100 + x[1] * 10 + x[2] * 2- 62 + H * 1000 + x[3] * 100 + x[4] * 10; 
	if(result != N)
		return 0;
	return 1;
}
void Try(int k){
	if(k == 6){
		if(check() == 1){
			counter++;
			//cout << x[0] << x[1] << x[2] << "-" << x[5] << "62" << "+" << H << x[3] << x[4] << x[2] << endl;
		}
			
	}
	else{
		for(int i=1; i<=9; ++i){
			if(!digit[i]){
				x[k] = i;
				digit[i] = 1;
				Try(k+1);
				digit[i] = 0;
			}
		}
	}
	
}

int main(){
	cin >> N;
	if(N > 11000){
		cout << "-1" << endl;
		return 0;
	}
	
	int upper = (N+962)/1000, lower;
	if(N < 1425)
		lower = 1;
	else
		lower = (N-425)/1000;
		
	x = new int[6]; 
	counter = 0;
	
	for(H=lower; H<=upper; H++){
		digit[H] = 1;
		Try(0);
		digit[H] = 0;
	}
	
	cout << counter << endl;
}
