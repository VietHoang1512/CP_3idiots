#include <bits/stdc++.h>
using namespace std;

#define int long long
#define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        int total = arr.size();
        int res = 0;
        for (int i = 0; i <= total - m * k; i++)
        {
            int tmp = 1;
            for (int j = 1; j < k; j++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (arr[i + l] != arr[i + j * m + l])
                        tmp = 0;
                }
            }
            res = max(tmp, res);
        }
        return res;
    }
};