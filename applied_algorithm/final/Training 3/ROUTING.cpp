#include<bits/stdc++.h>
using namespace std;

int length;	// Number of places has to travel
int *arr; // Set of including vertices
int *visit; // Status of visiting that vertice
int last; // Last vertice
int f; // Current cost 
int result; // Minimum cost path
int cmin=INT_MAX; // Lower bound for edge
int **edge; // Cost for travel from this vertice to another vertice
int vend;

void init(int n){
	length = n;
	f = 0;
	result = INT_MAX;
}

void Try(int k){
	if(k == length-1){
		if(edge[last][vend] > 0){ // Having edge from x[k-1] to arr[length-1]
			result = min(result, f + edge[last][vend]);
		}
	}
	else{
		for(int i=1; i<length-1; ++i){
			int v = arr[i];
			if((!visit[i]) && (edge[last][v] > 0)){
				int old_last = last;
				int old_f = f;
				visit[i] = 1;
				f += edge[last][v];
				last = v;
				
				if(f + cmin * (length-k-1) < result)
					Try(k+1);
				
				visit[i] = 0;
				last = old_last;
				f = old_f;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, r;
	cin >> n >> r;
	vector <int> res;
	
	edge = new int*[n];
	visit = new int[n];
	arr = new int[n];
	for(int i=0; i<n; ++i){
		edge[i] = new int[n];
		visit[i] = 0;
	}
		
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> edge[i][j];
			if(edge[i][j])
				cmin = min(cmin, edge[i][j]);
		}
	}	
	
	for(int i=0; i<=r; ++i){
		string inp;
        getline(cin, inp);
        vector <int> arr_inp;
        istringstream iinp(inp);
        int temp;
        while (iinp >> temp){
            arr_inp.push_back(temp-1);
        }
        
		if (i == 0) continue;
		length = arr_inp.size();
		init(arr_inp.size());
		for(int j=0; j<length; ++j){
			arr[j] = arr_inp[j];
		}
		vend = arr_inp.back();
		
		/*	DEBUG STATUS
		cout << length << endl;
		for(int j=0; j<length; ++j)
			cout << arr[j] << " ";
		cout << endl;
		for(int j=0; j<n; ++j)
			cout << visit[j] << " ";
		cout << endl;
		cout << f << " " << result << endl;
		*/
		
		last = arr[0];
		f = 0;
		Try(1);
		if(result == INT_MAX)
			result = 0;
			
		res.push_back(result);
	}
	
	for(int i=0; i<r; ++i)
		cout << res[i] << endl;
	
	
}

