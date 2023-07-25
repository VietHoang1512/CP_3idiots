#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        map<int, int> m;
        k = abs(k);
        int len = arr.size();
        if (len % 2)
            return false;
        for (auto n : arr)
        {
            m[(n % k + k) % k]++;
        }
        if (m[0] % 2)
            return false;
        for (int i = 1; i < k; i++)
        {
            if (m[i] != m[k - i])
                return false;
        }
        return true;
    }
};
Console
