#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a, b;
	long m = 1000000007;
	cin>> a;
	cin>> b;
	cout<< ((a%m) + (b%m))%m;
	return 0;
}
