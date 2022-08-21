#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        sort(amount.begin(), amount.end());
        // for (int i=0; i<3; i++){
        //     cout << amount[i] << endl;
        // }
        int ans = (amount[1] - amount[0]);
        amount[2] = amount[2] - ans;
        amount[1] = amount[0];
        if (amount[2] >= amount[1] * 2)
        {
            ans += amount[2];
            return ans;
        }
        else
        {
            int a = amount[2] / 2;
            ans += 2 * a;
            amount[0] -= a;

            amount[2] -= 2 * a;
            ans += amount[0] + amount[2];
            return ans;
        }
        return ans;
    }
};