#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution {
public:
    int minMaxGame(vector<int>& nums) {

        while(nums.size()>1){
            nums = construct(nums);
        }
        return nums[0];
    }
    vector<int> construct(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i=0; i<n/2; i++){
            if (i%2==1)
                res.push_back(max(nums[2 * i], nums[2 * i + 1]));
            else
                res.push_back(min(nums[2 * i], nums[2 * i + 1]));
        }
        return res;
    }
};
// [70,38,21,22]