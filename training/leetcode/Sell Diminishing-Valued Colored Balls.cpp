#include <bits/stdc++.h>
using namespace std;

long long main()
{
}

const long long mod = 1e9 + 7;

class Solution
{
public:
    int maxProfit(vector<int> &inventory, int orders)
    {
        priority_queue<pair<long long, long long>> PQ;
        long long res = 0;
        for (long long i = 0; i < inventory.size(); i++)
        {
            PQ.push({inventory[i], i});
        }
        long long ordered = 0;
        while (ordered < orders)
        {
            cout << "Ordered " << ordered << endl;
            pair<long long, long long> p1 = PQ.top();
            PQ.pop();
            pair<long long, long long> p2;
            if (PQ.size())
            {
                p2 = PQ.top();
            }
            else
            {
                long long num = orders - ordered;
                res = (res + (2 * p1.first - num + 1) * num / 2) % mod;
                return res;
            }
            long long num = min(p1.first - p2.first + 1, orders - ordered);
            ordered += num;
            res = (res + (2 * p1.first - num + 1) * num / 2) % mod;
            if (p1.first - num > 1)
                PQ.push({p1.first - num, p1.second});
        }
        return res;
    }
};