#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums, int k=-5) {
        if(k==-1) return true;
        if(k==-5) k=nums.size()-1;
        if(k==0) return false;
        if(k==1) return nums[0]==nums[1];
        if ((nums[k]==nums[k-1]+1)&&(nums[k-1]==nums[k-2]+1)) return validPartition(nums, k-3);
        if(nums[k]==nums[k-1]){
            if (nums[k-1]==nums[k-2]) return (validPartition(nums, k-3)||validPartition(nums, k-2));
            return validPartition(nums, k-2);
        }
        return false;
        
    }
};