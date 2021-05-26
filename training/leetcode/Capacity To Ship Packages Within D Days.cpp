#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // sort(weights.rbegin(), weights.rend());
        int l = *max_element(weights.begin(), weights.end()), r = accumulate(weights.begin(), weights.end(), 0);
        while (r > l)
        {
            int tmp = (r + l) / 2;
            if (shipable(weights, days, tmp))
            {
                r = tmp;
            }
            else
            {
                l = tmp;
            }
            if (r == l + 1)
            {
                if (shipable(weights, days, l))
                    return l;
                break;
            }
        }
        // cout << shipable(weights, days, 11) << endl;
        // cout << endl;
        return r;
    }
    bool shipable(vector<int> &weights, int days, int capacity)
    {
        int cnt = 0, tmp = capacity, total = weights.size();
        // int l = 0, r = total - 1;
        // while (r >= l)
        // {
        //     cnt++;
        //     cout << "\n"
        //          << cnt << ": ";

        //     tmp = 0;
        //     for (int i = l; i <= r; i++)
        //     {
        //         if (tmp + weights[i] <= capacity)
        //         {
        //             l = i + 1;
        //             tmp += weights[i];
        //             cout << weights[i] << " ";
        //         }
        //         else
        //             break;
        //     }
        //     for (int i = r; i >= l; i--)
        //     {
        //         if (tmp + weights[i] <= capacity)
        //         {
        //             r = i - 1;
        //             tmp += weights[i];
        //             cout << weights[i] << " ";
        //         }
        //         else
        //             break;
        //     }
        // }

        for (auto x : weights)
        {
            if (tmp + x > capacity)
            {
                cnt++;
                tmp = x;
            }
            else
            {
                tmp += x;
            }
        }
        return cnt <= days;
    }
};