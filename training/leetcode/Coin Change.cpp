#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}
class Solution
{
public:
    map<int, int> m;
    vector<int> A;
    int coinChange(vector<int> &coins, int amount)
    {
        if (!amount)
            return 0;
        sort(coins.begin(), coins.end());
        A = coins;
        m[0]=0;
        int gcd = A[0], total = A.size();
        for (auto c : A)
        {
            gcd = __gcd(gcd, c);
            m[c] = 1;
        }
        if ((amount % gcd) || (A[0] > amount))
            return -1;

        return dp(amount);
    }
    int dp(int n)
    {
        if (m.count(n))
            return m[n];
        int tmp = INT_MAX / 2;
        for (auto c : A)
        {
            if (n < c)
                break;
            if (dp(n - c) >= 0)
                tmp = min(tmp, 1 + dp(n - c));
        }
        if (tmp >= INT_MAX / 2)
            return m[n] = -1;
        return m[n] = tmp;
    }
};