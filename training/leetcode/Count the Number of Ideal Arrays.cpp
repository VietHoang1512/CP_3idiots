#include <bits/stdc++.h>
using namespace std;

int main()
{
}

int spf[10005];


void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < 10005; i++)


        spf[i] = i;


    for (int i = 4; i < 10005; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < 10005; i++)
    {

        if (spf[i] == i)
        {

            for (int j = i * i; j < 10005; j += i)


                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}


vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        sieve();
        vector<int> dp(maxValue + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= maxValue; i++)
        {
            int ans=0
            vector<int> primes = getFactorization(maxValue);
            map<int, int> m;
            int num_div = primes.size();
            for (auto p:primes){
                m[p]++;
            }
            int num_div = m.size();
            if (num_div == 1)
                dp[i] = n-1;
            else{
                for (auto p:m){
                    dp[i] 
                }
            }
        }

        return 0;
    }
};