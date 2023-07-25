class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long cur=0, res=0;
        for(auto x:nums){
            cur += x;
            res += (cur>0LL);
        }
        return res;
    }
};