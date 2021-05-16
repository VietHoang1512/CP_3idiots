#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int reinitializePermutation(int n)
    {
        // if (n == 2)
        //     return 1;
        vector<int> perm(n, 0);
        int res = 0;

        for (int i = 0; i < n; i++)
        {

            perm[i] = i;
        }
        vector<int> arr(n, 0);
        while (CONTINUE(arr))
        {
            arr = TRANSFORM(perm);
            res++;
            perm = arr;
        }
        return res;
    }
    vector<int> TRANSFORM(vector<int> perm)
    {
        int n = perm.size();
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                arr[i] = perm[i / 2];
            if (i % 2 == 1)
                arr[i] = perm[n / 2 + (i - 1) / 2];
        }
        return arr;
    }
    bool CONTINUE(vector<int> perm)
    {
        int n = perm.size();
        for (int i = 0; i < n; i++)
        {
            if (perm[i] - i)
                return true;
        }
        return false;
    }
};