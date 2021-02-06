
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> adj[200005];
        int visited[200005];
        memset(visited,0, sizeof(visited));
        vector<int> res;
        int next;
        int total = adjacentPairs.size()+1;
        if (total==2) return adjacentPairs[0];
        
        for(auto x:adjacentPairs){
            adj[x[0]+100000].push_back(x[1]+100000);
            adj[x[1]+100000].push_back(x[0]+100000);
        }
        for(int i=0; i<200003; i++){
            int len = adj[i].size();
            if(len==1){
                res.push_back(i-100000);
                visited[i] = 1;
                next = adj[i][0];
                cout << (i-100000) << endl;
                break;
            }
            
        }
        while(total--){
            cout << (next-100000) << endl;
            visited[next] = 1;
            res.push_back(next-100000);
            int len = adj[next].size();
            
            if(len==1) return res;
            
            if(!visited[adj[next][0]])
                next = adj[next][0];
            else
                next = adj[next][1];                  

        }
        return res;
    }
};