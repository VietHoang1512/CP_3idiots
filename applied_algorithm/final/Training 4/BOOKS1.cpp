#include<bits/stdc++.h>
using namespace std;

int n, k, p[505];
long long lower, upper;

bool is_divide(long long amount){
	long long s=0;
	int counter=1;
	for(int i=n-1; i>=0; --i){
		if(p[i] > amount)
			return false;
		if(s + p[i] > amount){
			++counter;
			s = 0;
		}
		s += p[i];
	}
	
	return (counter <= k);
}

void divide(long long amount){
	vector <int> v;
	long long s=0;
	int counter=1;
	for(int i=n-1; i>=0; --i){
		if((s + p[i] > amount) || (k-counter-1 == i)){
			v.push_back(-1);
			s = 0;
			++counter;
		}
		v.push_back(p[i]);
		s += p[i];
	}
	reverse(v.begin(), v.end());
	
	int len=v.size();
	for(int i=0; i<len; ++i){
		if(v[i] == -1)
			cout << "/ ";
		else
			cout << v[i] << " ";
	}
	cout << endl;
}

void books(){
	long long up=upper, lo=lower, mid;
	while(lo < up){
		mid = (up + lo)/ 2;
		if(is_divide(mid)){
			up = mid;
		}
		else{
			lo = mid + 1;
		}
	}
	
	divide(lo);
}

int main(){
	int t, temp;
	scanf("%d", &t);
	
	for(int i=0; i<t; ++i){
		lower = INT_MAX;
		upper = 0;
		
		scanf("%d%d", &n, &k);
		for(int j=0; j<n; ++j){
			scanf("%d", &temp);
			lower = (lower > temp)? temp: lower;
			upper += temp;
			p[j] = temp;
		}
		
		books();
	}
	
	return 0;
}
