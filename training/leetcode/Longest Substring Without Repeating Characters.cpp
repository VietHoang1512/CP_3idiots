#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int total = s.size();
        if (total<=1) return total;
        int start = 0, end=0;
        int res=1;
        map<char, int> m;
        m[s[0]] = 1;
        while(1){
            end++;
            while(m[s[end]]>0){
                m[s[start]]--;
                start++;
            }
            m[s[end]]++;
            res = max(res, end-start+1);
            if (end==total-1) break;
        }
        return res;
    }
};