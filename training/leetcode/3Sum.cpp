#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define __builtin_popcount __builtin_popcountll
// #define SCD(t) scanf("%d", &t)
// #define SCLD(t) scanf("%ld", &t)
// #define SCLLD(t) scanf("%lld", &t)
// #define SCC(t) scanf("%c", &t)
// #define SCS(t) scanf("%s", t)
// #define SCF(t) scanf("%f", &t)
// #define SCLF(t) scanf("%lf", &t)
// #define read(type) readInt<type>()
// #define IN(A, B, C) assert(B <= A && A <= C)

int main()
{
}
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int total = nums.size();

        if (total < 3)
            return res;

        map<int, int> m;
        map<int, map<int, int>> mi;
        for (auto x : nums)
        {
            m[x]++;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < total - 2; i++)
        {
            for (int j = i + 1; j < total - 1; j++)
            {
                int x = -nums[i] - nums[j];
                if ((x > nums[j]) && m.count(x) && (!mi[nums[i]][nums[j]]))
                {
                    res.push_back({nums[i], nums[j], x});
                    mi[nums[i]][nums[j]] = 1;
                }
                else if ((x == nums[j]) && (x > nums[i]) && (m[x] > 1) && (!mi[nums[i]][nums[j]]))
                {
                    res.push_back({nums[i], nums[j], x});
                    mi[nums[i]][nums[j]] = 1;
                }
            }
        }
        if (m[0] >= 3)
            res.push_back({0, 0, 0});
        return res;
    }
};