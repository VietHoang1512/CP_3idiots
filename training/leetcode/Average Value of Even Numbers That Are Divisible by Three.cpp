#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        double cnt=0, total=0;
        cout << "\n***\n";
        for (auto n:nums){
            if (n%6) continue;
            cout << n <<  " ";
            total += n;
            cnt++;
        }
        if (!cnt) return 0;
        return round(total/cnt);

    }
};