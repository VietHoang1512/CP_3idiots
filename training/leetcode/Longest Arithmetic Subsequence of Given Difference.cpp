#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int dp[100005];
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> len;
        int res = 1;
        cout << len[0] << endl;
        for (auto i : arr)
        {
            len[i] = 1 + len[i - difference];
            res = max(res, len[i]);
        }
        return res;
        // int total = arr.size();
        // for(int i=0; i<difference){
        //     dp[i]=1
        // }
        // for(int i=difference;i<total; i++){
        //     dp[i] = dp[]
        // }
    }
};