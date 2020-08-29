#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

const int mx=100000;

int n, m, src, sink;
int n_cats=0;
int cnt=0;

vector <int> neighbors[mx];
bool visited[mx];
int cat[mx];

int dfs(int u, int n_cats, int & cnt){
    //cout << " -> " << u;
    visited[u] = true;
    
    if(cat[u]) n_cats++;
    else n_cats = 0;
    
    if (n_cats>m) {
        //cout << endl;
        return 0;
    }
    
    if (!neighbors[u].size()){
        cnt++;
        //cout << endl << n_cats << endl;
        return 0;
    }
    
    for (int v:neighbors[u]){
        if (!visited[v]) {
            dfs(v, n_cats, cnt);
        }
    }
    return 0;
}

int main(){

    cin >> n >>m;
    for (int i=1; i<=n; i++){
        cin >> cat[i];
    }

    for (int i=1; i<n; i++){
        cin >> src >> sink;
        neighbors[src].push_back(sink);
        //neighbors[sink].push_back(src);
    }

    dfs(1, n_cats, cnt);
    // for (int v:neighbors[1]){
    //     dfs(v, n_cats, cnt);
    // }
    cout  << cnt;
}
