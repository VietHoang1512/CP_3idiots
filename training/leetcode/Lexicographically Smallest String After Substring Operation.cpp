#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestString(string s)
    {
        int total = s.size();
        int cur=0;
        while(s[cur]!='a'){
            cur++;
            if(cur==total){
                s[total-1]--; 
                return s;
            }
        }
        int next=cur;
        while((next+1<total)&&(s[next+1]!='a')){
            next++;
        }
        for (int i = 0; i < min(total, next); i++)
        {
            s[i]--;
        }
        return s;
    }
};