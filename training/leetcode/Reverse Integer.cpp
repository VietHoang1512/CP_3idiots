#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        if(!x) return x;
        if (x==-2147483648) return 0;
        int res=0, sign = abs(x)/x;
        x = abs(x);
        // cout << "\n****\n";
        // cout << x << endl;
        while(x){
            int mod = x%10;
            if(INT_MAX/10<res) return 0;
            if((INT_MAX/10==res)&&(mod>7)) return 0;
            res = res*10+mod;
            x /=10;
            // cout << mod << " ";
        }
        return sign*res;
    }
};