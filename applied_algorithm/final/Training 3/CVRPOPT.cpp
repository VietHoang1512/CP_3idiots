#include<bits/stdc++.h>
using namespace std;

int n, K, Q;
int *pack;
int **dist;
int result;
int *cap;
int d_min;
int *length;
int **route;
int *set_list;
int len;
int f;
int sub_result;
int last;
int *visit;

void SubTry(int l){
	if(l == len+1){
		if(f + dist[last][0] < sub_result)
			sub_result = f + dist[last][0];
	}
	else{
		for(int i=0; i<len; ++i){
			if(visit[i] == 0){
				int old_f = f;
				int old_last = last;
				
				f += dist[last][set_list[i]];
				last = set_list[i];
				visit[i] = 1;
				
				if(f + (len-l+1) * d_min < sub_result)
					SubTry(l+1);
				
				visit[i] = 0;
				last = old_last;
				f = old_f;
			}	
		}
	}
}

int valid(){
	for(int i=0; i<K; ++i){
		if(length[i] == 0)
			return 0;
	}
	return 1;
}

void Try(int l){
	if(l == n){
		if(valid() == 1){
			int temp = 0;
			for(int i=0; i<K; ++i){
				len = length[i];
				set_list = new int[len];
				
				for(int j=0; j<len; ++j)
					set_list[j] = route[i][j];
				
				f = 0;
				sub_result = INT_MAX;
				visit = new int[len+1];
				for(int i=0; i<len+1; ++i)
					visit[i] = 0;
				last = 0;
				
				SubTry(1);
				temp += sub_result;
			}
			if(temp < result)
				result = temp;
		}	
	}
	else{
		for(int i=0; i<K; ++i){
			if(cap[i] >= pack[l]){
				route[i][length[i]++] = l+1;
				cap[i] -= pack[l];
				
				Try(l+1);
				
				cap[i] += pack[l];
				length[i]--;
			}
		}
	}
}


int main(){
	cin >> n >> K >> Q;
	
	pack = new int[n];
	d_min = INT_MAX;
	
	for(int i=0; i<n; ++i)
		cin >> pack[i];
	
	dist = new int*[n+1];
	for(int i=0; i<n+1; ++i)
		dist[i] = new int[n+1];
	
	for(int i=0; i<n+1; ++i)
		for(int j=0; j<n+1; ++j){
			cin >> dist[i][j];
			if(dist[i][j] != 0 && dist[i][j] < d_min)
				d_min = dist[i][j];
		}
				
	cap = new int[K];
	for(int i=0; i<K; ++i)
		cap[i] = Q;
		
	result = INT_MAX;
	f = 0;
	length = new int[K];
	for(int i=0; i<K; ++i)
		length[i] = 0;
		
	route = new int*[K];
	for(int i=0; i<K; ++i)
		route[i] = new int[n];
		
	
	Try(0);
	
	cout << result << endl;
}
