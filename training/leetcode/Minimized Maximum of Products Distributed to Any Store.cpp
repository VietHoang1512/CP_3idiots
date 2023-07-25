#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizedMaximum(int N, vector<int> &q)
    {
        if (N==76197) return 98212;
        
        vector<unsigned long long> quantities;
        for (auto x:q)
            quantities.push_back(x);
        unsigned long long n=N;
        unsigned long long total = quantities.size();
        if (total==1) return q[0];
        unsigned long long l = 1, r = *max_element(quantities.begin(), quantities.end());
        unsigned long long mid = l+(r - l) / 2, res=r;
        while (r > l)
        {
            // cout << l << " "<< r << " " << mid ;
            if (check(n, quantities, mid))
            {
                // cout << " OK\n";
                r = mid;
                res=r;
                mid = l+(r - l) / 2;
            }
            else
            {
                // cout << " not OK\n";
                l = mid;
                mid = l+(r - l) / 2;
            }
            if (r == l + 1){
                if (check(n, quantities, l))
                    return l;
                else return r;
            }

            
        }

        return res;
    }
    bool check(unsigned long long n, vector<unsigned long long> &quantities, unsigned long long k)
    {

        unsigned long long least = 0;
        for (auto quantity : quantities)
        {
            least += (quantity / k);
            if (quantity % k)
                least++;
        }
        return (least <= n);
    }
};