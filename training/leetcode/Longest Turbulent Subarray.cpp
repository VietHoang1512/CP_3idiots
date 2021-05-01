#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 4 * 1e4 + 5;

class Solution
{
public:
    int incr[mx], decr[mx];
    int maxTurbulenceSize(vector<int> &a)
    {
        int total = a.size();
        incr[0] = decr[0] = 1;
        int res = 1;
        for (int i = 1; i < total; i++)
        {
            if (a[i] > a[i - 1])
            {
                incr[i] = decr[i - 1] + 1;
                decr[i] = 1;
            }
            else if (a[i] < a[i - 1])
            {
                decr[i] = incr[i - 1] + 1;
                incr[i] = 1;
            }
            else
            {
                decr[i] = 1;
                incr[i] = 1;
            }
            res = max(res, max(decr[i], incr[i]));
        }
        return res;
    }
};