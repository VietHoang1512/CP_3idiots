#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, T, D;
	int res=0;
	scanf("%d%d%d", &n, &T, &D);

	int amount[n], dtime[n];
	for(int i=0; i<n; ++i)
		scanf("%d", &amount[i]);
	for(int i=0; i<n; ++i)
		scanf("%d", &dtime[i]);
	
	int result[T+1][n];
	for(int i=0; i<n; ++i)
		result[0][i] = 0;
		
	for(int t=1; t<=T; ++t){
		result[t][0] = (t >= dtime[0])? amount[0]: 0;
		for(int i=1; i<n; ++i){
			if(t >= dtime[i]){
				result[t][i] = amount[i];
				int temp = t-dtime[i];
				for(int j=max(0, i-D); j<i; ++j)
					result[t][i] = max(result[temp][j] + amount[i], result[t][i]);
				res = max(res, result[t][i]);
			}
			else
				result[t][i] = 0;
		}
	}
	
	cout << res;
	return 0;
}
