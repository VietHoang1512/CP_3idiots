#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int P)
    {
        sort(tokens.begin(), tokens.end());
        int total = tokens.size(), l = 0, r = total - 1, score = 0;
        int res = 0;
        if (total == 1)
            return P >= tokens[0];
        vector<int> cum_sum(total, 0);
        int cum_sum_ = 0;
        for (int i = 0; i < total; i++)
        {
            cum_sum_ += tokens[i];
            cum_sum[i] = cum_sum_;
        }
        // for (auto x : cum_sum)
        // {
        //     cout << x << " ";
        // }
        cout << endl;
        while ((P >= 0) && (r > l))
        {
            cout << P << " ";
            int tmp = P;
            for (int i = l; i <= r; i++)
            {

                if (tmp >= cum_sum[i] - cum_sum[l] + tokens[l])
                    res = max(res, i - l + 1);
                else
                    break;
            }
            if (P < tokens[l])
                break;

            P -= tokens[l];
            P += tokens[r];
            l++;
            r--;
        }
        return res;
    }
};