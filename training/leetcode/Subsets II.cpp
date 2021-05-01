#include <bits/stdc++.h>
using namespace std;

int main()
{
}


const int mx = 25;
const int shift = 10;
class Solution
{
public:
    vector<vector<int>> res;
    int cnt[mx];
    int cur[mx];
    int total;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        total = nums.size();
        for (auto x : nums)
            cnt[x + shift]++;

        // cout << "Count vector: ";
        // for (int i = 0; i < mx; i++)
        // {
        //     cout << cnt[i] << " ";
        // }
        // cout << endl;
        TRY(0);

        // for (int i = 0; i < pow(2, total); i++)
        // {
        //     vector<int> cur;
        //     for (int j = 0; j < total; j++)
        //     {
        //         if ((i >> j) & 1)
        //             cur.push_back(nums[i]);
        //     }
        //     res.push_back(cur);
        // }

        return res;
    }
    void TRY(int k)
    {
        // cout << "Trying on " << k << endl;
        if (k == mx)
        {
            // cout << "Pushing vector: ";
            // for (int i = 0; i < mx; i++)
            // {
            //     cout << cur[i] << " ";
            // }
            // cout << endl;
            vector<int> tmp;
            for (int i = 0; i < mx; i++)
            {
                for (int j = 0; j < cur[i]; j++)
                {
                    tmp.push_back(i - shift);
                }
            }
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i <= cnt[k]; i++)
        {
            cur[k] = i;
            TRY(k + 1);
            // cur[k] = 0;
        }
    }

    // void TRY(int k, int cnt, int total, vector<int> cur)
    // {
    //     if (cnt == total)
    //     {
    //         res.push_back(cur);
    //     }
    // }
};