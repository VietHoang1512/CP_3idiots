#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maxWidthRamp(vector<int> &A)
    {
        int res = 0;
        int total = A.size();
        for (int i = 0; i < total - 1; i++)
        {
            if (total - i < res)
                break;
            for (int j = total - 1; j > i; j--)
            {
                if (A[i] <= A[j])
                {
                    res = max(res, j - i);
                    break;
                }
            }
        }
        return res;
    }
};