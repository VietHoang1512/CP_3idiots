#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt=0, mx=0, total=blocks.size();
        for(int i=0; i<k; i++){
            if(blocks[i]=='B') cnt++;
        }
        mx = cnt;
        for(int i=k; i<total; i++){
            cnt = cnt - (blocks[i-k]=='B') + (blocks[i]=='B');
            mx = max(mx, cnt);
        }
        return k-mx;
        
    }
};