#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        int res = 0;
        int total = A.size();
        sort(A.begin(), A.end());
        for (int i = 1; i < total; i++)
        {
            if (A[i - 1] >= A[i])
            {
                res += (A[i - 1] - A[i] + 1);
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};