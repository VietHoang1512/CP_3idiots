#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        // cout << "\n\n";
        int total = nums.size();
        int res = 0;
        for (int i = 1; i < (1 << total); i++)
        {
            int tmp = 0;
            // cout << endl;
            for (int j=0; j < total; j++)
            {

                // cout << i << "-" << j << endl;
                if ((i >> j) & 1)
                {
                    tmp ^= nums[j];
                    // cout << i << " ";
                }
            }
            res += tmp;
        }
        return res;
    }
};