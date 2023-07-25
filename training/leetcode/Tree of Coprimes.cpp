#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {

        // vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
        vector<vector<int>> coprime(51, vector<int>(51, 0));
        for (int i = 0; i <= 50; i++)
        {
            for (int j = 0; j <= 50; j++)
            {
                int gcd = __gcd(i, j);
                coprime[i][j] = gcd > 1;
                coprime[j][i] = gcd > 1;
            }
        }
    }
};