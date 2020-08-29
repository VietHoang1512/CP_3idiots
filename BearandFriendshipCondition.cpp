const int mx=150000;
#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n_vertices=0, n_edges=0;

vector <long long> neighbors[mx];
bool visited[mx];

// dfs with non-visited vertice
void dfs(int u, int & n_vertices, int & n_edges){
    n_vertices++;
    n_edges += neighbors[u].size();
    //cout << u << " ";
    visited[u] = true;
    for (int v: neighbors[u] ){
        if (!visited[v]) {
            dfs(v, n_vertices, n_edges);
        }
    }
}

int main(){
    int m,n;
    cin >> n >> m;

    int src, sink;
    for (int i=1; i<=m; i++){
       cin >> src >> sink;
       neighbors[src].push_back(sink);
       neighbors[sink].push_back(src);
    }

    for (int u=1; u<=n; u++){
        if (!visited[u]){
            // cout << "From vertice " << u << " visiting" << endl;
            int n_edges=0, n_vertices=0;
            dfs(u, n_vertices, n_edges);
            //cout << endl<< n_edges << n_vertices << endl;
            if ((long long)n_vertices*(n_vertices-1) != n_edges){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}


