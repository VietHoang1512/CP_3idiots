#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int res = 0;
    int diff = INT_MAX;
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        int n_base = baseCosts.size(), n_topping = toppingCosts.size();
        for (auto base : baseCosts)
        {
            vector<int> cnt_topping(n_topping, 0);
            int cur_diff = target - base;
            // if (cur_diff <= 0)
            //     continue;
            TRY(toppingCosts, 0, cnt_topping, cur_diff, target);
        }
        return res;
    }
    void TRY(vector<int> &toppingCosts, int k, vector<int> cnt_topping, int cur_diff, int target)
    {
        int n_topping = toppingCosts.size();
        if (k == n_topping)
        {
            if (abs(cur_diff) == diff)
            {
                res = min(res, target - cur_diff);
            }
            else if (abs(cur_diff) < diff)
            {
                res = target - cur_diff;
                diff = abs(cur_diff);
            }
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            int tmp = cur_diff - i * toppingCosts[k];
            cnt_topping[k] = i;
            // if (tmp >= 0)
            TRY(toppingCosts, k + 1, cnt_topping, tmp, target);
        }
    }
};