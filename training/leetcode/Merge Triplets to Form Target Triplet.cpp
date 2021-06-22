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
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int c0 = 0, c1 = 0, c2 = 0, c01 = 0, c12 = 0, c20 = 0;
        for (auto triplet : triplets)
        {
            if (triplet == target)
            {
                return true;
            }
            if ((triplet[0] == target[0]) && (triplet[1] <= target[1]) && (triplet[2] <= target[2]))
            {
                c0++;
                if (triplet[1] == target[1])
                    c01++;
                if (triplet[2] == target[2])
                    c20++;
            }
            if ((triplet[1] == target[1]) && (triplet[0] <= target[0]) && (triplet[2] <= target[2]))
            {
                c1++;
                if (triplet[0] == target[0])
                    c01++;
                if (triplet[2] == target[2])
                    c12++;
            }
            if ((triplet[2] == target[2]) && (triplet[1] <= target[1]) && (triplet[0] <= target[0]))
            {
                c2++;
                if (triplet[1] == target[1])
                    c12++;
                if (triplet[0] == target[0])
                    c20++;
            }
        }
        return c0 * c1 * c2 + c01 * c2 + c12 * c0 + c20 * c1;
    }
};