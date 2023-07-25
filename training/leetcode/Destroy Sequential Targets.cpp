#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int total = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> m;
        for (auto n:nums){
            m[n%space]++;
        }
        int mx=0;
        for(auto p:m){
            if(p.second>mx){
                mx = p.second;
            }
        }
        for (auto n: nums){
            if (m[n%space]==mx) return n;
        }
        return 0;
    }
};