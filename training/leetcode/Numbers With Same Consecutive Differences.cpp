#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> res;

    vector<int> numsSameConsecDiff(int n, int k)
    {
        for (int i = 1; i < 10; i++)
        {
            TRY(1, n, k, i);
        }
        return res;
    }
    void TRY(int t, int n, int k, int num)
    {
        if (t == n)
        {
            res.push_back(num);
            return;
        }
        int last_digit = num % 10;
        if (last_digit >= k)
            TRY(t + 1, n, k, num * 10 + last_digit - k);
        if (k && (last_digit + k < 10))
            TRY(t + 1, n, k, num * 10 + last_digit + k);
    }
};