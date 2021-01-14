#include<bits/stdc++.h>
using namespace std;

struct Cubic{
	int a, b, h;
	
	Cubic(int a, int b, int h){
		this->a = a;
		this->b = b;
		this->h = h; 
	}
	
	Cubic(){
	}
};

vector <Cubic> v;
int edge[100][100]; // edge[i][j] = 1 if there is edge from i to j else 0
int best[100];

void Init(){
	for(int i=0; i<v.size(); ++i){
		for(int j=0; j<v.size(); ++j){
			if(j != i){
				if(((v[i].a > v[j].a) && (v[i].b > v[j].b)) || ((v[i].a > v[j].b) && (v[i].b > v[j].a)))
					edge[i][j] = 1;
				else
					edge[i][j] = 0;
			}
		}
	}
	memset(best, 0, sizeof(best));
}

int DFS(int p){
	int height=v[p].h;
	int res=height;
	
	for(int i=0; i<v.size(); ++i){
		if(edge[p][i]){
			int temp=height;
			if(best[i] == 0){
				temp += DFS(i);
			}
			else{
				temp += best[i];
			}
			res = (temp > res)? temp: res;
		}
	}
	return best[p] = res;
}

int main(){
	int n, num_case=1;
	int a, b, c; // Size of Cubic
	
	while(scanf("%d", &n) && n){ // End of input is 0
		v.clear();
 		for(int i=0; i<n; ++i){
 			scanf("%d%d%d", &a, &b, &c);
 			v.push_back(Cubic(a, b, c));
 			v.push_back(Cubic(a, c, b));
			v.push_back(Cubic(b, c, a));
		}
 		Init();	
 		
 		int result=0;
 		for(int i=0; i<v.size(); ++i){
 			if(best[i] == 0){
 				best[i] = DFS(i);
			 }
			 result = max(result, best[i]);
		 }
		 cout << "Case " + to_string(num_case) + ": maximum height = " + to_string(result) << endl;
		num_case++;
	}
	
	return 0;
}
