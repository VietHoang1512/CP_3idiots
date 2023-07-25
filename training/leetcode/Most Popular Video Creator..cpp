#include <bits/stdc++.h>
using namespace std;



bool my_compare(string a, string b)
{

    if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)
        return a.size() > b.size();

    else return a < b;
}


class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<long long>& views) {
        map<string, long long> creator2view, creator2max;
        map<string, vector<string>> creator2ids;
        vector<vector<string>> res;
        long long total = views.size();
        for(long long i=0; i<total; i++){
            creator2view[creators[i]]+=views[i];
            creator2max[creators[i]] = max(creator2max[creators[i]], views[i]);
        }
        long long mx=0;
        for(long long i=0; i<total; i++){
            if(views[i]==creator2max[creators[i]])
                creator2ids[creators[i]].push_back(ids[i]);
        }        
        for (auto creator:creators){
            sort(creator2ids[creator].begin(), creator2ids[creator].end(), my_compare);
        }
        for(auto p:creator2view){
            mx = max(mx, p.second);
        }
        for(auto p:creator2view){
            if(mx==p.second){
                res.push_back({p.first, creator2ids[p.first][0]});
            }
        }        
        return res;

    }
};