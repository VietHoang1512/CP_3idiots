#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int MAX = 1e5 + 5;
class Solution
{
public:
    int mx;
    int res;
    int cum_left[MAX], cum_right[MAX];

    int maxScore(vector<int> &cardPoints, int k)
    {
        mx = k;
        int total = cardPoints.size();

        // TRY(cardPoints, 1, 0, total - 1, 0);
        int cum_left_ = 0, cum_right_ = 0;
        for (int i = 0; i < total; i++)
        {
            cum_left_ += cardPoints[i];
            cum_left[i + 1] += cum_left_;
            cum_right_ += cardPoints[total - 1 - i];
            cum_right[i + 1] += cum_right_;
        }
        for (int i = 0; i <= k; i++)
        {
            res = max(res, cum_left[i] + cum_right[(k - i)]);
        }
        return res;
    }
    // void TRY(vector<int> &cardPoints, int k, int l, int r, int cur)
    // {
    //     if (k == mx + 1)
    //     {
    //         res = max(res, cur);
    //         return;
    //     }
    //     cur += cardPoints[l];
    //     TRY(cardPoints, k + 1, l + 1, r, cur);
    //     cur -= cardPoints[l];
    //     cur += cardPoints[r];
    //     TRY(cardPoints, k + 1, l, r - 1, cur);
    //     cur -= cardPoints[r];
    // }
};
