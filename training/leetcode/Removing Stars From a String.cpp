#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    string removeStars(string s)
    {
        int n = s.size();
        vector<int> keep(n, 1);
        int cnt = 0;
        for (int i= n - 1; i >= 0; i--)
        {
            if (s[i]=='*'){
                keep[i] = 0;
                cnt++;
            }
            else{
                if(cnt>0){
                    keep[i] = 0;
                    cnt--;
                }
            }
        }
        string res="";
        for(int i=0; i<n; i++)
        {
            if (keep[i]==1)
                res += s[i];
        }
        return res;
    }
};