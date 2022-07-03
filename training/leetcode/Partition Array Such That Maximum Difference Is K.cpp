#include <bits/stdc++.h>
using namespace std;

int main()
{
}


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // sort
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mn = nums[0], res=1;
        for (auto n:nums){
            if (n-mn>k){
                res++;
                mn = n;
            }
        }
        return res;
    }
};