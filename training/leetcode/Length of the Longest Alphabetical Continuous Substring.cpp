#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len=s.size();
        int ans=1;
        int cnt=1;
        for(int i=1;i<len;i++){
            if(s[i]==s[i-1]+1) cnt++;
            else{
                
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};