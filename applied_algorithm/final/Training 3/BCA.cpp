#include<bits/stdc++.h>
using namespace std;

int m; // Number of courses
int n; // Number of teachers
int **pref; // Pref[i][j] mean teacher j prefer subject i size n*m
int **conf; // Conflict pair of subjects
int *x;
int result;
int *load;
int f;
int counter;

int check(int k, int i){
	for(int j=0; j<k; ++j){
		if(conf[j][k] == 1)
			if(x[j] == i)
				return 0;
	}
	return 1;
}

void Try(int k){
	if(k == n){
		if(f < result){
			result = f;
			counter++;
		}
	}
	else{
		for(int i=0; i<m; ++i){
			if(pref[k][i] == 1){// If teacher i prefer subject k
				if(check(k, i) == 1){
					int old_f = f;
					
					x[k] = i;
					load[i]++;
					if(load[i] > f)
						f = load[i];
					if(f < result)
						Try(k+1);
					load[i]--;
					f = old_f;
				}
			}
		}
	}
}

int main(){
	cin >> m >> n;
	
	counter = 0;
	conf = new int*[n];
	for(int i=0; i<n; ++i){
		conf[i] = new int[n];
		for(int j=0; j<n; ++j)
			conf[i][j] = 0;
	}
		
	pref = new int*[n];
	for(int i=0; i<n; ++i){
		pref[i] = new int[m];
		for(int j=0; j<m; ++j)
			pref[i][j] = 0;
	}
	
	load = new int[m];
	for(int i=0; i<m; ++i)
		load[i] = 0;
	
	x = new int[n];
	
	for(int i=0; i<m; ++i){
		int t, temp;
		scanf("%d", &t);
		for(int j=0; j<t; ++j){
			scanf("%d", &temp);
			pref[temp-1][i] = 1;
		}
	}
	
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		conf[a-1][b-1] = 1;
		conf[b-1][a-1] = 1;
	}
	
	result = INT_MAX;
	f = 0;
	
	Try(0);
	
	if(counter == 0)
		cout << -1 << endl;
	else
		cout << result << endl;
	return 0;
}
