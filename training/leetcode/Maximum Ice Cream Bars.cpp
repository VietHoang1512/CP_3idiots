#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int res = 0;
        sort(costs.rbegin(), costs.rend());
        while (costs.size() && coins >= costs.back())
        {
            coins -= costs.back();
            costs.pop_back();
            res++;
        }
        return res;
    }
};