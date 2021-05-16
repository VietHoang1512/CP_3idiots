#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minOperations(vector<int> &a)
    {
        int n = a.size();
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] <= a[i - 1])
            {
                res += (a[i - 1] + 1 - a[i]);
                a[i] = a[i - 1] + 1;
            }
        }

        return res;
    }
};