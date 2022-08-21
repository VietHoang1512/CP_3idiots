#include <bits/stdc++.h>
using namespace std;

long long main()
{
}

class Solution
{
public:
    long long edgeScore(vector<int> &edges)
    {
        long long N = edges.size();
        vector<long long> v(N);
        for (long long i = 0; i < N; i++)
        {
            v[edges[i]] += i;
        }
        long long s = v[0], res = 0;

        for (long long i = 0; i < N; i++)
        {
            if (v[i] > s)
            {
                s = v[i];
                res = i;
            }
        }
        return res;
    }
};