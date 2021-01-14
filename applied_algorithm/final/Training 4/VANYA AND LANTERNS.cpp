#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, l, a[1005];
	scanf("%d%d", &n, &l);
	
	for(int i=0; i<n; ++i)
		scanf("%d", a+i);

	sort(a, a+n);
	int result=max(2 * a[0], 2 * (l-a[n-1]));
	for(int i=1; i<n; ++i)
		result = max(result, a[i]-a[i-1]);
	printf("%.9lf", 0.5 * result);
	
	return 0;
}
