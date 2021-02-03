class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int len = nums.size();
        if(len==1) return nums[0]==1;
        int gcd = nums[0];        
        for(int i=0; i<len; i++){
            gcd = __gcd(gcd, nums[i]);
            if (gcd==1) return true;
        }
        if (gcd>1) return false;
        return true;
    }
};