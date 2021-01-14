#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int n, m, k;
vector <pair <int, int>> *edge;
long long result=INF;
int *permu;
int *possible;
int root;
bool solve=false;

long long mst(){
	priority_queue<pair <int, int>, vector <pair <int, int>> , greater<pair <int, int>> > pq; 
    long long res=0;
    vector<int> key(n, INF); 
    vector<bool> visit(n, false); 
  
    pq.push(make_pair(0, root)); 
    key[root] = 0;
  
    for(int w=0; w<k; ++w){ 
        int u=pq.top().second;
        pq.pop();
        visit[u] = true;
        
        for(auto e: edge[u]){
        	int v=e.first;
        	int weight=e.second;
        	if(possible[v]){
        		if(!visit[v]){
        			if(key[v] > weight){
        				key[v] = weight;
        				pq.push(make_pair(key[v], v));
					}
				}
			}
		}
    }
	
	for(int i=0; i<n; ++i){
		if(possible[i]){
			if(key[i] == INT_MAX)
				return -1;
			res += key[i];
		}
	}
	return res; 
}

void Try(int l){
	if(l == k){
		long long temp=mst();
		if(temp != - 1){
			result = min(result, temp);
			solve = true;
		}
	}
	else{
		for(int i=permu[l-1]+1; i<n-k+l+1; ++i){
			permu[l] = i;
			possible[i] = 1;
			Try(l+1);
			possible[i] = 0;
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	++k;
	
	int a, b, cost;
	edge = new vector <pair <int, int>>[n];
	permu = new int[k];
	possible = new int[n];
	for(int i=0; i<m; ++i){
		scanf("%d%d%d", &a, &b, &cost);
		edge[a-1].push_back(make_pair(b-1, cost));
		edge[b-1].push_back(make_pair(a-1, cost));
	}
	
	for(int i=0; i<n-k+1; ++i){
		for(int j=0; j<n; ++j){
			possible[j] = 0;
		}
		permu[0] = i;
		possible[i] = 1;
		root = i;
		Try(1);
	}
	
	if(solve)
		cout << result << endl;
	else
		cout << -1 << endl;
	return 0;
}


