#include<bits/stdc++.h>
using namespace std;

int change[6] = {500, 100, 50, 10, 5, 1};

int main(){
	int n;
	cin >> n;
	n = 1000 - n;
	int counter=0;
	int res;
	for(int i=0; i<6; ++i){
		res = n / change[i];
		n = n % change[i];
		counter += res;
	}
	
	cout << counter;
	return 0;
}
