#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // set<long long> s(nums.begin(), nums.end());
        // vector< long long> v(s.begin(), s.end());
        // sort(v.rbegin(), v.rend());
        // int total = v.size();
        // long long res=0;
        // if (total<k) return 0;
        // while(k--){
        //     res += v[k];
        //     cout << v[k] <<" ";
        // }
        // cout << "\n***\n";
        vector<long long> v(nums.begin(), nums.end());
        map<long long, int> m;
        int total = v.size(), cur_res=0, res=0;
        if(total<k) return 0LL;
        for(int i=0; i<k; i++){
            m[v[i]]++;
            res+=v[i];
        }
        res = cur_res;
        for(int i=k; i<total; i++){
            m[v[i-k]]--;
            if (m[v[i-k]]==0) m.erase(v[i-k]);
            m[v[i]]++;
            cur_res = cur_res+v[i]-v[i-k];
            res = max(res, cur_res);
            
        }
        return res;
        
    }
};