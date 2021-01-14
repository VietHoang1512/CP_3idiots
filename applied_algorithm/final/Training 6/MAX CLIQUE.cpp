#include<bits/stdc++.h>
using namespace std;

int n, m;
int edge[14][14];

int length(int mask){
	int counter=0;
	for(int i=0; i<n; ++i){
		if(mask & (1<<i)){
			++counter;
		}
	}
	return counter;
}

bool check(int num, int mask){
	if(num == 1)
		return true;
	
	vector <int> v;
	for(int i=0; i<n; ++i){
		if(mask & (1 << i)){
			v.push_back(i);
		}
	}
	
	int s=v.size();
	for(int i=0; i<s-1; ++i){
		for(int j=i+1; j<s; ++j){
			if(!edge[v[i]][v[j]]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			edge[i][j] = 0;
			
	int a, b;
	for(int i=0; i<m; ++i){
		scanf("%d%d", &a, &b);
		edge[a-1][b-1] = 1;
		edge[a-1][b-1] = 1;
	}
	
	int result=0, upper=(1<<n);
	for(int i=1; i<upper; ++i){
		int len=length(i);
		//cout << len << endl;
		if(check(len, i))
			result = max(result, len);
	}
	
	cout << result;
	return 0;
}
