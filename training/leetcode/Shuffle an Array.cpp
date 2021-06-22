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
    vector<int> v;
    int s = 0;
    Solution(vector<int> &nums)
    {
        v = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        if (s)
        {
            s--;
            swap(v[0], v[v.size() - 1]);
        }
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {

        s = (s + 1) % 2;
        swap(v[0], v[v.size() - 1]);
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */