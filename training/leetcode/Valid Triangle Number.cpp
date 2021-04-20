#include <bits/stdc++.h>
using namespace std;

int main()
{

}

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = nums.size(), res=0;
        for(int i=0; i<total-2;i++){
            for(int j=i+1; j<total-1; j++){
                for(int k=j+1; k<total; k++){
                    if(nums[k]>=nums[i]+nums[j]) break;
                    res++;
                }
            }
        }
        return res;
    }
};