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
    bool makeEqual(vector<string> &words)
    {
        int total = words.size();
        map<int, int> m;
        for (auto word : words)
        {
            for (auto c : word)
            {
                m[c]++;
            }
        }
        for (auto p : m)
        {
            if (p.second % total)
                return false;
        }
        return true;
    }
};