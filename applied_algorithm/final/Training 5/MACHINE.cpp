#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	int m; 
	scanf("%d", &n);
	
	pair <int, int> period[n];
	for(int i=0; i<n; ++i)
		scanf("%d%d", &period[i].first, &period[i].second);
	
	// From the beginning to the end
	sort(period, period+n, [](pair <int, int> a, pair <int, int> b){return a.second < b.second;});
	m = period[n-1].second;
	
	int left[m+2];
	int lend, lbegin = period[0].second+1;
	int counter=0, i=lbegin;
	left[i-1] = 0;

	for(; i<=m+1; ++i){
		// The latest period must end before i
		if(counter == n)
			break;
		left[i] = left[i-1];
		while(period[counter].second < i){
			left[i] = max(left[i-1], period[counter].second - period[counter].first);
			counter++;
		}
	}
	lend = i;
	// From the end reverse the beginning
	sort(period, period+n, [](pair <int, int> a, pair <int, int> b){return a.first > b.first;});
	
	int right[m+1];
	int rbegin, rend=period[0].first;
	counter=0;
	i=rend;
	right[i+1] = 0;
	
	for(; i>=0; --i){
		// The latest period must end before i
		if(counter == n)
			break;
		right[i] = right[i+1];
		while(period[counter].first >= i){
			right[i] = max(right[i+1], period[counter].second - period[counter].first);
			counter++;
		}
	}
	rbegin = i;
	
	int result=-1;
	for(int j=max(lbegin, rbegin); j<=min(lend, rend); ++j)
		if(left[j] != 0 && right[j] != 0)
			result = max(result, left[j] + right[j]);
		
	cout << result;
	return 0;
}
