#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int numTimesAllBlue(vector<int> &light)
    {
        int tmp = 0, res = 0, n = light.size();
        // vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            tmp = max(tmp, light[i] - 1);
            if (tmp == i)
                res++;
        }
        return res;
    }
};